#include <stack>
/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false

*/

class MyQueue{
    public:
    std::stack<int> stIn;
    std::stack<int> stOut;

    MyQueue(){};
    void push(int num){
        stIn.push(num);
    }
    int pop(){
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    int peek(){
        int result = this->pop(); 
        // 如果不借助写好的pop函数，直接使用stOut.top()的话需要考虑stOut为空的情况。
        /*
        例如这样
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        */
        stOut.push(result);
        return result;
    }
    bool empty(){
        return stIn.empty() && stOut.empty();
    }
};

int main(){}