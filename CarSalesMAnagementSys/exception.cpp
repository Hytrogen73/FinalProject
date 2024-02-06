#include <iostream>
#include <exception>
#include <string>

using namespace std;

class Exception : public exception {
private:
    string errorMessage;

public:
    Exception(const string& message) : errorMessage(message) {}

    const char* what() const throw() {
        return errorMessage.c_str();
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

int main() {
    try {
        int id = get_id();
        // Code that may throw an exception
        throw Exception("An error occurred!");
    } catch (const Exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}