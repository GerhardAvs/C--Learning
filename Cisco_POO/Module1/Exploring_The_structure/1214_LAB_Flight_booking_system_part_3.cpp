#include <iostream>
#include <string>

const int MAX_FLIGHTS = 10;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  FlightBooking();
  void printStatus();
  bool reserveSeats(int number_of_seats);
  bool cancelReservations(int number_of_seats);
  int  getId() { return id; }
private:
  int id;
  int capacity;
  int reserved;
};

FlightBooking::FlightBooking()
{
  id = 0; capacity = 0; reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  this->id = id;
  this->capacity = capacity;

  int max_seats = capacity * 105 / 100;
  if (reserved < 0)
    reserved = 0;
  if (reserved > max_seats)
    reserved = max_seats;

  this->reserved = reserved;
}

void FlightBooking::printStatus()
{
  int percentage = reserved * 100 / capacity;

  std::cout << "Flight " << id << " : " << reserved << "/" << capacity
             << " (" << percentage << "%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
  if (number_of_seats < 0)
    return false;

  int max_seats = capacity * 105 / 100;
  if (reserved + number_of_seats > max_seats)
    return false;

  reserved += number_of_seats;
  return true;
}

bool FlightBooking::cancelReservations(int number_of_seats)
{
  if (number_of_seats < 0)
    return false;

  if (reserved - number_of_seats < 0)
    return false;

  reserved -= number_of_seats;
  return true;
}

// Busca el índice del vuelo con ese id (0 = slot vacío). -1 si no existe.
int findFlight(FlightBooking flights[], int count, int id)
{
  for (int i = 0; i < count; i++)
    if (flights[i].getId() == id)
      return i;
  return -1;
}

void printAllStatus(FlightBooking flights[], int count)
{
  bool any = false;

  for (int i = 0; i < count; i++)
  {
    if (flights[i].getId() != 0)
    {
      flights[i].printStatus();
      any = true;
    }
  }

  if (!any)
    std::cout << "No flights in the system" << std::endl;
}

int main() {
  FlightBooking flights[MAX_FLIGHTS];

  std::string command;
  while (true)
  {
    printAllStatus(flights, MAX_FLIGHTS);

    std::cout << "What would you like to do?: ";
    std::cin >> command;

    if (command == "quit")
      break;

    if (command == "create")
    {
      int id, capacity;
      std::cin >> id >> capacity;

      if (id == 0)
        std::cout << "Cannot perform this operation: invalid flight id" << std::endl;
      else if (findFlight(flights, MAX_FLIGHTS, id) != -1)
        std::cout << "Cannot perform this operation: flight " << id << " already exists" << std::endl;
      else
      {
        int empty_slot = findFlight(flights, MAX_FLIGHTS, 0);
        if (empty_slot == -1)
          std::cout << "Cannot perform this operation: no more flights can be created" << std::endl;
        else
          flights[empty_slot] = FlightBooking(id, capacity, 0);
      }
    }
    else if (command == "delete")
    {
      int id;
      std::cin >> id;

      int idx = findFlight(flights, MAX_FLIGHTS, id);
      if (idx == -1)
        std::cout << "Cannot perform this operation: flight " << id << " not found" << std::endl;
      else
        flights[idx] = FlightBooking();   // vuelve al estado "vacío"
    }
    else if (command == "add")
    {
      int id, n;
      std::cin >> id >> n;

      int idx = findFlight(flights, MAX_FLIGHTS, id);
      if (idx == -1)
        std::cout << "Cannot perform this operation: flight " << id << " not found" << std::endl;
      else if (n < 0)
        std::cout << "Cannot perform this operation: invalid number of seats" << std::endl;
      else if (!flights[idx].reserveSeats(n))
        std::cout << "Cannot perform this operation: capacity reached" << std::endl;
    }
    else if (command == "cancel")
    {
      int id, n;
      std::cin >> id >> n;

      int idx = findFlight(flights, MAX_FLIGHTS, id);
      if (idx == -1)
        std::cout << "Cannot perform this operation: flight " << id << " not found" << std::endl;
      else if (n < 0)
        std::cout << "Cannot perform this operation: invalid number of seats" << std::endl;
      else if (!flights[idx].cancelReservations(n))
        std::cout << "Cannot perform this operation: not enough reservations" << std::endl;
    }
  }

  return 0;
}