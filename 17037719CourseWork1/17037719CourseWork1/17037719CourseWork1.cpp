//Joshua Morgan - 17037719 - Coursework 1

#include <iostream> //uses the IO stream Library 


using namespace std;


class Node
{
public:
	Node(int value, Node* nextptr = NULL, Node* prevptr = NULL, int currentpriority = 0)
	{
	Node::value = value; //This is the value
	next = nextptr; // this declares next as next pointer 
	prev = prevptr; //Declares prev as previous pointer 
	priority = currentpriority; //this declares current priority as priority
}
	int getVal(void) { //Gets the value of the node
		return value;
	}
	Node* getNext(void) { //this gets the next node
		return next;
	}
	Node* getPrev(void) { //gets the previous node 
		return prev;
	}
	void setVal(int value) { //this sets the value of value
		this->value = value;
	}
	void setPrev(Node* prevptr) { //this will set the pointer to the node in the previous position 
		prev = prevptr;
	}
	void setNext(Node* nextptr) { //this will set the pointer to the next node 
		next = nextptr;
	}
	int getPriority(void) { //Gets whatever value the priority the node 
		return priority;
	}
	void setPriority(int priority) { //sets the priority of the node
		Node::priority = priority;
	}
private:
	Node* next;
	Node* prev;
	int priority;
	int value;
};

class Stack
{
public:
	Stack(void) { top = nullptr; } //this is the constructer for the stack 
	~Stack(void) { while (top != nullptr) Pop();  } //this is the destructor for the stack
	void Push(int value) { 
		Node* tmp = new Node(value, top); //this is creating a new node
		top = tmp; // this sets the top of the stack as a temp
	}
	Node* NodePop(void) { 
		Node* tmp = top;
		if (top != nullptr) //if the top is not equal to null it will change the top to the next node
		{
			top = top->getNext(); //this gets the next node from the top 
		}
		return tmp;
	}

	int Pop(void) { // This is taking the value
		int ret = 0; 
		if (top != nullptr) {	
			Node* tmp = NodePop(); //this calls the NodePop function
			ret = tmp->getVal(); // this calls the get value method for the temp node 
			delete tmp; //deletes the temporary node
		}
		else throw "Stack is Empty"; //will throw this message when there is nothing left in the stack 
		return ret; //this returns the ret value
	}
private:
	Node* top;
};

class Queue
{
protected:
	Node* back;
	Node* front;

public:
	Queue(void) {
		front = back = NULL; //This constructor is setting up the que so that both back and front equal null
	}
	~Queue(void) { 
		while (front != NULL) { delete NodeDequeue(); } //This is moving the pointer back and deleting the front 
	}
	void Enqueue(int i, int priority = 0) { //adding an item to a queue 
		Node* tmp = new Node(i, back); //this is creating a new node
		back = tmp;
		if (front == NULL) front = back; //if the front of the que is empty then the back value will be checked 
		else
		{
			tmp = back->getNext(); // else the temp will equal the next node from back
			tmp->setPrev(back);
		}
	}

	int Dequeue(void) { //taking an item from a que 
		Node* tmp = NodeDequeue(); //this sets a temporary node as node dequeue
		int ret = 0;
		if (tmp != nullptr) //if the temporary node is not equal to null pointer then ..
		{
			ret = tmp->getVal(); //this will get the value for the temporary node
		}
		else
		{
			throw "Queue Empty"; //will show a message saying the Queue is empty
		}
		if (front == nullptr) back = front;
		delete tmp; //deletes the temp node 
		return ret; //returns the value 
	}

private:
	virtual Node* NodeDequeue(void) { //This is creating a  
		Node* tmp = front; //this will create a temporary node and put it at the front of the que
		if (front != nullptr) //if the front is not equal to null pointer then front will get previous. 
		{
			front = front->getPrev();
			if (front != nullptr) front->setNext(nullptr); //if the front is not equal to null pointer then set the  front as the next node as null pointer 
		}
		return tmp; //return the temp value
	}
};

class Scheduler : public Queue
{
private:
	Node* NodeDequeue(void) {

	}
};



