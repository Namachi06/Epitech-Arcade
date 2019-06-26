/*
** EPITECH PROJECT, 2019
** File.cpp
** File description:
** Get the lists of games and libs
*/

#include "../../include/core/File.hpp"

File::File(const std::string &path) : _path(path)
{
}

File::~File()
{
}

std::vector<std::string> File::getList()
{
    struct dirent *dp;
    DIR *dir;
    std::vector<std::string> pathResult;

    if ((dir = openDir(_path.c_str())) == NULL)
        throw ArcadeExceptions::SystemFunctionsError("Directory not found: " + _path);
    while ((dp = readDir(dir))) {
        if (strstr(dp->d_name, ".so")) {
            std::ostringstream path;
            path << _path << dp->d_name;
            pathResult.push_back(path.str());
        }
    }
    closeDir(dir);
    if (pathResult.size() == 0)
        throw ArcadeExceptions::LibraryException("Can't find shared libraries in " + _path);
    return (pathResult);
}

void File::getNameSubStr(std::string &name)
{
    name = name.substr(0, name.find_last_of("."));
    name.erase(0, name.find_last_of("_") + 1);
}

void File::getName(std::vector<std::string> &pathResult)
{
    std::vector<std::string>::iterator path;
    for (path = pathResult.begin(); path != pathResult.end(); ++path) {
        getNameSubStr(*path);
    }
}

DIR *File::openDir(const char *path)
{
    return opendir(path);
}

struct dirent *File::readDir(DIR *dirp)
{
    return readdir(dirp);
}

int File::closeDir(DIR *dirp)
{
    return closedir(dirp);
}
