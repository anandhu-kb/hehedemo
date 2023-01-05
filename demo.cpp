#include <iostream>

class Time {
 private:
  int hours;
  int minutes;
  int seconds;
 public:
  Time(int h = 0, int m = 0, int s = 0) {  // Constructor to initialize the time object
    hours = h;
    minutes = m;
    seconds = s;
  }
  void read() {  // Function to read the time from the user
    std::cout << "Enter hours, minutes and seconds: ";
    std::cin >> hours >> minutes >> seconds;
  }
  void display() {  // Function to display the time
    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
  }
  Time operator+(const Time& t) {  // Overloaded operator+ to add two Time objects
    int total_seconds = seconds + t.seconds;
    int total_minutes = minutes + t.minutes + total_seconds / 60;
    int final_seconds = total_seconds % 60;
    int total_hours = hours + t.hours + total_minutes / 60;
    int final_minutes = total_minutes % 60;
    return Time(total_hours, final_minutes, final_seconds);
  }
};

int main() {
  Time t1, t2;
  t1.read();  // Read time from the user
  t2.read();  // Read time from the user
  Time t3 = t1 + t2;  // Add two Time objects
  std::cout << "Time 1: ";
  t1.display();  // Display time 1
  std::cout << "Time 2: ";
  t2.display();  // Display time 2
  std::cout << "Time 3: ";
  t3.display();  // Display time 3
  return 0;
}
