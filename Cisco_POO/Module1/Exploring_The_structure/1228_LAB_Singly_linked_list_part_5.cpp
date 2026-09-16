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
  void push_back(int value);
  bool pop_back(int &value);
  int size();
private:
  Node* head;
  Node* tail;
  int   count;
};

List::List() : head(nullptr), tail(nullptr), count(0)
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

  if (tail == nullptr)
    tail = new_head;

  count++;
}

bool List::pop_front(int &value)
{
  if (head == nullptr)
    return false;

  Node* popped = head;
  head = popped->next;

  if (head == nullptr)
    tail = nullptr;

  value = popped->value;
  delete popped;
  count--;

  return true;
}

void List::push_back(int value)
{
  Node* new_node = new Node(value);

  if (tail == nullptr)
  {
    head = new_node;
    tail = new_node;
  }
  else
  {
    tail->next = new_node;
    tail = new_node;
  }

  count++;
}

bool List::pop_back(int &value)
{
  if (tail == nullptr)
    return false;

  value = tail->value;

  if (head == tail)               // solo había un elemento en la lista
  {
    delete tail;
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    // buscamos el nodo ANTERIOR a tail, empezando desde head
    Node* current = head;
    while (current->next != tail)
      current = current->next;

    delete tail;
    current->next = nullptr;      // este nodo pasa a ser el último
    tail = current;               // tail avanza hacia atrás
  }

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