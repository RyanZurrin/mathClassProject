#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors
// prgrammer:   Ryan Zurrin
#ifndef INPUT_LIST_H
#define INPUT_LIST_H
// A class template for holding a linked list.

#include "Calculator.h"
using namespace std;


template <class T>
class Input_List : public Calculator
{
	// Declare a structure for the list
	struct ListNode
	{
		T value;                // The value in this node
		struct ListNode* next;  // To point to the next node
	};
	ListNode* head;          // List head pointer

public:
	Input_List()  // Constructor
	{
		head = nullptr;
	}
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	~Input_List();
	void displayList() const;
 };
 /*_________________________________________________________________________
appendNode appends a node containing the value pased into newValue, to the
end of the list.                                                       */
	template <class T>
	void Input_List<T>::appendNode(T newValue)
	{
		ListNode* newNode;  // To point to a new node
		ListNode* nodePtr;  // To move through the list

		// Allocate a new node and store newValue there.
		newNode = new ListNode;
		newNode->value = newValue;
		newNode->next = nullptr;

		// If there are no nodes in the list
		// make newNode the first node.
		if (!head)
			head = newNode;
		else  // Otherwise, insert newNode at end.
		{
			// Initialize nodePtr to head of list.
			nodePtr = head;

			// Find the last node in the list.
			while (nodePtr->next)
				nodePtr = nodePtr->next;

			// Insert newNode as the last node.
			nodePtr->next = newNode;
		}
	}
	/*_________________________________________________________________________
	displayList shows the value stored in each node of the linked list pointed
	to by head.                                                             */
	template <class T>
	void Input_List<T>::displayList() const
	{
		ListNode* nodePtr;  // To move through the list

		// Position nodePtr at the head of the list.
		nodePtr = head;

		// While nodePtr points to a node, traverse
		// the list.
		while (nodePtr!= nullptr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	/*_________________________________________________________________________
	 The insertNode function inserts a node with newValue copied to its value
	 member.                                                                */
	template <class T>
	void Input_List<T>::insertNode(T newValue)
	{
		// Allocate a new node and store newValue there.
		ListNode* newNode = new ListNode;
		newNode->value    = newValue;
		// If there are no nodes in the list
		// make newNode the first node
		if (!head)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else  // Otherwise, insert newNode
		{
			// Position nodePtr at the head of list.
			ListNode* nodePtr = head;
			// Initialize previousNode to nullptr.
			ListNode* previousNode = nullptr;
			// Skip all nodes whose value is less than newValue.
			while (nodePtr != nullptr && nodePtr->value < newValue)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}
			// If the new node is to be the 1st in the list,
			// insert it before all other nodes.
			if (previousNode == nullptr)
			{
				head = newNode;
				newNode->next = nodePtr;
			}
			else  // Otherwise insert after the previous node.
			{
				previousNode->next = newNode;
				newNode->next = nodePtr;
			}
		}
	}
	template <class T>
	void Input_List<T>::deleteNode(T searchValue)
	{
		ListNode* nodePtr;       // To traverse the list

		// If the list is empty, do nothing.
		if (!head)
			return;

		// Determine if the first node is the one.
		if (head->value == searchValue)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			ListNode * previousNode;
			// Initialize nodePtr to head of list
			nodePtr = head;

			// Skip all nodes whose value member is
			// not equal to num.
			while (nodePtr != nullptr && nodePtr->value != searchValue)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			// If nodePtr is not at the end of the list,
			// link the previous node to the node after
			// nodePtr, then delete nodePtr.
			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}
	template <class T>
	Input_List<T>::~Input_List()
	{
		// Position nodePtr at the head of the list.
		ListNode* nodePtr = head;

		// While nodePtr is not at the end of the list...
		while (nodePtr != nullptr)
		{
			// Save a pointer to the next node.
			ListNode* nextNode = nodePtr->next;

			// Delete the current node.
			delete nodePtr;

			// Position nodePtr at the next node.
			nodePtr = nextNode;
		}


};



#endif
