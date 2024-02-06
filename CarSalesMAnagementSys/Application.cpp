#include <iostream>
#include <string>
#include "Car.cpp"
#include "Customer.cpp"
#include "Car2ndHand.cpp"

using namespace std;

bool validate_choice(int choice, int minChoice, int maxChoice) {
    if (choice < minChoice || choice > maxChoice) {
        return false;
    }
    else {
        return true;
    }
}

int get_choice(int minChoice, int maxChoice) {
    int choice;
    while (true) {
        cout << "Enter your choice (" << minChoice << "-" << maxChoice << "): ";
        cin >> choice;
        if (!validate_choice(choice, minChoice, maxChoice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: invalid choice" << endl;
        }
        else {
            return choice;
        }
    }
}

class Application {
private:
    Car car;
    Customer customer;
    Car2ndHand car2ndHand;

public:
    void run() {
        int choice;
        system("cls");
        do {
            cout << "1. Manage Cars" << endl;
            cout << "2. Manage Second-Hand Cars" << endl;
            cout << "3. Manage Customers" << endl;
            cout << "4. Exit" << endl;
            choice = get_choice(1, 4);

            switch (choice) {
                case 1: {
                    system("cls");
                    int carChoice;
                    do {
                        cout << "1. Add a car" << endl;
                        cout << "2. Update car" << endl;
                        cout << "3. Remove car" << endl;
                        cout << "4. Search car by ID" << endl;
                        cout << "5. View all cars" << endl;
                        cout << "6. Back" << endl;
                        carChoice = get_choice(1, 6);

                        switch (carChoice) {
                            case 1:
                                car.input();
                                break;
                            case 2:
                                car.update();
                                break;
                            case 3:
                                car.removeCar();
                                break;
                            case 4:
                                car.searchCarById();
                                break;
                            case 5:
                                car.viewAll();
                                break;
                            case 6:
                                cout << "Returning to the main menu..." << endl;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                        }
                    } while (carChoice != 6);
                }
                break;

                case 2: {
                    system("cls");
                    int car2ndHandChoice;
                    do {
                        cout << "1. Add Second-Hand Car" << endl;
                        cout << "2. Update Second-Hand Car" << endl;
                        cout << "3. Remove Second-Hand Car" << endl;
                        cout << "4. View All Second-Hand Cars" << endl;
                        cout << "5. Back" << endl;
                        car2ndHandChoice = get_choice(1, 5);

                        switch (car2ndHandChoice) {
                            case 1:
                                car2ndHand.input();
                                break;
                            case 2:
                                car2ndHand.update();
                                break;
                            case 3:
                                car2ndHand.removeCar();
                                break;
                            case 4:
                                car2ndHand.viewAll();
                                break;
                            case 5:
                                cout << "Returning to the main menu..." << endl;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                        }
                    } while (car2ndHandChoice != 5);
                }
                break;

                case 3: {
                    system("cls");
                    int customerChoice;
                    do {
                        cout << "1. Add Customer" << endl;
                        cout << "2. Update Customer" << endl;
                        cout << "3. Remove Customer" << endl;
                        cout << "4. View All Customers" << endl;
                        cout << "5. Back" << endl;
                        customerChoice = get_choice(1, 5);

                        switch (customerChoice) {
                            case 1:
                                customer.input();
                                break;
                            case 2:
                                customer.update();
                                break;
                            case 3:
                                customer.removecustomer();
                                break;
                            case 4:
                                customer.viewAll();
                                break;
                            case 5:
                                cout << "Returning to the main menu..." << endl;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                        }
                    } while (customerChoice != 5);
                }
                break;

                case 4:
                    system("cls");
                    cout << "Exiting the application. Goodbye!" << endl;
                    break;

                default:
                    system("cls");
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 4);
    }
};