#pragma once

#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "book.h"

#define BOOKS_FILE "books.txt"
#define USERS_FILE "users.txt"


void resetFiles();           // ���� �ʱ�ȭ �Լ�
//void loadUsers();            // ����� ��� �ҷ����� �Լ�
void setupFileSystem();      // ���� �ý��� �ʱ�ȭ �Ǵ� �ҷ����� �Լ�

#endif // FILE_SYSTEM_H