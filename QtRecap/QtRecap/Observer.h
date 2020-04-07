#pragma once
#include <vector>
#include <algorithm>

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};


class Observable
{
	std::vector<Observer*> obs;
public:
	void add_observer(Observer* a)
	{
		obs.push_back(a);
	}

	void remove_observer(Observer *o)
	{
		obs.erase(std::remove(obs.begin(), obs.end(), o));
	}

	void notify()
	{
		for (auto a : obs)
		{
			a->update();
		}
	}
};