/*
题意：

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *p) : val(x), next(p) {};
};

class LinkedList
{
private:
    ListNode *_dummyhead; // 👈 在这里声明 _dummyhead
    int _size;

public:
    LinkedList() : _dummyhead(new ListNode(0)), _size(0) {};

    int get(int index)
    {
        // get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
        if (index < 0 || index > _size)
        {
            return -1;
        }
        ListNode *cur = _dummyhead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    // addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    void addAtHead(int val)
    {
        ListNode *newnode = new ListNode(val);
        newnode->next = _dummyhead->next;
        _dummyhead->next = newnode;
        _size++;
    }
    // addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
    void addAtTail(int val)
    {
        ListNode *newnode = new ListNode(val);
        ListNode *cur = _dummyhead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newnode;
        _size++;
    }
    // addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    void addAtIndex(int index, int val)
    {

        if (index < 0)
        {
            addAtHead(val);
        }
        if (index > _size)
        {
            return;
        }
        ListNode *newnode = new ListNode(val);
        ListNode *cur = _dummyhead;
        while (index--)
        {
            cur = cur->next;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        _size++;
    }
    // deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

    void deleteAtIndex(int index)
    {
        if (index > _size || index < 0)
        {
            return;
        }
        ListNode *cur = _dummyhead;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }
    // 打印链表
    void printLinkedList()
    {
        ListNode *cur = _dummyhead;
        while (cur->next != nullptr)
        {
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList list = LinkedList();
    list.addAtHead(3);
    list.addAtHead(4);
    list.addAtHead(5);
    list.printLinkedList();
}
