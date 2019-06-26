/*
** EPITECH PROJECT, 2019
** ArcadeException.hpp
** File description:
** Arcade exceptions
*/

#ifndef ARCADEEXCEPTIONS_HPP_
    #define ARCADEEXCEPTIONS_HPP_

#include <string>
#include <exception>

namespace ArcadeExceptions {

    class ArcadeException : public std::exception {
        public:
            ArcadeException(std::string const &e);
            ~ArcadeException();
            virtual const char *what() const throw();

        private:
            std::string _errorMessage;
    };

    class LibraryException : public ArcadeException {
        public:
            LibraryException(std::string const &errorMessage);
            ~LibraryException();
    };

    class InvalidArgument : public ArcadeException {
        public:
            InvalidArgument(std::string const &errorMessage);
            ~InvalidArgument();
    };

    class SystemFunctionsError : public ArcadeException {
        public:
            SystemFunctionsError(std::string const &errorMessage);
            ~SystemFunctionsError();
    };
}

#endif /* !ARCADEEXCEPTIONS_HPP_ */
