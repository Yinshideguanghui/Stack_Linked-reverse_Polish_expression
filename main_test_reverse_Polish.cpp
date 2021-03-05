#include"linked_stack.h"
#include"linked_stack.cpp"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string test_expression = "(A+B)*C+D*(E-F)+G*H";
	Stack<char> stack1;
	cout << "中缀表达式： " << test_expression <<'\n';
	//利用栈输出逆波兰表达式
	char temp;
	cout << "逆波兰表达式：";
	for (unsigned int i = 0; i < test_expression.length(); i++)
	{
		//加减号前有加减乘除则出栈到遇到小括号，都无出栈到空，而后入栈
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
		//乘除号遇到乘除号则出栈直到遇到小括号，都无出栈到空，而后入栈
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
		//遇前小括号直接入栈
		else if (test_expression[i] == '(')
		{
			stack1.push(test_expression[i]);
		}
		//遇后小括号把前小括号之前出栈并输出，前小括号出栈
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
		//其余直接输出
		else
		{
			cout << test_expression[i];
		}
	}
	//输出剩余符号
	while (!stack1.empty())
	{
		stack1.top(temp);
		cout << temp;
		stack1.pop();
	}
	cout << endl; return 0;
}