#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool canceReservations(int number_ob_seats);
private:
  int id;
  int capacity;
  int reserved;
};
// ...
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  // Save data to members according to limits
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
  // try to add reservations and return 'true' on success
  // keep the limits in mind
  return false;
}

bool FlightBooking::canceReservations(int number_ob_seats);
{
  // try to cancel reservations and return 'true' on success
  // keep the limits in mind
  return false;
}

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  std::string command = "";
  while (command != "quit")
  {
    booking.printStatus();
    std::cout << "What would you like to do?: "
    std::cin.getline(command);

    // handle the command
  }

  return 0;
}