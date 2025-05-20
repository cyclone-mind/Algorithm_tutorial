
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *p) : val(x), next(p) {};
};

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur)
    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main()
{
}
