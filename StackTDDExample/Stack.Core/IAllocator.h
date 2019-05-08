#pragma once

template <class T>
class IAllocator {
public:
	virtual ~IAllocator() = default;
	virtual T* Create() = 0;
	virtual void Destroy(T* item) = 0;
};
