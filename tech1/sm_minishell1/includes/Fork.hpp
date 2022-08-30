/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Fork
*/

#ifndef FORK_HPP_
#define FORK_HPP_

#include <exception>
#include <iostream>
#include <string>

class Fork {
    public:
        class fork_exception : public std::exception {
            public:
                fork_exception(const std::string &message) : _message(message) {}
                const char *what() const noexcept override { return _message.c_str(); }
            private:
                std::string _message;
        };
        Fork(void * data, int (*func)(void *), bool isWait = false);
        ~Fork();
        void process();
        int getStatus() const { return _status; }
        void setData(void *data) { _data = data; }
    protected:
    private:
        void * _data;
        int (*_func)(void *);
        bool _isWait;
        int _status;
};

#endif /* !FORK_HPP_ */
