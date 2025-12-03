#ifndef LAB05_HEADER_HPP
#define LAB05_HEADER_HPP

#endif //LAB05_HEADER_HPP

#include <iostream>
#include "bits/stdc++.h"

float mean(const std::vector<unsigned >&);
bool is_one_negative(const std::vector<unsigned>&);
bool is_all_exc(const std::vector<unsigned>&);

struct Student
{
    std::string Name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
};

void SortByName(std::vector<Student>&);
void SortByRating(std::vector<Student>&);
size_t CountTwoness(const std::vector<Student>&);
size_t CountExcellent(const std::vector<Student>&);
std::vector<Student> VectorMathExcellent(const std::vector<Student>&);
std::vector<std::string> GroupsId(const std::vector<Student>&);

struct Group
{
    std::string Id;
    std::vector<Student> Students;
};

std::vector<Group> Groups(const std::vector<Student>&);