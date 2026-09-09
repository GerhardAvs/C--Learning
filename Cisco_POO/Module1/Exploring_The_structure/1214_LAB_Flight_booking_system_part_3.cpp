#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  FlightBooking();
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool cancelReservations(int number_ob_seats);
  int getId() { retutn id };
private:
  int id;
  int capacity;
  int reserved;
};

FlightBooking::FlightBooking()
{
  id = 0; capacity = 0; reserved = 0;
}

// ...

int main() {
  FlightBooking booking[10];

  // Use this to have some starting value
  // booking[0] = FlightBooking(1, 400, 0);
  // booking[0].printStatus();

  std::string command = "";
  while (command != "quit")
  {
    std::cout << "What would you like to do?: "
    std::cin.getline(command);

    // handle the command
  }

  return 0;
}