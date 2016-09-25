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
	//std::ifstream ifs(inFilename);
	std::ifstream ifs(inFilename.c_str());
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
			//curRecord.push_back(move(s));
			curRecord.push_back(s);

		if (curRecord.size() == 3)
			//outVecRecords.push_back(Record(move(curRecord[0]), move(curRecord[1]), move(curRecord[2])));
			outVecRecords.push_back(Record(curRecord[0], curRecord[1], curRecord[2]));
		else
			cout << "Warning: Empty line or wrong input" << endl;
	}

	ifs.close();
	return true;
}

// Save records to file
bool SaveFile(const string& outFilename, const vector<Record>& records)
{
	//ofstream outFile(outFilename);
	ofstream outFile(outFilename.c_str());
	if (!outFile)
	{
		cerr << "Unable to open " << outFilename << endl;
		return false;
	}

	//for (auto& r : records)
	//{
	//	outFile << r.firstName << ',' << r.lastName << ',' << r.score << '\n';
	//}

	for (vector<Record>::const_iterator itr=records.begin(); itr!=records.end(); ++itr)
	{
		outFile << itr->firstName << ',' << itr->lastName << ',' << itr->score << '\n';
	}

	outFile.close();
	return true;
}

// Sort records using pre-defined sorting function
void SortRecord(vector<Record>& r)
{
	sort(r.begin(), r.end(), sortingFunc());
}

