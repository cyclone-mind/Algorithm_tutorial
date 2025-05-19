#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *p) : val(x), next(p) {};
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummyhead = new ListNode();
    dummyhead->next = head;
    ListNode *fast = dummyhead;
    ListNode *slow = dummyhead;
    n++;        // 让fast先走n+1步
    while (n--) // 通常leetcode上的n设置都是合法的。
    {
        fast = fast->next;
        //   if (fast == nullptr) {
        //     // 通常leetcode上的n设置都是合法的。但是如果n+1大于链表长度，直接返回原链表，防止出现空指针->next的错误
        //     ListNode* res = dummyhead->next;
        //     delete dummyhead;
        //     return res;
        // }
        // fast = fast->next;
    }
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;
    return dummyhead->next; // 注意需要返回虚拟节点的next才是头节点，如果换成head，删除第一个节点是，head就出现了空指针访问的问题了。
}

/*
 * 方法二：fast先走n步，然后再多走一步
 * 这样slow和fast之间同样保持n+1的距离
 * 这种写法常见于LeetCode讨论区
 */
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode* dummyHead = new ListNode(0);
//     dummyHead->next = head;
//     ListNode* slow = dummyHead;
//     ListNode* fast = dummyHead;
//     while(n-- && fast != NULL) { // 这里的判断是先让fast走到最后一个节点，绝对不能走到null，因为下面要fast->next
//         fast = fast->next;
//     }
//     fast = fast->next; // fast再提前走一步
//     while (fast != NULL) {
//         fast = fast->next;
//         slow = slow->next;
//     }
//     ListNode* tmp = slow->next;
//     slow->next = tmp->next;
//     delete tmp;
//     ListNode* newHead = dummyHead->next;
//     delete dummyHead;
//     return newHead;
// }

// 打印链表的辅助函数
void printList(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        std::cout << cur->val;
        if (cur->next)
            std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main()
{
    // 构造链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode *n5 = new ListNode(5);
    ListNode *n4 = new ListNode(4, n5);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    std::cout << "原链表: ";
    printList(n1);

    // 删除倒数第2个节点（即4）
    ListNode *newHead = removeNthFromEnd(n1, 2);

    std::cout << "删除倒数第2个节点后的链表: ";
    printList(newHead);

    // 记得释放内存
    while (newHead)
    {
        ListNode *tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }
    return 0;
}