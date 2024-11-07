#include <iostream>
#include <vector>
int main()
{
    std::vector<int> doubled{0, 0, 1, 2, 1, 2};
    for(auto i : doubled)
        std::cout<<i;
}