/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_shell
*/

#ifndef SM_SHELL_HPP_
#define SM_SHELL_HPP_

#include <iostream>
#include "Fork.hpp"
#include "Execve.hpp"
#include <map>

typedef struct data_s {
    std::vector<std::string> cmd;
    std::vector<std::string> env;
} data_t;

class sm_shell {
    public:
        sm_shell(char **env);
        ~sm_shell();
        void run();
        bool Builtins();
        bool env();
        bool setenv();
        bool unsetenv();
        bool cd();
        void checkStatus(int status);
    protected:
    private:
        Fork _fork;
        std::vector<std::string> _env;
        std::vector<std::string> _cmd;
        std::map<std::string, bool (sm_shell::*)(void)> _builtins;
        data_t *_data;
        int _status;
};

#endif /* !SM_SHELL_HPP_ */
