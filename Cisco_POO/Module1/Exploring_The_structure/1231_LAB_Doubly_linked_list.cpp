// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
// +------+
//
//  Node*
// +------+
// | tail |-->nullptr
// +------+
//
//
//
// A list with two elements:
//
//  Node*      Node         Node
//
//            +-----+      +-----+
//   nullptr<-|prev |   +--|prev |
// +------+   +-----+<--+  +-----+
// | head |-->|value|      |value|
// +------+   +-----+  +-->+-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+

class Node
{
public:
  Node(int val);
  int value;
  Node* prev
  Node* next;
};

class List
{
public:
  List();
  List(List &other);
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