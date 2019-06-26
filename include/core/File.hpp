/*
** EPITECH PROJECT, 2019
** File.hpp
** File description:
** Check libs and games
*/

#ifndef FILE_HPP_
    #define FILE_HPP_

#include "../exception/ArcadeExceptions.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <algorithm>
#include <cstring>

class File {
	public:
        File() = default;
		File(const std::string &path);
		~File();

        std::vector<std::string> getList();
        void addSubStr(std::string &str, const std::string &subStr);
        void getNameSubStr(std::string &name);
        void getName(std::vector<std::string> &pathResult);

        static DIR *openDir(const char *path);
        static struct dirent *readDir(DIR *dirp);
        static int closeDir(DIR *dirp);

	private:
        std::string _path;
};

#endif /* !FILE_HPP_ */
