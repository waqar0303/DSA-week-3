#include <iostream>
#include <string>
using namespace std;

class myCarStack
{
private:
    string cars[8];
    int top;

public:
    myCarStack()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == 7;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void parkCar(string carNo)
    {
        if (isFull())
        {
            cout << "Parking Full!" << endl;
            return;
        }
        cars[++top] = carNo;
        cout << "Car Parked: " << carNo << endl;
    }

    void removeCar(string carNo)
    {
        if (isEmpty())
        {
            cout << "Parking Empty!" << endl;
            return;
        }

        myCarStack tempStack;
        bool found = false;

        while (!isEmpty())
        {
            string current = cars[top--];

            if (current == carNo)
            {
                cout << "Car Removed: " << carNo << endl;
                found = true;
                break;
            }
            else
            {
                tempStack.parkCar(current);
            }
        }

        if (!found)
        {
            cout << "Car Not Found!" << endl;
        }

        while (!tempStack.isEmpty())
        {
            parkCar(tempStack.cars[tempStack.top--]);
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No Cars Parked." << endl;
            return;
        }

        cout << "Cars in Parking (Top to Bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << cars[i] << " ";
        }
        cout << endl;
    }

    void totalCars()
    {
        cout << "Total Cars: " << top + 1 << endl;
    }

    void searchCar(string carNo)
    {
        for (int i = 0; i <= top; i++)
        {
            if (cars[i] == carNo)
            {
                cout << "Car Found!" << endl;
                return;
            }
        }
        cout << "Car Not Found!" << endl;
    }
};

int main()
{
    myCarStack parking;
    int choice;
    string carNo;

    do
    {
        cout << "\n1. Park Car\n2. Remove Car\n3. Display Cars\n4. Total Cars\n5. Search Car\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Car Number: ";
            cin >> carNo;
            parking.parkCar(carNo);
            break;

        case 2:
            cout << "Enter Car Number to Remove: ";
            cin >> carNo;
            parking.removeCar(carNo);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            parking.totalCars();
            break;

        case 5:
            cout << "Enter Car Number to Search: ";
            cin >> carNo;
            parking.searchCar(carNo);
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}