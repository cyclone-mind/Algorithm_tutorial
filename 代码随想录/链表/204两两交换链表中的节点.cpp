#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *p) : val(x), next(p) {};
};

ListNode* swapPairs(ListNode* head) {
   ListNode *dummyhead = new ListNode();
    dummyhead->next = head;
    ListNode *cur = dummyhead;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode *tmp0 = cur->next;          // 第一个节点
        ListNode *tmp1 = cur->next->next;    // 第二个节点

        // 交换 tmp0 和 tmp1
        tmp0->next = tmp1->next;  // 1 -> 3
        tmp1->next = tmp0;        // 2 -> 1
        cur->next = tmp1;         // dummy -> 2

        cur = tmp0;  // 移动到交换后的第二个节点（即原来的第一个节点）
    }
    ListNode *result = dummyhead->next;
    delete dummyhead;
    return result;
}

int main(){

}