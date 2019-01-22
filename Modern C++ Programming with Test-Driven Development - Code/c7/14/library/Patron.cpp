#include "Patron.h"
#include "Holding.h"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

Patron::Patron(const string& name, int id) 
	: mName(name)
	, mId(id)
	, mBalance(0) 
{
}

Patron::Patron(const string& name, const string& cardNumber)
    : mName(name)
    , mBalance(0)
{
    string idPortion = cardNumber.substr(1);
    istringstream(idPortion) >> mId;
}

string Patron::CardNumber() const
{
    ostringstream text;
    text << "p" << mId;
    return text.str();
}

std::ostream& operator<<(std::ostream& stream, Patron& patron) 
{
	return stream << patron.Name() << " (" << patron.CardNumber() << ")";
}

string Patron::Name() const
{
	return mName;
}

int Patron::Id() const
{
	return mId;
}

int Patron::FineBalance() const
{
	return mBalance;
}

void Patron::ApplyFine(Book& book, unsigned int daysLate)
{
   switch (book.Type()) {
      case Book::TYPE_BOOK:
         AddFine(Book::BOOK_DAILY_FINE * daysLate); 
         break;
      case Book::TYPE_MOVIE:
         {
            int fine = 100 + Book::MOVIE_DAILY_FINE * daysLate;
            if (fine > 1000)
               fine = 1000;
            AddFine(fine);
         }
         break;
      case Book::TYPE_NEW_RELEASE:
         AddFine(Book::NEW_RELEASE_DAILY_FINE * daysLate);
         break;
   }
}

void Patron::AddFine(int amount) 
{
	mBalance += amount;
}

void Patron::Remit(int amount) 
{
	mBalance -= amount;
}

set<Holding> Patron::Holdings() const
{
	return mHoldings;
}

void Patron::Borrow(const Holding& holding)
{
	mHoldings.insert(holding);
}

void Patron::ReturnHolding(const Holding& holding)
{
	mHoldings.erase(holding);
}

bool Patron::operator==(const Patron& rhs) const
{
	return mId == rhs.mId;
}

bool Patron::operator!=(const Patron& rhs) const
{
	return !(*this == rhs);
}
