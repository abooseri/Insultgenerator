#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>

/*
 * insultgenerator_netid.cpp
 *
 * Author: Alan McLeod
 * Part of a sample solution for CISC320 assignment 1. This implementation uses a 3D bool
 * array and does not need any sorting or searching to generate the insults in the shortest
 * time measured.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>

#include "insultgenerator_netid.h"

using namespace std;

FileException::FileException(const string& m) : message(m) {}
string FileException::what() const { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}
string NumInsultsOutOfBounds::what() const { return message; }

InsultGenerator::InsultGenerator() : sourceSize(0) {
	srand(time(0));
} // end constructor


