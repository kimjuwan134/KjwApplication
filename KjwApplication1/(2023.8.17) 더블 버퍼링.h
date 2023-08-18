#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#pragma region ���� ���۸�
// HANDLE �ε����� �����ؼ� ���۸� ��ü��Ű�� ����
int screenIndex = 0;

// ������ ũ��
int width = 100;
int height = 60;

// ���� ����
HANDLE Screen[2];

// [0] : Front Buffer
// [1] : Back Buffer

struct Player
{
	int x;
	int y;
	const char* shape;
};

// ���۸� �ʱ�ȭ�ϴ� �Լ�
void Init()
{
	CONSOLE_CURSOR_INFO cursor;

	// ������ ���� ������, ���� ������
	COORD size = { width, height };

	// LEFT, TOP, RIGHT, BOTTOM
	SMALL_RECT rect = { 0,0,width - 1, height - 1 };

	// ȭ�� 2���� �����մϴ�.
	// FRONT BUFFER
	Screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	SetConsoleScreenBufferSize(Screen[0], size);

	SetConsoleWindowInfo(Screen[0], TRUE, &rect);

	// BACK BUFFER
	Screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	SetConsoleScreenBufferSize(Screen[1], size);

	SetConsoleWindowInfo(Screen[1], TRUE, &rect);

	// Ŀ���� Ȱ��ȭ ����
	// false : ����
	// true : ��

	cursor.bVisible = false;

	SetConsoleCursorInfo(Screen[0], &cursor);
	SetConsoleCursorInfo(Screen[1], &cursor);
}

// ���۸� ��ü�ϴ� �Լ�
void Flipping()
{
	// ���۴� �ϳ��� Ȱ��ȭ��ų �� �ֽ��ϴ�.
	SetConsoleActiveScreenBuffer(Screen[screenIndex]);

	// true <- false

	screenIndex = !screenIndex;
}

// ��ü�� ���۸� �����ִ� �Լ�
void Clear()
{
	COORD coord = { 0,0 };

	DWORD dw;

	FillConsoleOutputCharacter
	(
		Screen[screenIndex],
		' ',
		width * height,
		coord,
		&dw
	);
}

// ���۸� �����ϴ� �Լ�
void ReleaseScreen()
{
	CloseHandle(Screen[0]);
	CloseHandle(Screen[0]);
}

// ���۸� �̿��ؼ� ����ϴ� �Լ�
void ShowBuffer(int x, int y, const char* string)
{
	COORD cursorPosition = { x,y };

	DWORD dw;

	SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

	WriteFile
	(
		Screen[screenIndex],
		string,
		strlen(string),
		&dw,
		NULL
	);
}
#pragma endregion

int main()
{
#pragma region ���� ���۸�
	/*
	char key = 0;

	Player player = { 5,5,"��" };

	// 1. ���� �ʱ�ȭ
	Init();

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();

			switch (key)
			{
			case UP:
				if (player.y <= 0) break;
				player.y--;
				break;
			case LEFT:
				if (player.x <= 0)break;
				player.x -= 2;
				break;
			case RIGHT:
				player.x += 2;
				break;
			case DOWN:
				player.y++;
				break;
			}
		}

		ShowBuffer(player.x, player.y, player.shape);

		// 2. ���� ��ü
		Flipping();

		// 3. ������ ������ �����մϴ�.
		Clear();
	}

	// 4. ���۸� �����մϴ�.
	ReleaseScreen();
	*/
#pragma endregion

#pragma region �ִ� �����

	int x = 0;
	int y = 0;
	int z = 0;

	while (1)
	{
		scanf_s("%d%d", &x, &y);

		for (int i = 1; i <= x && i <= y; i++)
		{
			if (x % i == 0 && y % i == 0)
			{
				z = i;
			}
		}

		printf("%d", z);
	}



#pragma endregion


	return 0;
}
