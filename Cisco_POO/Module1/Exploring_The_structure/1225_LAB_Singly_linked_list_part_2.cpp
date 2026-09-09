#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
  cout << "+Node" << endl;
}

Node::~Node()
{
  cout << "-Node" << endl;
}

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
private:
  Node* head;
};

// ...

int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  return 0;
}