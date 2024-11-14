#pragma once

// ���� ����ü ����
typedef struct tagBook {
    char title[50]; // ���� ����
    char author[50]; // ���� ����
    int year; // ���� ����
    int isLent; // ���� ���� (1�̸� ���� ��, 0�̸� ���� ����)
} Book;

// ���� �ʱ�ȭ �Լ�
void initBook(Book* book, const char* title, const char* author, int year);

// ���� ���� ��� �Լ�
void printBook(const Book* book);
