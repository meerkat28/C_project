#pragma once

// 도서 구조체 정의
typedef struct tagBook {
    char title[50]; // 도서 제목
    char author[50]; // 도서 저자
    int year; // 출판 연도
    int isLent; // 대출 여부 (1이면 대출 중, 0이면 대출 가능)
} Book;

// 도서 초기화 함수
void initBook(Book* book, const char* title, const char* author, int year);

// 도서 정보 출력 함수
void printBook(const Book* book);
