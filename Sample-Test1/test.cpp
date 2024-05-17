#include "pch.h"
#include "../Baseball/baseball.cpp"

using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNum) {
		// ASSERT 걸릴 애들
		try {
			game.guess(string(guessNum));
			FAIL();
		}
		catch (exception e) {
			// PASS 
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultMatchedNumger) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}
