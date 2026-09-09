#include <iostream>

using namespace std;

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
};

// ...

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
    list.pop_front(i);
    cout << "popped " << i << ", size: " << list.size() << endl;
  }
  return 0;
}