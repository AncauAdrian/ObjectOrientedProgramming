#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

class Activity
{
	std::string act, time;

public:
	Activity(std::string act, std::string time);

};

Activity::Activity(std::string act, std::string time)
{
	this->act = act;
	this->time = time;
}

template<typename t>
class ToDo
{
	std::vector<t> v;

public:
	ToDo(); // Default Const
	ToDo(const std::vector<t>& other); // Copy constructor
	std::vector<t>& operator=(const std::vector<t>& other);

	std::vector<t>& operator+=(const t& val);

	std::vector<t>::iterator& begin()
	{
		return v.begin();
	}

	std::vector<t>::iterator& end()
	{
		return b.end();
	}

	friend std::ostream& operator<<(std::ostream& stream, Activity a);
};template<typename t>
ToDo<t>::ToDo()
{
}template<typename t>
ToDo<t>::ToDo(const std::vector<t>& other)
{
	this->v = other;
}template<typename t>std::vector<t>& ToDo<t>::operator=(const std::vector<t>& other){	this->v = other;	return *this;}template<typename t>std::vector<t>& ToDo<t>::operator+=(const t& val){	this->v.push_back(val);	return *this;}std::ostream& operator<<(std::ostream& stream, Activity a)
{
	stream << a.act << a.time;
}void ToDoList();