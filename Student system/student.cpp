#include "student.h"

void Lesson::set()
{
	cout << "������γ����ƣ�";
	cin >> lesson;
	cout << "������ÿγ̷�����";
	cin >> score;
}
double Lesson::get_score()
{
	return score;
}
void Lesson::display()
{
	cout << "�γ�" << lesson << "�ķ���Ϊ" << score << endl;
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
	cout << "�ܷ�Ϊ��" << sum_score<<endl;
	cout << "ƽ����Ϊ��" << average_score<<endl;
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
	cout << "����γ̳ɹ�" << endl;
}
void LessonList::deletelesson(int m)
{
	n--;
	lessons.erase(lessons.begin() + m - 1);
	cout << "ɾ���γ̳ɹ�"<<endl;
}
void person::setname()
{
	cout << "������������";
	cin >> name;
}
void person::showname()
{
	cout << name;
}
void student::Set(int n)
{
	setname();
	cout << "������ѧ��ѧ�ţ�";
	cin >> num;
	Lessons.setn(n);
	Lessons.Setlessons();
	
}
void student::show()
{
	cout << "������";
	showname();
	cout << ",ѧ�ţ�" << num<<endl;
	Lessons.display1();
	cout << "����Ϊ��" << rink<<endl;
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
	cout << "������༶������";
	cin >> n;
	int t;
	cout << "������γ̵�������";
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
		cout << "����ѧ���ɹ�" << endl;
	}
	getrink();
	cout << "�����Ѹ���"<<endl;
}
void Class::deletestudent(int m)
{
	n--;
	Students.erase(Students.begin() + m - 1);
	cout << "ɾ��ѧ���ɹ�" << endl;
	getrink();
	cout << "�����Ѹ���"<<endl;
}
void Class::ADDlesson(int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Ϊ";
		Students[i].showname();
		cout << "ͬѧ���ӿγ�" << endl;
		Students[i].Addlesson(m);
	}
	getrink();
	cout << "�����Ѹ���";
}
void Class::DELETElesson(int m)
{
	for (int i = 0; i < n; i++)
	{
		Students[i].Deletelesson(m);
	}
	getrink();
	cout << "�����Ѹ���";
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
		cout << "���޴���" << endl;
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
		cout << "���޴���" << endl;
	}
}

void Class::meau()
{
	cout << "~~~~~~~~��ӭʹ��ѧ������ϵͳ~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~��ѡ��������~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ѧ��ʹ���밴1~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~��ʦʹ���밴2~~~~~~~~~~~" << endl;
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
		cout << "��������ȷ�����֣�" << endl;
		system("pause");
		system("CLS");
		meau();
	}
}

void Class::meau1()
{
	cout << "~~~~~~~~��ѡ����Ҫʹ�õĹ���~~~~~~~~" << endl;
	cout << "~~~~~~~~~1.���������ҳɼ�~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~2.��ѧ�Ų��ҳɼ�~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~0.�˳�ʹ��~~~~~~~~~~~~~~~~" << endl;
	int id;
	cin >> id;
	if (id == 1)
	{
		string name;
		cout << "��������Ҫ���ҵ�������";
		cin >> name;
		Search1(name);
	}
	else if (id == 2)
	{
		int num;
		cout << "��������Ҫ���ҵ�ѧ�ţ�";
		cin >> num;
		Search2(num);
	}
	else if (id == 0)
	{
		cout << "��л����ʹ�ã�";
		system("pause");
		system("cls");
		meau();
	}
	else
		cout << "��������ȷ�����֣�" << endl;
}
void Class::meau2()
{
	cout << "~~~~~~~~��ѡ����Ҫʹ�õĹ���~~~~~~~~" << endl;
	cout << "~~~~~~~~1.�����λѧ������Ϣ~~~~~~~~" << endl;
	cout << "~~~~~~~~2.�鿴��λѧ���ĳɼ�~~~~~~~~" << endl;
	cout << "~~~~~~~~3.����ѧ��~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~4.ɾ��ѧ��~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~5.���ӿγ�~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~6.ɾ���γ�~~~~~~~~~~~~~~~~~" << endl;;
	cout << "~~~~~~~~7.���������ҳɼ�~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~8.��ѧ�Ų��ҳɼ�~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~0.�˳�ʹ��~~~~~~~~~~~~~~~~~" << endl;
	int id;
	cin >> id;
	switch (id)
	{
	case 1:
	{
		Setclass();
		cout << "¼����Ϣ��ɣ�" << endl;
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
		cout << "������Ҫ���ӵ�ѧ����������";
		cin >> m;
		addstudent(m);
		break;
	}
	case 4:
	{
		int m;
		cout << "������Ҫɾ���ڼ�λѧ����";
		cin >> m;
		deletestudent(m);
		break;
	}
	case 5:
	{

		int m;
		cout << "������Ҫ���ӵĿγ̵�������";
		cin >> m;
		ADDlesson(m);
		break;
	}
	case 6:
	{
		int m;
		cout << "������Ҫɾ���ڼ��ſγ̣�";
		cin >> m;
		DELETElesson(m);
		break;
	}
	case 7:
	{
		string Name;
		cout << "��������Ҫ���ҵ�������";
		cin >> Name;
		Search1(Name);
		break;
	}
	case 8:
	{
		int Num;
		cout << "��������Ҫ���ҵ�ѧ�ţ�";
		cin >> Num;
		Search2(Num);
		break;
	}
	case 0:
	{
		cout << "��лʹ�ã�" << endl;
		system("pause");
		system("cls");
		meau();
	}
	default:
		cout << "��������ȷ�����֣�" << endl;
		break;
	}
}