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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur = new ListNode();
    ListNode* head = cur;
    cur->next = head;
    int next = 0;
    while (l1 && l2)
    {
        int sum = l1->val + l2->val + next;
        l1 = l1->next;
        l2 = l2->next;
        next = sum / 10;

        ListNode* newNode = new ListNode(sum % 10);
        cur->next = newNode;
        cur = cur->next;

    }
    while (l1)
    {
        int sum = l1->val + next;
        l1 = l1->next;

        ListNode* newNode = new ListNode(sum % 10);
        cur->next = newNode;
        cur = cur->next;

        next = sum / 10;
    }
    while (l2)
    {
        int sum = l2->val + next;
        l2 = l2->next;

        ListNode* newNode = new ListNode(sum % 10);
        cur->next = newNode;
        cur = cur->next;

        next = sum / 10;
    }
    if (next)
    {
        ListNode* newNode = new ListNode(next);
        cur->next = newNode;
        cur = cur->next;
    }
    return head->next;
}
int main()
{
    return 0;
}