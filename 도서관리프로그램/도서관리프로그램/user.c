#include "std.h"

User users[MAX_USERS]; // 사용자 배열
int userCount = 0; // 현재 사용자 수

// 사용자 추가 함수
int addUser(const char* id, int isAdmin) {
    // 현재 사용자 수가 최대 사용자 수를 초과한 경우
    if (userCount >= MAX_USERS) {
        return -1; // 추가 불가를 나타내는 -1 반환
    }

    // 사용자의 ID를 구조체에 복사 (id 문자열을 users 배열의 id 필드에 복사)
    strcpy_s(users[userCount].id, sizeof(users[userCount].id), id);

    // 어드민 여부 설정 (isAdmin 값에 따라 설정)
    users[userCount].isAdmin = isAdmin;
    // 사용자 수 증가
    userCount++;

    return 0; // 성공적으로 추가된 경우 0 반환
}
// 사용자 찾기 함수
int findUser(const char* id) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// 어드민 비밀번호 확인 함수
int verifyAdminPassword() {
    char password[50];
    printf("비밀번호를 입력하세요: ");
    scanf_s("%49s", password, (unsigned)sizeof(password));
    if (strcmp(password, "admin123") == 0) {
        return 1;
    }
    else {
        printf("비밀번호가 틀렸습니다.\n");
        return 0;
    }
}
