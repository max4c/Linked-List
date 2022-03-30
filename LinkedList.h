#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList: public LinkedListInterface<T>
{
private:
	struct Node {
	 T data; // The data we are storing
	 Node* next; // A pointer to the next Node 
	 Node(const T& the_data, Node* next_val = NULL) :
	   data(the_data) {next = next_val;}
	};
	
	Node *head;
	int num_items;
public:

	LinkedList(void) {
		head = NULL;
		num_items = 0;
	};
	virtual ~LinkedList(void) {
		clear();
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertHead(T value)
	{
		cout <<"In insertHead" << endl;
		if(duplicateCheck(value)== 1){
			return;
		}
		else{
		Node *ptr = head; // create new pointer so head can move
		head = new Node(value); //new node
		head->next = ptr; //connector
		num_items++;
		cout <<"Leaving insertHead" << endl;
		}
	};

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertTail(T value)
	{
		cout << "In Tail" << endl;
		
		if(duplicateCheck(value)== 1){
			cout << "Leaving Tail" << endl;
			return;
		}
		else{
		Node *ptr = head;
		Node *tail = new Node(value);

		if(head == NULL){
			head = tail;
			tail->next = NULL;
			num_items++;
			cout << "Leaving Tail";
			return;
		}

			while (ptr->next)
			{
				ptr = ptr->next;
			}
		ptr->next = tail;
		num_items++;
		cout << "Leaving Tail" << endl;
		}
	};

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	virtual void insertAfter(T value, T insertionNode)
	{
		cout << "In insertAfter"<<endl;

		if(duplicateCheck(value)== 1){
			cout << "Leaving insertAfter"<<endl;
			return;
		}

		else{
	
			Node *newnode = new Node(value);

			for(Node *ptr =head; ptr != NULL; ptr = ptr->next) {
		  	if(ptr->data == insertionNode) { // Insert after this
		  	newnode->next = ptr->next;
		  	ptr->next = newnode;
		  	num_items++;
				cout << "Leaving insertAfter"<<endl;
		  	} 
			}
		}
	};

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	virtual void remove(T value)
	{
		cout << "In Remove" << endl;

		 if(notFoundCheck(value)== 1){ //check if value is not in list
			cout << "Leaving Remove"<<endl;
			return;
		}
		
		if(value == head->data) { //to remove head
			Node *curr = head;
			head = head->next;
			delete curr;
			num_items--;
			cout << "Leaving Remove" <<endl;
		}
		else{ //to remove any other element
			Node *ptr = head;
			while(ptr != NULL){
				if(ptr->next->data == value) {
					Node *curr = ptr->next;
					ptr->next = ptr->next->next;
					delete curr;
					num_items--;
					cout << "Leaving Remove" << endl;
					return;
				}
				else{
					ptr = ptr->next;
				}
			}
		}
	};

	/*
	clear

	Remove all nodes from the list.
	*/
	virtual void clear()
	{
		Node *curr = head;
		while(head != NULL) {
			curr = head;
			head = head ->next;
			delete curr;
		}
		head = NULL;
		num_items = 0;
	};

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	virtual T at(int index)
	{
		cout << "In at"<<endl;
		if(index >= num_items || index < 0 || num_items == 0) {
			cout << "Leaving at:Out of Range" << endl;
			throw std::out_of_range("At Error");
		} 
		else {
			Node *ptr = head;
			int temp = 0;
			for(Node *ptr =head; ptr != NULL; ptr = ptr->next) {
		  		if(temp == index) { 
						cout << "Leaving at:Found Element";
		  			return(ptr->data);
		  		}else {
		  			temp++;
		  		}
			}
		}
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	virtual int size()
	{
		return num_items;
	};

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	virtual string toString()
	{
		stringstream ss;
		for(Node *ptr =head; ptr != NULL; ptr = ptr->next){
			if(ptr->next != NULL)
			ss << ptr->data << " ";
			else{
				ss << ptr->data;
			}
		}
		return(ss.str());
	};

	// Used to Check for Duplicate Values
	bool duplicateCheck(T value) 
	{
		Node *ptr = head;
		while (ptr != NULL){
			if (ptr->data == value){
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	};

	bool notFoundCheck(T value)
	{
		Node *ptr = head;
		while (ptr != NULL){
			if (ptr->data == value){
				return false;
			}
			ptr = ptr->next;
		}
		return true;
	};

};
