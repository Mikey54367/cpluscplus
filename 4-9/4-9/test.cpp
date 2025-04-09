#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//k个一组翻转链表
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* newHead = new ListNode();
    int n = k;
    ListNode* cur = head;
    while (n--)
    {
        if (cur == nullptr) return head;
        cur = cur->next;
    }
    n = k;
    ListNode* prev = head;
    while (n--)
    {
        cur = head;
        head = head->next;
        cur->next = newHead->next;
        newHead->next = cur;
    }
    prev->next = reverseKGroup(head, k);
    cur = newHead->next;
    delete newHead;
    return cur;
}
//两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    hash[nums[0]] = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (hash.count(target - nums[i]))
        {
            return { i,hash[target - nums[i]] };
        }
        hash[nums[i]] = i;
    }
    return { 1,2 };
}
//判断是否互为字符串重排
bool CheckPermutation(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int arr1[26] = { 0 };
    int arr2[26] = { 0 };
    for (int i = 0; i < s1.size(); ++i)
    {
        arr1[s1[i] - 'a']++;
        arr2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}
//存在重复元素
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (hash.count(nums[i])) return true;
        hash.insert(nums[i]);
    }
    return false;
}
//存在重复元素2
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (hash.count(nums[i]))
        {
            if (abs(i - hash[nums[i]]) <= k) return true;
        }
        hash[nums[i]] = i;
    }
    return false;
}
//字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash;
    for (auto& e : strs)
    {
        string s = e;
        sort(s.begin(), s.end());
        hash[s].emplace_back(move(e));
    }
    vector<vector<string>> ret;
    for (auto& e : hash)
    {
        ret.emplace_back(move(e.second));
    }
    return ret;
}
//最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
    int j = 0;
    string ret;
    char c;
    int n = strs[0].size();
    while (n--)
    {
        for (int i = 0; i < strs.size(); ++i)
        {
            if (i == 0)
                c = strs[i][j];
            if (i == strs.size() - 1)
            {
                if (j >= strs[i].size()) return ret;
                if (strs[i][j] != c) return ret;
                else
                {
                    j++;
                    ret += c;
                }
            }
            else
            {
                if (j >= strs[i].size()) return ret;
                if (strs[i][j] != c) return ret;
            }
        }
    }

    return ret;
}
//最长回文字串
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int lenOfRet = 0;
    int leftOfRet = -1;
    for (int i = n; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (i == j || i + 1 == j) dp[i][j] = true;
                else dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j])
            {
                if (j - i + 1 > lenOfRet)
                {
                    lenOfRet = j - i + 1;
                    leftOfRet = i;
                }
            }
        }
    }
    return s.substr(leftOfRet, lenOfRet);
}
//二进制求和
string addBinary(string a, string b) {
    string ret;
    int cur1 = a.size()-1;
    int cur2 = b.size()-1;
    int t = 0;
    while (cur1 >= 0 || cur2 >= 0 || t)
    {
        if (cur1 >= 0)
            t += a[cur1--] - '0';
        if (cur2 >= 0)
            t += b[cur2--] - '0';
        ret += (t % 2 + '0');
        t /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int main()
{
    addBinary("11", "1");
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);
    reverseKGroup(head, 2);
	return 0;
}