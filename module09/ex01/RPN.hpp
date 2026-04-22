#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<char> stack;

public:
	RPN(void);
	RPN(std::string csv, std::string input);
	RPN(RPN &other);
	RPN &operator=(const RPN &other);
	void AddToStack(char c);
	char PopTheStack();
	int CalcOperator(char calc_operator);
};
