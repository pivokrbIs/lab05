#include "header.hpp"

float mean(const std::vector<unsigned>& arr)
{
    float suma = 0;
    for (int i = 0;i < arr.size();i++) suma += arr[i];
    return suma/arr.size();
}

bool is_one_negative(const std::vector<unsigned>& arr)
{
    bool flag = false;
    for (int i = 0;i < arr.size();i++) if (arr[i] == 2) {flag = true; break;}
    return flag;
}

bool is_all_exc(const std::vector<unsigned>& arr)
{
    bool flag = true;
    for (int i = 0;i < arr.size();i++) if (arr[i] != 5) {flag = false; break;}
    return flag;
}