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
    virtual void display() ;
    virtual ~Student(){}  //为了析构链能完全执行声明为虚析构
protected:
    int num;
    string name; //error:在背继承时会发现归属不明的错误
    float score;
};

Student::Student(int n,string nam,float s)
{
    num=n;
    name=nam;
    score=s;
}

void Student::display()
{
    cout<<"num:"<<num<<"\n name:"<<name<<"\n score;"<<score<<"\n\n";
}

class Graduate:public virtual Student // error: if don't have keyword virtual
{
public:
    Graduate(int,string,float,float);
    void display();
private:
    string name1;//重新声明并且不同命
    float pay;
};
Graduate::Graduate(int n,string nam,float s,float p):Student(n,name,s),name1(nam),pay(p)
{

}
void Graduate::display()
{
    //
    cout<<"num:"<<num<<"\n name:"<<name1<<"\n score:"<<score<<"\n pay:"<<pay<<endl;
}



int main()
{
    Student stud1(1001,"Li",87.5);
    Student *pt=&stud1;
    pt->display();
    Graduate grad1(1001,"Li",87.5,563.5);
    pt=&grad1;
    pt->display();
    return 0;
}
