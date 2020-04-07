#include "Tutorial.h"
#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

Tutorial::Tutorial()
{
	this->title = std::string("None");
	this->author = std::string("None");
	this->likes = 0;
	this->duration = 0;
	this->link = std::string("None");
}

Tutorial::Tutorial(std::string title, std::string author, int likes, int duration, std::string link)
{
	this->title = title;
	this->author = author;
	this->likes = likes;
	this->duration = duration;
	this->link = link;
}

std::string Tutorial::getTitle() const
{
	return this->title;
}

std::string Tutorial::getAuthor() const
{
	return this->author;
}

int Tutorial::getLikes() const
{
	return this->likes;
}

int Tutorial::getDuration() const
{
	return this->duration;
}

std::string Tutorial::getLink() const
{
	return this->link;
}

std::string Tutorial::prettyfy()
{
	return std::string("Title: " + this->title + "  Author: " + this->author + "  Duration: " +
		std::to_string(this->duration / 60) + ":" + std::to_string(this->duration % 60) + "  Likes: " + std::to_string(this->likes) + "  Link: " + this->link);
}

//bool Tutorial::operator==(Tutorial& t)
//{
//	if (this->title.compare(t.getTitle()) == 0 && this->author.compare(t.getAuthor()) == 0)
//		return true;
//
//	return false;
//}

bool operator==(const Tutorial & a, const Tutorial & b)
{
	if (a.title.compare(b.title) == 0 && a.author.compare(b.author) == 0)
		return true;

	return false;
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

std::istream& operator>>(std::istream & is, Tutorial & t)
{
	using namespace std;
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;

	int likes, minutes, seconds;
	likes = std::stoi(tokens[3]);
	int index = tokens[2].find(':');

	minutes = std::stoi(tokens[2].substr(0, index));
	seconds = std::stoi(tokens[2].substr(index + 1, tokens[2].length()));
	t.title = tokens[0];
	t.author = tokens[1];
	t.duration = minutes * 60 + seconds;
	t.likes = likes;
	t.link = tokens[4];

	return is;
}

std::ostream& operator<<(std::ostream & os, const Tutorial & t)
{
	using namespace std;
	os << t.title << "," << t.author << "," << to_string(t.duration / 60) << ":" << to_string(t.duration % 60) << "," << to_string(t.likes)
		<< "," << t.link << "\n";
	return os;
}

void testTutorial()
{
	Tutorial t(std::string("Test"), std::string("Me"), 123, 70, std::string("https://www.fuckyou.com"));
	assert(t.getTitle().compare("Test") == 0);
	assert(t.getAuthor().compare("Me") == 0);
	assert(t.getLikes() == 123);
	assert(t.getDuration() == 70);
	assert(t.getLink().compare("https://www.fuckyou.com") == 0);
	assert(t.prettyfy().compare("Title: Test  Author: Me  Duration: 1:10  Likes: 123  Link: https://www.fuckyou.com") == 0);
	Tutorial t1(std::string("Test"), std::string("Me"), 123, 70, std::string("https://www.fuckyou.com"));
	assert(t1 == t);
	assert(t == t1);

}
