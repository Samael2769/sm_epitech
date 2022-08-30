/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_shell
*/

#ifndef SM_SHELL_HPP_
#define SM_SHELL_HPP_

#include <iostream>
#include <vector>
#include <string>

class sm_shell {
    public:
        sm_shell();
        ~sm_shell();
    protected:
    private:
        std::vector<std::string> _env;
};

#endif /* !SM_SHELL_HPP_ */
