#pragma once

#include <vector>
#include "StackItem.h"
#include "IAllocator.h"
#include "HeapAllocator.h"

template <class T>
class Stack {
private:
	StackItem<T>* top;	
	HeapAllocator<StackItem<T>> heapAllocator;
	IAllocator<StackItem<T>>& allocator;
public:
	Stack() : allocator(heapAllocator) {

	}

	Stack(IAllocator<StackItem<T>>& a) : allocator(a) {

	}

	~Stack() {
		StackItem<T>* curr = top;
		while (curr != nullptr) {
			StackItem<T>* toDelete = curr;
			curr = curr->Next;			
			allocator.Destroy(toDelete);
		}
	}

	void Push(T item) {
		if (top == nullptr) {
			top = allocator.Create();
			top->Item = item;
		}
		else {
			StackItem<T>* newItem = allocator.Create();
			newItem->Item = item;
			newItem->Next = top;
			top = newItem;
		}
	}

	T Pop() {			
		if (top == nullptr)
			throw std::exception("Empty stack!");

		T poppedItem = top->Item;
		StackItem<T>* itemToDelete = top;
		top = top->Next;
		allocator.Destroy(itemToDelete);
		return poppedItem;
	}
};