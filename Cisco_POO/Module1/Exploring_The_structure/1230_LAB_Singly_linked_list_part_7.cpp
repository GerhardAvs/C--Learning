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
  // Uncomment the line below once you're ready
  // List(List &other);
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int  at(int index);
  void insert_at(int index, int value)
  void remove_at(int index) which will
  int size()
private:
  // other members you may have used
  Node* head;
  Node* tail;
};

// ...
void printList(List &quot;list)
{
  for (int i = 0; i < list.size(); i++)
  {
    cout << "list[" << i << "] == " list.at(i) << endl;
  }
}

int main()
{
  List list1;
  list1.push_front(1);
  list1.push_front(2);
  list1.push_front(3);
  list1.push_front(4);
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

  return 0;
}