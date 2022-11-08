#include "student.h"

void Lesson::set()
{
	cout << "请输入课程名称：";
	cin >> lesson;
	cout << "请输入该课程分数：";
	cin >> score;
}
double Lesson::get_score()
{
	return score;
}
void Lesson::display()
{
	cout << "课程" << lesson << "的分数为" << score << endl;
}
void LessonList::setn(int n)
{
	this->n = n;
}
int LessonList::getn()
{
	return n;
}
void LessonList::Setlessons()
{
	for (int i = 0; i < n; i++)
	{
		Lesson grade;
		grade.set();
		lessons.push_back(grade);
	}
}
double LessonList::getsum()
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += lessons[i].get_score();
	}
	sum_score = sum;
	return sum;
}
double LessonList::getaver()
{
	average_score= sum_score / n;
	return average_score;
}
void LessonList::display1()
{
	getsum();
	getaver();
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ".";
		lessons[i].display();
	}
	cout << "总分为：" << sum_score<<endl;
	cout << "平均分为：" << average_score<<endl;
}
void LessonList::addlesson(int m)
{
	n += m;
	for (int i = 0; i < m; i++)
	{
		Lesson grade;

		grade.set();
		lessons.push_back(grade);
	}
	cout << "加入课程成功" << endl;
}
void LessonList::deletelesson(int m)
{
	n--;
	lessons.erase(lessons.begin() + m - 1);
	cout << "删除课程成功"<<endl;
}
void person::setname()
{
	cout << "请输入姓名：";
	cin >> name;
}
void person::showname()
{
	cout << name;
}
void student::Set(int n)
{
	setname();
	cout << "请输入学生学号：";
	cin >> num;
	Lessons.setn(n);
	Lessons.Setlessons();
	
}
void student::show()
{
	cout << "姓名：";
	showname();
	cout << ",学号：" << num<<endl;
	Lessons.display1();
	cout << "排名为：" << rink<<endl;
}
double student::get_sum()
{
	return Lessons.getsum();
}
void student::Setrink(int n)
{
	rink = n;
}
void student::Addlesson(int m)
{
	Lessons.addlesson(m);
}
void student::Deletelesson(int m)
{
	Lessons.deletelesson(m);
}
bool student::search1(string name)
{
	if (name == this->name)
	{
		return true;
	}
	else
		return false;
}
bool student::search2(int num)
{
	if (num == this->num)
	{
		return true;
	}
	else
		return false;
}
void Class::Setclass()
{
	cout << "请输入班级人数：";
	cin >> n;
	int t;
	cout << "请输入课程的数量：";
	cin >> t;
	for (int i = 0; i < n; i++)
	{
		student stu;
		stu.Set(t);
		Students.push_back(stu);
	}
}
void Class::getrink()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (Students[j].get_sum() < Students[j + 1].get_sum())
			{
				student stu = Students[j];
				Students[j] = Students[j + 1];
				Students[j + 1] = stu;
				
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		Students[i].Setrink(i + 1);
	}
}
void Class::Show()
{
	getrink();
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "." << endl;
		Students[i].show();
	}
}
void Class::addstudent(int m)
{
	n += m;
	for (int i = 0; i < m; i++)
	{
		student stu;
		stu.Set(Students[0].Lessons.getn());
		Students.push_back(stu);
		cout << "增加学生成功" << endl;
	}
	getrink();
	cout << "排名已更新"<<endl;
}
void Class::deletestudent(int m)
{
	n--;
	Students.erase(Students.begin() + m - 1);
	cout << "删除学生成功" << endl;
	getrink();
	cout << "排名已更新"<<endl;
}
void Class::ADDlesson(int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << "为";
		Students[i].showname();
		cout << "同学增加课程" << endl;
		Students[i].Addlesson(m);
	}
	getrink();
	cout << "排名已更新";
}
void Class::DELETElesson(int m)
{
	for (int i = 0; i < n; i++)
	{
		Students[i].Deletelesson(m);
	}
	getrink();
	cout << "排名已更新";
}
void Class::Search1(string name)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (Students[i].search1(name)!=0)
		{
			Students[i].show();
			break;
		}
	}
	if (i == n)
	{
		cout << "查无此人" << endl;
	}
}
void Class::Search2(int num)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (Students[i].search2(num) != 0)
		{
			Students[i].show();
			break;
		}
	}
	if (i == n)
	{
		cout << "查无此人" << endl;
	}
}

void Class::meau()
{
	cout << "~~~~~~~~欢迎使用学生管理系统~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~请选择你的身份~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~学生使用请按1~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~老师使用请按2~~~~~~~~~~~" << endl;
	int id;
	cin >> id;
	if (id == 1)
	{
		for (;;)
		{
			system("pause");
			system("cls");
			meau1();
		}
	}
	else if (id == 2)
	{	
		for (;;)
		{
			system("pause");
			system("cls");
			meau2();
		}
	}
	else
	{
		cout << "请输入正确的数字！" << endl;
		system("pause");
		system("CLS");
		meau();
	}
}

void Class::meau1()
{
	cout << "~~~~~~~~请选择你要使用的功能~~~~~~~~" << endl;
	cout << "~~~~~~~~~1.按姓名查找成绩~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~2.按学号查找成绩~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~0.退出使用~~~~~~~~~~~~~~~~" << endl;
	int id;
	cin >> id;
	if (id == 1)
	{
		string name;
		cout << "请输入想要查找的姓名：";
		cin >> name;
		Search1(name);
	}
	else if (id == 2)
	{
		int num;
		cout << "请输入想要查找的学号：";
		cin >> num;
		Search2(num);
	}
	else if (id == 0)
	{
		cout << "感谢您的使用！";
		system("pause");
		system("cls");
		meau();
	}
	else
		cout << "请输入正确的数字！" << endl;
}
void Class::meau2()
{
	cout << "~~~~~~~~请选择你要使用的功能~~~~~~~~" << endl;
	cout << "~~~~~~~~1.输入各位学生的信息~~~~~~~~" << endl;
	cout << "~~~~~~~~2.查看各位学生的成绩~~~~~~~~" << endl;
	cout << "~~~~~~~~3.增加学生~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~4.删除学生~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~5.增加课程~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~6.删除课程~~~~~~~~~~~~~~~~~" << endl;;
	cout << "~~~~~~~~7.按姓名查找成绩~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~8.按学号查找成绩~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~0.退出使用~~~~~~~~~~~~~~~~~" << endl;
	int id;
	cin >> id;
	switch (id)
	{
	case 1:
	{
		Setclass();
		cout << "录入信息完成！" << endl;
		break;
	}
	case 2:
	{
		Show();
		break;
	}
		
	case 3:
	{
		int m;
		cout << "请输入要增加的学生的人数：";
		cin >> m;
		addstudent(m);
		break;
	}
	case 4:
	{
		int m;
		cout << "请输入要删除第几位学生：";
		cin >> m;
		deletestudent(m);
		break;
	}
	case 5:
	{

		int m;
		cout << "请输入要增加的课程的数量：";
		cin >> m;
		ADDlesson(m);
		break;
	}
	case 6:
	{
		int m;
		cout << "请输入要删除第几门课程：";
		cin >> m;
		DELETElesson(m);
		break;
	}
	case 7:
	{
		string Name;
		cout << "请输入想要查找的姓名：";
		cin >> Name;
		Search1(Name);
		break;
	}
	case 8:
	{
		int Num;
		cout << "请输入想要查找的学号：";
		cin >> Num;
		Search2(Num);
		break;
	}
	case 0:
	{
		cout << "感谢使用！" << endl;
		system("pause");
		system("cls");
		meau();
	}
	default:
		cout << "请输入正确的数字！" << endl;
		break;
	}
}