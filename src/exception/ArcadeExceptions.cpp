/*
** EPITECH PROJECT, 2019
** ArcadeExceptions.cpp
** File description:
** Handle exceptions
*/

#include "../../include/exception/ArcadeExceptions.hpp"

ArcadeExceptions::ArcadeException::ArcadeException(std::string const &e) : _errorMessage(e)
{
}

ArcadeExceptions::ArcadeException::~ArcadeException()
{
}

const char *ArcadeExceptions::ArcadeException::what() const throw()
{
    return _errorMessage.c_str();
}

// Invalid argument
ArcadeExceptions::InvalidArgument::InvalidArgument(std::string const &errorMessage) : ArcadeException(errorMessage)
{
}

ArcadeExceptions::InvalidArgument::~InvalidArgument()
{
}

// Library Exception
ArcadeExceptions::LibraryException::LibraryException(std::string const &errorMessage) : ArcadeException(errorMessage)
{
}

ArcadeExceptions::LibraryException::~LibraryException()
{
}

// System function errors
ArcadeExceptions::SystemFunctionsError::SystemFunctionsError(std::string const &errorMessage) : ArcadeException(errorMessage)
{
}

ArcadeExceptions::SystemFunctionsError::~SystemFunctionsError()
{
}