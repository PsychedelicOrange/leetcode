#include <iostream>
#include <vector>
#include <unordered_map>
int main()
{
    std::vector<int> doubled{0, 0, 1, 2, 1, 2};
    std::unordered_map<int, int> freq;
    for (auto i : doubled)
    {
        auto given = freq.insert(std::pair<int, int>(i, 0));
        given.first->second++;
        if (given.first->second > 2 )
        {
            std::cout << " empty array";
        }
    }
    for(auto i : freq)
    {
        if(i.second != 2)
        {
            std::cout << " empty array";
        }
    }
}