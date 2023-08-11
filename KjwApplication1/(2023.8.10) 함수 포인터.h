#pragma once
#include <stdio.h>
#include <string.h>

#pragma region 함수 포인터
// 함수의 주소값을 저장하고 가리킬 수 있는 변수입니다.

void Delegate()
{
	printf("대리자~");
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
	printf("cptr 함수의 결과 : %d\n", cptr(x, y));

}


#pragma endregion


int main()
{
#pragma region 함수 포인터


	// 함수 포인터는 함수의 반환형과 매개 변수의 타입이 일치해야 하며, 
	// 함수 포인터를 사용하여 동적으로 메모리를 할당할 수 없습니다.
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

#pragma region 소수 판별 알고리즘

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
	//		printf("소수입니다.");
	//	}
	//	if (count != 1)
	//	{
	//		printf("소수가 아닙니다.");
	//	}


#pragma endregion

#pragma region 회문 판별 알고리즘

	// const char* content = "LeveL";
	// printf("%d", strlen(content));

	//	int b = 0;
	//	
	//	for(b; b <= strlen(content); b++)
	//	if (content[] == content[4] && content[1] == content[strlen(content) - 1])
	//	{
	//		printf("회문입니다.");
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
	//		printf("회문입니다.");
	//	}
	//	else
	//	{
	//		printf("회문이 아닙니다.");
	//	}
#pragma endregion



	return 0;
}
