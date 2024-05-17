#include<string>
#include<stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& guessNum) {
		if (guessNum.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNum) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must bo number.");
		}

		if (guessNum[0] == guessNum[1]
			|| guessNum[0] == guessNum[2]
			|| guessNum[1] == guessNum[2]) {
			throw invalid_argument("Must not have the same number.");
		}
	}
};