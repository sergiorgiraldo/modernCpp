#pragma once

#include "IAllocator.h"

template <class T>
class HeapAllocator : public IAllocator<T> {
public:
	T* Create() override {
		return new T();
	}

	virtual void Destroy(T* item) {
		delete item;
	}
};
