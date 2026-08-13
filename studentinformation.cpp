#include<iostream>

using namespace std;

struct Student
{
	int rollNo;
	char name[50];
	string email;
	float marks;
	
};

void addStudent(Student*s,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter Student Details:"<<i+1<<endl;
		
		cout<<"\n Student roll no:";
		cin>>s[i].rollNo;
		
		cout<<"\n Student Name:";
		cin>>s[i].name;
		
		cout<<"\n Student Email:";
		cin>>s[i].email;
		
		cout<<"\n Student Marks:";
		cin>>s[i].marks;
			}
}
	
	void displayStudent(Student*s,int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"\n Student:"<<i+1<<endl;  
			cout<<"\n Roll No:"<<(s+i)->rollNo<<endl;
			cout<<"\n Student Name:"<<(s+i)->name<<endl;
			cout<<"\n Student Email:"<<(s+i)->email<<endl;
			cout<<"\n Student Marks:"<<(s+i)->marks<<endl;                            
		}
	}
int main()
{
	
	int n;
	
	cout<<"\n Enter Number Of Student:";
	cin>>n;
	
	Student s[n];
	
	addStudent(s,n);
	displayStudent(s,n);
	
}

