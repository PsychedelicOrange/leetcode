#include <iostream>
#include <vector>
using namespace std;
int maxMoney=0;
vector<int>money;
vector<int>maxp;
int ifpick(int k)
{
    cout << "picking "<<k<<"\n";
    if(k ==-1 )
    {
        return 0;
    }
    else if(k ==0 )
    {
        return money[0];
    }
    else if (maxp[k]==-1)
    {
        int val = max(ifpick(k-2)+money[k],ifpick(k-1));
        maxp[k] = val;
        return val;
    }
    else{
        return maxp[k];
    }
}
int run(vector<int>&nums)
{
    money = nums;
    maxp = vector<int>(nums.size(),-1);
    maxp[0] = money [0];
    for(int i = nums.size() - 1; i >=0; i--)
    {
        ifpick(i);
    }
    for(int i = 0; i < maxp.size();i++)
    {
        cout << maxp[i]<<" ";
        if(maxp[i] > maxMoney)
        {
            maxMoney = maxp[i];
        }
    }
    
    return maxMoney;
}
int main()
{
vector <int> nums = {1,2,3,1};
cout<< "answer"<< run(nums);   
}