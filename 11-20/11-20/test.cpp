#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
//两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
    ListNode* prev = new ListNode();
    ListNode* newHead = prev;
    prev->next = head;
    ListNode* cur = head;
    ListNode* next;
    ListNode* nNext;
    while (cur && cur->next)
    {
        next = cur->next;
        nNext = next->next;
        prev->next = next;
        cur->next = nNext;
        next->next = cur;
        prev = cur;
        cur = nNext;
    }
    return newHead->next;
}
//重排链表
void reorderList(ListNode* head) {
    ListNode* slow = head; ListNode* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* newHead = new ListNode();
    ListNode* mid = slow;
    while (slow)
    {
        ListNode* next = slow->next;
        slow->next = newHead->next;
        newHead->next = slow;
        slow = next;
    }
    ListNode* cur1 = head; ListNode* cur2 = newHead->next;
    ListNode* prev = new ListNode();
    prev->next = head;
    ListNode* tail = prev;
    int flag = 1;
    while (cur1 != mid && cur2)
    {
        if (flag)
        {
            tail->next = cur1;
            cur1 = cur1->next;
            tail = tail->next;
            tail->next = nullptr;
            flag = 0;
        }
        else
        {
            tail->next = cur2;
            cur2 = cur2->next;
            tail = tail->next;
            tail->next = nullptr;
            flag = 1;
        }
    }
    while (cur2)
    {
        tail->next = cur2;
        cur2 = cur2->next;
        tail = tail->next;
        tail->next = nullptr;
    }
}
//多个链表排序
ListNode* mergeKLists(vector<ListNode*>& lists) {

    int n = lists.size();
    if (n == 0)
        return nullptr;
    for (int j = 1; j < n; j *= 2)
    {
        for (int i = 0; i + j < n; i += 2 * j)
        {
            ListNode* newHead = new ListNode();
            ListNode* newTail = newHead;
            ListNode* cur1 = lists[i];
            ListNode* cur2 = lists[i + j];

            while (cur1 && cur2)
            {
                if (cur1->val <= cur2->val)
                {

                    newTail->next = cur1;
                    cur1 = cur1->next;
                    newTail = newTail->next;
                    newTail->next = nullptr;
                }
                else
                {
                    newTail->next = cur2;
                    cur2 = cur2->next;
                    newTail = newTail->next;
                    newTail->next = nullptr;
                }
            }
            while (cur1)
            {
                newTail->next = cur1;
                cur1 = cur1->next;
                newTail = newTail->next;
                newTail->next = nullptr;
            }
            while (cur2)
            {
                newTail->next = cur2;
                cur2 = cur2->next;
                newTail = newTail->next;
                newTail->next = nullptr;
            }
            lists[i] = newHead->next;
            delete newHead;
            lists[i + j] = nullptr;
        }
    }
    return lists[0];
}
int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(5);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);
    ListNode* node7 = new ListNode(2);
    ListNode* node8 = new ListNode(6);
    /*node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    node5->next = node6;
    node7->next = node8;*/
    vector<ListNode*> v{ node1, node2 };
    mergeKLists(v);
	return 0;
}