#include <iostream>

using namespace std;

#include <string>

const double tax = 0.25;

class Commodity {
    public:
    Commodity(string name, int id, double price) : name(name), id(id), price(price) {}
    string get_name() const { return name; }
    int get_id() const { return id; }
    double get_price() const { return price; }
    double get_price(double quantity) const { return price * quantity; }
    double get_price_with_sales_tax(double quantity) const { return price * quantity * tax; }
    void set_price(double new_price) { price = new_price; }

    private:
        string name;
        int id;
        double price;
        };

