#ifndef _GRIT_TEST_HEADER_
#define _GRIT_TEST_HEADER_

#include <string>
#include <vector>
#include <functional>

#include <cstdlib>

using namespace std;

// Record definition
typedef struct _record{
	string firstName;
	string lastName;
	int score;

/*
	_record() = default;
	_record(string&& fName, string&& lName, string&& sc) : firstName(fName), lastName(lName)
	{
		score = stoi(sc);
	}
*/
	_record(const string& fName, const string& lName, const string& sc) : firstName(fName), lastName(lName)
	{
		score = atoi(sc.c_str());
	}
} Record;

/*
// Sorting function used to sort records
static std::function <bool(const Record&, const Record&)> sortingFunc = [&](const Record& a, const Record& b)
{
	if (a.score == b.score)
		return a.firstName < b.firstName;
	else
		return a.score > b.score;
};
*/

struct sortingFunc
{
	bool operator()(const Record& a, const Record& b)
	{
		if(a.score == b.score)
			return a.firstName < b.firstName;
		else
			return a.score > b.score;
	}
};


// Load records from file
bool LoadFile(const string& inFilename, vector<Record>& outVecRecords);

// Save sorted records to file
bool SaveFile(const string& outFilename, const vector<Record>& records);

// Sort records using pre-defined sorting function
//void SortRecord(vector<Record>& r, function<bool(const Record&, const Record&)> sortingFunc);
void SortRecord(vector<Record>& r);

#endif
