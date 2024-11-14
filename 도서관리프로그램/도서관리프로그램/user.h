#pragma once

#define MAX_USERS 100
#define MAX_ADMINS 3
#define PASSWORD "admin123"

// 사용자 구조체 정의
typedef struct {
    char id[50]; // 사용자 ID
    int isAdmin; // 어드민 여부
} User;

extern User users[MAX_USERS]; // 사용자 배열
extern int userCount; // 현재 사용자 수

// 사용자 추가 함수
void addUser(const char* id, int isAdmin);

// 사용자 찾기 함수
int findUser(const char* id);

// 어드민 비밀번호 확인 함수
int verifyAdminPassword();
