#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
private:
	T* arr;
	int top;
	int size;
	void resize()
{
    int newSize = size * 2;  
    T* newArr = new T[newSize];  

    for (int i = 0; i <= top; i++)
    {
        newArr[i] = arr[i];  
    }

    delete[] arr;  
    arr = newArr;  
    size = newSize;  
}

public:
	Stack(int stackSize)
	{
		size = stackSize;
		arr = new T[size];
		top = -1; // stack is initially empty
	}

	~Stack()
	{
		delete[] arr;
	}

	bool isEmpty()
	{
		return top == -1;
	}

	bool isFull()
	{
		return top == size - 1;
	}

	void push(int value)
	{
		if (isFull())
		{
			cout << "Error: Stack is full\n";
			return;
		}
		top++;
		arr[top] = value;
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Error: Stack is empty\n";
			return -1; // return -1 to indicate an error
		}
		int popped = arr[top];
		top--;
		return popped;
	}

	int peek()
	{
		if (isEmpty())
		{
			cout << "Error: Stack is empty\n";
			return -1; // return -1 to indicate an error
		}
		return arr[top];
	}

	void clear()
	{
		top = -1;
	}

	Stack clone() const
	{
		Stack newStack(size);
		newStack.top = top;
		for (int i = 0; i <= top; i++)
		{
			newStack.arr[i] = arr[i];
		}
		return newStack;
	}

	int get_index(int item)
	{
		for (int i = 0; i <= top; i++)
		{
			if (arr[i] == item)
				return i;
		}
		return -1;
	}

	void reverseString(string& name)
    {
        Stack<char> charStack(name.length());
        for (char ch : name)
        {
            charStack.push(ch);
        }

        for (int i = 0; i < name.length(); i++)
        {
            name[i] = charStack.pop();
        }
    }

	
	
	bool balancingPrantheses(string s)
	{
    	Stack<char> parenthesesStack(s.length());  
    	for (char ch : s)
    	{
        	if (ch == '(' || ch == '[' || ch == '{')
        	{
            	parenthesesStack.push(ch);  
        	}
        	else if (ch == ')' || ch == ']' || ch == '}')
        	{
            	if (parenthesesStack.isEmpty())
            	{
                	return false;  
            	}
            	char top = parenthesesStack.pop();  
            	if ((ch == ')' && top != '(') ||
                	(ch == ']' && top != '[') ||
                	(ch == '}' && top != '{'))
            	{
                	return false;  
            	}
        	}
    	}
    	return parenthesesStack.isEmpty();  
	}


	void NextGreatorElement()
	{
    	Stack<T> tempStack(size);  
    	while (!isEmpty()) 
    	{
        	T current = pop();  
        	while (!tempStack.isEmpty() && tempStack.peek() <= current) 
        	{
            	tempStack.pop();  
        	}
        	tempStack.push(current);  
    	}
    	while (!tempStack.isEmpty()) 
    	{
        	cout << tempStack.pop() << " has no greater element" << endl;
    	}
	}

	void removingConsecutiveDuplicates()
	{
    	Stack<T> tempStack(size);  
    	while (!isEmpty()) 
    	{
        	T current = pop();  
        	if (tempStack.isEmpty() || current != tempStack.peek()) 
        	{
            	tempStack.push(current);  
        	}
    	}

    	while (!tempStack.isEmpty()) 
    	{
        	push(tempStack.pop());  
    	}
	}

}



	


};
