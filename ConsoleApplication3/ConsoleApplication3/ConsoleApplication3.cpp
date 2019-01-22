// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct A {
	int i;
};

void foo(std::shared_ptr<A>, double d) {};

double bar_might_throw() { return 1.0; };

int main() {
	foo(std::shared_ptr<A>(new A{ 22 }),
		bar_might_throw());
}