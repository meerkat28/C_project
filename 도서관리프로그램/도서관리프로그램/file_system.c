#include "std.h"

// ���� �ʱ�ȭ �Լ� 
void resetFiles() {
    FILE* books_file = fopen(BOOKS_FILE, "w");
    FILE* users_file = fopen(USERS_FILE, "w");

    if (books_file == NULL || users_file == NULL) {
        printf("������ �ʱ�ȭ�� �� �����ϴ�.\n");
        return;
    }

    fclose(books_file);
    fclose(users_file);

    printf("������ ���������� �ʱ�ȭ�Ǿ����ϴ�.\n");
}


/*
// ����� ��� �ҷ����� �Լ�
void loadUsers() {
    FILE* file = fopen(USERS_FILE, "r");
    if (file == NULL) {
        printf("����� ������ �ҷ��� �� �����ϴ�.\n");
        return;
    }

    char user_id[100];
    printf("����� ����� ���:\n");
    while (fgets(user_id, sizeof(user_id), file) != NULL) {
        printf("����� ID: %s", user_id);
    }
    fclose(file);
}
*/

// ���� �ý��� �ʱ�ȭ �Ǵ� �ҷ����� ����
void setupFileSystem() {
    char choice;
    printf("������ �ʱ�ȭ �Ͻðڽ��ϱ�? (y/n): ");
    scanf_s(" %c", &choice, sizeof(choice));

    if (choice == 'y' || choice == 'Y') {
        resetFiles();
    }
    else if (choice == 'n' || choice == 'N') {
        printf("���� ���� ������ �ҷ��ɴϴ�...\n");
        //loadUsers();
    }
    else {
        printf("�߸��� �Է��Դϴ�.\n");
    }
}