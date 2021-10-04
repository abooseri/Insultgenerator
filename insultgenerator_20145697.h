#pragma once

#include <string>
#include <vector>

using namespace std;

const int MAX_NUM_INSULTS(10000);
const string SOURCE_FILE("InsultsSource.txt");


class InsultGenerator {
    public: 
		InsultGenerator();
		void initialize(); 	// reads file					
		vector<string> generate(int) const; // generate specified number of insults
		void generateAndSave(string, int) const; // generate specified number of insults into a file	
		string talkToMe() const; // returns an insult
	private:
		int sourceLength;
		vector<string> column1;
		vector<string> column2;
		vector<string> column3;
		int randInt(int) const; // random int below upper limit
};

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





