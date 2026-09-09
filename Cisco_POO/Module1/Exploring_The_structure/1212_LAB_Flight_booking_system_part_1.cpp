#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
private:
  int id;
  int capacity;
  int reserved;
};

void FlightBooking::printStatus()
{
  // print report here
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  // Save data to members
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

  return 0;
}