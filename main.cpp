#include <iostream>
#include <string>

class Woman {
 public:
  Woman(std::string fullName, int age, float weight, float height) {
    this->fullName = fullName;
    this->age      = age;
    this->weight   = weight;
    this->height   = height;
  }

  void showInfo() {
    std::cout << "Full name: " << fullName << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Weight: " << weight << "\n";
  }

  int getAge() { return age; }

  void setAge(int age) { this->age = age; }

  float getWeight() { return weight; }

  float getHeight() { return height; }

 private:
  std::string fullName;
  int         age;
  float       weight;
  float       height;
};

class HealthChecker {
 public:
  void check(Woman *woman) {
    weight        = woman->getWeight();
    height        = woman->getHeight();
    bloodPressure = 130;
    heartBeat     = 80;
  }

  std::string getResult() {
    float BMI = weight / (height * height);
    std::cout << BMI;
    if (BMI >= 18.5 && BMI <= 24.9 && bloodPressure >= 120 && bloodPressure < 140 && heartBeat >= 60 && heartBeat < 100)
      return "Normal";
    return "Abnormal";
  }

 private:
  float weight;
  float height;
  int   bloodPressure;
  int   heartBeat;
};

int main() {
  Woman         *hariwon = new Woman("Hariwon", 32, 55, 1.65);
  HealthChecker *checker = new HealthChecker();

  checker->check(hariwon);
  std::string result = checker->getResult();

  std::cout << result;
  return 0;
}