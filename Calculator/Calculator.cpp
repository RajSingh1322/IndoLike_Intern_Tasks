#include <iostream>
using namespace std;

class Calculator {
public:
    void showMenu() {
        cout << "\nSimple Calculator" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
    }

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
};

int main() {
    Calculator calc;
    int choice;
    double num1, num2;

    do {
        calc.showMenu();
        cin >> choice;
        
        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        }
        
        switch (choice) {
            case 1:
                cout << "Result: " << calc.add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << calc.subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << calc.multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << calc.divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Exiting calculator. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}
