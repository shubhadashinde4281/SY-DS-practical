#include<iostream>
#include<string>

using namespace std;

struct Employee
{
	int employeeId;
	string employeeName;
	float Salary;
	Node *next;
};
	Node *head=NULL;
	
	void insert()
	{
		cout<<"Enter Employee Id:";
		cin>>newNode->employeeId;
		
		cout<<"Enter Employee Name:";
		cin>>newNode->employeeName;
		
		cout<<"Enter Employee Salary:"
		cin>>newNode->Salary;
		
		
		newNode->next=head;
		head=newNode;
		
		cout<<"Employee Record Inserted Successfully.\n";
	}
	
	void deleteNode(int id)
	{
		if(head == NULL)
		{
			cout<<"List is empty.\n";
			return;
		}
		
		Node *temp = head;
		Node *prev = NULL;
		
		if(head->empId==id)
		{
			
			head= head->next;
			delete temp;
			cout<<"Employee Record Deleted Successfully.\n"
			return;
		}
		while(temp !=NULL && temp->employeeId !=id)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp == NULL)
		{
			cout<<"Employee Record Not Found.\n";
			return;
		}
		
		prev->next=temp->next;
		delete temp;
		
		cout<<"Employee Record Deleted Successfully.\n";
	}
	
	void search(int id)
	{
		Node *temp = head;
		
		while (temp !=NULL)
		{
			if(temp->employeeId==id)
			{
				cout<<"\n Employee Found";
				cout<<"Employee ID:"<<temp->employeeId<<endl;
				cout<<"Employee Name:"<<temp->employeeName<<endl;
				cout<<"Employee Salary:"<<temp->Salary<<endl;
				return;
			}
			temp=temp->next;
		}
		cout<<"Employee Record Not Found.\n";
	}
	
	void display()
	{
		if(head==NULL)
		{
			cout<<"List is Empty.\n";
			return;
		}
		
		Node *temp = head;
		cout<<"\n Employee Records\n";
		cout<<"-------------------------------------\n";
		
		while(temp != NULL)
		{
			cout<<"ID :"<<temp->employeeId;
			cout<<"\t Name:"<<temp->employeeName;
			cout<<"\t Salary:"<<temp->Salary<<endl;
			
			temp = temp->next
		
		}
	}
int main()
{
	
}