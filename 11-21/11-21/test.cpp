#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
class cmp
{
public:
    bool operator()(ListNode* node1, ListNode* node2)
    {
        return node1->val > node2->val;
    }
};
//合并多个链表
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
    ListNode* newHead = new ListNode();
    ListNode* newTail = newHead;
    for (int i = 0; i < n; ++i)
    {
        if (lists[i]) heap.push(lists[i]);
    }
    while (!heap.empty())
    {
        ListNode* tmp = heap.top();
        newTail->next = tmp;
        tmp = tmp->next;
        newTail = newTail->next;
        newTail->next = nullptr;
        heap.pop();
        if (tmp) heap.push(tmp);
    }
    return newHead->next;
}
//k个一组翻转链表
ListNode* reverseKGroup(ListNode* head, int k) {
    int n = 0;
    ListNode* cur = head;
    while (cur)
    {
        n++;
        cur = cur->next;
    }
    n = n / k;
    cur = head;
    ListNode* newHead = new ListNode();
    ListNode* prev = newHead;
    ListNode* tmp = nullptr;
    for (int i = 0; i < n; ++i)
    {
        tmp = cur;
        for (int j = 0; j < k; ++j)
        {
            ListNode* next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }
        prev = tmp;
    }
    prev->next = cur;
    return newHead->next;
}
//环绕字符串中唯一的子字符串
int findSubstringInWraproundString(string s) {
    int n = s.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
        if ((s[i] == s[i - 1] + 1) || (s[i] == 'a' && s[i - 1] == 'z')) dp[i] += dp[i - 1];
    vector<int> arr(26);
    for (int i = 0; i < n; ++i)
    {
        arr[s[i] - 'a'] = max(arr[s[i] - 'a'], dp[i]);
    }
    int sum = 0;
    for (auto e : arr) sum += e;
    return sum;
}
//最长递增子序列
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
//摆动序列
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n, 1);
    vector<int> g(n, 1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j]) f[i] = max(f[i], g[j] + 1);
            if (nums[i] < nums[j]) g[i] = max(g[i], f[j] + 1);
        }
    }
    return max(*max_element(f.begin(), f.end()), *max_element(g.begin(), g.end()));
}
int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    reverseKGroup(node1, 2);
	return 0;
}