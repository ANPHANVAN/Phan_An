#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // cout << "what your's age: \n";
    // int age;
    // cin >> age;
    // cout << "your age is: " << age << endl;

    // string fullName;
    // cout << "Type your full name: ";
    // getline(cin, fullName);
    // cout << "Your name is: " << fullName;
    // A vector with 3 elements
    vector<string> cars = {"Volvo", "BMW", "Ford"};

    // Adding another element to the vector
    cars.push_back("Tesla");
    cout << cars[3]<<endl;
    cout << "This is sizeof() cars(byte): " << sizeof(cars) << endl;
    
    struct Car
    {
        string brand;
        string model;
        int year;
    };

    Car myCar1, myCar2;

    myCar1.brand = "Toyota";
    myCar1.model = "E23";
    myCar1.year = 1996;

    // Put data into the second structure
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;

    // Print the structure members
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
    
    string food = "Pizza";
    cout << "this is food address in memory: " << &food << endl;

    return 0;
}