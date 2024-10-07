#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void send_response(shared_ptr<Connection> connection, const string &message) {
    auto write_buffer = make_shared<boost::asio::streambuf>();
    ostream write_stream(write_buffer.get());
    write_stream << message;

    async_write(connection->socket, *write_buffer,
                [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                    if (!ec) {
                        boost::system::error_code ignored_ec;
                        connection->socket.shutdown(tcp::socket::shutdown_both, ignored_ec);
                        connection->socket.close(ignored_ec);
                    } else {
                        cout << "Error sending response: " << ec.message() << endl;
                    }
                });
}

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    
    async_read_until(connection->socket, *read_buffer, "\r\n",
        [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
            if (!ec) {
                istream read_stream(read_buffer.get());
                string request;
                getline(read_stream, request);

                if (request.find("GET / ") != string::npos) {
                    send_response(connection, "HTTP/1.1 200 OK\r\n\r\nDette er hovedsiden");
                } else if (request.find("GET /en_side") != string::npos) {
                    send_response(connection, "HTTP/1.1 200 OK\r\n\r\nDette er en side");
                } else {
                    send_response(connection, "HTTP/1.1 404 Not Found\r\n\r\n404 Not Found");
                }
            }
        });
  }

  void accept() {
    auto connection = make_shared<Connection>(io_service);
    
    // Accepts a new (client) connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();
    io_service.run();
  }
};

int main() {
  EchoServer echo_server;

  cout << "Starting echo server" << endl
       << "Open a browser and navigate to http://localhost:8080 or http://localhost:8080/en_side" << endl;

  echo_server.start();
}
