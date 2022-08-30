/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_shell
*/

#include "sm_shell.hpp"
#include <sstream>

int f_fct(void * data)
{
    data_t *_data = static_cast<data_t *>(data);
    Execve _execve(_data->env);
    try {
        _execve.exec(_data->cmd);
    } catch (Execve::execveException &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

sm_shell::sm_shell(char ** env): _fork((void*)_data, f_fct, true)
{
    for (int i = 0; env[i]; i++) {
        _env.push_back(env[i]);
    }
}

sm_shell::~sm_shell()
{
    
}

static std::vector<std::string> split(std::string str, char delim)
{
    std::vector<std::string> res;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delim))
        res.push_back(token);
    return res;
}

void sm_shell::run()
{

    while(true) {
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line) || line == "exit")
            exit(0);
        _cmd = split(line, ' ');
        _data = new data_t {_cmd, _env};
        _fork.setData((void*)_data);
        _fork.process();
        _cmd.clear();
    }
}