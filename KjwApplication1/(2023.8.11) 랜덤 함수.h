#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int life;
int computer;
int answer;

void Init()
{
	srand(time(NULL));
	life = 5;
	computer = rand() % 50 + 1;
}

void Update()
{
	printf("컴퓨터가 가지고 있는 값 : ");

	scanf_s("%d", &answer);
}

void Render()
{
	if (computer == answer)
	{
		printf("\n게임에서 승리하였습니다.\n");
		exit(1);
	}
	else if (computer > answer)
	{
		printf("\n컴퓨터가 가지고 있는 값보다 작습니다.\n");
		life--;
	}
	else if (computer < answer)
	{
		printf("\n컴퓨터가 가지고 있는 값보다 큽니다.\n");
		life--;
	}

	if (life <= 0)
	{
		printf("게임에서 패배하였습니다.");
	}
}


int main()
{
#pragma region 랜덤 함수
	// 0 ~ 32767 사이의 난수 값을 반환하는 함수입니다.

	//	int seed = 0;
	//	
	//	// 1970년 1월 1일 ~
	//	srand(time(NULL));
	//	
	//	for (int i = 0; i < 10; i++)
	//	{
	//		seed = rand() % 10 + 1;
	//		printf("seed의 값 : %d\n", seed);
	//	}



#pragma endregion

#pragma region UP-DOWN 게임(내가 한거)

	//	int seed = 0;
	//	int health = 5;
	//	int answer = 0;
	//	srand(time(NULL));
	//	
	//	seed = rand() % 50 + 1;
	//	
	//	printf("현재 목숨 : %d\n", health);
	//	printf("1 ~ 50까지의 숫자 중 랜덤한 하나의 숫자를 맞추시오.\n");
	//	
	//	while (health)
	//	{
	//		scanf_s("%d", &answer);
	//		if (seed > answer)
	//		{
	//			printf("값을 올리세요.\n");
	//			health--;
	//			printf("현재 목숨 : %d\n", health);
	//		}
	//		else if (seed < answer)
	//		{
	//			printf("값을 내리세요.\n");
	//			health--;
	//			printf("현재 목숨 : %d\n", health);
	//		}
	//		else if (seed == answer)
	//		{
	//			printf("정답입니다!\n");
	//			break;
	//		}
	//		else if(health == 0)
	//		{
	//			printf("게임에서 패배하였습니다.\n");
	//		}
	//	}




#pragma endregion

#pragma region UP-DOWN(정답 풀이)

	// 게임 데이터 초기화
	Init();


	while (life > 0)
	{
		// 게임 업데이트 함수
		Update();

		// 게임 랜더링 함수
		Render();
	}




#pragma endregion


	return 0;
}
