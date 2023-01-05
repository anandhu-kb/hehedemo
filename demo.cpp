#include <iostream>

class DM;  // Forward declaration of class DM

class DB {
 private:
  int feet;
  int inches;
 public:
  DB(int f = 0, int i = 0) {  // Constructor
    feet = f;
    inches = i;
  }
  friend DM operator+(const DM&, const DB&);  // Declare friend function
};

class DM {
 private:
  int meters;
  int centimeters;
 public:
  DM(int m = 0, int c = 0) {  // Constructor
    meters = m;
    centimeters = c;
  }
  friend DM operator+(const DM&, const DB&);  // Declare friend function
};

// Friend function to add two objects of DM and DB
DM operator+(const DM& dm, const DB& db) {
  int total_centimeters = dm.centimeters + db.inches * 2.54;  // Convert inches to centimeters
  int total_meters = dm.meters + db.feet * 0.3048 + total_centimeters / 100;  // Convert feet to meters and add to total meters
  int final_centimeters = total_centimeters % 100;  // Get the remaining centimeters
  return DM(total_meters, final_centimeters);  // Return the sum in DM
}

int main() {
  DM dm1(1, 50), dm2(0, 75);
  DB db1(3, 2), db2(1, 6);
  DM dm3 = dm1 + dm2;  // Add two objects of DM
  std::cout << "DM: " << dm3.meters << " meters " << dm3.centimeters << " centimeters" << std::endl;
  DM dm4 = dm1 + db1;  // Add an object of DM and an object of DB
  std::cout << "DM: " << dm4.meters << " meters " << dm4.centimeters << " centimeters" << std::endl;
  return 0;
}
