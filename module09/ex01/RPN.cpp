#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "Constructor called" << std::endl;
}

RPN::RPN(char *input)
{
	for (int i = 0; input[i]; ++i)
	{
		char c = input[i];
		if (std::isdigit(c))
		{
			this->AddToStack(c - '0');
			continue;
		}
		else if (c == '+' || c == '-' || c == '/' || c == '*')
		{
			this->CalcOperator(c);
			continue;
		}
		else if (c == ' ')
			continue;
		throw std::runtime_error("Error");	
	}
	int val = this->PopTheStack();
	std::cout << val << std::endl;
}

RPN::RPN(RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return *this;
	this->stack = other.stack;
	return *this;
}

RPN::~RPN(void)
{
	//std::cout << "Destructor called" << std::endl;
}

// helpers
int AddValues(int a, int b)
{
	return b + a;
}

int SubtractValues(int a, int b)
{
	return b - a;
}

int MultiplyValues(int a, int b)
{
	return b * a;
}

int DivideValues(int a, int b)
{
	return b / a;
}
// end helpers

void RPN::AddToStack(int val)
{
	this->stack.push(val);
}

int RPN::PopTheStack()
{
	int val = this->stack.top();
	this->stack.pop();
	return val;
}

int RPN::CalcOperator(char calc_operator)
{
	int top = PopTheStack();
	int res = top;
	while (!this->stack.empty())
	{
		top = PopTheStack();
		switch (calc_operator)
		{
		case '+':
			res = AddValues(res, top);
			AddToStack(res);
			return res;
		case '-':
			res = SubtractValues(res, top);
			AddToStack(res);
			return res;
		case '*':
			res = MultiplyValues(res, top);
			AddToStack(res);
			return res;
		case '/':
			if (res != 0)
				res = DivideValues(res, top);
			else
				throw std::runtime_error("Error: Divide by 0?!?!?!");	
			AddToStack(res);
			return res;
		}
	}
	AddToStack(res);
	return res;
}

