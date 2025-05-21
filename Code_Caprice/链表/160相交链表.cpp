#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *p) : val(x), next(p) {};
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *curA = headA;
    ListNode *curB = headB;
    int sizeA = 0;
    int sizeB = 0;
    while (curA)
    {
        sizeA++;
        curA = curA->next;
    }
    while (curB)
    {
        sizeB++;
        curB = curB->next;
    }
    int dif;
    if (sizeA - sizeB > 0)
    {
        dif = sizeA - sizeB;
        curA = headA;
        curB = headB;
        while (dif--)
        {
            curA = curA->next;
        }
        while (curA)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
    else
    {
        dif = sizeB - sizeA;
        curA = headA;
        curB = headB;
        while (dif--)
        {
            curB = curB->next;
        }
        while (curA)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
}

int main(){return 0;}