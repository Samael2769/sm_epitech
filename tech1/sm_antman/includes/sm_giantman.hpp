/**
 * @ Author: Samael
 * @ Create Time: 2023-04-11 07:09:19
 * @ Modified by: Samael
 * @ Modified time: 2023-04-28 05:47:14
 * @ Description:
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <regex>

class sm_giantman {
    public:
        sm_giantman(std::string path, int type);
        ~sm_giantman();
        void read_file();
        void read_file2();
        void mapping(std::string pattern, int key);
        std::string decompress(const std::string &str);
    private:
        std::string path;
        int type;
        std::map<int, int> dict;
};