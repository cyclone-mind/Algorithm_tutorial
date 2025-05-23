

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummyhead = new ListNode();
    dummyhead->next = head;
    ListNode *cur = dummyhead;
    while(cur->next!=nullptr){
        if(cur->next->val == val){
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }else{
            cur = cur->next;
        }
    }
    head = dummyhead->next;
    delete dummyhead;
    return head;
}

int main(){
    
}
