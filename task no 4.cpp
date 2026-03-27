#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    string arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(string value)
    {
        if (top < 99)
        {
            arr[++top] = value;
        }
    }

    string pop()
    {
        if (top >= 0)
        {
            return arr[top--];
        }
        return "";
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void clear()
    {
        top = -1;
    }
};

int main()
{
    Stack undoStack;
    Stack redoStack;
    string text = "";
    int choice;
    char ch;

    do
    {
        cout << "\nCurrent Text: " << text << endl;
        cout << "1. Type Character\n2. Delete Character\n3. Undo\n4. Redo\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter character: ";
            cin >> ch;
            undoStack.push(text);
            text += ch;
            redoStack.clear();
            break;

        case 2:
            if (text != "")
            {
                undoStack.push(text);
                text.pop_back();
                redoStack.clear();
            }
            else
            {
                cout << "Nothing to delete\n";
            }
            break;

        case 3:
            if (!undoStack.isEmpty())
            {
                redoStack.push(text);
                text = undoStack.pop();
            }
            else
            {
                cout << "Nothing to undo\n";
            }
            break;

        case 4:
            if (!redoStack.isEmpty())
            {
                undoStack.push(text);
                text = redoStack.pop();
            }
            else
            {
                cout << "Nothing to redo\n";
            }
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}