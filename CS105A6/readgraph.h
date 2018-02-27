#ifndef READGRAPH_063982ANS
#define READGRAPH_063982ANS

#include "Rating.h"
#include "Person.h"
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;
using std::map;
using std::pair;
using std::string;

struct PGroup{
    Person& p;
    int group;
    PGroup(Person& p, const int group) : p(p), group(group){}
};

struct deleteIfMatchesName {
    string name;
    deleteIfMatchesName(const string& name) : name(name){}
    bool operator() (const Rating* pr) { 
        // cout << " pr === " << pr << "   " << pr->pperson->name << endl;
        if(pr->pperson->name == name){
            // const Rating* temp = pr;
            // pr = NULL;
            // delete temp;
            return true;
        } 
        return false;
    }
};

void readIn(vector<Person*>& capulets, vector<Person*>& montagues){

    /// variables used to load in the input
    size_t personCount; /// how many people there are
    vector<Rating*> defCapRating; /// a default rating for all capulets
    vector<Rating*> defMonRating; /// a default rating for all montagues
    map<string, PGroup> personMap; /// mapping a persons name to the person and group
    
    cin >> personCount; /// read in the count
    
    /// add the people to the group
    string name; 
    int groupNum; 
    for(size_t i = 0; i < personCount; ++i){
        cin >> name >> groupNum; /// read in our name and group
        /// get which list or rating we need based on the group
        vector<Person*>& group = groupNum==1? capulets : montagues;
        vector<Rating*>& rating = groupNum==1? defCapRating : defMonRating;
        group.push_back(new Person(name));
        Person* pourPerson = group.back();
        PGroup pg(*pourPerson, groupNum);
        personMap.insert( pair<string, PGroup>(name, pg));
        rating.push_back( new Rating(pourPerson, 0) );
    }
    
    string line;
    string preferenceName;
    getline(cin, line); /// get a line to get into correct position
    /// i will use client as the person at the front of the list whose
    /// ratings we are adding
    for(size_t i = 0; i < personCount; ++i){
        /// get our preferences 
        getline(cin, line); 
        std::istringstream lis(line); /// get an input stream over our line
        lis >> name; /// our client name
    
        PGroup& pg = personMap.find(name)->second; /// find our client with the map
        Person& client = pg.p; /// our client
        list<Rating*>& ratings = client.ratings; /// our client prefs

        /// make a copy of our default rating into our ratings using copy
        vector<Rating*>& defRating = pg.group==1? defMonRating : defCapRating;
        for (vector<Rating*>::iterator i = defRating.begin(); i != defRating.end(); ++i){
            if ( (*i)->pperson->name != client.name)
                ratings.push_back(new Rating( (*i)->pperson,(*i)->rating));
        }
                
        /// now iterate over the preferences, and replace the default ratings
        int rating = personCount /2;
        while( lis >> preferenceName){
            for (list<Rating*>::iterator i = ratings.begin(); i != ratings.end(); ++i){
                if ( (*i)->pperson->name == preferenceName)
                    (*i)->rating = rating;
            }
            // ratings.erase(last,ratings.end());
            rating--;
        }        
    }
    /// cleanup def rating*
    for (int group =0; group <= 1; ++group){
        vector<Rating*>& defRating = group==1? defMonRating : defCapRating;
        for (vector<Rating*>::iterator i = defRating.begin(); i != defRating.end(); ++i){
            delete *i;
        }           
        defRating.clear();
    }
    
}

#endif