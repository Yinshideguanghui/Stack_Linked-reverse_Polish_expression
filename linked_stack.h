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
	//���캯��
	Stack(Node <Stack_entry>* new_top = NULL) :top_node(new_top) {}	//�����޲�����ڵ�
	Stack(const Stack& original);									//����ջ
	//��������
	~Stack();
	//��������
	bool empty() const;
	Error_code pop();
	Error_code push(const Stack_entry& item);
	Error_code top(Stack_entry& item) const;
	//��ȫ��ʩ�������ظ�ֵ�����
	void operator =(const Stack& original);
protected:
	Node <Stack_entry>* top_node;
};