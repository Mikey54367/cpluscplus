#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_set<char> hash;
    int left = 0; int right = 0;
    int n = s.size();
    int ret = 0;
    while (right < n)
    {
        if (hash.count(s[right]))
        {
            hash.erase(s[left]);
            ret = max(ret, right - left);
            left++;
        }
        else
        {
            hash.insert(s[right]);
            right++;
        }
    }
    ret = max(ret, right - left);
    return ret;
}
int main()
{
	return 0;
}