#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char text[100] = "";

    char undo[100][100];        
    char redo[100][100]; 

    int undoTop = -1;
    int redoTop = -1;

    int choice;
    char input[100];

    do {
        cout << endl;
        cout << "1. Type Text" << endl;
        cout << "2. Delete Last Character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display Text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: " << endl;

        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter text: " << endl;
            cin >> input;
            strcpy(undo[++undoTop], text);
            strcat(text, input);
            redoTop = -1;

            break;
        case 2:
            if (strlen(text) == 0) {
                cout << "Nothing to delete" << endl;
                break;
            }
            strcpy(undo[++undoTop], text);
            text[strlen(text) - 1] = '\0';
            redoTop = -1;

            break;

        case 3:
            if (undoTop == -1) {
                cout << "Nothing to undo" << endl;
                break;
            }

            strcpy(redo[++redoTop], text);
            strcpy(text, undo[undoTop--]);

            break;

        case 4:
            if (redoTop == -1) {
                cout << "Nothing to redo" << endl;
                break;
            }

            strcpy(undo[++undoTop], text);
            strcpy(text, redo[redoTop--]);

            break;

        case 5:
            cout << "Current Text: " << text << endl;
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