#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

struct Player
{
	int x, y;
	const char* shape[][];
};

struct Enemy
{
	int x, y;
	const char* shape;
};

void gotoXY(int x, int y)
{
	// x, y ��ǥ ����
	COORD position = { x, y };

	// Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Keyboard(Player* player)
{
	char key = 0;

	if (_kbhit())
	{
		key = _getch();

		if (key == -32)
		{
			key = _getch();
		}

		switch (key)
		{
		case LEFT:if (player->x <= 0)return;
			player->x -= 2;
			break;
		case RIGHT:if (player->x >= 28)return;
			player->x += 2;
			break;
		}
	}
}

int RandomX()
{
	srand(time(NULL));

	int x = rand() % 31;

	if (x % 2 == 1)
	{
		x += 1;
	}

	return x;
}

int main()
{
#pragma region ���ڿ� ���� �Լ�

	// ���ڿ� ���� �Լ�
	/*
	const char* name = "James";
	int result = strlen(name);
	printf("result�� �� : %d", result);
	*/
	// ���ڿ� ���� �Լ�
	/*
	char firstArr[] = "First";
	char secondArr[] = "Second";

	strcat(firstArr, secondArr);

	printf("firstArr�� �� : %s\n", firstArr);
	*/
	// ���ڿ� ���� �Լ�
	/*
	char a[10] = { "String" };
	char b[10];

	// ù ��° �Ű����� : ������� ���� �迭
	// �� ��° �Ű����� : ������ ���� �迭
	strcpy(b, a);

	printf("a�� ���ڿ� : %s\n", a);
	printf("b�� ���ڿ� : %s\n", b);
	*/
	// ���ڿ� �� �Լ�
	/*
	char firstA[] = { "AAB" };
	char secondB[] = { "AAC" };

	// ���� ������ "0"
	// ���ʿ� �ִ� ���� ũ�� "1"
	// ���ʿ� �ִ� ���� ũ�� "-1"

	printf("�� ���ڿ��� ���� ��� : %d\n", strcmp(firstA, secondB));
	*/

	//  _____
	// /     \
	//��     ��
	//��     ��
	//��     ��
	//��_____��
#pragma endregion

	system("mode con cols=30 lines=25");

	Player player = { 13,23,"��" };
	Enemy enemy = { RandomX(),0,"��" };

	while (1)
	{
		Keyboard(&player);

		if (enemy.y >= 24)
		{
			enemy.y = 0;
			enemy.x = RandomX();
		}
		if (player.x == enemy.x && player.y == enemy.y)
		{
			break;
		}
		gotoXY(enemy.x, enemy.y++);
		printf("%s", enemy.shape);
		gotoXY(player.x, player.y);
		printf("%s", player.shape);

		Sleep(100);
		system("cls");
	}

	return 0;
}
