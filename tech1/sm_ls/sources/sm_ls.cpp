/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_ls
*/

#include "sm_ls.hpp"
#include <experimental/filesystem>
#include <algorithm>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>

namespace fs = std::experimental::filesystem;

sm_ls::sm_ls()
{
}

sm_ls::~sm_ls()
{
    
}

void sm_ls::run()
{
    if (paths.size() == 0)
        paths.push_back(".");
    for (int i = 0; i < paths.size(); i++) {
        if (paths.size() > 1 || opts.find("R"))
            std::cout << paths[i] << ":" << std::endl;
        if (opts.find('l') != std::string::npos)
            display_long(paths[i]);
        else
            display_normal(paths[i]);
        if (opts.find('R') != std::string::npos)
            display_recursive(paths[i]);
        if (i != paths.size() - 1)
            std::cout << std::endl;
    }
}

static void demo_perms(fs::perms p)
{
     std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
              << " ";
}

static void file_type(fs::file_type t)
{
    if (t == fs::file_type::directory)
        std::cout << "d";
    else if (t == fs::file_type::regular)
        std::cout << "-";
    else if (t == fs::file_type::symlink)
        std::cout << "l";
    else if (t == fs::file_type::block)
        std::cout << "b";
    else if (t == fs::file_type::character)
        std::cout << "c";
    else if (t == fs::file_type::fifo)
        std::cout << "p";
    else if (t == fs::file_type::socket)
        std::cout << "s";
    else if (t == fs::file_type::unknown)
        std::cout << "?";
}

void sm_ls::display_long(std::string & path)
{
    struct stat statbuf;
    struct passwd *pw;
    struct group *gr;
    if (!fs::is_directory(path)) {
        fs::directory_entry p(path);
        file_type(p.status().type());
        demo_perms(fs::status(p).permissions());
        if (stat(p.path().c_str(), &statbuf) == -1)
            throw std::runtime_error("stat error");
        std::cout << statbuf.st_nlink << " ";
        pw = getpwuid(statbuf.st_uid);
        gr = getgrgid(statbuf.st_gid);
        std::cout << pw->pw_name << " " << gr->gr_name << " ";
        std::cout << std::setw(6) << statbuf.st_size << " ";
        std::string date = ctime(&statbuf.st_mtime);
        date.erase(date.end() - 9, date.end());
        date.erase(date.begin(), date.begin() + 4);
        std::cout << std::setw(10) << date << " ";
        std::cout << p.path().filename().string() << std::endl;
        return;
    }
    if (opts.find('a') != std::string::npos) {
        std::vector<std::string> x;
        x.push_back(".");
        x.push_back("..");
        for (int i = 0; i < x.size(); i++) {
            fs::directory_entry p(x[i]);
            file_type(p.status().type());
            demo_perms(fs::status(p).permissions());
            if (stat(p.path().c_str(), &statbuf) == -1)
                throw std::runtime_error("stat error");
            std::cout << statbuf.st_nlink << " ";
            pw = getpwuid(statbuf.st_uid);
            gr = getgrgid(statbuf.st_gid);
            std::cout << pw->pw_name << " " << gr->gr_name << " ";
            std::cout << std::setw(6) << statbuf.st_size << " ";
            std::string date = ctime(&statbuf.st_mtime);
            date.erase(date.end() - 9, date.end());
            date.erase(date.begin(), date.begin() + 4);
            std::cout << std::setw(10) << date << " ";
            std::cout << p.path().filename().string() << std::endl;
        }
    }
    for (auto & p : fs::directory_iterator(path)) {
        file_type(p.status().type());
        demo_perms(fs::status(p).permissions());
        if (stat(p.path().c_str(), &statbuf) == -1)
            throw std::runtime_error("stat error");
        std::cout << statbuf.st_nlink << " ";
        pw = getpwuid(statbuf.st_uid);
        gr = getgrgid(statbuf.st_gid);
        std::cout << pw->pw_name << " " << gr->gr_name << " ";
        std::cout << std::setw(6) << statbuf.st_size << " ";
        std::string date = ctime(&statbuf.st_mtime);
        date.erase(date.end() - 9, date.end());
        date.erase(date.begin(), date.begin() + 4);
        std::cout << std::setw(10) << date << " ";
        std::cout << p.path().filename().string() << std::endl;
    }
}

void sm_ls::display_normal(std::string & path)
{
    if (!fs::is_directory(path)) {
        std::cout << path <<  std::endl;
        return;
    }
    if (opts.find('a') != std::string::npos)
        std::cout << ". " << ".. "; 
    for (auto & p : fs::directory_iterator(path)) {
        std::string name = p.path().filename().string();
        if (name[0] == '.' && opts.find('a') == std::string::npos)
            continue;
        std::cout << name << " ";
    }
    std::cout << std::endl;
}

void sm_ls::display_recursive(std::string & path)
{
    std::vector<std::string> directories;
    for (auto & p : fs::directory_iterator(path)) {
        if (fs::is_directory(p.path()))
            directories.push_back(p.path().string());
    }
    for (int i = 0; i < directories.size(); i++) {
        sm_ls ls;
        ls.add_opt(opts);
        ls.add_path(directories[i]);
        ls.run();
    }
}