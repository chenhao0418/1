#include <iostream>
#define MaxSize 30
using namespace std;

//˳��ջ���ݽṹ
typedef struct Stack
{
	int* base;	//ջ��ָ�� ����
	int* top;	//ջ��ָ�� һֱ��ջ��Ԫ����һ��λ��;
	int stacksize;	//ջ���õ��������;
}SqStack;

//��ʼ��ջ
int InitStack(SqStack& s)
{
	s.base = new int[100];	//��̬�����������;
	if (!s.base)
	{
		cout << "����ʧ��" << endl;
		return 0;
	}
	s.top = s.base;		//ջ��ָ����ջ��ָ����ͬ;
	s.stacksize = MaxSize;
	return 1;
}

//�˵�;
void menu()
{
	cout << "--------------------1.��ջ          2.��ջ--------------------" << endl;
	cout << "--------------------3.ɾ��ջ��      4.����ջ--------------------" << endl;
	cout << "--------------------5.��ջ����      6.���ջ--------------------" << endl;
	cout << "--------------------7.����ջ        8.�˳�--------------------" << endl;
}

//��ջ����
void PushToStack(SqStack& s)
{
	int n, e, flag;
	cout << "��������Ҫ��ջ��Ԫ�ظ�����" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "������Ԫ�ص�ֵ��" << endl;
		cin >> e;
		if (s.top - s.base == MaxSize)
		{
			cout << "ջ��,��ջ" << endl;
			return;
		}
		*(s.top++) = e;
		//���������*(++s.top)��*(s.base)��δ֪����;
	}
}

//��ջ����
void PopFromStack(SqStack& s)
{
	int n, flag, e;
	cout << "��������Ҫ��ջ��Ԫ�ظ�����" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (s.top == s.base)
		{
			cout << "ջ�ѿ�" << endl;
			return;
		}
		e = *(--s.top);		//�ȼ��� ָ��ջ��Ԫ�أ��ٸ�e
		cout << e << "�ѳ�ջ" << endl;
	}
}

//ȡջ��Ԫ��;
void GetTopOfStack(SqStack s)
{
	if (s.top == s.base)
	{
		cout << "ջΪ��" << endl;
		return;
	}
	int e = *(--s.top);
	cout << "ջ��Ԫ��Ϊ��" << e << endl;
}

//����ջ
void TraveStack(SqStack s)
{
	while (s.base != s.top)
		cout << *(--s.top) << " ";
	if (s.base == s.top)
	{
		cout << "ջ����ɱ���" << endl;
		return;
	}
}

//��ջ�ĳ���
void LengthStack(SqStack& s)
{
	if (s.base == s.top)
	{
		cout << "ջΪ��" << endl;
		return;
	}
	cout << s.top - s.base << endl;
}

//���ջ
void ClearStack(SqStack& s)
{
	s.top = s.base;
	return;
}

//����ջ
void DestroyStack(SqStack& s)
{
	s.top = nullptr;
	s.stacksize = 0;
	delete(s.base);
	return;
}

//������
int main()
{
	SqStack s;
	int choice;
	InitStack(s);
	while (1)
	{
		menu();
		cout << "������˵���ţ�" << endl;
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
			cout << "�����������������" << endl;
			break;
		}
	}
	return 0;
}
