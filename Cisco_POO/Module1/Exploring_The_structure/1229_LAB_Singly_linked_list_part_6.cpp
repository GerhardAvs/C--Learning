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
  int  at(int index);
  void insert_at(int index, int value);
  void remove_at(int index);
  int  size();
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

  if (head == tail)
  {
    delete tail;
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    Node* current = head;
    while (current->next != tail)
      current = current->next;

    delete tail;
    current->next = nullptr;
    tail = current;
  }

  count--;
  return true;
}

int List::at(int index)
{
  Node* current = head;

  for (int i = 0; i < index; i++)
    current = current->next;

  return current->value;
}

void List::insert_at(int index, int value)
{
  if (index == 0)
  {
    push_front(value);
    return;
  }

  if (index == count)
  {
    push_back(value);
    return;
  }

  // buscamos el nodo justo ANTES de la posición donde queremos insertar
  Node* before = head;
  for (int i = 0; i < index - 1; i++)
    before = before->next;

  Node* new_node = new Node(value);
  new_node->next = before->next;
  before->next = new_node;

  count++;
}

void List::remove_at(int index)
{
  if (index == 0)
  {
    int discarded;
    pop_front(discarded);
    return;
  }

  if (index == count - 1)
  {
    int discarded;
    pop_back(discarded);
    return;
  }

  // buscamos el nodo justo ANTES del que queremos eliminar
  Node* before = head;
  for (int i = 0; i < index - 1; i++)
    before = before->next;

  Node* to_delete = before->next;
  before->next = to_delete->next;
  delete to_delete;

  count--;
}

int List::size()
{
  return count;
}

void printList(List &list)
{
  for (int i = 0; i < list.size(); i++)
  {
    cout << "list[" << i << "] == " << list.at(i) << endl;
  }
}

int main()
{
  List list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  printList(list);
  cout << endl;

  list.remove_at(2);
  printList(list);
  cout << endl;

  list.insert_at(1, 6);
  printList(list);

  return 0;
}