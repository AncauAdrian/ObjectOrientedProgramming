#include "Building.h"


std::string Building::toString()
{
	return std::string("Building -- Address: " + this->address + "  Construction Year: " + std::to_string(this->constructionYear));
}

Block::Block(std::string address, int year, int totalAp, int occAp)
{
	this->address = address;
	this->constructionYear = year;
	this->totalApartments = totalAp;
	this->occupiedApartments = occAp;
}

bool Block::mustBeRestored()
{
	if (2019 - this->constructionYear <= 40)
		return false;

	float percentage = (float)(this->occupiedApartments) / (float)(this->totalApartments);
	if (percentage > 8.0f / 10.0f)
		return true;

	return false;
}

bool Block::canBeDemolished()
{
	float percentage = (float)(this->occupiedApartments) / (float)(this->totalApartments);
	
	if (percentage < 5 / 100)
		return true;

	return false;
}

std::string Block::toString()
{
	return std::string("Block -- Address: " + this->address + "  Construction Year: " + std::to_string(this->constructionYear) +
		"  Total Apartments: " + std::to_string(this->totalApartments) + "  Occupied Apartments: " + std::to_string(this->occupiedApartments));
}

House::House(std::string address, int year, std::string type, bool historical)
{
	this->address = address;
	this->constructionYear = year;
	this->type = type;
	this->isHistorical = historical;
}

bool House::mustBeRestored()
{
	if (2019 - this->constructionYear > 100)
		return true;

	return false;
}

bool House::canBeDemolished()
{
	return !this->isHistorical;
}

std::string House::toString()
{
	return std::string("House -- Address: " + this->address + "  Construction Year: " + std::to_string(this->constructionYear) +
		"  Type: " + this->type + "  Historical " + (this->isHistorical ? std::string("yes") : std::string("no")));
}
