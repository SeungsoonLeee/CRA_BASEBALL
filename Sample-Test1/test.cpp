#include "pch.h"
#include "../Baseball/baseball.cpp"

using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
	void assertIllegalArgument(string guessNum) {
		// ASSERT �ɸ� �ֵ�
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
}
