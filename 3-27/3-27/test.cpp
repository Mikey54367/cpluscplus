#include<iostream>
#include<vector>
using namespace std;
//丢失的数字
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret ^= nums[i];
        ret ^= i;
    }
    ret ^= n;
    return ret;
}
//两整数之和
int getSum(int a, int b) {
    int tmp = a;
    a = a ^ b;
    b = tmp & b;
    while (b)
    {
        b = b << 1;
        tmp = a;
        a = a ^ b;
        b = tmp & b;
    }
    return a;
}
//汉诺塔问题
void hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n) {
    if (n == 1)
    {
        auto it = A.end();
        --it;
        C.push_back(*it);
        A.pop_back();
        return;
    }
    hanota(A, C, B, n - 1);
    auto it = A.end();
    --it;
    C.push_back(*it);
    A.pop_back();
    hanota(B, A, C, n - 1);
}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    hanota(A, B, C, n);
}
//只出现一次的数字2
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += (nums[j] >> i) & 1;
        }
        sum %= 3;
        ret = ret | (sum << i);
    }
    return ret;
}
//消失的两个数字
vector<int> missingTwo(vector<int>& nums) {
    int n = nums.size();
    int a = 0;
    for (int i = 0; i < n; ++i)
    {
        a ^= nums[i];
    }
    for (int i = 1; i <= n + 2; ++i)
    {
        a ^= i;
    }
    int ret1 = 0;
    int ret2 = 0;
    int i = 0;
    for (; i < 32; ++i)
    {
        if ((a >> i) & 1) break;
    }
    for (int j = 0; j < n; ++j)
    {
        if ((nums[j] >> i) & 1) ret1 ^= nums[j];
        else ret2 ^= nums[j];
    }
    for (int j = 1; j <= n + 2; ++j)
    {
        if ((j >> i) & 1) ret1 ^= j;
        else ret2 ^= j;
    }
    return { ret1,ret2 };
}
//替换所有的问号
string modifyString(string s) {
    int n = s.size();
    if (s[0] == '?')
    {
        if (s[1] == 'a') s[0] = 'b';
        else s[0] = 'a';
    }
    if (s[n - 1] == '?')
    {
        if (s[n - 2] == 'a') s[n - 1] = 'b';
        else s[n - 1] = 'a';
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if (s[i] == '?')
        {
            char c1 = s[i - 1];
            char c2 = s[i + 1];
            char c0 = 'a';
            while (c0 == c1 || c0 == c2)
                c0++;
            s[i] = c0;
        }
    }
    return s;
}
//提莫攻击
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();
    int ret = 0;
    int start = timeSeries[0];
    int end = timeSeries[0] + duration - 1;
    for (int i = 1; i < n; ++i)
    {
        if (timeSeries[i] > end)
        {
            ret += end - start + 1;
            start = timeSeries[i];
            end = timeSeries[i] + duration - 1;
        }
        else
            end = timeSeries[i] + duration - 1;
    }
    ret += end - start + 1;
    return ret;
}
//递归合并两个有序链表
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
//递归翻转链表
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    ListNode* tmp = newHead;
    while (tmp && tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = head;
    head->next = nullptr;
    return newHead;
}
int main()
{
    ListNode l1(1);
    ListNode l2(2);
    l1.next = &l2;
    reverseList(&l1);
    vector<int> v1{ 1,0 };
    vector<int> v2;
    vector<int> v3;
    hanota(v1, v2, v3);
	return 0;
}