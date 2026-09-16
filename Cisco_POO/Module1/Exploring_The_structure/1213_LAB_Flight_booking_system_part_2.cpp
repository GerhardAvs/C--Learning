#include <iostream>
#include <string>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_of_seats);
  bool cancelReservations(int number_of_seats);
private:
  int id;
  int capacity;
  int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  this->id = id;
  this->capacity = capacity;

  int max_seats = capacity * 105 / 100;   // 105% de la capacidad

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

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  booking.printStatus();

  std::string command;
  while (true)
  {
    std::cout << "What would you like to do?: ";
    std::cin >> command;

    if (command == "quit")
      break;

    int n;
    std::cin >> n;

    bool success = false;
    if (command == "add")
      success = booking.reserveSeats(n);
    else if (command == "cancel")
      success = booking.cancelReservations(n);

    if (success)
      booking.printStatus();
    else
      std::cout << "Cannot perform this operation" << std::endl;
  }

  return 0;
}