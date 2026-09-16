#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
public:
  ShopItemOrder(string name, double unit_price, int quantity);

  // Getters
  string get_name();
  double get_unit_price();
  int    get_quantity();
  double get_total_price();

  // Setters
  void set_name(string name);
  void set_unit_price(double unit_price);
  void set_quantity(int quantity);

  // Impresión amigable
  void print();

private:
  string name;
  double unit_price;
  int    quantity;
};

ShopItemOrder::ShopItemOrder(string name, double unit_price, int quantity)
{
  this->name = name;
  this->unit_price = (unit_price < 0) ? 0 : unit_price;
  this->quantity   = (quantity < 0) ? 0 : quantity;
}

string ShopItemOrder::get_name()
{
  return name;
}

double ShopItemOrder::get_unit_price()
{
  return unit_price;
}

int ShopItemOrder::get_quantity()
{
  return quantity;
}

double ShopItemOrder::get_total_price()
{
  return unit_price * quantity;
}

void ShopItemOrder::set_name(string name)
{
  this->name = name;
}

void ShopItemOrder::set_unit_price(double unit_price)
{
  if (unit_price < 0)
    return;   // ignoramos precios inválidos

  this->unit_price = unit_price;
}

void ShopItemOrder::set_quantity(int quantity)
{
  if (quantity < 0)
    return;   // ignoramos cantidades inválidas

  this->quantity = quantity;
}

void ShopItemOrder::print()
{
  cout << quantity << " x " << name
       << " @ $" << unit_price
       << " = $" << get_total_price() << endl;
}


int main()
{
  ShopItemOrder order("Wireless Mouse", 19.99, 3);
  order.print();

  order.set_quantity(5);
  order.print();

  order.set_unit_price(-10.0);   // se ignora, precio inválido
  order.print();

  order.set_name("Wireless Mouse (Black)");
  order.print();

  return 0;
}