#include <iostream>
#include <vector>

#include "gritTest.h"

using namespace std;

void Usage(const char* appName)
{
	cout << "Usage: " << appName << " filename" << endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		Usage(argv[0]);
		return 0;
	}

	vector<Record> records;

	// Load records from input file
	if (LoadFile(argv[1], records) == false)
	{
		cout << "Error reading from " << argv[1] << endl;
		exit(1);
	}
	
	// Sort records using pre-defined sorting function
	//SortRecord(records, sortingFunc);
	SortRecord(records);

	// Print sorted records
	//for (auto& r : records)
	//	cout << r.firstName << ',' << r.lastName << ',' << r.score << endl;
	for(vector<Record>::const_iterator itr=records.begin(); itr!=records.end(); ++itr)
		cout << itr->firstName << ',' << itr->lastName << ',' << itr->score << endl;

	// construct output file name from inputfile's base name,
	// if input file name is data1.xyz, output filename will be data1-graded.txt
	// if input file name is data2, output file name will be data2-graded.txt
	string outFilename = string(argv[1]);
	outFilename = outFilename.substr(0, outFilename.rfind('.')) + "-graded.txt";

	// Save sorted records into file
	if (SaveFile(outFilename, records) == false)
	{
		cout << "Error writing to " << outFilename << endl;
		exit(2);
	}

	cout << "Finished, created " << outFilename << endl;
	return 0;
}

