//This program reads a file and pushes the characters
//into a stack, then pops the characters from that stack
//into another file. The resulting file is the reverse
//of the first file.
//Kodi Lein
//SDEV340-81
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

//**DynStack Class**//
class DynStack
{
private:
	struct StackNode
	{
		char value;
		StackNode* next;
	};

	StackNode* top;

public:
	DynStack()		 //constructor
	{
		top = NULL;
	}
	void push(char); //push function template
	void pop(char&); //pop function template
	bool isEmpty() //isEmpty function
	{
		bool status = false;
		if (!top)
		{
			status = true;
		}
		return status;
	}
};

//**Push Function**//
void DynStack::push(char a)
{
	StackNode* newNode = NULL;
	newNode = new StackNode;
	newNode->value = a;

	if (isEmpty()) //start new stack 
	{
		top = newNode;
		newNode->next = NULL;
	}
	else //add to stack
	{
		newNode->next = top;
		top = newNode;
	}
}

//**Pop Function**//
void DynStack::pop(char& ch)
{
	StackNode* temp = NULL;
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else //pop value from top of stack
	{
		ch = top->value;
		temp = top->next;
		delete top;
		top = temp;

	}
}

//**MAIN**//
int main()
{
	string inputFile = "Input.txt"; //file with characters to be pushed into stack
	ifstream in(inputFile.c_str());

	DynStack stack;
	char ch; //characters from Input.txt 

	cout << "\n======= Input.txt =========== \n\n";

	if (in) //if there is an input file
	{
		while (in.get(ch)) //get characters from Input.txt
		{
			cout << ch;  //display file
			stack.push(ch); //push characters from Input.txt into stack
		}
		in.close(); //close Input.txt
	}
	else 
	{
		cout << "\nInput.txt not found. Create Input.txt in current folder";
	}

	string outputFile = "Output.txt"; //Output file where stack characters will be placed
	ofstream out(outputFile.c_str());
	char temp;

	while (!stack.isEmpty())
	{
		stack.pop(temp); //pop characters from stack
		out.put(temp); //put characters into Output.txt
	}
	out.close(); //close Output.txt

	cout << "\n\n======== Output.txt ==========\n\n";

	ifstream readOutputFile(outputFile.c_str());

	while (readOutputFile.get(ch)) //get characters from Output.txt
	{
		cout << ch; //display Output.txt
	}
	readOutputFile.close(); //close Output.txt
	cout << endl;

	return 0;
}