#include "pch.h"

class Soundex {
public:
	std::string encode(const std::string& word) const {
		return "";
	}
};

#include "gmock/gmock.h" 

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
	Soundex soundex;

	auto encoded = soundex.encode("A");
}