#pragma once
#include "Tutorial.h"
//#include "DynamicVector.h"
#include <vector>

class Repository
{
protected:
	std::vector<Tutorial> v;
public:
	// Adds a new tutorial to the vector
	void add_tutorial(Tutorial t);

	// Finds a tutorial and returns the index of the element, a tutorial's uniqueness is determined by the Title and Author
	int find(Tutorial t);

	// Removes the tutorial from the list, a tutorial's uniqueness is determined by the Title and Author
	void remove_tutorial(Tutorial &t);

	void remove_tutorial(int index);

	// Update a specific tutorial from the list, a tutorial's uniqueness is determined by the Title and Author
	void update_tutorial(Tutorial t);

	// Returns a string from the repo
	std::string pretty_print();

	// Returns a repo of tutorials that have the author
	Repository search_a(std::string author);

	// Saves the repo to a file
	virtual void file_save();

	// Loads the repo from a file
	virtual void file_load();

	virtual void display();

	bool isEmpty();

	int getLength();

	Repository& operator=(const Repository & r);

	Tutorial& operator[](const int index);

	std::vector<Tutorial> getVector();
};

class RepositoryCSV : public Repository
{
private:
	std::string filename;
public:
	RepositoryCSV(std::string f) : filename(f) {}

	void file_save() override;

	void file_load() override;

	void display() override;
};

class RepositoryHTML : public Repository
{
private:
	std::string filename;
public:
	RepositoryHTML(std::string f) : filename(f) {}

	void file_head(std::ofstream& f);

	void file_tail(std::ofstream& f);

	void write_row(std::ofstream& f, Tutorial& t);

	void file_save() override;

	void file_load() override;

	void display() override;
};


void testRepository();

void test_html();
