#include<iostream>
#include "util_manage.h"
#include "student.h";

using namespace std;
	
Student std1[100];
char name[30];
int id;
int checkId;
int kor;
int eng;
int math;
double avg;
int i = 0;

void errCheck()
{
	if (!cin)
	{
		cout << "\n" << "숫자만 입력 가능합니다" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

	}
}




void func_menu_1() {
	int j = 0;
	cout << "학생 이름을 입력하세요 : ";
	cin >> name;
	cout << "학번을 입력하세요 : ";
	cin >> id;
	
	errCheck();

	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == id)
			break;
	}

	if (std1[j].getStudentId() == id)
	{
		cout << "중복된 학번이 존재합니다." << endl;

	}


	else if (id > 0)
	{
		std1[i].setStudentName(name);
		std1[i].setStudentId(id);
		i++;
		
	}

	else
		cout << "잘못된 ID형식입니다." << endl;

}
void func_menu_2() {
	int j = 0;
	cout << "입력할 학생의 학번을 입력하세요 : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "학번입력이 잘못되었습니다." << endl;

	}
	else
	{ 	
		cout << "국어점수를 입력하세요 : ";
		cin >> kor;
		std1[j].setKoreaGrade(kor);
	}
}
void func_menu_3() {
	int j = 0;
	cout << "입력할 학생의 학번을 입력하세요 : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
		break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "학번입력이 잘못되었습니다." << endl;

	}
	else
	{ 
		cout << "영어점수를 입력하세요 : ";
		cin >> eng;
		std1[j].setEnglishGrade(eng);
	}
}
void func_menu_4() {
	int j = 0;
	cout << "입력할 학생의 학번을 입력하세요 : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "학번입력이 잘못되었습니다." << endl;
		
	}
	else
	{ 
		cout << "수학점수를 입력하세요 : ";
		cin >> math;
		std1[j].setMathGrade(math);
	}
}
void func_menu_5() {
	int j = 0;
	cout << "평균점수를 계산할 학생의 학번을 입력하세요 : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "학번입력이 잘못되었습니다." << endl;

	}

	else
	{ 
		cout << checkId<<" 학번 학생의 평균점수 계산이 완료되었습니다."<<endl;
		std1[j].calculateAverage();
	}
}
void func_menu_6() {
	int j = 0;
	for (j = 0; j < i; j++)
	{
		std1[j].calculateAverage();
	}
	cout << "전체학생 평균점수 계산이 완료되었습니다.  "<<endl;
}


void func_menu_7() {
	bool isSwap;
	do {
		isSwap = false;
		for (int j = 1; j < i; j++)
		{
			if (std1[j - 1].getAvg() < std1[j].getAvg()) 
			{ 
				swap(std1[j - 1], std1[j]);
				isSwap = true;
			} 
		}
	} while (isSwap);

	
	for (int j = 0; j < i; j++)
		std1[j].showStudentInfo();


}
void func_menu_8() {
	int j = 0;
	size_t a;
	cout << "삭제할 학생의 학번을 입력하세요 : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "학번입력이 잘못되었습니다." << endl;

	}
	
	else
	{
		for (a = j; a < i; a++)
		{
			std1[a] = std1[a + 1];
		}
		--i;
	}
}
void func_menu_9() {
	for(int j = 0;j<i;j++)
		std1[j].showStudentInfo();
}
