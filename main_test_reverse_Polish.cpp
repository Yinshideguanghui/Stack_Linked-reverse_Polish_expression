#include"linked_stack.h"
#include"linked_stack.cpp"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string test_expression = "(A+B)*C+D*(E-F)+G*H";
	Stack<char> stack1;
	cout << "��׺���ʽ�� " << test_expression <<'\n';
	//����ջ����沨�����ʽ
	char temp;
	cout << "�沨�����ʽ��";
	for (unsigned int i = 0; i < test_expression.length(); i++)
	{
		//�Ӽ���ǰ�мӼ��˳����ջ������С���ţ����޳�ջ���գ�������ջ
		if (test_expression[i] == '+' || test_expression[i] == '-')
		{
			stack1.top(temp);
			if (temp == '*' || temp == '/' || temp == '+' || temp == '-')
			{
				while (temp != '(' && !(stack1.empty()))
				{
					cout << temp;
					stack1.pop();
					stack1.top(temp);
				}
			}
			stack1.push(test_expression[i]);
		}
		//�˳��������˳������ջֱ������С���ţ����޳�ջ���գ�������ջ
		else if (test_expression[i] == '*' || test_expression[i] == '/')
		{
			stack1.top(temp);
			if (temp == '*' || temp == '/')
			{
				while (temp != '(' && !(stack1.empty()))
				{
					cout << temp;
					stack1.pop();
					stack1.top(temp);
				}
			}
			stack1.push(test_expression[i]);
		}
		//��ǰС����ֱ����ջ
		else if (test_expression[i] == '(')
		{
			stack1.push(test_expression[i]);
		}
		//����С���Ű�ǰС����֮ǰ��ջ�������ǰС���ų�ջ
		else if (test_expression[i] == ')')
		{
			stack1.top(temp);
			while (temp != '(')
			{
				cout << temp;
				stack1.pop();
				stack1.top(temp);
			}
			stack1.pop();
		}
		//����ֱ�����
		else
		{
			cout << test_expression[i];
		}
	}
	//���ʣ�����
	while (!stack1.empty())
	{
		stack1.top(temp);
		cout << temp;
		stack1.pop();
	}
	cout << endl; return 0;
}