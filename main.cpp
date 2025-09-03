#include <iostream>
#include <memory>
#include <string>

class Vehicle {
 public:
  Vehicle() { std::cout << "Created Vehicle\n"; }

  std::string getModelName() { return modelName; }

  void setModelName(std::string modelName) { this->modelName = modelName; }

  void setVersion(int version) { this->version = version; }

 protected:
  void run() { std::cout << "Vehicle is running..."; }

 private:
  std::string modelName;
  int         version;
};

class Taxi : public Vehicle {
 public:
  Taxi() { std::cout << "Created Taxi\n"; }

  void run() {
    Vehicle::run();
    std::cout << "This is a taxi.";
  }

  void run(int km) { kmCounter = km; }

  int calculateFee() { return kmCounter * 10000; }

 private:
  int kmCounter;
};

class Truck : public Vehicle {};

int main() {
  std::unique_ptr<Taxi> taxi = std::make_unique<Taxi>();

  taxi->run(10);

  std::cout << taxi->calculateFee() << " VND\n";

  return 0;
}