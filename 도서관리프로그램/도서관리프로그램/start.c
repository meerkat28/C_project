#include "std.h"

char currentUser[50]; // 현재 로그인한 사용자 ID를 저장

// 프로그램 초기화 함수

void program_init() {
    // 기본 어드민 계정 추가
    addUser("admin1", 1);
    addUser("admin2", 1);
    addUser("admin3", 1);
    
    printf("도서 관리 프로그램에 오신 것을 환영합니다!\n");
    printf("프로그램을 시작합니다.\n");

    // 로그인 루프
    while (login() == -1) {
        printf("로그인 실패. 다시 시도해주세요.\n");
    }

}

// 프로그램 시작 함수
void program_start() {
    int choice;
    while (1) {
        system("cls");
        // 메뉴 출력
        printf("\n도서 관리 프로그램 메뉴:\n");
        printf("1. 도서 목록 보기\n");
        printf("2. 도서 추가\n");
        printf("3. 도서 대출\n");
        printf("4. 도서 반납\n");
        printf("5. 로그아웃\n");
        printf("6. 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        // 사용자의 선택에 따른 동작 수행
        switch (choice) {
        case 1:
            display(); // 도서 목록 보기
          
            break;
        case 2:
            // 어드민 권한 확인 후 도서 추가
            if (users[findUser(currentUser)].isAdmin) {
                addBook();
            }
            else {
                printf("권한이 없습니다. 어드민 계정만 도서를 추가할 수 있습니다.\n");
            }
            break;
        case 3:
            lendBook(); // 도서 대출
            break;
        case 4:
            returnBook(); // 도서 반납
            break;
        case 5:
            logout(); // 로그아웃
            return;
        case 6:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
            break;
        }
        system("pause");
    }
}

// 프로그램 종료 함수
void program_exit() {
    printf("프로그램을 종료합니다.\n");
}

// 로그인 함수
int login() {
    char id[50];
    printf("사용자 ID를 입력하세요: ");
    scanf_s("%s", id, (unsigned)sizeof(id));

    int userIndex = findUser(id);
    if (userIndex == -1) {
        // 사용자가 없으면 새로 추가
        printf("사용자를 찾을 수 없습니다. 새로운 사용자로 등록합니다.\n");
        addUser(id, 0); // 일반 사용자로 등록
        strcpy_s(currentUser, sizeof(currentUser), id);
        return 0;
    }
    else if (users[userIndex].isAdmin) {
        // 어드민 사용자라면 비밀번호 확인
        if (verifyAdminPassword()) {
            printf("어드민으로 로그인되었습니다.\n");
            strcpy_s(currentUser, sizeof(currentUser), id);
            return userIndex;
        }
        else {
            return -1;
        }
    }
    else {
        // 일반 사용자 로그인
        printf("일반 사용자로 로그인되었습니다.\n");
        strcpy_s(currentUser, sizeof(currentUser), id);
        return userIndex;
    }
}

// 로그아웃 함수
void logout() {
    printf("로그아웃 되었습니다.\n");
    memset(currentUser, 0, sizeof(currentUser)); // 현재 사용자 ID 초기화
    while (login() == -1) {
        printf("로그인 실패. 다시 시도해주세요.\n");
    }
    program_start(); // 다시 프로그램 시작
}

int main() 
{
    
    setupFileSystem();
    program_init(); // 프로그램 초기화
    program_start(); // 프로그램 시작
    program_exit(); // 프로그램 종료

    return 0;
}
