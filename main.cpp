#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Dog{
	public:
	void Bark(){
		std::cout<< "aoao" << std::endl;
	}
};


int main()
{
	Dog * dog1 = new Dog();
	dog1->Bark();
	delete dog1;  // 修正了删除语法，直接使用 delete 操作符

	const char* str1 = "Hello, World!";
	str1[2] = "o";


}