#include "pch.h"
#include "../Baseball/baseball.cpp"

using namespace std;

TEST(TestCaseName, ThrowException) {
	Baseball game;

	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(TestCaseName, ThrowExceptionWhenInvalidChar) {
	Baseball game;

	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}
