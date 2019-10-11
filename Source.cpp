#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

const int LINES = 20551;

string lineRead();
int counting(string input);
bool match(string word, string input);


int main() {
	srand(time(NULL));
	string input;
	int count;
	string word = lineRead();


	count = counting(input);

	cout << "You had " << count << " correct words" << endl;
		
	}



string lineRead() {
	int lines;
	ifstream infile;
	infile.open("words7.dat");

	infile >> lines;

	int n = rand() % lines;
	string words[LINES];
	string word;


	for (int i = 0; i < n; i++) {
		infile >> words[i];
	}

	word = words[n - 1];
	return word;
}

int counting(string input) {
	bool matching;
	ofstream outfile;
	outfile.open("mywords.dat");
	int count = 0;
	char choice;
	bool game = true;
	string word;
	word = lineRead();


	while (game) {
		cout << "The word of the day is " << word << endl;

		cout << "Please enter a word:";
		cin >> input;
		cout << "Your word is " << input << endl;
		outfile << input << endl;
		matching = match(word,input);
		if (matching == true)
		   count++;

		cout << "Do you want to enter another word?" << endl; 
		cout << "y for yes" << endl;
		cout << "n for no" << endl;
		cin >> choice;
		if (choice != 'y' && choice != 'n') {
			cout << "error!" << endl;
			cout << "Do you want to enter another word?" << endl;
			cout << "y for yes" << endl;
			cout << "n for no" << endl;
			cin >> choice;

		}
        else if (choice == 'n') {
			game = false;
		}
	}
	return count;
}



bool match(string word, string input) {
	int count;
	int lines;
	int n;
	bool matching = true;

	if (word.find(input) != string::npos) {
		cout << input <<  " can be found in " << word << endl;
		return true;

	}
	else {
		cout << input << " cannot be found in " << word << endl;
		return false;
	}


	return matching;
}


/*

wrote the string in 3rd function instreead of second that is why it randomized the word
werote word of day in file instead of function
the dead function erorr was solved with an &
had to remove function arguments from first function



*/