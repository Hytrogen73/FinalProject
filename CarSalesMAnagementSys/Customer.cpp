#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>
using namespace std;
bool isInteger(const string& input) {
    if (input.empty() || ((!isdigit(input[0])) && (input[0] != '-') && (input[0] != '+')))
        return false;

    char* p;
    strtol(input.c_str(), &p, 10);

    return (*p == 0);
}

class Customer {
private:
    string name;
    double id;
    string birthdate;
    string customerDataFile = "customer_data.txt";

public:
    Customer() {
        this->name = "Unknown";
        this->id = 0;
        this->birthdate = "Unknown";
    }

    Customer(string name, double id, string birthdate) {
        this->name = name;
        this->id = id;
        this->birthdate = birthdate;
    }

   

    void input() {
        system("cls");
        cout << "Enter ID: ";
        cin >> id; 
        if (id < 1 || id > 1000) {
        cout << "Invalid ID. Please try again." << endl;
        return;
    }
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
         bool validName = true;
    for (char c : name) {
        if (!isalpha(c)) {
            validName = false;
            break;
        }
    }
    if (!validName) {
        cout << "Invalid name. Please try again." << endl;
        return;
    }

        cout << "Enter date : ";
        string day;
        cin>>day;
        cout << "Enter Month (1,2,3,..,12): ";
        int mm;
        cin >>mm;
        cout << "Enter Year : ";
        int year;
        cin>>year;
     
     birthdate = day + "/" + to_string(mm) + "/" + to_string(year);
    cin.ignore();
        ofstream customerFile(customerDataFile, ios::app);
        if (customerFile.is_open()) {
            customerFile << "ID: " << id << " Name: " << name << " Birthdate: " << birthdate << endl;
            customerFile.close();
            cout << "Successful create customer in the data." << endl;
        } else {
            cout << "Error opening customer data file." << endl;
        }
    }

    void update() {
        system("cls");
        string new_name, new_birthdate;
        double new_id;

        cout << "Enter updated name: ";
        cin.ignore();
        getline(cin, new_name);
        cout << "Enter updated ID: ";
        cin >> new_id;
        cout << "Enter updated Birthdate (dd/mm/yyyy): ";
        cin >> new_birthdate;
        cin.ignore();

        ifstream customerFile(customerDataFile);
        ofstream tempFile("temp_customer_data.txt", ios::app);
        if (customerFile.is_open() && tempFile.is_open()) {
            string line;
            while (getline(customerFile, line)) {
                if (line.find(to_string(id)) != string::npos) {
                    tempFile << "ID: " << new_id << " Name: " << new_name << " Birthdate: " << new_birthdate << endl;
                } else {
                    tempFile << line << endl;
                }
            }
            customerFile.close();
            tempFile.close();

            remove(customerDataFile.c_str());
            rename("temp_customer_data.txt", customerDataFile.c_str());

            cout << "Successful update customer in the data." << endl;
        } else {
            cout << "Error opening customer data file." << endl;
        }
    }

void removecustomer() {
    system("cls");
   
    cout << "Enter the ID of the customer to remove: ";
    cin >> id;

    ifstream inputFile("customer_data.txt"); // Open the file for reading
    ofstream outputFile("temp.txt"); // Open a temporary file for writing

    string line;
    bool customerFound = false;

    // Read the input file line by line
    while (getline(inputFile, line)) {
        // Extract the customer ID from the line
        int lineid = stoi(line.substr(0, line.find(',')));

        // Check if the line's customer ID matches the provided ID
        if (lineid == id) {
            customerFound = true;
            continue; // Skip writing this line to the temporary file
        }

        // Write the line to the temporary file
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    if (customerFound) {
        cout << "Customer found." << endl;
        cout << "Are you sure you want to remove this customer? (Y/N): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y') {
            // Delete the original file
            remove("customer_data.txt");

            // Rename the temporary file to the original file name
            rename("temp.txt", "customer_data.txt");

            cout << "Customer removed successfully." << endl;
        } else {
            cout << "Removal canceled." << endl;
        }
    } else {
        cout << "Customer not found." << endl;
    }
}

    void viewAll() {
        system("cls");
        ifstream customerFile(customerDataFile);
        if (customerFile.is_open()) {
            string line;
            while (getline(customerFile, line)) {
                cout << line << endl;
            }
            customerFile.close();
        } else {
            cout << "Error opening customer data file." << endl;
        }
    }

    static bool compareByName(const Customer& customer1, const Customer& customer2) {
        return customer1.name < customer2.name;
    }

    static bool compareById(const Customer& customer1, const Customer& customer2) {
        return customer1.id < customer2.id;
    }

    void sortCustomersByName(vector<Customer>& customers) {
        sort(customers.begin(), customers.end(), compareByName);
    }

    void sortCustomersById(vector<Customer>& customers) {
        sort(customers.begin(), customers.end(), compareById);
    }
};