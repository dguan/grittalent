#include <gtest/gtest.h>
#include "gritTest.h"

//static vector<Record> data = {{"BUNDY", "TERESSA", "88"}, {"SMITH", "ALLAN", "70"}, {"KING", "MADISON", "88"}, {"SMITH", "FRANCIS", "85"}};
static vector<Record> data;

bool testSorting()
{
	data.push_back(Record("BUNDY", "TERESSA", "88"));
	data.push_back(Record("SMITH", "ALLAN", "70"));
	data.push_back(Record("KING", "MADISON", "88"));
	data.push_back(Record("SMITH", "FRANCIS", "85"));
	
	SortRecord(data, sortingFunc());
	
	for(unsigned int idx=1; idx < data.size(); ++idx)
	{
		if(data[idx].score > data[idx-1].score)
			return false;
		else if(data[idx].score == data[idx-1].score)
			return data[idx].firstName >= data[idx-1].firstName;
	}

	return true;
}

TEST(TestSortingFunction, ifSorted)
{
	EXPECT_TRUE(testSorting());
}

TEST(TestSortedRecords, checkIndividualRecord)
{
	EXPECT_TRUE(data[0].score == 88);
	EXPECT_TRUE(data[1].lastName == "MADISON");
	EXPECT_TRUE(data[2].firstName == "SMITH");
	EXPECT_TRUE(data[3].score == 70);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);  
  
    // Runs all tests using Google Test.  
    return RUN_ALL_TESTS();
}
