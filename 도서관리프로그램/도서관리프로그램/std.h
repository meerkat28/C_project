#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "start.h"
#include "book.h"
#include "control.h"
#include "file_system.h"

// ����� ����ü ����
typedef struct {
    char id[50]; // ����� ID
    int isAdmin; // ���� ���� (1�̸� ����, 0�̸� �Ϲ� �����)
} User;

#define MAX_USERS 10
//extern = �ܺ� ���� ���
extern User users[MAX_USERS]; // �ִ� ����� ��
extern int userCount; // ���� ����� ��

// ����� �߰� �Լ�
int addUser(const char* id, int isAdmin);

// ����� ã�� �Լ�
int findUser(const char* id);

// ���� ��й�ȣ Ȯ�� �Լ�
int verifyAdminPassword();
