/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Fork
*/

#include "Fork.hpp"
#include <unistd.h>
#include <sys/wait.h>

Fork::Fork(void * data, int (*func)(void *), bool isWait)
{
    _data = data;
    _func = func;
    _isWait = isWait;
}

Fork::~Fork()
{
}

void Fork::process()
{
    pid_t pid = fork();
    int status = 0;

    if (pid == 0) {
        exit(_func(_data));
    } else if (pid < 0) {
        throw fork_exception("Fork failed");
    } else if (_isWait) {
        wait(&status);
        _status = status;
    }
}