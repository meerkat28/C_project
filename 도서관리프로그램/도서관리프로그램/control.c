#include "std.h"

static Book books[MAX_BOOKS]; // 도서 배열
static int bookCount = 0; // 현재 도서 수
static char currentUser[50]; // 현재 로그인한 사용자 ID

// 도서 추가 함수
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("도서를 추가할 수 없습니다. 최대 도서 수에 도달했습니다.\n");
        return;
    }

    char title[50], author[50];
    int year;

    // 도서 정보 입력
    printf("도서 제목: ");
    getchar(); // 입력 버퍼의 개행 문자 제거
    scanf_s("%s", title, sizeof(title));
  //  gets_s(title, sizeof(title));

    printf("저자: ");
    getchar();
    scanf_s("%s", author,sizeof(author));
  //  gets_s(author, sizeof(author));

    printf("출판 연도: ");
    scanf_s("%d", &year);

    // 도서 초기화 후 추가
    initBook(&books[bookCount++], title, author, year);
    printf("도서가 추가되었습니다.\n");
}

// 도서 목록 보기 함수
void display() {
    if (bookCount == 0) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    printf("\n도서 목록:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. ", i + 1);
        printBook(&books[i]);
    }
}

// 도서 대출 함수
void lendBook() {
    int lentCount = 0;

    printf("\n대출 가능한 도서 목록:\n");
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isLent) {
            printf("%d. ", i + 1);
            printBook(&books[i]);
            lentCount++;
        }
    }

    if (lentCount == 0) {
        printf("대출 가능한 도서가 없습니다.\n");
        return;
    }

    int choice;
    printf("대출할 도서 번호를 입력하세요: ");
    scanf_s("%d", &choice);

    if (choice < 1 || choice > bookCount || books[choice - 1].isLent) {
        printf("잘못된 선택입니다.\n");
        return;
    }

    books[choice - 1].isLent = 1; // 도서 대출 상태로 변경
    printf("'%s' 도서가 대출되었습니다.\n", books[choice - 1].title);
}

// 도서 반납 함수
void returnBook() {
    int borrowedCount = 0;

    printf("\n대출 중인 도서 목록:\n");
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isLent) {
            printf("%d. ", i + 1);
            printBook(&books[i]);
            borrowedCount++;
        }
    }

    if (borrowedCount == 0) {
        printf("대출 중인 도서가 없습니다.\n");
        return;
    }

    int choice;
    printf("반납할 도서 번호를 입력하세요: ");
    scanf_s("%d", &choice);

    if (choice < 1 || choice > bookCount || !books[choice - 1].isLent) {
        printf("잘못된 선택입니다.\n");
        return;
    }

    books[choice - 1].isLent = 0; // 도서 반납 상태로 변경
    printf("'%s' 도서가 반납되었습니다.\n", books[choice - 1].title);
}
