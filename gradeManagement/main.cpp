#include<iostream>
#include "util_manage.h"
#include "student.h";
using namespace std;

typedef struct {
	char menu;
	void(*fptr)();

}MenuFunc;

MenuFunc funcMap[] = {
	{'1', func_menu_1},
	{'2', func_menu_2},
	{'3', func_menu_3},
	{'4', func_menu_4},
	{'5', func_menu_5},
	{'6', func_menu_6},
	{'7', func_menu_7},
	{'8', func_menu_8},
	{'9', func_menu_9},
};

void showMenus() {
	cout << "1.  학생 정보 저장" << endl;
	cout << "2.  국어 점수 저장" << endl;
	cout << "3.  영어 점수 저장" << endl;
	cout << "4.  수학 점수 저장" << endl;
	cout << "5.  평균 점수 계산 및 저장" << endl;
	cout << "6.  전체 학생의 평균 계산 및 저장" << endl;
	cout << "7.  성적순 출력" << endl;
	cout << "8.  삭제" << endl;
	cout << "9.  전체 학생의 정보 출력" << endl;
	cout << "q.  종료" << endl;
}

int excuteMenu(char menu) {

	int result = 1;

	if (menu < '1' || menu > '9') {
		cout << "잘못된 입력입니다." << endl;
		return 0;
	}

	for (int i = 0; i < sizeof(funcMap) / sizeof(MenuFunc); i++) {
		if (funcMap[i].menu == menu) {
			funcMap[i].fptr();
			result = true;
			break;
		}
	}

	return result;
}

int main() {
	showMenus();

	while (1) {
		char menu = NULL;

		cout << "\r\n실행할 메뉴를 선택하세요: " << endl;
		cin >> menu;

		if (menu == 'q') {
			cout << "프로그램을 종료합니다" << endl;
			break;
		}

		if (!excuteMenu(menu)) {
			cout << "잘못된 명령입니다. 다시 메뉴를 선택하세요 \n" << endl;
		}

	}

}