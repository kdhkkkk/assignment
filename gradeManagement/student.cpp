#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "student.h";

using namespace std;

Student::Student(const char* name, int id, int kor, int eng, int math) {
	strcpy(this->name, name);
	this->id = id;
	this->kor = kor;
	this->eng = eng;
	this->math = math;
	this->avg = NULL;
}

char Student::getStudentName()
{
	return *name;
}

void Student::setStudentName(char* name)
{
	strcpy(this->name, name);
}

int Student::getStudentId()
{
	return id;
}

void Student::setStudentId(int id)
{
	this->id = id;
}
int Student::getKoreaGrade() {
	return kor;
}
void Student::setKoreaGrade(int kor) {
	this->kor = kor;
}
int Student::getEnglishGrade() {
	return eng;
}
void Student::setEnglishGrade(int eng) {
	this->eng = eng;
}
int Student::getMathGrade() {
	return math;
}
void Student::setMathGrade(int math) {
	this->math = math;
}

void Student::calculateAverage() {
	avg = (double)(kor + eng + math) / 3.0;

}


int Student::getAvg() {
	return avg;
}
void Student::showStudentInfo() {
	cout << fixed;
	cout.precision(2);
	cout << "이름 : " << name << ", ID : " << id << ", 국어점수 : " << kor << ", 영어점수 : " << eng << ", 수학점수 : " << math << ", 평균 : " << avg << endl;
}