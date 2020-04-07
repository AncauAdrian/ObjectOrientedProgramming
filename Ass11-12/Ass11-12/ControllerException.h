#pragma once
#include <string>

class ControllerException
{
	std::string message;

public:
	ControllerException();
	ControllerException(std::string message);
	std::string what() const;
};

