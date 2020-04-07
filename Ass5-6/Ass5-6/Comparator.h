#pragma once
#include <string>
#include "Tutorial.h"

template <typename T>
class Comparator
{
public:
	virtual bool compare(const T & a, const T & b) const = 0;
};


class ComparatorAscendingByTitle : public Comparator<Tutorial>
{
public:
	bool compare(const Tutorial& a, const Tutorial& b) const override;
};


class ComparatorAscendingByAuthor : public Comparator<Tutorial>
{
public:
	bool compare(const Tutorial& a, const Tutorial& b) const override;
};