#include <iostream>
#include <string>

const int MAX_MEMBERS = 10;

class Member {
public:
  Member();
  Member(int id, std::string name);
  int  getId();
  bool extend(int months);
  void cancel();
  void printStatus();
private:
  int         id;
  std::string name;
  int         months;
};

Member::Member()
{
  id = 0;
  name = "";
  months = 0;
}

Member::Member(int id, std::string name)
{
  this->id = id;
  this->name = name;
  this->months = 0;
}

int Member::getId()
{
  return id;
}

bool Member::extend(int n)
{
  if (n < 0)
    return false;

  months += n;
  return true;
}

void Member::cancel()
{
  months = 0;
}

void Member::printStatus()
{
  std::cout << "Member " << id << " : " << name
             << ", subscription valid for " << months << " months" << std::endl;
}

// Busca el índice del socio con ese id (0 = slot vacío). -1 si no existe.
int findMember(Member members[], int count, int id)
{
  for (int i = 0; i < count; i++)
    if (members[i].getId() == id)
      return i;
  return -1;
}

void printAllStatus(Member members[], int count)
{
  bool any = false;

  for (int i = 0; i < count; i++)
  {
    if (members[i].getId() != 0)
    {
      members[i].printStatus();
      any = true;
    }
  }

  if (!any)
    std::cout << "No members in the system" << std::endl;
}

int main() {
  Member members[MAX_MEMBERS];

  std::string command;
  while (true)
  {
    printAllStatus(members, MAX_MEMBERS);

    std::cout << "What would you like to do?: ";
    std::cin >> command;

    if (command == "quit")
      break;

    if (command == "create")
    {
      int id;
      std::cin >> id;
      std::cin.ignore();          // salta el espacio antes del nombre
      std::string name;
      std::getline(std::cin, name);

      if (id == 0)
        std::cout << "Cannot perform this operation: invalid member id" << std::endl;
      else if (findMember(members, MAX_MEMBERS, id) != -1)
        std::cout << "Cannot perform this operation: member " << id << " already exists" << std::endl;
      else
      {
        int empty_slot = findMember(members, MAX_MEMBERS, 0);
        if (empty_slot == -1)
          std::cout << "Cannot perform this operation: no more members can be created" << std::endl;
        else
          members[empty_slot] = Member(id, name);
      }
    }
    else if (command == "delete")
    {
      int id;
      std::cin >> id;

      int idx = findMember(members, MAX_MEMBERS, id);
      if (idx == -1)
        std::cout << "Cannot perform this operation: member " << id << " not found" << std::endl;
      else
        members[idx] = Member();   // vuelve al estado "vacío"
    }
    else if (command == "extend")
    {
      int id, n;
      std::cin >> id >> n;

      int idx = findMember(members, MAX_MEMBERS, id);
      if (idx == -1)
        std::cout << "Cannot perform this operation: member " << id << " not found" << std::endl;
      else if (!members[idx].extend(n))
        std::cout << "Cannot perform this operation: invalid number of months" << std::endl;
    }
    else if (command == "cancel")
    {
      int id;
      std::cin >> id;

      int idx = findMember(members, MAX_MEMBERS, id);
      if (idx == -1)
        std::cout << "Cannot perform this operation: member " << id << " not found" << std::endl;
      else
        members[idx].cancel();
    }
  }

  return 0;
}