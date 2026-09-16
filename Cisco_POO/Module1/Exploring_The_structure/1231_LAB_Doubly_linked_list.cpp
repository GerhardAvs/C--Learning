#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* prev;
  Node* next;
};

Node::Node(int val) : value(val), prev(nullptr), next(nullptr)
{
}

class List
{
public:
  List();
  List(List &other);
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
  Node* find_node(int index);   // método auxiliar privado
  Node* head;
  Node* tail;
  int   count;
};

List::List() : head(nullptr), tail(nullptr), count(0)
{
}

List::List(List &other) : head(nullptr), tail(nullptr), count(0)
{
  Node* current = other.head;

  while (current != nullptr)
  {
    push_back(current->value);
    current = current->next;
  }
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

  if (head != nullptr)
    head->prev = new_head;
  else
    tail = new_head;             // la lista estaba vacía

  head = new_head;
  count++;
}

bool List::pop_front(int &value)
{
  if (head == nullptr)
    return false;

  Node* popped = head;
  head = popped->next;

  if (head != nullptr)
    head->prev = nullptr;
  else
    tail = nullptr;              // sacamos el único elemento

  value = popped->value;
  delete popped;
  count--;

  return true;
}

void List::push_back(int value)
{
  Node* new_node = new Node(value);
  new_node->prev = tail;

  if (tail != nullptr)
    tail->next = new_node;
  else
    head = new_node;             // la lista estaba vacía

  tail = new_node;
  count++;
}

bool List::pop_back(int &value)
{
  if (tail == nullptr)
    return false;

  Node* popped = tail;
  tail = popped->prev;

  if (tail != nullptr)
    tail->next = nullptr;
  else
    head = nullptr;              // sacamos el único elemento

  value = popped->value;
  delete popped;
  count--;

  return true;
}

// Encuentra el nodo en la posición 'index', recorriendo desde
// el extremo más cercano (head o tail) para ahorrar la mitad
// de los pasos en listas largas — algo que la lista simple no podía hacer.
Node* List::find_node(int index)
{
  Node* current;

  if (index <= count / 2)
  {
    current = head;
    for (int i = 0; i < index; i++)
      current = current->next;
  }
  else
  {
    current = tail;
    for (int i = count - 1; i > index; i--)
      current = current->prev;
  }

  return current;
}

int List::at(int index)
{
  return find_node(index)->value;
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

  Node* after = find_node(index);     // el nodo que actualmente ocupa esa posición
  Node* before = after->prev;

  Node* new_node = new Node(value);
  new_node->prev = before;
  new_node->next = after;

  before->next = new_node;
  after->prev = new_node;

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

  Node* to_delete = find_node(index);
  Node* before = to_delete->prev;
  Node* after = to_delete->next;

  before->next = after;
  after->prev = before;

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
  List list1;
  list1.push_back(1);
  list1.push_back(2);
  list1.push_back(3);
  list1.push_back(4);
  cout << "list1" << endl;
  printList(list1);
  cout << endl;

  List list2(list1);
  cout << "list2" << endl;
  printList(list2);
  cout << endl;

  list1.insert_at(1, 6);
  list2.remove_at(2);

  cout << "list1" << endl;
  printList(list1);
  cout << "list2" << endl;
  printList(list2);
  cout << endl;

  int value;
  while (list1.pop_back(value))
    cout << "popped from back: " << value << endl;

  return 0;
}