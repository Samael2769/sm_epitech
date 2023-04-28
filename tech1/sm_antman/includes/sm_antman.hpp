/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_antman
*/

#ifndef SM_ANTMAN_HPP_
#define SM_ANTMAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class sm_antman {
    public:
        sm_antman(std::string path, int type);
        ~sm_antman();
        void read_file();
        void read_file2();
        std::string compress(const std::string &str);
    protected:
    private:
        std::string _path;
        std::vector<std::string> _compressed_file;
        std::map<std::string, std::string> _dictionary;
};

#endif /* !SM_ANTMAN_HPP_ */
