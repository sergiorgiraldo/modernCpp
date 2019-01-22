/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef HttpFactory_h
#define HttpFactory_h

#include <memory>
#include "Http.h"

class HttpFactory {
public:
   HttpFactory();
   std::shared_ptr<Http> get();
   void setInstance(std::shared_ptr<Http>);
   void reset();

private:
   std::shared_ptr<Http> instance;
};
#endif
