#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Lesson
{
	string lesson;
	double score;

public :
	void set();
	double get_score();
	void display();
};
class LessonList
{
	double sum_score;
	double average_score;
	vector<Lesson>lessons;
	int n;
public:
	void setn(int n);
	int getn();
	void Setlessons();
	double getsum();
	double getaver();
	void display1();
	void addlesson(int n);
	void deletelesson(int n);
};

class person
{
protected:
	string name;
public:
	void setname();
	void showname();
};
class student:public person
{
	int num;//ѧ��
	int rink;//����		
public:
	LessonList Lessons;//�γ̳ɼ�
	void Set(int n);
	void Setrink(int n);
	void show();
	double get_sum();
	void Addlesson(int m);
	void Deletelesson(int m);
	bool search1(string name);
	bool search2(int num);
};

class Class//�༶��
{
	vector<student>Students;
	int n;//�༶����
public:
	void Setclass();
	void getrink();
	void Show();
	void addstudent(int);
	void deletestudent(int);
	void ADDlesson(int);
	void DELETElesson(int);
	void Search1(string name);
	void Search2(int num);
	void meau();
	void meau1();
	void meau2();
};