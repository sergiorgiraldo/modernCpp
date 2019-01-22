#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

#include <memory>

using namespace ::testing;
using namespace std;

class ARetweetCollection: public Test {
public:
   RetweetCollection collection;
};

MATCHER_P(HasSize, expected, "") { 
   return 
      arg.size() == expected && 
      arg.isEmpty() == (0 == expected); 
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
   ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
   ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero) {
   ASSERT_THAT(collection.size(), Eq(0u));

   ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNotEmptyWhenItsSizeIsNonZero) {
   collection.add(Tweet());
   ASSERT_THAT(collection.size(), Gt(0u));

   ASSERT_FALSE(collection.isEmpty());
}

class ARetweetCollectionWithOneTweet: public Test {
public:
   RetweetCollection collection;
   shared_ptr<Tweet> tweet;

   void SetUp() override {
      tweet = shared_ptr<Tweet>(new Tweet("msg", "@user"));
      collection.add(*tweet);
   }
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty) {
   ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOfOne) {
   ASSERT_THAT(collection.size(), Eq(1u));
}

TEST_F(ARetweetCollectionWithOneTweet, IgnoresDuplicateTweetAdded) {
   Tweet duplicate(*tweet);
   collection.add(duplicate);

   ASSERT_THAT(collection.size(), Eq(1u));
}

