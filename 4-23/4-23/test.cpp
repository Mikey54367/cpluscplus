#include<iostream>
#include<string>
using namespace std;
//最长回文串
int longestPalindrome(string s) {
    int arr[256] = { 0 };
    for (int i = 0; i < s.size(); ++i)
    {
        ++arr[s[i]];
    }
    int ret = 0;
    int flag = 0;
    for (int i = 0; i < 256; ++i)
    {
        if (arr[i] % 2)
        {
            ret += arr[i] - 1;
            flag = 1;
        }
        else
            ret += arr[i];
    }
    ret += flag;
    return ret;
}
int main()
{
	return 0;
}