#include "std.h"

// ���� �ʱ�ȭ �Լ�
void initBook(Book* book, const char* title, const char* author, int year) {
    strcpy_s(book->title, sizeof(book->title), title);
    strcpy_s(book->author, sizeof(book->author), author);
    book->year = year;
    book->isLent = 0; // �⺻���� ���� ���� ���·� ����
}

// ���� ���� ��� �Լ�
void printBook(const Book* book) {
    printf("����: %s, ����: %s, ���� ����: %d", book->title, book->author, book->year);
    if (book->isLent) {
        printf(" - ���� ��"); // ���� ���� ���
    }
    printf("\n");
}
