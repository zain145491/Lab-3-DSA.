#include <iostream>
using namespace std;
template<typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};
template<typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    T* minArr;
    int topindex;
    int maxsize;

public:
    myStack(int size) {
        maxsize = size;
        arr = new T[maxsize];
        minArr = new T[maxsize];
        topindex = -1;
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        topindex++;
        arr[topindex] = value;
        if (topindex == 0)
            minArr[topindex] = value;
        else
            minArr[topindex] = (value < minArr[topindex - 1]) ? value : minArr[topindex - 1];
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return T();
        }
        return arr[topindex--];
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return arr[topindex];
    }

    bool isEmpty() const override {
        return topindex == -1;
    }

    bool isFull() const override {
        return topindex == maxsize - 1;
    }
    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return minArr[topindex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements (Top to Bottom):" << endl;
        for (int i = topindex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};
int main() {
    int size;
    cout << "Enter stack size: " << endl;
    cin >> size;

    myStack<int> s(size);
    int choice, val;

    do {
        cout << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if empty" << endl;
        cout << "5. Check if full" << endl;
        cout << "6. Display stack" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: " << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: " << endl;
            cin >> val;
            s.push(val);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Empty" : "Not Empty") << endl;
            break;

        case 5:
            cout << (s.isFull() ? "Full" : "Not Full") << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum Element: " << s.getMin() << endl;
            break;

        case 8:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 8);

    return 0;
}