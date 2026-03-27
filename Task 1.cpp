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
class mystack : public AbstractStack<T> {
private:
    T* arr;
    int maxsize;
    int topindex;

public:
    mystack(int size) {
        maxsize = size;
        arr = new T[maxsize];
        topindex = -1;
    }

    ~mystack() {
        delete[] arr;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++topindex] = value;
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
    cout << "Enter the maximum size of the stack: " << endl;
    cin >> size;

    mystack<int> s(size);

    int choice, val;

    do {
        cout << endl;
        cout << "--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Show Top" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Check Empty/Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: " << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: " << endl;
            cin >> val;
            s.push(val);
            break;

        case 2:
            val = s.pop();
            cout << "Popped: " << val << endl;
            break;

        case 3:
            cout << "Top element: " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << (s.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
            cout << (s.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}