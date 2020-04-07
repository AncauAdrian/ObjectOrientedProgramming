#pragma once
#include <string>
#include <vector>

class Tutorial
{
	std::string title;
	std::string author;
	int likes;
	int duration;
	std::string link;

public:

	// Default constructor
	Tutorial();

	Tutorial(std::string title, std::string author, int likes, int duration, std::string link);
	
	std::string getTitle() const;
	std::string getAuthor() const;
	int getLikes() const;
	int getDuration() const;
	std::string getLink() const;

	// Returns a printable string of the Tutorial
	std::string prettyfy();

	//bool operator==(Tutorial& t);

	friend bool operator==(const Tutorial& a, const Tutorial& b);

	friend std::istream& operator>>(std::istream& is, Tutorial& s);
	friend std::ostream& operator<<(std::ostream& os, const Tutorial& s);
};


std::vector<std::string> tokenize(std::string str, char delimiter);

void testTutorial();
