#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>

using namespace std;

struct Student
{
	string name;
	int score;
	bool operator<(const Student& other)
	{
		//return score<other.score;
		return score != other.score ? score > other.score : name<other.name;
	}

	friend ostream& operator<<(ostream& os,const Student& s)
	{
		os<<"Student: "<<s.name<<"  "<<s.score<<endl;
		return os;
	}
};

#endif /*__STUDENT_H*/