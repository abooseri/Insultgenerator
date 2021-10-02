#pragma once
#include <string>
#include <vector>

using namespace std;

const string SOURCE_FILE("InsultsSource.txt");

class FileException {
   public:
	FileException(const string&);
	string what() const;
private:
	string message;
};

class NumInsultsOutOfBounds {
	public:
		NumInsultsOutOfBounds(const string&);
		string what() const;
	private:
		string message;
};

class InsultGenerator {
    public: 
		void initialize(); 						// Loads the attribute contents from the source file.
	    string talkToMe() const;
		vector<string> generate(int) const;
		void generateAndSave(string, int) const;	
	private:
		int sourceSize;
		vector<string> part1;
		vector<string> part2;
		vector<string> part3;
		int randInt(int) const;
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

