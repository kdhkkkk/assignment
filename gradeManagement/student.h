class Student {
private:
	int id;
	char name[30];
	int kor;
	int eng;
	int math;
	double avg;

public:
	Student(const char* name = "null" , int id = -1, int kor = -1, int eng = -1, int math = -1);


	char getStudentName();
	void setStudentName(char *name);
	int getStudentId();
	void setStudentId(int id);
	int getKoreaGrade();
	void setKoreaGrade(int kor);
	int getEnglishGrade();
	void setEnglishGrade(int eng);
	int getMathGrade();
	void setMathGrade(int math);
	int getAvg();
	void calculateAverage();
	void showStudentInfo();
};