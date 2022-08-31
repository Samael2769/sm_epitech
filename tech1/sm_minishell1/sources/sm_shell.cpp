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
    _builtins["env"] = &sm_shell::env;
    _builtins["setenv"] = &sm_shell::setenv;
    _builtins["unsetenv"] = &sm_shell::unsetenv;
    _builtins["cd"] = &sm_shell::cd;
    _status = 0;
}

sm_shell::~sm_shell()
{
    
}

bool sm_shell::env()
{
    for (int i = 0; i < _env.size(); i++) {
        std::cout << _env[i] << std::endl;
    }
    return true;
}

bool sm_shell::setenv()
{
    std::string var = _cmd[1];
    std::string value = _cmd[2];
    std::string new_var = var + "=" + value;
    if (_cmd.size() != 3) {
        std::cerr << "setenv: Too many arguments." << std::endl;
        _status = 1;
    }
    for (int i = 0; i < _env.size(); i++) {
        if (_env[i].substr(0, var.size()) == var) {
            _env[i] = new_var;
            return true;
        }
    }
    _env.push_back(new_var);
    return true;
}

bool sm_shell::unsetenv()
{
    if (_cmd.size() != 2) {
        std::cerr << "unsetenv: Too many arguments." << std::endl;
        _status = 1;
    }
    for (int j = 1; j < _cmd.size(); j++) {
        for (int i = 0; i < _env.size(); i++) {
            if (_env[i].substr(0, _cmd[j].size()) == _cmd[j]) {
                _env.erase(_env.begin() + i);
            }
        }
    }
    return true;
}

bool sm_shell::cd()
{
    if (_cmd.size() == 1) {
        chdir("/");
    } else {
        if (chdir(_cmd[1].c_str()) == -1) {
            std::cerr << "cd: No such file or directory." << std::endl;
            _status = 1;
        }
    }
    return true;
}

std::vector<std::string> split(std::string str, char delim)
{
    std::vector<std::string> res;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delim))
        res.push_back(token);
    return res;
}

bool sm_shell::Builtins()
{
    if (_builtins.find(_cmd[0]) != _builtins.end()) {
        (this->*_builtins[_cmd[0]])();
        return true;
    }
    return false;
}

void sm_shell::checkStatus(int status)
{
    if (WIFEXITED(status)) {
        _status = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        _status = WTERMSIG(status);
    } else if (WIFSTOPPED(status)) {
        _status = WSTOPSIG(status);
    }
}

void sm_shell::run()
{

    while(true) {
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line) || line == "exit")
            exit(_status);
        _cmd = split(line, ' ');
        _data = new data_t {_cmd, _env};
        _fork.setData((void*)_data);
        if (Builtins() == false) {
            _fork.process();
            checkStatus(_fork.getStatus());
        }
        _cmd.clear();
    }
}