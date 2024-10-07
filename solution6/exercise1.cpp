#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class ChessBoardPrint {
  public:
      void operator()(const ChessBoard& board) const {
          board.print_board();
      }
  };

  std::function<void(const ChessBoard&)> after_piece_move;

    ChessBoard() : after_piece_move([](const ChessBoard&) {}) {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares) {
        square_column.resize(8);
    }
    }

    void set_after_move_function(std::function<void(const ChessBoard&)> func) {
        after_piece_move = func;
    }

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns a short string representing the piece
    virtual char representation() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color) {}

    std::string type() const override {
      return color_string() + " king";
    }

    char representation() const override {
      return (color == Color::WHITE) ? 'K' : 'k';
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int delta_x = abs(to_x - from_x);
      int delta_y = abs(to_y - from_y);
      return (delta_x <= 1 && delta_y <= 1);
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}

    std::string type() const override {
      return color_string() + " knight";
    }

    char representation() const override {
      return (color == Color::WHITE) ? 'N' : 'n';
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int delta_x = abs(to_x - from_x);
      int delta_y = abs(to_y - from_y);
      return (delta_x == 2 && delta_y == 1) || (delta_x == 1 && delta_y == 2);
    }
  };

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string& from, const std::string& to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(std::string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(std::string() + to[1]) - 1;

    auto& piece_from = squares[from_x][from_y];
    if (piece_from) {
        if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
            cout << piece_from->type() << " is moving from " << from << " to " << to << endl;

            auto& piece_to = squares[to_x][to_y];
            if (piece_to) {
                if (piece_from->color != piece_to->color) {
                    cout << piece_to->type() << " is being removed from " << to << endl;
                    if (auto king = dynamic_cast<King*>(piece_to.get())) {
                        cout << king->color_string() << " lost the game" << endl;
                    }
                } else {
                    cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                    return false;
                }
            }
            // Move the piece
            piece_to = std::move(piece_from);

            // Use the functional object to print the board after a move
            after_piece_move(*this);

            return true;
        } else {
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
        }
    } else {
        cout << "no piece at " << from << endl;
        return false;
    }
  }


  /// Prints the chessboard with the pieces in their current positions
  void print_board() const {
    for (int y = 7; y >= 0; --y) {
      for (int x = 0; x < 8; ++x) {
        if (squares[x][y]) {
          cout << squares[x][y]->representation();
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main() {
  ChessBoard board;
  ChessBoard::ChessBoardPrint print_function;

  board.set_after_move_function(print_function);

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  board.print_board(); // Print the initial board state

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
