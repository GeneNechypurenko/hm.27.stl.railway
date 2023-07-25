#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class AIRS //Automated Information Railway station System
{
private:
	char trainNumber[6];
	char departureTime[6];
	char destination[21];

public:
	AIRS();
	AIRS(const char* train, const char* time, const char* dest);

	void input();
	void output() const;

	void add(vector<AIRS>& trains);
	void show(vector<AIRS>& trains) const;

	void save(const string filename, vector<AIRS>& trains) const;
	void load(const string filename, vector<AIRS>& trains);
};

