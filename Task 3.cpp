#include <iostream>
using namespace std;

class CarStack {
private:
    string arr[8];
    int top;
public:
    CarStack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == 7;
    }
    void push(string car) {
        if (isFull()) {
            cout << "Parking Full!" << endl;
            return;
        }
        arr[++top] = car;
        cout << "Car Parked: " << car << endl;
    }
    string pop() {
        if (isEmpty()) {
            cout << "Parking Empty!" << endl;
            return "";
        }
        return arr[top--];
    }
     string peek() {
        if (isEmpty()) return "";
        return arr[top];
    }
    void display() {
        if (isEmpty()) {
            cout << "No cars parked" << endl;
            return;
        }
        cout << "Cars in parking:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
    int count() {
        return top + 1;
    }
    bool search(string car) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }
    void removeCar(string car) {
        CarStack temp;

        bool found = false;

        while (!isEmpty()) {
            string x = pop();
            if (x == car) {
                cout << "Car Removed: " << car << endl;
                found = true;
                break;
            }
            temp.push(x);
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        if (!found)
            cout << "Car not found!" << endl;
    }
};
int main() {
    CarStack parking;
    int choice;
    string car;

    do {
        cout << endl;
        cout << "1. Park Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. Display Cars" << endl;
        cout << "4. Total Cars" << endl;
        cout << "5. Search Car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: " << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: " << endl;
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "Enter car number to remove: " << endl;
            cin >> car;
            parking.removeCar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total Cars: " << parking.count() << endl;
            break;

        case 5:
            cout << "Enter car number: " << endl;
            cin >> car;
            if (parking.search(car))
                cout << "Car Found" << endl;
            else
                cout << "Car Not Found" << endl;
            break;

        case 6:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}