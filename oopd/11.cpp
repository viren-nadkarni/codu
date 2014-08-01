#include <iostream>
#include <cstdlib>

using namespace std;

class StudentPersonal
{
	protected:
		int roll,age;
		string name,gender;
	public:
		void getDataSP(string n,int a,string g,int r)
		{
			name=n;
			gender=g;
			roll=r;
			age=a;
		};
		StudentPersonal(){};
};

class StudentScore:public StudentPersonal
{
	protected:
		int mark1,mark2,mark3,mark4;
	public:
		void getDataSSc(int m1,int m2,int m3,int m4)
		{
			mark1=m1;
			mark2=m2;
			mark3=m3;
			mark4=m4;
		};
		StudentScore(){};
};

class StudentSports
{
	protected:
		int score;
	public:
		void getDataSSp(int s)
		{
			score=s;
		};
		StudentSports(){};
};

class StudentResult:public StudentScore,public StudentSports
{
	private:
		float total,avg;
		char grade;
	public:
		void calc()
		{
			total=mark1+mark2+mark3+mark4+score;
			avg=total/5;
			
			if(avg>=90)
				grade='A';
			else if(avg>=80)
				grade='B';
			else if(avg>=70)
				grade='C';
			else if(avg>=60)
				grade='D';
			else grade='E';
		}
		void putData();
};

void StudentResult::putData()
{
	cout << "\nName: " << name << "\nAge: " << age << "\nGender: " << gender << "\nRoll Number: " << roll;
	cout << "\n\nSubject1: " << mark1 << "\nSubject2: " << mark2 << "\nSubject3: " << mark3 << "\nSubject4: " << mark4;
	cout << "\nSports: " << score << endl << endl;
	cout << "Total: " << total << "\nAverage: " << avg << "\nGrade: " << grade;
	
}

int main()
{
	cout << "$ StudentResult object is created\n";
	StudentResult obj;
	
	cout << "\n$ StudentPersonal object is created (\"Robert Quest\",18,\"Male\",64)\n";
	obj.getDataSP("Robert Quest",18,"Male",64);
	
	cout << "$ StudentScore object is created (91,75,69,88)\n";
	obj.getDataSSc(91,75,69,88);
	
	cout << "$ StudentSports object is created (95)\n";
	obj.getDataSSp(95);
	
	obj.calc();
	
	cout << "$ Calling StudentResult.PutData()\n";
	obj.putData();
	
	return 0;
}

