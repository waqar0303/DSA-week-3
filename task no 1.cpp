#include<iostream>
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
	T* array;
	int capacity;
	int topindex;


public:
	mystack(int size = 100)
	{
		capacity = size;
		array = new T[capacity];
		topindex = -1;
	}
	
	void push(T value)override
	{
		if (isFull())
		{
			cout << "Stack is full." << endl;
			return;
		}
		array[++topindex] = value;
	}

	T pop()override
	{
		if (isEmpty())
		{
			cout << "Stack is empty." << endl;

	    }
		return array[topindex--];

	}
	T top()const override
	{
		if (isEmpty())
		{
			cout << "stack is empty." << endl;

		}
		return array[topindex];
	}

	bool isEmpty()const override
	{
		return topindex == -1;
	}
	bool isFull()const override
	{
		return topindex == capacity - 1;
	}

	void display()const
	{
		if (isEmpty())
		{
			cout << "stack is empty." << endl;
		}
		cout << "Stack Element : ";
		for (int i = topindex; i >= 0; i--)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	~mystack()
	{
		delete[] array;
	}
};
int main()
{
	mystack <int> s(5);

	
	s.push(10);
	s.push(20);
	s.push(30);

	s.display();

	return 0;
	
}