#include <iostream>

using namespace std;

class FarmAnimal{
public:
  FarmAnimal(double water_consumption);
  double getWaterConsumption();
  // ...
private:
  double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
  this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
  return water_consumption;
}

class ConsumptionAccumulator
{
public:
  ConsumptionAccumulator();
  double getTotalConsumption();
  void addConsumption(Animal &animal);
private:
  double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
  total_consumption(0)
{
}

double ConsumptionAccumulator::getTotalConsumption()
{
  return total_consumption;
}

void ConsumptionAccumulator::addConsumption(Animal &animal)
{
  total_consumption += animal.getWaterConsumption();
}


int main()
{
  ConsumptionAccumulator accumulator;

  // read user input
  // create appropriate objects and add them to the accumulator

  cout << accumulator.getTotalConsumption();

  return 0;
}