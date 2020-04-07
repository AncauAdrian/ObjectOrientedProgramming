#include "Repository.h"
//#include "DynamicVector.h"
#include "Tutorial.h"
#include <fstream>
#include <vector>
#include <assert.h>
#include <iostream>

void Repository::add_tutorial(Tutorial t)
{
	this->v.push_back(t);
}

int Repository::find(Tutorial t)
{
	auto pos = std::find(this->v.begin(), this->v.end(), t);

	if (pos == this->v.end())
		return -1;

	return (int)std::distance(this->v.begin(), pos);
}

void Repository::remove_tutorial(Tutorial &t)
{
	int index = this->find(t);
	if (index == -1)
		throw "[ERROR] Could not find the tutorial!";

	this->v.erase(this->v.begin() + index);
}

void Repository::remove_tutorial(int index)
{
	this->v.erase(this->v.begin() + index);
}

void Repository::update_tutorial(Tutorial t)
{
	int index = this->find(t);
	if (index == -1)
		throw "[ERROR] Could not find the tutorial!";

	v[index] = t;
}

std::string Repository::pretty_print()
{
	std::string s;

	int i = 0;

	for(auto a : this->v)
		s += std::to_string(i++) + ": " + a.prettyfy() + '\n';

	return s;
}

Repository Repository::search_a(std::string author)
{
	Repository temp;
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->v[i].getAuthor().find(author) != std::string::npos) {
			temp.add_tutorial(this->v[i]);
		}
	}

	return temp;
}

void Repository::file_save()
{
	
}

void Repository::file_load()
{
	
}

void Repository::display()
{
}

bool Repository::isEmpty()
{
	if (this->v.empty())
		return true;

	return false;
}

int Repository::getLength()
{
	return this->v.size();
}

Repository & Repository::operator=(const Repository & r)
{
	this->v = r.v;
	return *this;
}

Tutorial & Repository::operator[](const int index)
{
	return this->v[index];
}

std::vector<Tutorial> Repository::getVector()
{
	return this->v;
}

void testRepository()
{
	Repository repo;
	Tutorial t1{ "TEst1", "Me1", 101, 61, "www1" };
	Tutorial t2{ "TEst2", "Me2", 102, 62, "www2" };
	Tutorial t3{ "TEst3", "Me3", 103, 63, "www3" };
	Tutorial t4{ "TEst4", "Me4", 104, 64, "www4" };

	repo.add_tutorial(t1);
	repo.add_tutorial(t2);
	repo.add_tutorial(t3);
	repo.add_tutorial(t4);
	repo[3];
	assert(repo.find(t1) == 0);
	assert(repo.find(t2) == 1);
	assert(repo.find(t3) == 2);
	assert(repo.find(t4) == 3);
	repo.remove_tutorial(t2);
	Tutorial t("TEst23123", "Me1", 101, 61, "www1");
	try
	{
		repo.remove_tutorial(t);
	}
	catch (...)
	{
		assert(true);
	}
	assert(repo.find(t1) == 0);
	assert(repo.find(t3) == 1);
	assert(repo.find(t4) == 2);
	repo.remove_tutorial(2);
	Tutorial t5{ "TEst3", "Me3", 104, 64, "www3" };
	repo.update_tutorial(t5);
	repo.remove_tutorial(0);
	repo.remove_tutorial(0);
	
	Repository newrepo;
	repo = newrepo;
	assert(repo.isEmpty());
	assert(repo.getLength() == 0);

	Tutorial tt{ "Test", "Test", 100, 64, "www" };
	repo.add_tutorial(tt);
	assert(!repo.isEmpty());
	assert(repo.getLength() == 1);
	/*repo.pretty_print();
	repo.search_a("Test");
	repo.search_a("Tesasdadst");*/

	try
	{
		repo.update_tutorial(t1);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_html()
{
	RepositoryHTML test("test.html");

	test.file_load();

	//std::cout << test.pretty_print();

	//test.file_save();
}

void RepositoryHTML::file_head(std::ofstream& f)
{
	f << "<!DOCTYPE html>\n";
	f << "<html>\n";
	f << "\t<head>\n\t\t<title>Playlist</title>\n";
	f << "\t</head>\n\t<body>\n";
	f << "\t\t<table border=\"1\">\n";
	f << "\t\t<tr>\n";
	f << "\t\t\t<td>" << "Title" << "</td>\n";
	f << "\t\t\t<td>" << "Author" << "</td>\n";
	f << "\t\t\t<td>" << "Duration" << "</td>\n";
	f << "\t\t\t<td>" << "Likes" << "</td>\n";
	f << "\t\t\t<td>" << "Link" << "</td>\n";
	f << "\t\t</tr>\n";
}

void RepositoryHTML::file_tail(std::ofstream& f)
{
	f << "\t</body>\n";
	f << "</html>\n";
}

void RepositoryHTML::write_row(std::ofstream& f, Tutorial& t)
{
	f << "\t\t<tr>\n";
	f << "\t\t\t<td>" << t.getTitle() << "</td>\n";
	f << "\t\t\t<td>" << t.getAuthor() << "</td>\n";
	f << "\t\t\t<td>" << t.getDuration() << "</td>\n";
	f << "\t\t\t<td>" << t.getLikes() << "</td>\n";
	f << "\t\t\t<td><a href =\"" << t.getLink() << "\">Link</a></td>\n";
	f << "\t\t</tr>\n";
}

void RepositoryHTML::file_save()
{
	using namespace std;

	ofstream f(this->filename.c_str());
	if (!f.is_open())
		return;

	this->file_head(f);

	for (auto t : this->v)
		write_row(f, t);

	this->file_tail(f);

	f.close();
}

void RepositoryHTML::file_load()
{
	using namespace std;

	ifstream f(filename.c_str());


	string buf;
	if (!f.is_open())
		return;

	this->v.clear();

	getline(f, buf, '<');
	getline(f, buf, '>');

	while (getline(f, buf, '<') && getline(f, buf, '>') && buf.compare("tr"));
	while (getline(f, buf, '<') && getline(f, buf, '>') && buf.compare("tr"));

	string title, author, link;
	int likes, duration;

	while (buf.compare("/body") != 0)
	{
		if (f.eof())
			break;

		getline(f, buf, '>');
		getline(f, buf, '<');

		title = buf;

		getline(f, buf, '>');
		getline(f, buf, '>');
		getline(f, buf, '<');

		author = buf;

		getline(f, buf, '>');
		getline(f, buf, '>');
		getline(f, buf, '<');

		duration = stoi(buf);

		getline(f, buf, '>');
		getline(f, buf, '>');
		getline(f, buf, '<');

		likes = stoi(buf);

		getline(f, buf, '\"');
		getline(f, buf, '\"');

		link = buf;

		while (buf.compare("tr") && getline(f, buf, '<') && getline(f, buf, '>'));


		Tutorial anew(title, author, likes, duration, link);

		this->v.push_back(anew);

		if (f.eof())
			break;
	}
	f.close();
}

void RepositoryHTML::display()
{
	std::string cmd = "start chrome " + this->filename;
	system(cmd.c_str());
}

void RepositoryCSV::file_save()
{
	using namespace std;

	ofstream f(this->filename.c_str());
	if (!f.is_open())
		return;

	for (auto a : this->v)
		f << a;

	f.close();
}

void RepositoryCSV::file_load()
{
	using namespace std;

	ifstream f(filename.c_str());


	Tutorial buf;
	if (!f.is_open())
		return;

	this->v.clear();

	while (f >> buf)
		this->add_tutorial(buf);

	f.close();
}

void RepositoryCSV::display()
{
	std::string cmd = "notepad " + this->filename;
	system(cmd.c_str());
}
