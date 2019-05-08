#include "pch.h"

#include "Stack.h"

template <class T>
class MockAllocator : public IAllocator<T> {
public:
	MOCK_METHOD0_T(Create, T*());
	MOCK_METHOD1_T(Destroy, void(T* item));
};

class GivenAStack : public ::testing::Test {
public:
	Stack<int> stack;
};

TEST_F(GivenAStack, WhenPushingShouldAddElement) {	
	stack.Push(1);
	ASSERT_EQ(1, stack.Pop());
}

TEST_F(GivenAStack, WhenDestroyingStackShouldFreeMemory) {	
	MockAllocator<StackItem<int>> mockAllocator;	
	Stack<int> s = Stack<int>(mockAllocator);

	auto i1 = new StackItem<int>();
	auto i2 = new StackItem<int>();	

	EXPECT_CALL(mockAllocator, Create())
		.WillOnce(::testing::Return(i1))
		.WillOnce(::testing::Return(i2));		
	
	EXPECT_CALL(mockAllocator, Destroy(i1)).Times(1);
	EXPECT_CALL(mockAllocator, Destroy(i2)).Times(1);	

	s.Push(1);
	s.Push(2);	

	//GMock automatically verify expectations on destruction.
}

TEST_F(GivenAStack, WhenPoppingShouldDestroyStackItem) {
	MockAllocator<StackItem<int>> mockAllocator;
	Stack<int> s = Stack<int>(mockAllocator);

	auto i1 = new StackItem<int>();
	EXPECT_CALL(mockAllocator, Create())
		.WillOnce(::testing::Return(i1));
	EXPECT_CALL(mockAllocator, Destroy(i1)).Times(1);

	s.Push(1);
	s.Pop();
}

TEST_F(GivenAStack, WhenPushingMultipleElementsShouldReturnExpectedValue) {
	stack.Push(1);
	stack.Push(2);

	ASSERT_EQ(2, stack.Pop());
	ASSERT_EQ(1, stack.Pop());
}

TEST_F(GivenAStack, WhenPoppingEmptyStackShouldThrow) {
	EXPECT_THROW({ stack.Pop(); }, std::exception);
}