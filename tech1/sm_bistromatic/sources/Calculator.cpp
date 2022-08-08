/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Calculator
*/

#include "Calculator.hpp"
#include <exception>

Calculator::Calculator(std::string &a)
{
    calc = a;
}

Calculator::~Calculator()
{
}

std::string Calculator::do_op()
{
    std::string res = mod("17", "2");
    return res;
}

void Calculator::convertBase(std::string base_nb, std::string base_op)
{
    std::string trueBase = "0123456789";
    std::string trueBaseOp = "+-*/%";

    int trueVal = 0;
    for (int i = 0; i < calc.length(); i++) {
        trueVal = 0;
        for (int j = 0; j < base_op.length(); j++) {
            if (calc[i] == base_op[j]) {
                calc[i] = trueBaseOp[j];
                trueVal = 1;
                break;
            }
        }
        if (trueVal == 1)
            continue;
        for (int j = 0; j < base_nb.length(); j++) {
            if (calc[i] == base_nb[j]) {
                calc[i] = trueBase[j];
                trueVal = 1;
                break;
            }
        }
        if (trueVal == 0)
            throw std::logic_error("Error: Value not in base");
    }
}

static bool isSmaller(std::string a, std::string b)
{
    int n1 = a.length();
    int n2 = b.length();

    if (n1 < n2)
        return true;
    if (n1 > n2)
        return false;
    for (int i = 0; i < n1; i++) {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }
    return false;
}

std::string Calculator::add(const std::string &a, const std::string &b)
{
    std::string s1 = a;
    std::string s2 = b;
    if (s1.length() > s2.length())
        std::swap(s1, s2);
    std::string res = "";
    int n1 = s1.length();
    int n2 = s2.length();

    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    int carry = 0;
    for (int i = 0; i < n1; ++i) {
        int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; ++i) {
        int sum = (s2[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        res.push_back(carry + '0');
    std::reverse(res.begin(), res.end());
    return res;
}

std::string Calculator::sub(const std::string &a, const std::string &b)
{
    std::string s1 = a;
    std::string s2 = b;
    std::string res = "";

    int isSmall = 0;
    if (isSmaller(s1, s2)) {
        std::swap(s1, s2);
        isSmall = 1;
    }
    int n1 = s1.length();
    int n2 = s2.length();
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    int carry = 0;

    for (int i = 0; i < n2; ++i) {
        int sub = (s1[i] - '0') - (s2[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;
        res.push_back(sub + '0');
    }
    for (int i = n2; i < n1; ++i) {
        int sub = (s1[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;
        res.push_back(sub + '0');
    }
    if (isSmall)
        res.push_back('-');
    std::reverse(res.begin(), res.end());
    return res;
}

std::string Calculator::mul(const std::string &a, const std::string &b)
{
    std::string s1 = a;
    std::string s2 = b;
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 == 0 || len2 == 0)
        return "0";
    std::vector<int> res(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = len1 - 1; i >= 0; --i) {
        int carry = 0;
        int n1 = s1[i] - '0';
        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; --j) {
            int n2 = s2[j] - '0';
            int sum = n1 * n2 + res[i_n1 + i_n2] + carry;
            carry = sum / 10;
            res[i_n1 + i_n2] = sum % 10;
            ++i_n2;
        }
        if (carry > 0)
            res[i_n1 + i_n2] += carry;
        ++i_n1;
    }
    int i = res.size() - 1;
    while (i >= 0 && res[i] == 0)
        --i;
    if (i == -1)
        return "0";
    std::string s = "";
    while (i >= 0)
        s += std::to_string(res[i--]);
    return s;
}

std::string Calculator::div(const std::string &a, const std::string &b)
{
    std::string s1 = a;
    int s2 = std::stoi(b);
    std::string res = "";
    int idx = 0;
    int tmp = s1[idx] - '0';
    while (tmp < s2)
        tmp = tmp * 10 + (s1[++idx] - '0');
    while(s1.size() > idx) {
        res += (tmp / s2) + '0';
        tmp = (tmp % s2) * 10 + s1[++idx] - '0';
    }
    if (res.empty())
        res = "0";
    return res;
}

std::string Calculator::mod(const std::string &a, const std::string &b)
{
    std::string s1 = a;
    int s2 = std::stoi(b);
    int res = 0;
    for (int i = 0; i < s1.length(); ++i) {
        res = (res * 10 + (s1[i] - '0')) % s2;
    }
    return std::to_string(res);
}