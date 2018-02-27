//Kevin Nguyen
//kdn433

#ifndef RATING_H_ZCVMKZBA
#define RATING_H_ZCVMKZBA
#include <iostream>
using namespace std;

class Person;
class Rating {
public:
    Person* pperson;
    int rating;
    Rating(Person* p, int rating) : pperson(p), rating(rating){};

    bool operator >(const Rating& value) {
		return this->rating > value.rating;
	}

	bool operator >=(const Rating& value) {
		return this->rating >= value.rating;
	}

	bool operator <(const Rating& value) {
		return this->rating < value.rating;
	}

	bool operator <=(const Rating& value) {
		return this->rating <= value.rating;
	}

	bool operator ==(const Rating& value) {
		return this->rating == value.rating;
	}

	bool operator !=(const Rating& value) {
		return !(this->rating == value.rating);
	}

};

#endif