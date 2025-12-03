#include "header.hpp"

void SortByName(std::vector<Student>& arr)
{
    for (int i = 0;i < arr.size();i++)
    {
        for (int j = i;j < arr.size();j++)
        {
            if (arr[i].Name > arr[j].Name) std::swap(arr[i], arr[j]);
        }
    }
}

void SortByRating(std::vector<Student>& arr)
{
    for (int i = 0;i < arr.size();i++)
    {
        for (int j = i;j < arr.size();j++)
        {
            if (mean(arr[i].Ratings) < mean(arr[j].Ratings)) std::swap(arr[i], arr[j]);
        }
    }
}

size_t CountTwoness(const std::vector<Student>& arr)
{
    int cnt = 0;
    for (int i = 0;i < arr.size();i++) if (is_one_negative(arr[i].Ratings)) cnt++;
    return cnt;
}

size_t CountExcellent(const std::vector<Student>& arr)
{
    int cnt = 0;
    for (int i = 0;i < arr.size();i++) if (is_all_exc(arr[i].Ratings)) cnt++;
    return cnt;
}

std::vector<Student> VectorMathExcellent(const std::vector<Student>& arr)
{
    std::vector<Student> ans;
    for (int i = 0;i < arr.size();i++)
    {
        auto it = std::find(arr[i].Subjects.begin(), arr[i].Subjects.end(), "Math");
        if (it != arr[i].Subjects.end())
        {
            if (arr[i].Ratings[it - arr[i].Subjects.begin()] == 5) ans.push_back(arr[i]);
        }
    }
    return ans;
}

std::vector<std::string> GroupsId(const std::vector<Student>& arr)
{
    std::vector<std::string> ans;
    std::unordered_set <std::string> t;

    for (int i = 0;i < arr.size();i++) t.insert(arr[i].GroupId);
    std::copy(t.begin(),t.end(), std::back_inserter(ans));

    return ans;
}

std::vector<Group> Groups(const std::vector<Student>& arr)
{
    std::vector<std::string> groupi = GroupsId(arr);
    std::vector<Group> ans(groupi.size());

    for (int i = 0;i < ans.size();i++) ans[i].Id = groupi[i];

    for (int i = 0;i < ans.size();i++)
    {
        for (int j = 0;j < arr.size();j++)
        {
            if (arr[j].GroupId == ans[i].Id) ans[i].Students.push_back(arr[j]);
        }
    }

    return ans;
}