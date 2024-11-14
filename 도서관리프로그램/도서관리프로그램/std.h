#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "start.h"
#include "book.h"
#include "control.h"
#include "file_system.h"

// 사용자 구조체 정의
typedef struct {
    char id[50]; // 사용자 ID
    int isAdmin; // 어드민 여부 (1이면 어드민, 0이면 일반 사용자)
} User;

#define MAX_USERS 10
//extern = 외부 변수 사용
extern User users[MAX_USERS]; // 최대 사용자 수
extern int userCount; // 현재 사용자 수

// 사용자 추가 함수
int addUser(const char* id, int isAdmin);

// 사용자 찾기 함수
int findUser(const char* id);

// 어드민 비밀번호 확인 함수
int verifyAdminPassword();
