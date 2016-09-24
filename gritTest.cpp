#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "gritTest.h"

using namespace std;

// Load records from file
bool LoadFile(const string& inFilename, vector<Record>& outVecRecords)
{
	std::ifstream ifs(inFilename);
	if (!ifs)
	{
		cerr << "Unable to open " << inFilename << endl;
		return false;
	}

	string str;
	while (getline(ifs, str))
	{
		stringstream lineStream(str);
		string s;
		vector<string> curRecord;

		while (getline(lineStream, s, ','))
			curRecord.push_back(move(s));

		if (curRecord.size() == 3)
			outVecRecords.push_back(Record(move(curRecord[0]), move(curRecord[1]), move(curRecord[2])));
		else
			cout << "Warning: Empty line or wrong input" << endl;
	}

	ifs.close();
	return true;
}

// Save records to file
bool SaveFile(const string& outFilename, const vector<Record>& records)
{
	ofstream outFile(outFilename);
	if (!outFile)
	{
		cerr << "Unable to open " << outFilename << endl;
		return false;
	}

	for (auto& r : records)
	{
		outFile << r.firstName << ',' << r.lastName << ',' << r.score << '\n';
	}

	outFile.close();
	return true;
}

// Sort records using pre-defined sorting function
void SortRecord(vector<Record>& r, function<bool(const Record&, const Record&)> sortingFunc)
{
	sort(r.begin(), r.end(), sortingFunc);
}

