#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string scramble(string word);

int main() {

	srand(time(NULL));

	//string test = "I don't give a holstein for programmers that can only spell a variable one way. (Dr. Stephany)";
	string test = "problem";
	cout << scramble(test);


}

string scramble(string word) {
	if (word.length() > 3) {
		string letterHold = "test";
		int firstLetter = rand() % word.length();
		int secondLetter = rand() % word.length();
		while (firstLetter == 0 || firstLetter == (word.length() - 1)) {
			firstLetter = rand() % word.length();
		}
		while (secondLetter == firstLetter || secondLetter == 0 || secondLetter == (word.length() - 1)) {
			secondLetter = rand() % word.length();
		}

		letterHold[1] = word[firstLetter];
		word[firstLetter] = word[secondLetter];
		word[secondLetter] = letterHold[1];
		return word;
	}
}