#include "RPN.hpp"

void RPN::AddToStack(char c)
{
	this->stack.push(c);
}

char RPN::PopTheStack()
{
	char c = this->stack.top();
	this->stack.pop();
	return c;
}

int RPN::CalcOperator(char calc_operator)
{
	char c = PopTheStack();
	int res = 0;
	while (c >= '0' && c <= '9')
	{
		switch (calc_operator)
		{
		case '+':
			res = AddValues(res, c - '0');
			break;
		case '-':
			res = SubtractValues(res, c - '0');
			break;
		case '*':
			res = MultiplyValues(res, c - '0');
			break;
		case '/':
			if (res == 0)
				break;
			res = DivideValues(res, c - '0');
			break;
		}
		char c = PopTheStack();
	}
}

// helpers
int AddValues(int a, int b)
{
	return a + b;
}

int SubtractValues(int a, int b)
{
	return a - b;
}

int MultiplyValues(int a, int b)
{
	return a * b;
}

int DivideValues(int a, int b)
{
	return a / b;
}
// end helpers