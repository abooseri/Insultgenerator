#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
#pragma once

class FileException {
   public:
	FileException(const string& message);
	string& what();
private:
	string message;
};

class TextFileIO {
public:
	TextFileIO(const string& filename);
	vector<string> readFile() const;
	int writeFile(const vector<string>& contents) const;
private:
	string filename;
};

class NumInsultsOutOfBounds {

};

class InsultGenerator {
	private:
		vector<string> insults;

    public: 
	int initialize() {

	};
int generate(int num) {
	for(int i = 0; i < num; i++) {
		srand(time(0));
	}
};

// generate random ints from 1 to 10,000
// no dupes and in alphabetical order(also saved)
//time to generate insults reported
// 3 picked from each coloumn(3)
//generate 1 - 10,000 insults

// read txt file and input data into an array
// Initilize reads file into attributes
// talkToMe() returns a single insult, generated at random.
//<set> sorts automatically
// srand(time(0))
