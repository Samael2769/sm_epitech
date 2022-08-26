/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_ls
*/

#ifndef SM_LS_HPP_
#define SM_LS_HPP_

#include <iostream>
#include <string>
#include <vector>

class sm_ls {
    public:
        sm_ls();
        ~sm_ls();
        void run();
        void add_path(std::string path) {
            this->paths.push_back(path);
        }
        void add_opt(std::string opt) {
            opts += opt;
        }
        void opt_remove(std::string opt) {
            opts.erase(opts.find(opt), 1);
        }
        void display_long(std::string & path);
        void display_normal(std::string & path);
        void display_recursive(std::string & path);
    protected:
    private:
        std::vector<std::string> paths;
        std::string opts;
};

#endif /* !SM_LS_HPP_ */
