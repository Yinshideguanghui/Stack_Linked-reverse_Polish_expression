#include"linked_stack.h"
#include<iostream>
using namespace std;

template <typename Stack_entry>		//���ƹ��캯��
Stack<Stack_entry>::Stack(const Stack& original)
{
	Node<Stack_entry>* new_copy, * original_node = original.top_node;
	if (original_node == NULL)top_node = NULL;
	else
	{
		top_node = new_copy = new Node<Stack_entry>(original_node->entry);
		while (original_node->next != NULL)
		{
			original_node = original_node->next;
			new_copy->next = new Node<Stack_entry>(original_node->entry);
			new_copy = new_copy->next;
		}
	}
}

template <typename Stack_entry>		//��������
Stack<Stack_entry>::~Stack()
{
	while (!empty())
		pop();
}

template <typename Stack_entry>		//�Ƿ�Ϊ��
bool Stack<Stack_entry>::empty() const
{
	return top_node == NULL;
}

template <typename Stack_entry>		//��ջ
Error_code Stack<Stack_entry>::push(const Stack_entry& item)
{
	Node<Stack_entry>* new_top = new Node<Stack_entry>(item, top_node);
	if (new_top == NULL)return overflow;
	top_node = new_top;
	return success;
}

template <typename Stack_entry>		//��ջ
Error_code Stack<Stack_entry>::pop()
{
	Node<Stack_entry>* old_top = top_node;
	if (top_node == NULL)return underflow;
	top_node = old_top->next;
	delete old_top;
	return success;
}

template <typename Stack_entry>		//��ȡջ��ֵ
Error_code Stack<Stack_entry>::top(Stack_entry& item) const
{
	if (top_node == NULL)return underflow;
	else item = top_node->entry;
	return success;
}

template <typename Stack_entry>		//���ظ�ֵ�����
void Stack<Stack_entry>::operator =(const Stack& original)
{

	Stack new_copy(original);
	while (!empty())
		pop();
	top_node = new_copy.top_node;
}