#include "gmock/gmock.h"
#include "Tweet.h"
#include <string>

using namespace ::testing;
using namespace std;

TEST(ATweet, DefaultsUserToNullWhenNotProvided) {
   Tweet tweet("msg");

   ASSERT_THAT(tweet.user(), Eq("@null"));
}

TEST(ATweet, IsEqualToAnotherWhenMessageAndUserAreEqual) {
   Tweet a("msg", "@user");
   Tweet b("msg", "@user");

   ASSERT_THAT(a, Eq(b));
}

TEST(ATweet, IsNotEqualToAnotherWhenMessagesAreUnequal) {
   Tweet a("msgX", "@user");
   Tweet b("msgY", "@user");

   ASSERT_THAT(a, Ne(b));
}

TEST(ATweet, IsNotEqualToAnotherWhenUsersAreUnequal) {
   Tweet a("msg", "@user1");
   Tweet b("msg", "@user2");

   ASSERT_THAT(a, Ne(b));
}

TEST(ATweet, IsLessThanWhenUserAndMessageAre) {
   Tweet a("msg", "@user1");
   Tweet b("msg", "@user2");

   ASSERT_THAT(a, Lt(b));
}

TEST(ATweet, IsLessThanWhenUserEqualAndMessageIsLessThan) {
   Tweet a("msgA", "@user");
   Tweet b("msgB", "@user");

   ASSERT_THAT(a, Lt(b));
}

TEST(ATweet, CanBeCopyConstructed) {
   Tweet a("msgA", "@user");
   Tweet b(a);

   ASSERT_THAT(a, Eq(b));
}

TEST(ATweet, RequiresUserToStartWithAtSign) {
   string invalidUser("notStartingWith@");
   ASSERT_ANY_THROW(Tweet tweet("msg", invalidUser));
}

TEST(ATweet, RequiresUserToStartWithAnAtSign) {
   string invalidUser("notStartingWith@");
   ASSERT_THROW(Tweet tweet("msg", invalidUser), InvalidUserException);
}

TEST(ATweet, RequiresUserNameToStartWithAnAtSign) {
   string invalidUser("notStartingWith@");
   try {
      Tweet tweet("msg", invalidUser);
      FAIL();
   } 
   catch (const InvalidUserException& expected) {}
}
