#include "ControllerException.h"



ControllerException::ControllerException()
{
	this->message = std::string("[ERROR] A Controller Exception was thrown!");
}

ControllerException::ControllerException(std::string message)
{
	this->message = message;
}

std::string ControllerException::what() const
{
	return this->message;
}
