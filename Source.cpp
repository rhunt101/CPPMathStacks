#include <iostream>
using namespace std;

//Ryan Hunt
//04-28-2025
//COP2222

/*	This program is an addition to the MathStack.cpp, which originally only had an add and subtract methods.
	The request was to add four more methods, with the capability to multiply, divide, add more than 2 integers,
	and subtract more than 2 integers. The method saves the integers pushed to the stack, and executes 
	the respective operators with the integers that are pushed to the list. After the list pops the sum and
	diffs back to the main method, and then deletes the contents, ready to have new integers brought in.*/

//Class for implementing the basic integer stack
class IntStack {
private:
	int* stackArray; // Pointer for dynamic array storage
	int stackSize;	 // Maximun size of the stack
	int top;		 // Index tracking the top element of the stack

public:
	// Constructor initializes stack with given size
	IntStack(int size) {
		stackArray = new int[size];
		stackSize = size;
		top = -1; // Stack is first empty
	}
	// Copy constructor for deep copying a stack
	IntStack(const IntStack& obj) {
		stackSize = obj.stackSize;
		stackArray = new int[stackSize];
		top = obj.top;
		for (int i = 0; i <= top; i++)
			stackArray[i] = obj.stackArray[i];
	}

	// Destroctor to clean up allocated memory
	~IntStack() {
		delete[] stackArray;
	}

	//Pushes a number onto the stack
	void push(int num) {
		if (IsFull()) {
			cout << "Stack is full.\n";
			return;
		}
		stackArray[++top] = num;
	}

	// Pops the top element off the stack and stores it in 'num'
	void pop(int& num) {
		if (isEmpty()) {
			cout << "Stack is empty.\n";
			return;
		}
		num = stackArray[top--];
	}

	//Checks if the stack is full
	bool IsFull() const {
		return top == stackSize - 1;
	}

	//Checks if the stack is empty
	bool isEmpty() const {
		return top == -1;
	}
};

// Class that extends IntStack to perform arithmetic operations
class MathStack : public IntStack {
public:
	// Constructor initializes MathStack with given size
	MathStack(int s) : IntStack(s) {}

	// Adds top two numbers, and stores sum back in stack
	void add() {
		int num, sum;
		pop(sum);
		pop(num);
		sum += num;
		push(sum);
	}

	// Subtracts second top two numbers from stack, stores result back in stack
	void sub() {
		int num, diff;
		pop(diff);
		pop(num);
		diff -= num;
		push(diff);
	}

	// Multiplies top 2 numbers, stores product back in stack
	void mult() {
		int num, sum;
		pop(sum);
		pop(num);
		sum *= num;
		push(sum);
	}
	
	// Divides top two numbers, checking for dilision by 0 before it stores product back in stack
	void div() {
		int num, quotient;
		pop(quotient);
		pop(num);
		if (quotient == 0) {
			cout << "Division by 0..." << endl;
			push(quotient);
			return;
		}
		quotient /= num;
		push(quotient);
	}

	// Adds all numbers in stack, stores total sum back in the stack
	void addAll() {
		int num, sum = 0;
		while (!isEmpty()) {
			pop(num);
			sum += num;
		}
		push(sum);
	}

	// Subtracts all numbers in stack, stores total sum back in the stack
	void subAll() {
		int num, diff;
		pop(diff);
		while (!isEmpty()) {
			pop(num);
			diff -= num;
		}
		push(diff);
	}
};

int main() {
	//Variable to catch the variables pushed back from the list after the methods.
	int catchVar;

	//Limit stack variables
	MathStack stack(5);

	//Addition integers
	cout << "Adding Stack:" << endl;
	cout << "Pushing 3...\n";
	stack.push(3);
	cout << "Pushing 6...\n";
	stack.push(6);

	//access add method
	stack.add();

	cout << "Sum equals -> ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	//Subtraction integers
	cout << "Subtracting Stack:" << endl;
	cout << "Pushing 7...\n";
	stack.push(7);
	cout << "Pushing 10...\n";
	stack.push(10);

	//access sub method
	stack.sub();

	cout << "Difference equals -> ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	//Multiplication integers
	cout << "Multiplication Stack:" << endl;
	cout << "Pushing 15...\n";
	stack.push(15);
	cout << "Pushing 4...\n";
	stack.push(4);

	//acces mult method
	stack.mult();

	cout << "Sum equals -> ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;
	
	//Division integers
	cout << "Division Stack:" << endl;
	cout << "Pushing 5...\n";
	stack.push(5);
	cout << "Pushing 100...\n";
	stack.push(100);

	//access div method
	stack.div();

	cout << "Sum equals -> ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	//Add all integers to push to the addAll method
	cout << "Adding all Stack:" << endl;
	cout << "Pushing 4...\n";
	stack.push(4);
	cout << "Pushing 7...\n";
	stack.push(7);
	cout << "Pushing 12...\n";
	stack.push(12);
	cout << "Pushing 3...\n";
	stack.push(3);

	//access addAll method
	stack.addAll();

	cout << "Sum of addition equals -> ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	//Subtract all integers to push to the subAll method
	cout << "Subtracting all Stack:" << endl;
	cout << "Pushing 4...\n";
	stack.push(4);
	cout << "Pushing 1...\n";
	stack.push(1);
	cout << "Pushing 20...\n";
	stack.push(20);
	cout << "Pushing 52...\n";
	stack.push(52);

	//access subAll method
	stack.subAll();

	cout << "Sum of subtraction equals -> ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;
};