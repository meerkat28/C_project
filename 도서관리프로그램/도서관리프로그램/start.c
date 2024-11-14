#include "std.h"

char currentUser[50]; // ���� �α����� ����� ID�� ����

// ���α׷� �ʱ�ȭ �Լ�

void program_init() {
    // �⺻ ���� ���� �߰�
    addUser("admin1", 1);
    addUser("admin2", 1);
    addUser("admin3", 1);
    
    printf("���� ���� ���α׷��� ���� ���� ȯ���մϴ�!\n");
    printf("���α׷��� �����մϴ�.\n");

    // �α��� ����
    while (login() == -1) {
        printf("�α��� ����. �ٽ� �õ����ּ���.\n");
    }

}

// ���α׷� ���� �Լ�
void program_start() {
    int choice;
    while (1) {
        system("cls");
        // �޴� ���
        printf("\n���� ���� ���α׷� �޴�:\n");
        printf("1. ���� ��� ����\n");
        printf("2. ���� �߰�\n");
        printf("3. ���� ����\n");
        printf("4. ���� �ݳ�\n");
        printf("5. �α׾ƿ�\n");
        printf("6. ���α׷� ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        // ������� ���ÿ� ���� ���� ����
        switch (choice) {
        case 1:
            display(); // ���� ��� ����
          
            break;
        case 2:
            // ���� ���� Ȯ�� �� ���� �߰�
            if (users[findUser(currentUser)].isAdmin) {
                addBook();
            }
            else {
                printf("������ �����ϴ�. ���� ������ ������ �߰��� �� �ֽ��ϴ�.\n");
            }
            break;
        case 3:
            lendBook(); // ���� ����
            break;
        case 4:
            returnBook(); // ���� �ݳ�
            break;
        case 5:
            logout(); // �α׾ƿ�
            return;
        case 6:
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
            break;
        }
        system("pause");
    }
}

// ���α׷� ���� �Լ�
void program_exit() {
    printf("���α׷��� �����մϴ�.\n");
}

// �α��� �Լ�
int login() {
    char id[50];
    printf("����� ID�� �Է��ϼ���: ");
    scanf_s("%s", id, (unsigned)sizeof(id));

    int userIndex = findUser(id);
    if (userIndex == -1) {
        // ����ڰ� ������ ���� �߰�
        printf("����ڸ� ã�� �� �����ϴ�. ���ο� ����ڷ� ����մϴ�.\n");
        addUser(id, 0); // �Ϲ� ����ڷ� ���
        strcpy_s(currentUser, sizeof(currentUser), id);
        return 0;
    }
    else if (users[userIndex].isAdmin) {
        // ���� ����ڶ�� ��й�ȣ Ȯ��
        if (verifyAdminPassword()) {
            printf("�������� �α��εǾ����ϴ�.\n");
            strcpy_s(currentUser, sizeof(currentUser), id);
            return userIndex;
        }
        else {
            return -1;
        }
    }
    else {
        // �Ϲ� ����� �α���
        printf("�Ϲ� ����ڷ� �α��εǾ����ϴ�.\n");
        strcpy_s(currentUser, sizeof(currentUser), id);
        return userIndex;
    }
}

// �α׾ƿ� �Լ�
void logout() {
    printf("�α׾ƿ� �Ǿ����ϴ�.\n");
    memset(currentUser, 0, sizeof(currentUser)); // ���� ����� ID �ʱ�ȭ
    while (login() == -1) {
        printf("�α��� ����. �ٽ� �õ����ּ���.\n");
    }
    program_start(); // �ٽ� ���α׷� ����
}

int main() 
{
    
    setupFileSystem();
    program_init(); // ���α׷� �ʱ�ȭ
    program_start(); // ���α׷� ����
    program_exit(); // ���α׷� ����

    return 0;
}
