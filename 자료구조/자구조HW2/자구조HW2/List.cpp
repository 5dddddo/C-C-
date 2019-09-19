#include "List.h"
#include <assert.h>
List::List()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}

void List::insert(const ListElementType & elem)
{
	// precondition: list is in order
	Link addedNode(new Node);
	assert(addedNode);
	addedNode->elem = elem;
	// Special case: if the existing list is empty, or if the new data
	// is less than the smallest item in the list, the new node is added
	// to the front of the list
	if (head == 0 || elem.getFrequency() >= head->elem.getFrequency()) {
		if (head == 0)
		{
			tail = addedNode;
			tail->next = 0;
		}
		addedNode->next = head;
		head = addedNode;
	}
	else {
		// find the pointer to the node that is the predecessor
		// to the new node in the in-order list
		Link pred(head);
		// assertion: pred->elem <= addedNode->elem
		while (pred->next != 0 && pred->next->elem.getFrequency() >= addedNode->elem.getFrequency())
			// loop invariant: pred->next != 0 && pred->next->elem <= elem
			pred = pred->next;
		// assertion 7-1: (pred->elem <= addedNode->elem) &&
		//    (addedNode->elem <= pred->next->elem || pred->next == 0)
		addedNode->next = pred->next;
		pred->next = addedNode;
		if (addedNode->next == 0)
			tail = addedNode;
		// assertion: pred->elem <= pred->next->elem &&
		//    (pred->next->elem <= pred->next->next->elem || pred->next->next == 0)
	}
	// postcondition: list is in order, with elem added in proper position
}

bool List::first(ListElementType & elem)
{
	// After calling first, current points to first item in list
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}

bool List::next(ListElementType & elem)
{
	// with proper use, current should always be nonzero
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}

bool List::last(ListElementType & elem)
{
	// After calling first, current points to first item in list
	if (tail == 0)
		return false;
	else {
		elem = tail->elem;
		current = tail;
		return true;
	}
}

bool List::find(ListElementType& elem, string newWord)
{
	current = head;
	while (current != 0)
	{
		if (current->elem.getSearchword().find(newWord) != string::npos)
		{
			elem = current->elem;
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::deleteNode(string deleteWord)
{
	ListElementType elem;
	Link currentPrev = head;
	if (find(elem, deleteWord))
	{
		while (currentPrev->next != current)
			currentPrev = currentPrev->next;
		currentPrev->next = current->next;
		delete current;
		return true;
	}
	else return false;
}

void List::AddSearch(ListElementType& elem)
{
	ListElementType tmp;
	Link currentPrev = head;
	current = head;
	while (current != 0)
	{
		if (current->elem.getSearchword() == elem.getSearchword())
		{
			current->elem.setFrequency(current->elem.getFrequency() + 1);
			while (currentPrev->next != current)
				currentPrev = currentPrev->next;
			if (current->elem.getFrequency() > currentPrev->elem.getFrequency())
			{
				tmp = current->elem;
				current->elem = currentPrev->elem;
				currentPrev->elem = tmp;
				return;
			}
		}
		current = current->next;
	}
	insert(elem);
}

void List::AddAll(List & addList)
{
	addList.current = addList.head;
	while (addList.current != 0)
	{
		insert(addList.current->elem);
		addList.current = addList.current->next;
	}
}
