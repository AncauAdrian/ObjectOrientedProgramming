#pragma once
#include <string>

class Building
{
protected:
	std::string address;
	int constructionYear;
public:
	virtual bool mustBeRestored() = 0;
	virtual bool canBeDemolished() = 0;
	std::string toString();
};



class Block : public Building
{
	int totalApartments, occupiedApartments;
public:
	Block(std::string address, int year, int totalAp, int occAp);
	bool mustBeRestored() override;
	bool canBeDemolished() override;
	std::string toString();
};


class House : public Building
{
	std::string type;
	bool isHistorical;
public:
	House(std::string address, int year, std::string type, bool historical);
	bool mustBeRestored() override;
	bool canBeDemolished() override;
	std::string toString();
};