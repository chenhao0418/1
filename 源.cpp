#include <iostream>
#define MaxSize 30
using namespace std;

//顺序栈数据结构
typedef struct Stack
{
	int* base;	//栈底指针 不变
	int* top;	//栈顶指针 一直在栈顶元素上一个位置;
	int stacksize;	//栈可用的最大容量;
}SqStack;

//初始化栈
int InitStack(SqStack& s)
{
	s.base = new int[100];	//动态分配最大容量;
	if (!s.base)
	{
		cout << "分配失败" << endl;
		return 0;
	}
	s.top = s.base;		//栈顶指针与栈底指针相同;
	s.stacksize = MaxSize;
	return 1;
}

//菜单;
void menu()
{
	cout << "--------------------1.入栈          2.出栈--------------------" << endl;
	cout << "--------------------3.删除栈顶      4.遍历栈--------------------" << endl;
	cout << "--------------------5.求栈长度      6.清空栈--------------------" << endl;
	cout << "--------------------7.销毁栈        8.退出--------------------" << endl;
}

//入栈功能
void PushToStack(SqStack& s)
{
	int n, e, flag;
	cout << "请输入需要入栈的元素个数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入元素的值：" << endl;
		cin >> e;
		if (s.top - s.base == MaxSize)
		{
			cout << "栈满,出栈" << endl;
			return;
		}
		*(s.top++) = e;
		//这里如果是*(++s.top)则*(s.base)是未知数字;
	}
}

//出栈功能
void PopFromStack(SqStack& s)
{
	int n, flag, e;
	cout << "请输入需要出栈的元素个数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (s.top == s.base)
		{
			cout << "栈已空" << endl;
			return;
		}
		e = *(--s.top);		//先减减 指向栈顶元素，再给e
		cout << e << "已出栈" << endl;
	}
}

//取栈顶元素;
void GetTopOfStack(SqStack s)
{
	if (s.top == s.base)
	{
		cout << "栈为空" << endl;
		return;
	}
	int e = *(--s.top);
	cout << "栈顶元素为：" << e << endl;
}

//遍历栈
void TraveStack(SqStack s)
{
	while (s.base != s.top)
		cout << *(--s.top) << " ";
	if (s.base == s.top)
	{
		cout << "栈已完成遍历" << endl;
		return;
	}
}

//求栈的长度
void LengthStack(SqStack& s)
{
	if (s.base == s.top)
	{
		cout << "栈为空" << endl;
		return;
	}
	cout << s.top - s.base << endl;
}

//清空栈
void ClearStack(SqStack& s)
{
	s.top = s.base;
	return;
}

//销毁栈
void DestroyStack(SqStack& s)
{
	s.top = nullptr;
	s.stacksize = 0;
	delete(s.base);
	return;
}

//主函数
int main()
{
	SqStack s;
	int choice;
	InitStack(s);
	while (1)
	{
		menu();
		cout << "请输入菜单序号：" << endl;
		cin >> choice;
		if (choice == 8)
			break;
		switch (choice)
		{
		case 1:
			PushToStack(s); break;
		case 2:
			PopFromStack(s); break;
		case 3:
			GetTopOfStack(s); break;
		case 4:
			TraveStack(s); break;
		case 5:
			LengthStack(s); break;
		case 6:
			ClearStack(s); break;
		case 7:
			DestroyStack(s); break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}
