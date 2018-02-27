//Kevin Nguyen
//kdn433

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include "Person.h"
#include "readgraph.h"
#include "Matcher.h"
using std::list;
using std::vector;

int main (int argc, char const *argv[])
{
    vector<Person*> left; /// capulets
    vector<Person*> right; /// montagues
    readIn(left, right); /// will fill in the provided lists
    
    /// print it all out to see it all worked
    for(int i=1; i <= 2; i++) {
        vector<Person*>& group = i==1 ? left : right;
        cout << "Group : " << i << endl;
        for(vector<Person*>::iterator iter = group.begin(); iter != group.end(); ++iter){
            Person* p = *iter;
            cout << p->name << " : " ;
            for (list<Rating*>::iterator iter = p->ratings.begin() ; iter != p->ratings.end(); ++iter){
                cout << "(" << (*iter)->pperson->name << ":" << (*iter)->rating << ") ";
            }
            cout << endl;
        }
    }

    //call matcher
    Matcher j;
    j.stableMatch(left, right);
    return 0;
}