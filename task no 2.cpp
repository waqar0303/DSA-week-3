#include <iostream>
#include<string>
using namespace std;

template <typename T>
class AbstractStack
{
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class mystack : public AbstractStack<T>
{
private:
    T* arr;
    T* minArr;  
    int capacity;
    int topIndex;
    int minTop;

public:
    mystack(int size = 100)
    {
        capacity = size;
        arr = new T[capacity];
        minArr = new T[capacity];
        topIndex = -1;
        minTop = -1;
    }

    ~mystack()
    {
        delete[] arr;
        delete[] minArr;
    }

    void push(T value) override
    {
        if (isFull())
        {
            cout << "Stack is full." << endl;
            return;
        }

        arr[++topIndex] = value;

     
        if (minTop == -1 || value <= minArr[minTop])
        {
            minArr[++minTop] = value;
        }
    }

    T pop() override
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            exit(1);
        }

        T popped = arr[topIndex--];

        if (popped == minArr[minTop])
        {
            minTop--;
        }

        return popped;
    }

    T top() const override
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            exit(1);
        }
        return arr[topIndex];
    }

    bool isEmpty() const override
    {
        return topIndex == -1;
    }

    bool isFull() const override
    {
        return topIndex == capacity - 1;
    }

    
    T getmin() const
    {
        if (minTop == -1)
        {
            cout << "Stack is empty." << endl;
            exit(1);
        }
        return minArr[minTop];
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack: ";
        for (int i = topIndex; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    mystack<int> s(10);
    int choice;
    int value;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. isFull\n6. Display\n7. Get Min\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Empty." << endl;
            else
                cout << "Not Empty." << endl;
            break;
        case 5:
            if (s.isFull())
                cout << "Full." << endl;
            else
                cout << "Not Full. << endl";
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum: " << s.getmin() << endl;
            break;

        case 8:
            cout << "Exiting." << endl;
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}

