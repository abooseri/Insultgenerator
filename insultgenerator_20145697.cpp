/*
 * insultgenerator_20145697.cpp
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>


#include "insultgenerator_20145697.h"

using namespace std;

FileException::FileException(const string& m) : message(m) {}
string FileException::what() const { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}
string NumInsultsOutOfBounds::what() const { return message; }

InsultGenerator::InsultGenerator() : sourceLength(0) {
	srand(time(0));
} 
void InsultGenerator::initialize() {
	string phrase;
	ifstream fileIn(SOURCE_FILE);
	if (fileIn.fail()) {
		throw FileException("Insults source file: " + SOURCE_FILE + " cannot be read.");
		return;
	}
	sourceLength = 0;
	while (!fileIn.eof()) { // check  for end of file 
		fileIn >> phrase;
		column1.push_back(phrase);
		fileIn >> phrase;
		column2.push_back(phrase);
		fileIn >> phrase;
		column3.push_back(phrase);
		sourceLength++;
	}
	fileIn.close();
} // open file

int InsultGenerator::randInt(int upperBound) const {
	int randInt = rand() %upperBound; //Use built-in random number generator.
	return randInt;
} // randomn int with upperbound

string InsultGenerator::talkToMe() const {
	string insult("Thou ");
	insult += column1.at(randInt(sourceLength));
	insult += " " + column2.at(randInt(sourceLength)) + " ";
	insult += column3.at(randInt(sourceLength)) + "!";
	return insult;
} // single insult returned 


vector<string> InsultGenerator::generate(int numInsults) const {
	if (numInsults < 1 || numInsults > MAX_NUM_INSULTS){
		throw NumInsultsOutOfBounds("This is not valid for the number of insults! Must be between 1-10,000");
	} //end exception check

	set<string> setOfInsults;
	string insult;
	while (numInsults > setOfInsults.size()) {
		insult = std::string(talkToMe());
		setOfInsults.insert(insult);
	} //Create a set of insults which is automatically sorted.

	vector<string> insults;
	copy(setOfInsults.begin(), setOfInsults.end(), back_inserter(insults));
	return insults;
} // 

void InsultGenerator::generateAndSave(string filename, int numInsults) const {
	int lineNumber = 0;
	vector <string> insultVector = generate(numInsults);
	ofstream fileOut(filename.c_str());
	if (fileOut.fail()){
		throw FileException("Your file:" + filename + "cannot be written");
	} //end file exception check

	while (lineNumber <numInsults) {
		fileOut << insultVector[lineNumber] <<endl;
		lineNumber++;
	}
	fileOut.close();
} 
// generate random ints from 1 to 10,000
// no dupes and in alphabetical order(also saved)
//time to generate insults reported
// 3 picked from each coloumn(3)
//generate 1 - 10,000 insults


// Initilize reads file into attributes
// talkToMe() returns a single insult, generated at random.
//<set> sorts automatically
