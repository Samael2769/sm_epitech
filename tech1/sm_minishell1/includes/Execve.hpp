/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Execve
*/

#ifndef EXECVE_HPP_
#define EXECVE_HPP_

#include <unistd.h>
#include <vector>
#include <cstring>
#include <string>
#include <exception>

class Execve {
    public:
        Execve(std::vector<std::string> env);
        ~Execve();
        class execveException : public std::exception {
            public:
                execveException(const std::string &message) : _message(message) {}
                const char *what() const noexcept override { return _message.c_str(); }
            private:
                std::string _message;
        };
        void exec(std::vector<std::string> cmd);
        char ** cvector(std::vector<std::string> vec);
    protected:
    private:
        char **_env;
        char **_cmd;
        std::vector<std::string> _paths;
};

#endif /* !EXECVE_HPP_ */
