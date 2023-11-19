#include <iostream> 
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;
# define numMaxSize 15

// 定义结构体的模板
template<typename T>
struct Stack
{
	// 定义堆栈结构
	T* top;// 指向栈顶
	T* base;// 指向栈底
	int stackSize;// 栈的大小
};

// 定义函数的模板
template<typename T>
void initStack(Stack<T>* stack)// 栈的初始化
{
	stack->base = stack->top = new T[1024];// 默认定义栈的大小为1024
	stack->stackSize = 1024;
}

template<typename T>
void push(Stack<T>* stack, T e) //将元素e压入栈顶
{
	*stack->top = e;
	stack->top++;// 栈顶指向下一元素位置
}

template <typename T>
int pop(Stack<T>* stack, T* e)// 将元素e弹出栈
{
	// 若栈顶和栈底位置相同则说明栈空
	if (stack->base == stack->top)
	{
		return 0;
	}
	// 栈非空，则栈顶后移一位，并返回弹出元素
	*(stack->top--);
	*e = *stack->top;
	return 1;
}

template <typename T>
int isEmpty(Stack<T>* stack)// 判断栈是否为空
{
	if (stack->top == stack->base)
	{
		return true;
	}
	else
		return false;
}

template <typename T>
int getTop(Stack<T>* stack, T* e)//将栈顶元素赋给e
{
	if (isEmpty(stack))
	{
		return false;
	}
	*e = *(stack->top - 1);
}

// 中缀式转后缀式
char* MidToAfter(const char* mid)
{
	char* after = new char[1024]; // 存储字符的后缀式
	memset(after, 0, 1024);// 将后缀式元素设为0，便于后续识别
	int afterIndex = 0;//后缀式的下标

	int midIndex = 0;// 中缀式的下标
	char midChar; // 中缀式的字符

	Stack<char> stack;// 存储中缀式的符号的栈
	initStack(&stack);

	int numIndex = 0;// 存储数字的下标
	bool flag = true;// 判断小数点个数，若超过一个则报错
	int numPoint = 0;// 记录小数点个数

	// 开始转换
	while (mid[midIndex])
	{
		midChar = mid[midIndex++];

		if (midChar == '\n')break;// 若为回车键则直接结束循环

		else if (midChar == ' ')continue;// 若为空格键则继续读入下一个字符串

		else if (midChar <= '9' && midChar >= '0')// 若为数字则将其存入num和after
		{
			flag = true;
			numPoint = 0;
			while (((midChar <= '9' && midChar >= '0') || midChar == '.') && numIndex < numMaxSize)
			{
				if (midChar == '.') numPoint++;
				if (numPoint > 1)
				{
					cout << "您的输入有误，错误为小数点个数大于1" << endl;
					return NULL;
				}
				numIndex++;
				after[afterIndex++] = midChar;// 将数字入后缀式
				midChar = mid[midIndex++];// 读入后续中缀式数字位
			}
			after[afterIndex++] = ' ';// 读完一个数后，后加上空格
		}

		if (midChar == '\n')break;// 在读入数字后，再读入字符，若为回车键则直接结束循环

		else if (midChar == ' ')continue;// 在读入数字后，再读入字符，若为空格键则继续读入下一个字符串

		else if (midChar < '0' || midChar >'9')// 读入字符，若为运算符则将运算符入stack栈
		{
			numIndex = 0;
			// (和^，优先级最高，直接入栈
			if (midChar == '(' || midChar == '（' || midChar == '^')push(&stack, midChar);

			// 读入)，则将括号内所有符号弹出栈，并入后缀式
			else if (midChar == ')' || midChar == '）')
			{
				bool flag1 = true;
				while (!isEmpty(&stack))
				{
					pop(&stack, &midChar);
					if (midChar == '(' || midChar == '（')
					{
						flag1 = false;
						break;
					}
					after[afterIndex++] = midChar;
					after[afterIndex++] = ' ';
				}
				if (flag1)
				{
					cout << "您的输入有误：缺少括号";
					return NULL;
				}
			}

			// 读入+和-
			else if (midChar == '+' || midChar == '-')
			{
				char element;
				getTop(&stack, &element);// 获取栈顶元素
				// 若栈空或只有左括号，则将+或-入栈
				if (isEmpty(&stack) || element == '(' || element == '（') push(&stack, midChar);
				// 否则将栈内除左括号以外的符号弹出栈，入后缀式中
				else
				{
					while (!isEmpty(&stack))
					{
						pop(&stack, &element);
						// 若弹出元素为左括号，则放回栈中，并结束循环
						if (element == '(' || element == '（')
						{
							push(&stack, element);
							break;
						}
						after[afterIndex++] = element;// 将弹出元素入后缀式
						after[afterIndex++] = ' ';
					}
					push(&stack, midChar);//最后将+或-入栈
				}
			}

			// 读入*和/和%
			else if (midChar == '*' || midChar == '/' || midChar == '%')
			{
				char element;
				getTop(&stack, &element);
				// 若栈空或只有左括号或+和-，则将*或/或%入栈
				if (isEmpty(&stack) || element == '(' || element == '（' || element == '+' || element == '-') push(&stack, midChar);
				// 否则将栈内除左括号以外的符号弹出栈，入后缀式中
				else
				{
					while (!isEmpty(&stack))
					{
						pop(&stack, &element);
						if (element == '(' || element == '（' || element == '+' || element == '-')
						{
							push(&stack, element);
							break;
						}
						after[afterIndex++] = element;
						after[afterIndex++] = ' ';
					}
					push(&stack, midChar);
				}
			}

			// 否则输入错误
			else
			{
				cout << "您的输入有误！" << endl;
				return NULL;
			}
		}
	}

	// 转换结束，将符号栈中符号弹出，入后缀式
	char element;
	while (!isEmpty(&stack))
	{
		pop(&stack, &midChar);
		after[afterIndex++] = midChar;
		after[afterIndex++] = ' ';
	}
	return after;
}

// 利用后缀式进行计算
double calculate(const char* after)
{
	if (after == NULL) return NULL;
	int afterIndex = 0;// 后缀式下标
	double number_1 = 0, number_2 = 0;// 计算两个数
	char afterChar;// 存储后缀式中的字符
	Stack<double> jisuan;// 用于计算的栈
	initStack(&jisuan);

	char num[numMaxSize];// 用于读取一个数
	int numIndex = 0;// num的下标

	// 判断中缀式是否正确
	for (int i = 0; after[i] != 0; i++)
	{
		if (after[i] == '(' || after[i] == '（')
		{
			cout << "请输入右括号" << endl;
			return NULL;
		}
	}

	while (after[afterIndex])
	{
		afterChar = after[afterIndex++];// 读入后缀式的字符串

		// 读入为数字
		if (afterChar >= '0' && afterChar <= '9')
		{
			numIndex = 0;
			while (((afterChar >= '0' && afterChar <= '9') || afterChar == '.') && numIndex < numMaxSize)
			{
				num[numIndex++] = afterChar;
				afterChar = after[afterIndex++];
			}
			num[numIndex] = 0;//表示读入了整个数字
			double number = atof(num);// 将字符串转为数字
			push(&jisuan, number);
		}

		// 读入为符号
		if (afterChar < '0' || afterChar > '9')
		{
			numIndex = 0;
			if (afterChar == ' ') continue;// 空格则读入下一个字符
			else
			{
				double result = 0;//记录运算结果
				switch (afterChar)
				{
				case'+':
					pop(&jisuan, &number_1);
					pop(&jisuan, &number_2);
					result = number_1 + number_2;
					push(&jisuan, result);
					break;
				case'-':
					pop(&jisuan, &number_1);
					pop(&jisuan, &number_2);
					result = number_2 - number_1;
					push(&jisuan, result);
					break;
				case'*':
					pop(&jisuan, &number_1);
					pop(&jisuan, &number_2);
					result = number_1 * number_2;
					push(&jisuan, result);
					break;
				case'/':
					pop(&jisuan, &number_1);
					pop(&jisuan, &number_2);
					if (number_1 == 0)
					{
						cout << "错误：除数为0" << endl;
						break;
					}
					result = number_2 / number_1;
					push(&jisuan, result);
					break;
				case'%':
					pop(&jisuan, &number_1);
					pop(&jisuan, &number_2);
					result = int(number_2) % int(number_1);
					push(&jisuan, result);
					break;
				case'^':
					pop(&jisuan, &number_1);
					pop(&jisuan, &number_2);
					result = pow(number_2, number_1);
					push(&jisuan, result);
					break;
				default:
					return NULL;
					break;
				}
			}
		}
	}
	if (isEmpty(&jisuan))
	{
		cout << "您的表达式输入错误" << endl;
		return NULL;
	}
	pop(&jisuan, &number_1);
	return number_1;
}

void main()
{
	cout << "请输入计算式：";
	char* mid = new char[1024];
	fgets(mid, 1024, stdin);//可读入\n,用以标记字符串输入结束
	char* after = MidToAfter(mid);
	double result = calculate(after);
	cout << "计算结果： " << result << endl;
}