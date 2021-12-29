#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

// Macro definitions for max variable length:
#define MAX_NAME_LENGTH 50
#define MAX_OCCUPATION_LENGTH 100

// Program variables:
string hello = "Hello, from hello variable\n";
char occupation[MAX_OCCUPATION_LENGTH];
char fullname[MAX_NAME_LENGTH];
string nameString;
int age;

// Create Car class:
class Car {
    public:
        string brand;
        string model;
        int year;
};

// Create MyClass class:
class MyClass {
    public:
        // Inside example:
        void insideMethod() {
            cout << "Hello, from inside method\n";
        }
        // Outside example:
        void outsideMethod();
};

// Method definition outside MyClass:
void MyClass::outsideMethod() {
    cout << "Hello, from outside method\n";
}

// Create Speed class:
class Speed {
    public:
        int speed(int maxSpeed);
};

// Method definition outside Speed class:
int Speed::speed(int speed) {
    return speed;
}

// Create Constructor class:
class CarConstructor {
    public:
        string brand;
        string model;
        int year;
        
        // Constructor with parameters:
        CarConstructor(string x, string y, int z) {
            brand = x;
            model = y;
            year = z;
        }
};

// Create Age class:
class Age {
    public:
        // Older than 18 years old:
        void oldEnough() {
            cout << "You may apply for your drivers license\n";
        }

        // Younger than 18 years old:
        void tooYoung() {
            cout << "You may not enter a nightclub...\n";
        }
};

// Create UserInout class:
class UserInput {
    public:        
        // Get user name:
        void userInput() {
            cout << "Enter your full name (press $ to complete): ";
            cin.getline (fullname, MAX_NAME_LENGTH, '$'); // $ is default delimiter

            // Convert character array into string:
            int a_size = sizeof(fullname);
            nameString = convertToString(fullname, a_size);
        }

        // Convert char[] to string to use as string outside initial method:
        string convertToString(char* a, int size) {
            int i;
            string s = "";
            for (i = 0; i < size; i++) {
                s = s + a[i];
            }
            return s;
        }

        // Get user occupation:
        void userOccupation() {
            cout << "Hi " + nameString + ", please enter your occupation (press $ to complete): ";
            cin.getline (occupation, MAX_OCCUPATION_LENGTH, '$');
            cout << "Your occupation is: " << occupation << endl;
        }

        // Get user age:
        void userAge() {
            // New Age object:
            Age ageObj;

            cout << "Enter your age: ";
            cin >> age;

            // Call Age class method according to age:
            (age < 18) ? ageObj.tooYoung() : ageObj.oldEnough();
        }
};

// Main entry point of program:
int main() {
    // Random console output:
    cout << hello;

    // New Car object:
    Car carObj;
    carObj.brand = "Nissan";
    carObj.model = "GTR R35";
    carObj.year = 2016;

    // Print above object values:
    cout << carObj.brand << " " << carObj.model << " " << carObj.year << "\n";

    // New MyClass object:
    MyClass myObj;
    myObj.insideMethod();
    myObj.outsideMethod();

    // New Speed object:
    Speed getSpeed;
    cout << "Max speed: " << getSpeed.speed(200) << "km/h\n";

    // New CarConstructor object:
    CarConstructor carConstructorObj("Ford", "Mustang", 1969);

    // Print above object values:
    cout << carConstructorObj.brand << " " << carConstructorObj.model << " " << carConstructorObj.year << "\n";

    // New UserInput object:
    UserInput user;
    user.userInput();
    user.userOccupation();
    user.userAge();

    // Current time:
    auto start = std::chrono::system_clock::now();
    auto legacyStart = std::chrono::system_clock::to_time_t(start);
    std::cout << "The current time is: " <<  std::ctime(&legacyStart) << '\n';

    return 0;
}