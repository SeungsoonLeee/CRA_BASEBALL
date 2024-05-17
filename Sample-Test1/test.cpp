#include "pch.h"
#include "../Baseball/baseball.cpp"

using namespace std;

TEST(TestCaseName, TestName) {
	Baseball game;

	EXPECT_THROW(game.guess(string("12")), length_error);
}
