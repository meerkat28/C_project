#pragma once

#define MAX_USERS 100
#define MAX_ADMINS 3
#define PASSWORD "admin123"

// ����� ����ü ����
typedef struct {
    char id[50]; // ����� ID
    int isAdmin; // ���� ����
} User;

extern User users[MAX_USERS]; // ����� �迭
extern int userCount; // ���� ����� ��

// ����� �߰� �Լ�
void addUser(const char* id, int isAdmin);

// ����� ã�� �Լ�
int findUser(const char* id);

// ���� ��й�ȣ Ȯ�� �Լ�
int verifyAdminPassword();
