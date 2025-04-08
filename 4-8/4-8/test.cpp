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
//�������
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* newHead = new ListNode();
    ListNode* prev = nullptr;
    ListNode* cur = newHead;
    int next = 0;
    while (l1 && l2)
    {
        ListNode* newNode = new ListNode();
        int tmp = l1->val + l2->val + next;
        next = tmp / 10;
        cur->val = tmp % 10;
        l1 = l1->next;
        l2 = l2->next;
        cur->next = newNode;
        prev = cur;
        cur = cur->next;
    }
    while (l1)
    {
        ListNode* newNode = new ListNode();
        int tmp = l1->val + next;
        next = tmp / 10;
        cur->val = tmp % 10;
        l1 = l1->next;
        cur->next = newNode;
        prev = cur;
        cur = cur->next;
    }
    while (l2)
    {
        ListNode* newNode = new ListNode();
        int tmp = l2->val + next;
        next = tmp / 10;
        cur->val = tmp % 10;
        l2 = l2->next;
        cur->next = newNode;
        prev = cur;
        cur = cur->next;
    }
    if (next)
    {
        cur->val = 1;
        return newHead;
    }
    delete cur;
    prev->next = nullptr;

    return newHead;
}
//�������������еĽڵ�  �ݹ��
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* tmp = head;
    ListNode* next = head->next;
    tmp->next = swapPairs(next->next);
    next->next = tmp;
    return next;
}
//��������
void reorderList(ListNode* head) {
    if (head->next == nullptr) return;
    ListNode* fast = head->next->next;
    ListNode* slow = head->next;
    ListNode* prev = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        prev = prev->next;
    }
    prev->next = nullptr;
    ListNode* newHead = new ListNode();
    while (slow)
    {
        ListNode* tmp = slow;
        slow = slow->next;
        tmp->next = newHead->next;
        newHead->next = tmp;
    }
    ListNode* l2 = newHead->next;
    ListNode* l1 = head;
    newHead->next = nullptr;
    ListNode* cur = newHead;
    while (l1 && l2)
    {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        l1 = l1->next;
        l2 = l2->next;
        cur->next = tmp1;
        tmp1->next = tmp2;
        cur = tmp2;
    }
    head = newHead->next;
    delete newHead;
}
struct cmp {
    bool operator()(ListNode* l1, ListNode* l2)
    {
        return l1->val > l2->val;
    }
};
//�ǳ��ǳ��� ʹ�öѽ��
//�ϲ�k����������  ʹ��С����
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* newHead = new ListNode();
    priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (lists[i])
            heap.push(lists[i]);
    }
    //��ѽ�����
    ListNode* cur = newHead;
    while (!heap.empty())
    {
        ListNode* t = heap.top();
        heap.pop();
        if (t->next) heap.push(t->next);
        cur->next = t;
        t->next = nullptr;
        cur = cur->next;
    }
    cur = newHead->next;
    delete newHead;
    return cur;
}
int main()
{
	return 0;
}