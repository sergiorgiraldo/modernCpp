#pragma once

template <class T>
class StackItem {
public:
	T Item;
	StackItem<T>* Next;
};
