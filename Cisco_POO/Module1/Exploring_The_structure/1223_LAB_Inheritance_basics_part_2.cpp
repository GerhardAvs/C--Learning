#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FarmAnimal{
public:
  FarmAnimal(double water_consumption);
  double getWaterConsumption();
private:
  double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
  this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
  return water_consumption;
}


class Cow : public FarmAnimal {
public:
  Cow(double weight);
};

Cow::Cow(double weight) : FarmAnimal(weight * 8.6 / 100.0)
{
}


class Sheep : public FarmAnimal {
public:
  Sheep(double weight);
};

Sheep::Sheep(double weight) : FarmAnimal(weight * 1.1 / 10.0)
{
}


class Horse : public FarmAnimal {
public:
  Horse(double weight);
};

Horse::Horse(double weight) : FarmAnimal(weight * 6.8 / 100.0)
{
}


class ConsumptionAccumulator
{
public:
  ConsumptionAccumulator();
  double getTotalConsumption();
  void addConsumption(FarmAnimal &animal);
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

void ConsumptionAccumulator::addConsumption(FarmAnimal &animal)
{
  total_consumption += animal.getWaterConsumption();
}


int main()
{
  ConsumptionAccumulator accumulator;

  string line;
  while (getline(cin, line))
  {
    if (line.empty())
      break;

    istringstream iss(line);
    string species;
    double weight;
    iss >> species >> weight;

    if (species == "cow")
    {
      Cow animal(weight);
      accumulator.addConsumption(animal);
    }
    else if (species == "sheep")
    {
      Sheep animal(weight);
      accumulator.addConsumption(animal);
    }
    else if (species == "horse")
    {
      Horse animal(weight);
      accumulator.addConsumption(animal);
    }
  }

  cout << accumulator.getTotalConsumption();

  return 0;
}