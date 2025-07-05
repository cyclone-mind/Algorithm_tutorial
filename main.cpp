#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 链表相交问题：找到两个链表的交点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 特殊情况处理
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    int size_A = 0;
    int size_B = 0;
    ListNode *cur_A = headA;
    ListNode *cur_B = headB;

    // 计算链表A的长度
    while (cur_A) {
        size_A++;
        cur_A = cur_A->next;
    }

    // 计算链表B的长度
    while (cur_B) {
        size_B++;
        cur_B = cur_B->next;
    }

    // 重新初始化指针
    cur_A = headA;
    cur_B = headB;

    // 让长链表的指针先移动，使两个指针到尾部的距离相等
    if (size_A >= size_B) {
        int diff = size_A - size_B;
        while (diff--) {
            cur_A = cur_A->next;
        }
    } else {
        int diff = size_B - size_A;
        while (diff--) {
            cur_B = cur_B->next;
        }
    }

    // 同时移动两个指针，直到找到交点或到达链表尾部
    while (cur_A != nullptr && cur_B != nullptr) {
        if (cur_A == cur_B) {
            return cur_A; // 找到交点
        }
        cur_A = cur_A->next;
        cur_B = cur_B->next;
    }

    return nullptr; // 没有交点
}

int main() {
    // 测试代码可以在这里添加
    return 0;
}