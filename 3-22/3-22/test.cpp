#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
//找出字符串中所有字母异位词
bool compare(int* a, int* b)
{
    for (int i = 0; i < 26; ++i)
    {
        if (a[i] != b[i]) return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p) {

    int s1[26] = { 0 };
    int p1[26] = { 0 };
    vector<int> ret;
    if (p.size() > s.size()) return ret;
    int n = p.size();
    for (int i = 0; i < n; ++i)
    {
        p1[p[i] - 'a']++;
    }
    int left = 0;
    int right = 0;
    while (right < n)
    {
        s1[s[right++] - 'a']++;
    }
    while (right < s.size())
    {
        if (compare(s1, p1)) ret.push_back(left);
        s1[s[right++] - 'a']++;
        s1[s[left++] - 'a']--;
    }
    if (compare(s1, p1)) ret.push_back(left);
    return ret;
}
//串联所有单词的字串
bool compare(unordered_map<string, int> hash1,
    unordered_map<string, int> hash2) {
    for (auto& e : hash1) {
        if (e.second != hash2[e.first])
            return false;
    }
    return true;
}
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    if (s.size() < words.size() * words[0].size())
        return ret;
    int n = words.size();
    unordered_map<string, int> hash_words;
    for (auto& e : words) {
        hash_words[e]++;
    }
    int step = words[0].size();
    for (int i = 0; i < step; ++i) {
        unordered_map<string, int> hash_s;
        int left = i;
        int right = i;
        while (right < n * step) {
            hash_s[s.substr(right, step)]++;
            right += step;
        }
        while (right < s.size()) {
            if (compare(hash_s, hash_words))
                ret.push_back(left);
            // hash_s.erase(s.substr(left,step));
            if (--hash_s[s.substr(left, step)] == 0)
                hash_s.erase(s.substr(left, step));
            left += step;
            hash_s[s.substr(right, step)]++;
            right += step;
        }
        if (compare(hash_s, hash_words))
            ret.push_back(left);
    }

    return ret;
}
int main()
{
    string s("wordgoodgoodgoodbestword");
    vector<string> vs{ "word","good","best","good" };
    findSubstring(s, vs);
	return 0;
}