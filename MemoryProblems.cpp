#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
    Student(int,string,float);
  virtual void display()const ;
protected:
    int num;
	string name;
	float score;
};

Student::Student(int n,string nam,float s)
{num=n;name=nam;score=s;}

void Student::display()const
{
	cout<<"num:"<<num<<"\nname:"<<name<<"\nscore;"<<score<<"\n\n";
}

class Graduate:public Student
{
public:
	Graduate(int,string,float,float);
	void display()const;
private:
	float pay;
};

void Graduate::display()const
{
	cout<<"num:"<<num<<"\nname:"<<name<<"\nscore:"<<score<<"\npay:"<<pay<<endl;
}

Graduate::Graduate(int n,string nam,float s,float p):Student(n,name,s),pay(p){}

int main()
{
Student stud1(1001,"Li",87.5);
Graduate grad1(1001,"Li",87.5,563.5);

Student *pt=&stud1;
pt->display();

pt=&grad1;
pt->display();
return 0;
}
//-------------------------------------------------------------------------------------------
/**
 * 作者：ChenYue
 * date：2012.12.05
 * */
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
    Student(int,string,float);
  virtual void display()const ;
protected:
    int num;
string name;
float score;
};

Student::Student(int n,string nam,float s)
{num=n;name=nam;score=s;}

void Student::display()const
{
cout<<"num:"<<num<<"\nname:"<<name<<"\nscore;"<<score<<"\n\n";
}

class Graduate:public Student
{
public:
Graduate(int,string,float,float);
void display()const;
private:
float pay;
};

void Graduate::display()const
{
cout<<"num:"<<num<<"\nname:"<<name<<"\nscore:"<<score<<"\npay:"<<pay<<endl;
}

Graduate::Graduate(int n,string nam,float s,float p):Student(n,nam,s),pay(p){}

int main()
{
Student stud1(1001,"Li",87.5);
Graduate grad1(1001,"Li",87.5,563.5);

Student *pt=&stud1;
pt->display();

pt=&grad1;
pt->display();
return 0;
}

