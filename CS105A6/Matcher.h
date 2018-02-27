//Kevin Nguyen
//kdn433

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Person.h"
#include "Rating.h"
using std::list;
using std::vector;

using namespace std;

class Matcher {
public:
	Matcher();
	map<Person*, Person*> stableMatch(const vector<Person*>& left, const vector<Person*>& right);
};