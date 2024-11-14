#include "std.h"

static Book books[MAX_BOOKS]; // ���� �迭
static int bookCount = 0; // ���� ���� ��
static char currentUser[50]; // ���� �α����� ����� ID

// ���� �߰� �Լ�
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("������ �߰��� �� �����ϴ�. �ִ� ���� ���� �����߽��ϴ�.\n");
        return;
    }

    char title[50], author[50];
    int year;

    // ���� ���� �Է�
    printf("���� ����: ");
    getchar(); // �Է� ������ ���� ���� ����
    scanf_s("%s", title, sizeof(title));
  //  gets_s(title, sizeof(title));

    printf("����: ");
    getchar();
    scanf_s("%s", author,sizeof(author));
  //  gets_s(author, sizeof(author));

    printf("���� ����: ");
    scanf_s("%d", &year);

    // ���� �ʱ�ȭ �� �߰�
    initBook(&books[bookCount++], title, author, year);
    printf("������ �߰��Ǿ����ϴ�.\n");
}

// ���� ��� ���� �Լ�
void display() {
    if (bookCount == 0) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    printf("\n���� ���:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. ", i + 1);
        printBook(&books[i]);
    }
}

// ���� ���� �Լ�
void lendBook() {
    int lentCount = 0;

    printf("\n���� ������ ���� ���:\n");
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isLent) {
            printf("%d. ", i + 1);
            printBook(&books[i]);
            lentCount++;
        }
    }

    if (lentCount == 0) {
        printf("���� ������ ������ �����ϴ�.\n");
        return;
    }

    int choice;
    printf("������ ���� ��ȣ�� �Է��ϼ���: ");
    scanf_s("%d", &choice);

    if (choice < 1 || choice > bookCount || books[choice - 1].isLent) {
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    books[choice - 1].isLent = 1; // ���� ���� ���·� ����
    printf("'%s' ������ ����Ǿ����ϴ�.\n", books[choice - 1].title);
}

// ���� �ݳ� �Լ�
void returnBook() {
    int borrowedCount = 0;

    printf("\n���� ���� ���� ���:\n");
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isLent) {
            printf("%d. ", i + 1);
            printBook(&books[i]);
            borrowedCount++;
        }
    }

    if (borrowedCount == 0) {
        printf("���� ���� ������ �����ϴ�.\n");
        return;
    }

    int choice;
    printf("�ݳ��� ���� ��ȣ�� �Է��ϼ���: ");
    scanf_s("%d", &choice);

    if (choice < 1 || choice > bookCount || !books[choice - 1].isLent) {
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    books[choice - 1].isLent = 0; // ���� �ݳ� ���·� ����
    printf("'%s' ������ �ݳ��Ǿ����ϴ�.\n", books[choice - 1].title);
}
