#include <iostream>
#include <stack>
#include <cctype>
#include <stdexcept>

class RPN
{
private:
	RPN(void);
	std::stack<int> stack;

public:
	RPN(char *input);
	RPN(RPN &other);
	RPN &operator=(const RPN &other);
	~RPN(void);
	void AddToStack(int val);
	int PopTheStack();
	int CalcOperator(char calc_operator);
};
