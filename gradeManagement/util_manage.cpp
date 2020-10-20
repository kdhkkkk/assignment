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
		cout << "\n" << "���ڸ� �Է� �����մϴ�" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

	}
}




void func_menu_1() {
	int j = 0;
	cout << "�л� �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> id;
	
	errCheck();

	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == id)
			break;
	}

	if (std1[j].getStudentId() == id)
	{
		cout << "�ߺ��� �й��� �����մϴ�." << endl;

	}


	else if (id > 0)
	{
		std1[i].setStudentName(name);
		std1[i].setStudentId(id);
		i++;
		
	}

	else
		cout << "�߸��� ID�����Դϴ�." << endl;

}
void func_menu_2() {
	int j = 0;
	cout << "�Է��� �л��� �й��� �Է��ϼ��� : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "�й��Է��� �߸��Ǿ����ϴ�." << endl;

	}
	else
	{ 	
		cout << "���������� �Է��ϼ��� : ";
		cin >> kor;
		std1[j].setKoreaGrade(kor);
	}
}
void func_menu_3() {
	int j = 0;
	cout << "�Է��� �л��� �й��� �Է��ϼ��� : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
		break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "�й��Է��� �߸��Ǿ����ϴ�." << endl;

	}
	else
	{ 
		cout << "���������� �Է��ϼ��� : ";
		cin >> eng;
		std1[j].setEnglishGrade(eng);
	}
}
void func_menu_4() {
	int j = 0;
	cout << "�Է��� �л��� �й��� �Է��ϼ��� : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "�й��Է��� �߸��Ǿ����ϴ�." << endl;
		
	}
	else
	{ 
		cout << "���������� �Է��ϼ��� : ";
		cin >> math;
		std1[j].setMathGrade(math);
	}
}
void func_menu_5() {
	int j = 0;
	cout << "��������� ����� �л��� �й��� �Է��ϼ��� : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "�й��Է��� �߸��Ǿ����ϴ�." << endl;

	}

	else
	{ 
		cout << checkId<<" �й� �л��� ������� ����� �Ϸ�Ǿ����ϴ�."<<endl;
		std1[j].calculateAverage();
	}
}
void func_menu_6() {
	int j = 0;
	for (j = 0; j < i; j++)
	{
		std1[j].calculateAverage();
	}
	cout << "��ü�л� ������� ����� �Ϸ�Ǿ����ϴ�.  "<<endl;
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
	cout << "������ �л��� �й��� �Է��ϼ��� : ";
	cin >> checkId;
	errCheck();
	for (j = 0; j < i; j++)
	{
		if (std1[j].getStudentId() == checkId)
			break;
	}

	if (std1[j].getStudentId() != checkId)
	{
		cout << "�й��Է��� �߸��Ǿ����ϴ�." << endl;

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
