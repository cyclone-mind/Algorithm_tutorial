#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *p) : val(x), next(p) {};
};

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) // 如果有环一定走里面，拿到返回值，如果无环，就一定有遍历到null，循环就不执行
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            ListNode *index1 = fast;
            ListNode * index2 = head;
            while (index1!= index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index2;
        }
    }
    return NULL;
    
}

int main(){
    
}