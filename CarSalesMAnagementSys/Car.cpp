#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#ifndef CAR_H
#define CAR_H
using namespace std;

class Car {
private:
    string carDataFile = "car_data.txt";
    vector<string> cars;

public:
    void input() {
        system("cls");

        int id;
        string make, model;
        int year;

         cout << "Enter car ID (1-1000): ";
        cin >> id;
        if (id < 1 || id > 1000) {
        cout << "Invalid ID. Please try again." << endl;
        return;
        }
        cout << "Enter car make: ";
        cin.ignore();
        getline(cin, make);

        // Validate make to contain only characters
        bool validMake = true;
        for (char c : make) {
        if (!isalpha(c)) {
            validMake = false;
            break;
        }
    }
    if (!validMake) {
        cout << "Invalid make. Please try again." << endl;
        return;
    }
        cout << "Enter car model: ";
        getline(cin, model);

        cout << "Enter car year: ";
        cin >> year;

            string carDetails = "ID: " + to_string(id) + " Make: " + make + "Model : " + model +  " Year: " + to_string(year);
        cars.push_back(carDetails);

        try {
            // Save the car data to the file
            ofstream outFile(carDataFile, ios::app);
            if (!outFile) {
                throw runtime_error("Failed to open car data file for writing.");
            }
            outFile << carDetails << endl;
            outFile.close();

            cout << "Car details have been added." << endl;
        } catch (const exception& e) {
            cout << "An error occurred: " << e.what() << endl;
        }
    }

    void update() {
        system("cls");

        string make, model;
        int year;

        cout << "Enter car make to update: ";
        cin.ignore();
        getline(cin, make);

        cout << "Enter car model to update: ";
        getline(cin, model);

        cout << "Enter car year to update: ";
        cin >> year;

        string carDetails = make + "," + model + "," + to_string(year);

        try {
            // Update the car details
            bool carUpdated = false;
            for (string& car : cars) {
                if (car.find(make) != string::npos && car.find(model) != string::npos) {
                    car = carDetails;
                    carUpdated = true;
                    break;
                }
            }

            if (!carUpdated) {
                throw runtime_error("Car not found for update.");
            }

            // Remove the existing car data file
            if (remove(carDataFile.c_str()) != 0) {
                throw runtime_error("Failed to remove car data file.");
            }

            // Save the updated car data to the file
            ofstream outFile(carDataFile);
            if (!outFile) {
                throw runtime_error("Failed to open car data file for writing.");
            }
            for (const string& car : cars) {
                outFile << car << endl;
            }
            outFile.close();

            cout << "Car details have been updated." << endl;
        } catch (const exception& e) {
            cout << "An error occurred: " << e.what() << endl;
        }
    }

    void removeCar() {
        system("cls");

        int id;

        cout << "Enter car ID to remove: ";
        cin >> id;

        try {
            // Remove the car details
            bool carRemoved = false;
            for (auto it = cars.begin(); it != cars.end(); ) {
                string carIdStr = it->substr(0, it->find(','));
                int carId = stoi(carIdStr);
                if (carId == id) {
                    it = cars.erase(it);
                    carRemoved = true;
                } else {
                    ++it;
                }
            }

            if (!carRemoved) {
                throw runtime_error("Car not found for removal.");
            }

            // Remove the existing car data file
            if (remove(carDataFile.c_str()) != 0) {
                throw runtime_error("Failed to remove car data file.");
            }

            // Save the updated car data to the file
            ofstream outFile(carDataFile);
            if (!outFile) {
                throw runtime_error("Failed to open car data file for writing.");
            }
            for (const string& car : cars) {
                outFile << car << endl;
            }
            outFile.close();

            cout << "Car has been removed." << endl;
        } catch (const exception& e) {
            cout << "An error occurred: " << e.what() << endl;
        }
    }

    void searchCarById() {
        system("cls");

        int id;

        cout << "Enter car ID to search: ";
        cin >> id;

        try {
            bool carFound = false;
            for (const string& car : cars) {
                string carIdStr = car.substr(0, car.find(','));
                int carId = stoi(carIdStr);
                if (carId == id) {
                    carFound = true;
                    cout << car << endl;
                    break;
                }
            }

            if (!carFound) {
                throw runtime_error("Car not found.");
            }
        } catch (const exception& e) {
            cout << "An error occurred: " << e.what() << endl;
        }
    }

void viewAll() {
    system("cls");

    try {
        ifstream inFile(carDataFile);
        if (!inFile) {
            throw runtime_error("Failed to open car data file for reading.");
        }

        string line;
        while (getline(inFile, line)) {
            // Parse car details
            size_t idPos = line.find(" ") + 4;
            size_t namePos = line.find(" ") + 6;
            size_t makePos = line.find(" ") + 6;
            size_t yearPos = line.find(" ") + 6;

            string carId = line.substr(idPos, namePos - idPos);
            string carName = line.substr(namePos + 5, makePos - namePos - 5);
            string carMake = line.substr(makePos, yearPos - makePos - 6);
            string carYear = line.substr(yearPos);

            // Display car details
            cout << "ID: " << carId << " Name: " << carName << " Make: " << carMake << " Year: " << carYear << endl;
        }

        inFile.close();
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
}
};
#endif // CAR_H