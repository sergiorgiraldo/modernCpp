/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Soundex_h
#define Soundex_h

#include <string>

class Soundex
{
public:
   std::string encode(const std::string& word) const {
      return zeroPad(head(word) + encodedDigits(word));
   }
   
private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }

   std::string encodedDigits(const std::string& word) const {
      if (word.length() > 1) return "1";
      return "";
   }

   std::string zeroPad(const std::string& word) const {
   // ...
      auto zerosNeeded = 4 - word.length();
      return word + std::string(zerosNeeded, '0');
   }
};
#endif
