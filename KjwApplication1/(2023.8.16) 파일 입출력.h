#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ReadTextFile(const char* fileName)
{
	FILE* readfile = fopen(fileName, "r");

	char buffer[10000] = { 0, };

	// fread()
	// ù ��° �Ű� ���� : ũ�⸦ ������ �迭�� ����Ű�� ������
	// �� ��° �Ű� ���� : �о���� ������ ũ��� ������ ����Ʈ�Դϴ�.
	// �� ��° �Ű� ���� : �о���� ���ҵ��� ������ �� ������ ũ���Դϴ�.
	// �� ��° �Ű� ���� : �����͸� �Է¹��� ��Ʈ���� FILE ��ü�� ����Ű�� �������Դϴ�.
	fread(buffer, 1, 10000, readfile);
	printf("%s", buffer);

	fclose(readfile);
}

int main()
{
#pragma region ���� �����
	// ���� ��� ��ġ(��ũ)�κ��� �����͸� �о���ų� �����ϴ� �����Դϴ�.

	// fopen("���� �̸�", "���� ���")
	// "w" : ���� ����
	// FILE* filePtr = fopen("data.txt", "w");
	// 
	// char content[] = "Content";
	// 
	// fputs(content, filePtr);
	// 
	// FILE* fileReader = fopen("data.txt", "r");
	// fgets(content, sizeof(content), fileReader);
	// printf("%s", content);

	// fclose(filePtr); // ���� �ݾ��ֱ�


#pragma endregion

	ReadTextFile("Resources/dragon.txt");

	while (1)
	{
		ReadTextFile("Resources/data.txt");

		system("cls");
	}

	return 0;
}
