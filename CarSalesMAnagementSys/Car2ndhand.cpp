#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.cpp"

using namespace std;

class Car2ndHand : public Car {
public:
    void input()  {
        Car::input();
        cout << "Additional logic for second-hand cars" << endl;
        // Additional logic for second-hand cars
    }

    void update()  {
        Car::update();
        cout << "Additional logic for updating second-hand cars" << endl;
        // Additional logic for updating second-hand cars
    }

    void removeCar()  {
        Car::removeCar();
        cout << "Additional logic for removing second-hand cars" << endl;
        // Additional logic for removing second-hand cars
    }

    void viewAll()  {
        Car::viewAll();
        cout << "Additional logic for viewing all second-hand cars" << endl;
        // Additional logic for viewing all second-hand cars
    }
};

bool validate_id(int id) {
    if (id <= 0) {
        return false;
    }
    else {
        return true;
    }
}

int get_id() {
    int id;
    while (true) {
        cout << "Enter ID: ";
        cin >> id;
        if (!validate_id(id)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: invalid ID" << endl;
        }
        else {
            return id;
        }
    }
}
