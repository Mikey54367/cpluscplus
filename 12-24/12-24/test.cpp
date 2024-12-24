#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
//串联所有单词的子串
bool func(unordered_map<string, int>& hash)
{
    auto it = hash.begin();
    while (it != hash.end())
    {
        if (it->second != 0) return false;
        ++it;
    }
    return true;
}
vector<int> findSubstring(string s, vector<string>& words) {
    int n = words.size();
    int count = 0;
    vector<int> ret;
    int len = words[0].size();
    int k = len;
    unordered_map<string, int> hash1;
    for (auto& e : words)
    {
        hash1[e]++;
    }
    while (k--)
    {
        int left = len - k - 1;
        int right = len - k - 1;
        count = 0;
        unordered_map<string, int> hash = hash1;;
        while (right < s.size())
        {
            hash[s.substr(right, len)]--;
            right += len;
            count++;
            if (count == n && func(hash)) ret.emplace_back(left);
            if (count > n)
            {
                hash[s.substr(left, len)]++;
                count--;
                left += len;
                if (count == n && func(hash)) ret.emplace_back(left);
            }
        }
    }
    return ret;
}
//[蓝桥杯 2024 国 B] 最小字符串
int main1()
{
    int n;
    int m;
    cin >> n >> m;
    string sN;
    cin >> sN;
    string sM;
    cin >> sM;
    sort(sM.begin(), sM.end());
    int j = 0;
    int i = 0;
    string ret;
    while (i < n && j < m)
    {
        if (sM[j] < sN[i]) ret += sM[j++];
        else ret += sN[i++];
    }
    while (i < n)
    {
        ret += sN[i++];
    }
    while(j < m)
    {
        ret += sM[j++];
    }
    cout << ret << endl;
	return 0;
}

