#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string scramble(string word);
void wordParser(string word);

int main() {
    srand(time(NULL));

    string test = "I don't give a holstein for programmers that can only spell a variable one way. (Dr. Stephany)";
    wordParser(test);

    return 0;
}

string scramble(string word) {
    if (word.length() > 3) { 
        int firstLetter = rand() % (word.length() - 3) + 1; 
        int secondLetter = rand() % (word.length() - 2) + 1;
        while (secondLetter == firstLetter) {
            secondLetter = rand() % (word.length() - 2) + 1;
        }
        char letterHold = word[firstLetter];
        word[firstLetter] = word[secondLetter];
        word[secondLetter] = letterHold;
    }
    return word;
}

void wordParser(string word) {
    const char space = ' ';
    string partOfPhrase = "";
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] != space) {
            partOfPhrase += word[i];
        }
        else {
            if (!partOfPhrase.empty()) {
                cout << scramble(partOfPhrase);
                partOfPhrase = "";
            }
            cout << space;
        }
    }
    if (!partOfPhrase.empty()) {
        cout << scramble(partOfPhrase);
    }
}
