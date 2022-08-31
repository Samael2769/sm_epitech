/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Execve
*/

#include "Execve.hpp"
#include <iostream>
#include <sstream>

static std::vector<std::string> split(std::string str, char delim)
{
    std::vector<std::string> res;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delim))
        res.push_back(token);
    return res;
}

Execve::Execve(std::vector<std::string> env)
{
    _env = cvector(env);
    std::string path_str = "PATH=/usr/bin:/bin";
    for (int i = 0; _env[i]; ++i) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=') {
            path_str = env[i].substr(5, env[i].size());
            break;
        }
    }
    _paths = split(path_str, ':');
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
    std::string path = "./" + cmd[0];

    if (access(path.c_str(), F_OK) == 0) {
        if (execve(path.c_str(), _cmd, _env) == -1)
            throw execveException("execve failed");
        return;
    } else {
        for (int i = 0; i < _paths.size(); i++) {
            path = _paths[i] + "/" + _cmd[0];
            if (access(path.c_str(), F_OK) == 0) {
                if (execve(path.c_str(), _cmd, _env) == -1)
                    throw execveException("execve failed");
                return;
            }
        }
    }
    throw execveException("Command not found");
}
