#include<string>
#include<stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		:question(question) {
		result = { false , 0 ,0 };
	}
	GuessResult guess(const string& guessNum) {
		assertIllegalArgument(guessNum);
		if (guessNum == question)
			return { true,3,0 };

		countStrike(guessNum);
		countBall(guessNum);

		return result;
	}
	void countBall(const string& guessNum)
	{
		for (int i = 0; i < 3; ++i)
			for (int check = 0; check < 3; ++check)
			{
				if (i == check)
					continue;
				if (guessNum[i] == question[check])
					result.balls++;
			}
	}
	void countStrike(const string& guessNum)
	{
		for (int i = 0; i < 3; ++i)
			if (guessNum[i] == question[i])
				result.strikes++;
	}
	void assertIllegalArgument(const std::string& guessNum)
	{
		if (guessNum.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNum) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must bo number.");
		}

		if (isDuplicateNumber(guessNum)) {
			throw invalid_argument("Must not have the same number.");
		}
	}
	bool isDuplicateNumber(const std::string& guessNum)
	{
		return guessNum[0] == guessNum[1]
			|| guessNum[0] == guessNum[2]
			|| guessNum[1] == guessNum[2];
	}
private:
	string question;
	GuessResult result;
};