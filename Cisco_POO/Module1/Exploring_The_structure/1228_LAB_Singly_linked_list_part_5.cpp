#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int size();
private:
  // other members you may have used
  Node* head;
  Node* tail;
};

List::List() : head(nullptr), tail(nullptr)
{
}

bool List::pop_back(int &value)
{
  // implement me!
  return false;
}

// ...

int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  int value = 0;
  while (list.pop_back(value))
  {
    cout << value << endl;
  }
  return 0;
}