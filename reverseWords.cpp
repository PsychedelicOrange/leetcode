#include <iostream>
#include <string>
using namespace std;
string reverseWords(string s) {
        int i =0,begin,end;
        while(i<s.size())
        {
            cout << i;
            begin = i;
            while(s[i+1]!=' ' && (i + 1  < s.size() -1) )
            {
                i++;
            }
            end = i;
            while(begin<end)
            {
                swap(s[begin],s[end]);
            }
            i+=2;
        }
        return s;
    }
int main()
{
    string s = "Hello Moto PLs ans!";
    cout << reverseWords(s);
    return 0;
}