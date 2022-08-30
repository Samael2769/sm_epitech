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

typedef struct data_s {
    std::vector<std::string> cmd;
    std::vector<std::string> env;
} data_t;

class sm_shell {
    public:
        sm_shell(char **env);
        ~sm_shell();
        void run();
    protected:
    private:
        Fork _fork;
        std::vector<std::string> _env;
        std::vector<std::string> _cmd;
        data_t *_data;
};

#endif /* !SM_SHELL_HPP_ */
