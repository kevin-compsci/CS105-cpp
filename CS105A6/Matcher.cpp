//Kevin Nguyen
//kdn433

#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include "Matcher.h"
#include "Person.h"
#include "Rating.h"


using namespace std;

Matcher::Matcher() {}

map<Person*, Person*> Matcher::stableMatch(const vector<Person*>& left, const vector<Person*>& right) {
	bool hasElement(map<string, string> result, string data);
    bool hasKey(map<string, string> result, string data);
	string findKey(map<string, string> result, string data);


    string temp;
    int counter = 0;
	int iteration = 0;

	map<string, int> rateList;
	map<string, map<string, int> > refList;
	map<string, string> result;

    //sets up lists to use
 	for(int i=1; i <= 2; i++) {
    	vector<Person*> group = i==1 ? left : right;
        for(vector<Person*>::iterator iter = group.begin(); iter != group.end(); ++iter, iteration++){
            Person* p = *iter;
            for (list<Rating*>::iterator iter = p->ratings.begin() ; iter != p->ratings.end(); ++iter){
            	rateList[(*iter)->pperson->name] = (*iter)->rating;
            }
            refList[p->name] = rateList;
            rateList = map<string, int>();
        }
    }

    //stable matching algorithm, still buggy
    while(counter < 30) {
        for (map<string, map<string, int> >::iterator its = refList.begin(); (its != refList.end()); ++its) {                
            if (!hasKey(result, its->first)) {
                for (map<string, int>:: iterator its2 = its->second.begin(); its2 != its->second.end(); its2++) {
                    if ((result.empty()) || (hasElement(result, its2->first) == false)) { //second elemnet is not in result mapping
                            result[its->first] = its2->first;
                    }
                    else if (hasElement(result, its2->first) == true) { //second element is in result mapping   
                        temp = findKey(result, its2->first);
                            if ( (refList[its->first].find(temp)->second) < (its2->second) ) {
                                result[its->first] = its2->first;                        
                                refList[temp].erase(its2->first); //erase the rating from free'd
                                result.erase(temp); //deletes the previous pairing that is now overwritten            
                            }
                    }
                    break;
                }
            } 
            if (refList[its->first].size() == 0) {
                cout << " terminate " << endl;
                counter = 9999;
            }
        }       
        counter++;
    }

    //Prints results
    for (map<string, string>::iterator its = result.begin(); its != result.end(); ++its) {
        cout << its->first << " : " << its->second << endl;
    }
}

//checks if element exists
bool hasElement(map<string, string> result, string data) {
	for(map<string, string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		if (iter->second == data) {
			return true;
		}
	}
	return false;
}

//checks if key exists
bool hasKey(map<string, string> result, string data) {
    for(map<string, string>::iterator iter = result.begin(); iter != result.end(); iter++) {
        if (iter->first == data) {
            return true;
        }
    }
    return false;  
}

//finds the key and returns it
string findKey(map<string, string> result, string data) {
	for(map<string, string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		if (iter->second == data) {
			return iter->first;
		}
	}
	return "";	
}