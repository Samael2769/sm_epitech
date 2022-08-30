/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Execve
*/

#include "Execve.hpp"
#include <iostream>

Execve::Execve(std::vector<std::string> env)
{
    _env = cvector(env);
}

Execve::~Execve()
{
}

char ** Execve::cvector(std::vector<std::string> vec)
{
    char **res = new char *[vec.size() + 1];
    for (int i = 0; i < vec.size(); i++)
        res[i] = strdup(vec[i].c_str());
    res[vec.size()] = NULL;
    return res;
}

void Execve::exec(std::vector<std::string> cmd)
{
    _cmd = cvector(cmd);
    std::string path = _cmd[0];
    path = "/bin/" + path;
    if (execve(path.c_str(), _cmd, _env) == -1)
        throw execveException("Command not found");
}
