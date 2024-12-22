#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//水果成篮
int totalFruit(vector<int>& fruits) {
    if (fruits.size() == 1) return 1;
    int kind1 = fruits[0], kind2 = fruits[1];
    if (kind1 == kind2)
    {
        for (auto e : fruits)
        {
            if (e != kind2)
            {
                kind2 = e;
                break;
            }
        }
    }
    int left = 0, right = 0;
    int ret = 0;
    while (right < fruits.size())
    {
        if (fruits[right] == kind1 || fruits[right] == kind2)
        {
            right++;
            ret = max(ret, right - left);
        }
        else
        {
            kind1 = fruits[right];
            kind2 = fruits[right - 1];
            int tmp = 0;
            while (left < right)
            {
                if (!(fruits[left] == kind1 || fruits[left] == kind2))
                    tmp = left;
                ++left;
            }
            left = tmp + 1;
        }
    }
    return ret;
}
//找到字符串中所有字⺟异位词
class Solution {
public:
    int hash[26];
    bool ifAllZero()
    {
        for (int i = 0; i < 26; ++i)
        {
            if (hash[i] != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;
        for (auto e : p) hash[e - 'a']++;
        int left = 0, right = 0;
        int n = p.size();
        while (right < s.size())
        {
            hash[s[right] - 'a']--;
            right++;
            if (ifAllZero()) ret.emplace_back(left);
            if (right - left > n)
            {
                hash[s[left] - 'a']++;
                left++;
                if (ifAllZero()) ret.emplace_back(left);
            }
        }
        return ret;
    }
};
bool isSpecialYear(int year)
{
    if (year / 1000 == (year % 100 / 10) && year % 10 == year % 1000 / 100 + 1) return true;
    return false;
}
int main()
{
    int year1;
    int year2;
    int year3;
    int year4;
    int year5;
    cin >> year1 >> year2 >> year3 >> year4 >> year5;
    int ret = 0;
    if (isSpecialYear(year1)) ret++;
    if (isSpecialYear(year2)) ret++;
    if (isSpecialYear(year3)) ret++;
    if (isSpecialYear(year4)) ret++;
    if (isSpecialYear(year5)) ret++;
    cout << ret << endl;
	return 0;
}