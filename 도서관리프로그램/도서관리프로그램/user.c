#include "std.h"

User users[MAX_USERS]; // ����� �迭
int userCount = 0; // ���� ����� ��

// ����� �߰� �Լ�
int addUser(const char* id, int isAdmin) {
    // ���� ����� ���� �ִ� ����� ���� �ʰ��� ���
    if (userCount >= MAX_USERS) {
        return -1; // �߰� �Ұ��� ��Ÿ���� -1 ��ȯ
    }

    // ������� ID�� ����ü�� ���� (id ���ڿ��� users �迭�� id �ʵ忡 ����)
    strcpy_s(users[userCount].id, sizeof(users[userCount].id), id);

    // ���� ���� ���� (isAdmin ���� ���� ����)
    users[userCount].isAdmin = isAdmin;
    // ����� �� ����
    userCount++;

    return 0; // ���������� �߰��� ��� 0 ��ȯ
}
// ����� ã�� �Լ�
int findUser(const char* id) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// ���� ��й�ȣ Ȯ�� �Լ�
int verifyAdminPassword() {
    char password[50];
    printf("��й�ȣ�� �Է��ϼ���: ");
    scanf_s("%49s", password, (unsigned)sizeof(password));
    if (strcmp(password, "admin123") == 0) {
        return 1;
    }
    else {
        printf("��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
        return 0;
    }
}
