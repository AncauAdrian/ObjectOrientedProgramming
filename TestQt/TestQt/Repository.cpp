#include "Repository.h"
#include <fstream>
#include <iostream>
#include <sstream>

Repository::Repository()
{
}


Repository::~Repository()
{
}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
	using namespace std;
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

void Repository::add(int start, int end, double temp, double prob, std::string desc)
{
	WeatherInfo i{ start, end, temp, prob, desc };
	v.push_back(i);
}

void Repository::file_load()
{
	using namespace std;

	ifstream f("weather.txt");

	string line;

	int start, end;
	double temp, prob;
	string desc;

	while (getline(f, line))
	{
		vector<string> info = tokenize(line, ';');
		start = stoi(info[0]);
		end = stoi(info[1]);
		temp = stod(info[2]);
		prob = stod(info[3]);
		desc = info[4];

		this->add(start, end, temp, prob, desc);
	}

	f.close();
}

std::vector<WeatherInfo>& Repository::getVector()
{
	return this->v;
}
