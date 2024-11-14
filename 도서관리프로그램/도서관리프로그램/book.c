#include "std.h"

// 도서 초기화 함수
void initBook(Book* book, const char* title, const char* author, int year) {
    strcpy_s(book->title, sizeof(book->title), title);
    strcpy_s(book->author, sizeof(book->author), author);
    book->year = year;
    book->isLent = 0; // 기본으로 대출 가능 상태로 설정
}

// 도서 정보 출력 함수
void printBook(const Book* book) {
    printf("제목: %s, 저자: %s, 출판 연도: %d", book->title, book->author, book->year);
    if (book->isLent) {
        printf(" - 대출 중"); // 대출 중인 경우
    }
    printf("\n");
}
