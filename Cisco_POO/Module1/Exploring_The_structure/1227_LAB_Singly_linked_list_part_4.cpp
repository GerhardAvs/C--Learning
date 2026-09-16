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

  if (tail == nullptr)      // la lista estaba vacía: el nuevo nodo es también el último
    tail = new_head;

  count++;
}

bool List::pop_front(int &value)
{
  if (head == nullptr)
    return false;

  Node* popped = head;
  head = popped->next;

  if (head == nullptr)      // sacamos el único nodo que había: la lista vuelve a estar vacía
    tail = nullptr;

  value = popped->value;
  delete popped;
  count--;

  return true;
}

void List::push_back(int value)
{
  Node* new_node = new Node(value);   // STEP 1: crear el nuevo nodo, aislado

  if (tail == nullptr)                // la lista estaba vacía
  {
    head = new_node;
    tail = new_node;
  }
  else
  {
    tail->next = new_node;            // STEP 2: el último nodo actual apunta al nuevo
    tail = new_node;                  // STEP 3: tail avanza para apuntar al nuevo último
  }

  count++;
}

int List::size()
{
  return count;
}

int main()
{
  List list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  int value = 0;
  while (list.pop_front(value))
  {
    cout << value << endl;
  }
  return 0;
}