#include <iostream>

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr){};
	ListNode(int x):val(x),next(nullptr){};
	ListNode(int x, ListNode *next): val(x), next(next){};
};

class MyLinkedList{
	private:
	int _size;
	ListNode * _dumyhead;
	public:
	MyLinkedList(){
		_dumyhead = new ListNode();
		_size = 0;
	}
	int get(int index){
		ListNode * cur = _dumyhead;
		while(index--){
			cur = cur->next;
		}
		return cur->val;
	}

}



int main(){

}