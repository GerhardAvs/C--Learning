#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
}

class List
{
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  int  size();
private:
  Node* head;
  int   count;
};

List::List() : head(nullptr), count(0)
{
}

List::~List()
{
  while (head != nullptr)
  {
    Node* to_delete = head;
    head = head->next;
    delete to_delete;
  }
}

void List::push_front(int value)
{
  Node* new_head = new Node(value);
  new_head->next = head;
  head = new_head;
  count++;
}

bool List::pop_front(int &value)
{
  if (head == nullptr)
    return false;

  Node* popped = head;
  head = popped->next;
  value = popped->value;
  delete popped;
  count--;

  return true;
}

int List::size()
{
  return count;
}

int main()
{
  List list;
  for (int i = 0; i <= 5; i++)
  {
    list.push_front(i);
    cout << "pushed " << i << ", size: " << list.size() << endl;
  }
  cout << endl;
  for (int i = 0; i <= 3; i++)
  {
    int value;
    list.pop_front(value);
    cout << "popped " << value << ", size: " << list.size() << endl;
  }
  return 0;
}