#pragma once

#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "book.h"

#define BOOKS_FILE "books.txt"
#define USERS_FILE "users.txt"


void resetFiles();           // 파일 초기화 함수
//void loadUsers();            // 사용자 목록 불러오기 함수
void setupFileSystem();      // 파일 시스템 초기화 또는 불러오기 함수

#endif // FILE_SYSTEM_H