/*
Level of difficulty
Easy

Objectives
Familiarize the student with:

C++ class and object syntax;
creating objects;
accessing object members.
Scenario
Before we start doing anything useful with classes, objects and the like, we should 
familiarize ourselves a little with these concepts.

So for now, let's represent a person in terms of classes!

Run the code in the editor and then experiment with it. Add some more members to 
the class and try accessing them.
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
  string name;
  int    age;
  
  // Your code here
  int weight;
  int height;
  string pronouns;
  

};

void print(Person* person)
{
    std::cout << person->name << " is "
          << person->age << " years old. "
          << person->pronouns << " weighs "
          << person->weight << " and has a height of "
          << person->height << std::endl;
}


int main()
{
  Person person;
  person.name = "Harry";
  person.age  = 23;
  person.weight = 80;
  person.height = 170;
  person.pronouns = "he";
  
  cout << "Meet " << person.name << endl;
  print(&person);

  // Your code here

  return 0;
}