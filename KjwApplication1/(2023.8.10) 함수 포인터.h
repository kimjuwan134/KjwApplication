#pragma once
#include <stdio.h>
#include <string.h>

#pragma region �Լ� ������
// �Լ��� �ּҰ��� �����ϰ� ����ų �� �ִ� �����Դϴ�.

void Delegate()
{
	printf("�븮��~");
}

int Add(int x, int y)
{
	return x + y;
}

int Substract(int x, int y)
{
	return x - y;
}

int Multiple(int x, int y)
{
	return x * y;
}

int Divide(int x, int y)
{
	return x / y;
}

void Calculator(int x, int y, int (*cptr) (int, int))
{
	printf("cptr �Լ��� ��� : %d\n", cptr(x, y));

}


#pragma endregion


int main()
{
#pragma region �Լ� ������


	// �Լ� �����ʹ� �Լ��� ��ȯ���� �Ű� ������ Ÿ���� ��ġ�ؾ� �ϸ�, 
	// �Լ� �����͸� ����Ͽ� �������� �޸𸮸� �Ҵ��� �� �����ϴ�.
	// void (*fptr) ();
	// 
	// Calculator(15, 30, Add);
	// Calculator(60, 20, Substract);
	// Calculator(1, 20, Multiple);
	// Calculator(60, 20, Divide);
	// 
	// 
	// fptr = Delegate;
	// 
	// fptr();
#pragma endregion

#pragma region �Ҽ� �Ǻ� �˰���

	//	int a = 0;
	//	scanf_s("%d", &a);
	//	
	//	int count = 0;
	//	
	//	for (int i = 2; i <= a; i++)
	//	{
	//		if (a % i == 0)
	//			count++;
	//	}
	//	if (count == 1)
	//	{
	//		printf("�Ҽ��Դϴ�.");
	//	}
	//	if (count != 1)
	//	{
	//		printf("�Ҽ��� �ƴմϴ�.");
	//	}


#pragma endregion

#pragma region ȸ�� �Ǻ� �˰���

	// const char* content = "LeveL";
	// printf("%d", strlen(content));

	//	int b = 0;
	//	
	//	for(b; b <= strlen(content); b++)
	//	if (content[] == content[4] && content[1] == content[strlen(content) - 1])
	//	{
	//		printf("ȸ���Դϴ�.");
	//	}

	//	int size = strlen(content);
	//	int flag = 0;
	//	
	//	for (int i = 0; i < size / 2; i++)
	//	{
	//		if (content[i] == content[size - 1 - i])
	//		{
	//			flag = 1;
	//		}
	//		else
	//		{
	//			flag = 0;
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		printf("ȸ���Դϴ�.");
	//	}
	//	else
	//	{
	//		printf("ȸ���� �ƴմϴ�.");
	//	}
#pragma endregion



	return 0;
}
