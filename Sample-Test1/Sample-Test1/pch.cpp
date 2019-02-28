//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include "gmock/gmock.h"

int main(int argc, char** argv) {
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
