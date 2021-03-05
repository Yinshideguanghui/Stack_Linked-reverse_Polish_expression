#pragma once
#include<iostream>
template <typename Node_entry>
struct Node {
	Node_entry entry;
	Node* next;

	Node() {}
	Node(Node_entry item, Node* add_on = NULL)
	{
		entry = item;
		next = add_on;
	}
};


enum Error_code { success, overflow, underflow };

template <typename Stack_entry>
class Stack
{
public:
	//构造函数
	Stack(Node <Stack_entry>* new_top = NULL) :top_node(new_top) {}	//来自无参数或节点
	Stack(const Stack& original);									//来自栈
	//析构函数
	~Stack();
	//基本操作
	bool empty() const;
	Error_code pop();
	Error_code push(const Stack_entry& item);
	Error_code top(Stack_entry& item) const;
	//安全措施——重载赋值运算符
	void operator =(const Stack& original);
protected:
	Node <Stack_entry>* top_node;
};