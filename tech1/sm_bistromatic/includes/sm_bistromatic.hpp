/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_bistromatic
*/

#ifndef SM_BISTROMATIC_HPP_
#define SM_BISTROMATIC_HPP_

#include <string>
#include <vector>
#include <algorithm>

//CLASS
class sm_bistromatic {
    public:
        sm_bistromatic(int s, std::string b1, std::string b2): size_read(s), nb_base(b1), op_base(b2)
        {}
        ~sm_bistromatic() {}
        int size_read;
        std::string nb_base;
        std::string op_base;
        std::string calc;
    protected:
    private:
};

//ALGO
void fillZeros(std::string &nb1, std::string &nb2);
int findBiggest(std::string &nb1, std::string &nb2);
void deleteZeros(std::string &nb);

//CALCULATORS
std::string infin_add(std::string nb1, std::string nb2);
std::string infin_sub(std::string nb1, std::string nb2);
std::string infin_mult(std::string s1, std::string s2);
std::string infin_div(std::string nb1, std::string nb2);

#endif /* !SM_BISTROMATIC_HPP_ */
