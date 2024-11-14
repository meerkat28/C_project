#include "std.h"

// 파일 초기화 함수 
void resetFiles() {
    FILE* books_file = fopen(BOOKS_FILE, "w");
    FILE* users_file = fopen(USERS_FILE, "w");

    if (books_file == NULL || users_file == NULL) {
        printf("파일을 초기화할 수 없습니다.\n");
        return;
    }

    fclose(books_file);
    fclose(users_file);

    printf("파일이 성공적으로 초기화되었습니다.\n");
}


/*
// 사용자 목록 불러오기 함수
void loadUsers() {
    FILE* file = fopen(USERS_FILE, "r");
    if (file == NULL) {
        printf("사용자 파일을 불러올 수 없습니다.\n");
        return;
    }

    char user_id[100];
    printf("저장된 사용자 목록:\n");
    while (fgets(user_id, sizeof(user_id), file) != NULL) {
        printf("사용자 ID: %s", user_id);
    }
    fclose(file);
}
*/

// 파일 시스템 초기화 또는 불러오기 선택
void setupFileSystem() {
    char choice;
    printf("파일을 초기화 하시겠습니까? (y/n): ");
    scanf_s(" %c", &choice, sizeof(choice));

    if (choice == 'y' || choice == 'Y') {
        resetFiles();
    }
    else if (choice == 'n' || choice == 'N') {
        printf("기존 파일 내용을 불러옵니다...\n");
        //loadUsers();
    }
    else {
        printf("잘못된 입력입니다.\n");
    }
}