#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<ctype.h>
using namespace std;;
//								Factory Management System 
//Class of Node
class Node
{
	private:
		string UserName;
		string Password;
		int EmployeeID;
		int EmployeeWH;
		string EmployeeName;
		string PhoneNo;
		int EmployeeRank;
		string EmployeeCNIC;
		string EmployeeDept;
		float grossSalary;
		float netSalary;
		float HourlyWage;
		Node* next;
	
	public:
		void SetHourlyWage(float);
		float GetHourlyWage();
		void SetgrossSalary(float);
		void SetnetSalary(float);
		float GetgrossSalary();
		float GetnetSalary();
		void SetEmployeeID(int);
		void SetEmployeeName(string);
		void SetPhoneNo(string);
		int GetEmployeeID();
		string GetEmployeeName();
		string GetPhoneNo();
		void SetEmployeeRank(int);
		void SetEmployeeWH(int);	
		void SetEmployeeCNIC(string);
		void SetEmployeeDept(string);
		int GetEmployeeRank();
		int GetEmployeeWH();
		string GetEmployeeCNIC();
		string GetEmployeeDept();
		void SetNext(Node*);
		Node* GetNext();
};
void  Node::SetHourlyWage(float HW)
{
	this->HourlyWage=HW;
}
float Node::GetHourlyWage()
{
	return this->HourlyWage;
}
float Node::GetnetSalary()
{
	return this->netSalary;
}
void Node::SetgrossSalary(float gs)
{
	this->grossSalary=gs;
}
void Node::SetnetSalary(float ns)
{
	this->netSalary=ns;
}
float Node::GetgrossSalary()
{
	return this->grossSalary;
}
void Node::SetNext(Node* Next)
{
	this->next=Next;
}
Node* Node::GetNext()
{
	return this->next;
}
void Node::SetEmployeeID(int ID)
{
	EmployeeID=ID;
}
void Node::SetEmployeeName(string Name)
{
	EmployeeName=Name;
}
void Node::SetPhoneNo(string phoneNo)
{
	PhoneNo=phoneNo;
}
void Node::SetEmployeeRank(int Rank)
{
	EmployeeRank=Rank;
}
void Node::SetEmployeeWH(int wh)
{
	EmployeeWH=wh;
}
void Node::SetEmployeeCNIC(string CNIC)
{
	EmployeeCNIC=CNIC;
}
void Node::SetEmployeeDept(string Department)
{
	EmployeeDept=Department;
}

//Getter
int Node::GetEmployeeWH()
{
	return this->EmployeeWH;
}
int Node::GetEmployeeID()
{
	return this->EmployeeID;
}
string Node::GetEmployeeName()
{
	return this->EmployeeName;
}
string Node::GetPhoneNo()
{
	return this->PhoneNo;
}
int Node::GetEmployeeRank()
{
	return this->EmployeeRank;
}
string Node::GetEmployeeCNIC()
{
	return this->EmployeeCNIC;
}
string Node::GetEmployeeDept()
{
	return this->EmployeeDept;
}

//List Class
class SinglyList
{
	private:
		Node* CurrentLocation;
	
	public:
		SinglyList();
		void SetCurrentLocation(Node*);
		bool Registration();
		bool Login();
		void AddEmployee(string,string,int,int,string,string,int);
		void SearchEmployee(int);
		void DeleteEmployee(int);
		void PrintEmployee();
		void Menu();
		void EmployeeMenu();
		void AdminMenu();
		void ManagerMenu();
		void CalculateSal();
		void Attendance();
		void SaveInFile();
		void Hourlywage(Node*);	
		bool CheckString(string);
		bool CheckStringAlph(string);
		void UpdateEmployee();
		void AddEmployeeInMenu();
};
void SinglyList::AddEmployeeInMenu()
{
		int Emp_ID,emp_rank,emp_WH;
		string emp_Name,emp_phone,emp_CNIC,emp_dept;
		cout<<"ENTER PHONE NUMBER OF THE WORKER --> ";
		cin>>emp_phone;
		while(CheckString(emp_phone))
		{
			cout<<"WRONG INPUT !!!!!"<<endl;
			cout<<"ENTER PHONE NUMBER OF THE WORKER --> ";
			cin>>emp_phone;
		}
		cout<<"ENTER NAME OF THE WORKER --> ";
		cin.ignore();
		getline(cin,emp_Name);
		while(CheckStringAlph(emp_Name))
		{
			cout<<"WRONG INPUT !!!"<<endl;
			cout<<"ENTER NAME OF THE WORKER --> ";
			getline(cin,emp_Name);
		}
		cout<<"ENTER CNIC OF THE WORKER --> ";
		getline(cin,emp_CNIC);
		while(CheckString(emp_CNIC))
		{
			cout<<"WRONG INPUT !!!"<<endl;
			cout<<"ENTER CNIC OF THE WORKER --> ";
			getline(cin,emp_CNIC);
		}
		while(emp_CNIC.size()<13 || emp_CNIC.size()>13)
		{
			cout<<"Length of CNIC is not correct !!!"<<endl;
			cout<<"Enter CNIC of the worker --> ";
			getline(cin, emp_CNIC);
		}
		cout<<"ENTER DEPERTMENT OF THE WORKER --> ";
		getline(cin, emp_dept);
		while(CheckStringAlph(emp_dept))
		{
			cout<<"Wrong INPUT!!!"<<endl;
			cout<<"ENTER DEPERTMENT OF THE WORKER --> ";
			getline(cin, emp_dept);
		}
		
		string user_string_num="";
		stringstream ss;
		int is_num=0,decimal_count=0,user_converted_num;
		bool is_num_bool=0;
		do
		{
			cout<<"ENTER ID OF THE WORKER --> ";
			cin>>user_string_num;
			if(user_string_num[0]=='-')
				is_num++;
			if(user_string_num[0]=='0' && isdigit(user_string_num[1]))
				is_num=0;
			else
			{
				for(int i=0;i<user_string_num.size();i++)
				{
					if(isdigit(user_string_num[i]))
						is_num++;
					if(user_string_num[i]=='.')
						decimal_count++;
				}
			}
			if(decimal_count==1)
				is_num=0;
			if(is_num==user_string_num.size())
			{
				stringstream str_stream_object(user_string_num);
				str_stream_object>>user_converted_num;
				is_num_bool=1;
			}
			else
			{
				cout<<"Error !!!"<<endl;
				cin.clear();
				is_num_bool=0;
				is_num=0;
				decimal_count=0;
			}
		} while(is_num_bool==0);
		ss<<user_string_num;
		ss>>Emp_ID;
		user_string_num="";
		stringstream ssr;
		is_num=0,decimal_count=0,user_converted_num;
		is_num_bool=0;
		do
		{
			cout<<"ENTER RANK OF THE WORKER --> ";
			cin>>user_string_num;
			if(user_string_num[0]=='-')
				is_num++;
			if(user_string_num[0]=='0' && isdigit(user_string_num[1]))
				is_num=0;
			else
			{
				for(int i=0;i<user_string_num.size();i++)
				{
					if(isdigit(user_string_num[i]))
						is_num++;
					if(user_string_num[i]=='.')
						decimal_count++;
				}
			}
			if(decimal_count==1)
				is_num=0;
			if(is_num==user_string_num.size())
			{
				stringstream str_stream_object(user_string_num);
				str_stream_object>>user_converted_num;
				is_num_bool=1;
			}
			else
			{
				cout<<"Error !!!"<<endl;
				cin.clear();
				is_num_bool=0;
				is_num=0;
				decimal_count=0;
			}
		} while(is_num_bool==0);
		ssr<<user_string_num;
		ssr>>emp_rank;
		AddEmployee(emp_Name,emp_phone,Emp_ID,emp_rank,emp_CNIC,emp_dept,emp_WH);
}
void SinglyList::UpdateEmployee()
{
	int updateID;
	cout<<"Enter the Emp ID whose record you want to update: ";
	cin>>updateID;
	int search=0;
	Node* tempNode=CurrentLocation;
	if(tempNode==NULL)
	{
		cout<<"There is no record to search !!!";
		return;
	}
	else
	{
		while(tempNode!=NULL)
		{
			if(tempNode->GetEmployeeID()==updateID)
			{
				search++;
				break;
			}
			tempNode=tempNode->GetNext();
		}
	}
	if(search>0)
	{
		cout<<"Record Found !!!"<<endl;
		int Emp_ID,emp_rank;
		string emp_Name,emp_phone,emp_CNIC,emp_dept;
		cout<<"ENTER PHONE NUMBER OF THE WORKER --> ";
		cin>>emp_phone;
		while(CheckString(emp_phone))
		{
			cout<<"WRONG INPUT !!!!!"<<endl;
			cout<<"ENTER PHONE NUMBER OF THE WORKER --> ";
			cin>>emp_phone;
		}
		cout<<"ENTER NAME OF THE WORKER --> ";
		cin.ignore();
		getline(cin,emp_Name);
		while(CheckStringAlph(emp_Name))
		{
			cout<<"WRONG INPUT !!!"<<endl;
			cout<<"ENTER NAME OF THE WORKER --> ";
			getline(cin,emp_Name);
		}
		cout<<"ENTER CNIC OF THE WORKER --> ";
		getline(cin,emp_CNIC);
		while(CheckString(emp_CNIC))
		{
			cout<<"WRONG INPUT !!!"<<endl;
			cout<<"ENTER CNIC OF THE WORKER --> ";
			getline(cin,emp_CNIC);
		}
		while(emp_CNIC.size()<16 || emp_CNIC.size()>16)
		{
			cout<<"Length of CNIC is not correct !!!"<<endl;
			cout<<"Enter CNIC of the worker --> ";
			getline(cin, emp_CNIC);
		}
		cout<<"ENTER DEPERTMENT OF THE WORKER --> ";
		getline(cin, emp_dept);
		while(CheckStringAlph(emp_dept))
		{
			cout<<"Wrong INPUT!!!"<<endl;
			cout<<"ENTER DEPERTMENT OF THE WORKER --> ";
			getline(cin, emp_dept);
		}
		
		string user_string_num="";
		stringstream ss;
		int is_num=0,decimal_count=0,user_converted_num;
		bool is_num_bool=0;
		do
		{
			cout<<"ENTER ID OF THE WORKER --> ";
			cin>>user_string_num;
			if(user_string_num[0]=='-')
				is_num++;
			if(user_string_num[0]=='0' && isdigit(user_string_num[1]))
				is_num=0;
			else
			{
				for(int i=0;i<user_string_num.size();i++)
				{
					if(isdigit(user_string_num[i]))
						is_num++;
					if(user_string_num[i]=='.')
						decimal_count++;
				}
			}
			if(decimal_count==1)
				is_num=0;
			if(is_num==user_string_num.size())
			{
				stringstream str_stream_object(user_string_num);
				str_stream_object>>user_converted_num;
				is_num_bool=1;
			}
			else
			{
				cout<<"Error !!!"<<endl;
				cin.clear();
				is_num_bool=0;
				is_num=0;
				decimal_count=0;
			}
		} while(is_num_bool==0);
		ss<<user_string_num;
		ss>>Emp_ID;
		user_string_num="";
		stringstream ssr;
		is_num=0,decimal_count=0,user_converted_num;
		is_num_bool=0;
		do
		{
			cout<<"ENTER RANK OF THE WORKER --> ";
			cin>>user_string_num;
			if(user_string_num[0]=='-')
				is_num++;
			if(user_string_num[0]=='0' && isdigit(user_string_num[1]))
				is_num=0;
			else
			{
				for(int i=0;i<user_string_num.size();i++)
				{
					if(isdigit(user_string_num[i]))
						is_num++;
					if(user_string_num[i]=='.')
						decimal_count++;
				}
			}
			if(decimal_count==1)
				is_num=0;
			if(is_num==user_string_num.size())
			{
				stringstream str_stream_object(user_string_num);
				str_stream_object>>user_converted_num;
				is_num_bool=1;
			}
			else
			{
				cout<<"Error !!!"<<endl;
				cin.clear();
				is_num_bool=0;
				is_num=0;
				decimal_count=0;
			}
		} while(is_num_bool==0);
		ssr<<user_string_num;
		ssr>>emp_rank;
		tempNode->SetEmployeeID(Emp_ID);
		tempNode->SetEmployeeName(emp_Name);
		tempNode->SetPhoneNo(emp_phone);
		tempNode->SetEmployeeDept(emp_dept);
		tempNode->SetEmployeeRank(emp_rank);
		tempNode->SetEmployeeCNIC(emp_CNIC);
		
	}
	else
	{
		cout<<"Record Not Found !!!"<<endl;
	}
	SaveInFile();
}
bool SinglyList::CheckStringAlph(string check)
{
	int length=check.size();
	for(int i=0;i<length;i++)
	{
		if(!((check[i]>=65  && check[i]<=90)||(check[i]>=97  && check[i]<=122)||(check[i]==32)))
			return true;
	}
	return false;
}
bool SinglyList::CheckString(string check)
{
	int length=check.size();
	for(int i=0;i<length;i++)
	{
		if(!((check[i]>=48  && check[i]<=57)))
			return true;
	}
	return false;
}
void SinglyList::Hourlywage(Node* newNode)
{
	if(newNode->GetEmployeeRank()==1)
		newNode->SetHourlyWage(578);
	else if(newNode->GetEmployeeRank()==2)
		newNode->SetHourlyWage(621.25);
	else if(newNode->GetEmployeeRank()==3)
		newNode->SetHourlyWage(691);
	else if(newNode->GetEmployeeRank()==4)
		newNode->SetHourlyWage(752.5);
	else if(newNode->GetEmployeeRank()==5)
		newNode->SetHourlyWage(817);
	else if(newNode->GetEmployeeRank()==6)
		newNode->SetHourlyWage(879.5);
	else if(newNode->GetEmployeeRank()==7)
		newNode->SetHourlyWage(952.5);
	else if(newNode->GetEmployeeRank()==8)
		newNode->SetHourlyWage(1002.75);
	else if(newNode->GetEmployeeRank()==9)
		newNode->SetHourlyWage(1090.25);
	else if(newNode->GetEmployeeRank()==10)
		newNode->SetHourlyWage(1170.25);
	else if(newNode->GetEmployeeRank()==11)
		newNode->SetHourlyWage(1266);
	else if(newNode->GetEmployeeRank()==12)
		newNode->SetHourlyWage(1365);
	else if(newNode->GetEmployeeRank()==13)
		newNode->SetHourlyWage(1485.25);
	else if(newNode->GetEmployeeRank()==14)
		newNode->SetHourlyWage(1634.75);
	else if(newNode->GetEmployeeRank()==15)
		newNode->SetHourlyWage(1815);
	else if(newNode->GetEmployeeRank()==16)
		newNode->SetHourlyWage(2092);
	else if(newNode->GetEmployeeRank()==17)
		newNode->SetHourlyWage(2469.75);
	else if(newNode->GetEmployeeRank()==18)
		newNode->SetHourlyWage(3100.25);
	else if(newNode->GetEmployeeRank()==19)
		newNode->SetHourlyWage(3668);
	else if(newNode->GetEmployeeRank()==20)
		newNode->SetHourlyWage(3884.75);
	else if(newNode->GetEmployeeRank()==21)
		newNode->SetHourlyWage(4114);
	else if(newNode->GetEmployeeRank()==22)
		newNode->SetHourlyWage(4270.75);
	else
		cout<<"Wrong Rank !!!"<<endl;	
}
void SinglyList::SaveInFile()
{
	fstream file;
	file.open("Employee.txt",ios::out|ios::trunc);
	if(!file)
	{
    	cout<<"\aThe file could not open !";
        Menu();
   	}
	Node* tempNode=CurrentLocation;
	if(tempNode==NULL)
	{
		cout<<"No Employee Is Registered !!!"<<endl;
		return;
	}
	else if(tempNode->GetNext()==NULL)
	{
		file<<" "<<tempNode->GetEmployeeID()<<" "<<tempNode->GetEmployeeName()<<" "<<tempNode->GetPhoneNo()<<" "<<tempNode->GetEmployeeCNIC()<<" "<<tempNode->GetEmployeeRank()<<"\n";  
	}
	else
	{
		while(tempNode!=NULL)
		{
			file<<" "<<tempNode->GetEmployeeID()<<" "<<tempNode->GetEmployeeName()<<" "<<tempNode->GetPhoneNo()<<" "<<tempNode->GetEmployeeCNIC()<<" "<<tempNode->GetEmployeeRank()<<"\n";
			tempNode=tempNode->GetNext();
		}
	}
	file.close();
}
void SinglyList::CalculateSal()
{
	int EmpID;
	cout<<"Enter the Employee ID of the employee whose salary you want to calculate : "<<endl;
	cin>>EmpID;
	int search=0;
	Node* tempNode=CurrentLocation;
	if(tempNode==NULL)
	{
		cout<<"There is no record to search !!!";
		return;
	}
	else
	{
		while(tempNode!=NULL)
		{
			if(tempNode->GetEmployeeID()==EmpID)
			{
				search++;
				break;
			}
			tempNode=tempNode->GetNext();
		}
	}
	if(search>0)
	{
		float tax;
		int WH=tempNode->GetEmployeeWH();
		if(WH<=40)
		{
			tempNode->SetgrossSalary(WH*tempNode->GetHourlyWage());
			tax=((tempNode->GetgrossSalary()*0.7)/100);
			tempNode->SetnetSalary(tempNode->GetgrossSalary()-tax);
		}
		if(WH>40)
		{
			int overTimeHour=WH-40;
			float overTimeSalary=overTimeHour*(1.5 * tempNode->GetHourlyWage());
			tempNode->SetgrossSalary((40*tempNode->GetHourlyWage())+overTimeSalary);
			tax=((tempNode->GetgrossSalary()*0.7)/100);
			tempNode->SetnetSalary(tempNode->GetgrossSalary()-tax);
		}
		cout<<"The Gross Pay of Employee with Emp ID "<<tempNode->GetEmployeeID()<<" is : ";
		cout<<tempNode->GetgrossSalary()<<endl;
		cout<<"The Net Pay of Employee with Emp ID "<<tempNode->GetEmployeeID()<<" is : ";
		cout<<tempNode->GetnetSalary()<<endl;	
	}
	else
	{
		cout<<"Record Not Found !!!"<<endl;
	}
}
void SinglyList::Attendance()
{
	int Empid,Wh;
	cout<<"Enter the EmpID whose Attendance you want to Enter: ";
	cin>>Empid;
	cout<<"Enter the Working Hours of the Employee to Mark Attendance: ";
	cin>>Wh;
	int search=0;
	Node* tempNode=CurrentLocation;
	if(tempNode==NULL)
	{
		cout<<"There is no record to search !!!";
		return;
	}
	else
	{
		while(tempNode!=NULL)
		{
			if(tempNode->GetEmployeeID()==Empid)
			{
				search++;
				break;
			}
			tempNode=tempNode->GetNext();
		}
	}
	if(search>0)
	{
		cout<<"Record Found !!!"<<endl;
		tempNode->SetEmployeeWH(Wh);
	}
	else
	{
		cout<<"Record Not Found !!!"<<endl;
	}
}
void SinglyList::ManagerMenu()
{
	int choice;
	cout<<"\n\t\t\t\t_______________________________________________________\n\n";
    cout<<"\t\t\t\t\t\t>> MANGER MENU <<";
    cout<<"\n\t\t\t\t-------------------------------------------------------\n"; 
    cout<<"\t\t\t\t--------- 1=> VIEW ALL EMPLOYEE------------------------\n";
    cout<<"\t\t\t\t--------- 2=> SEARCH EMPLOYEE BY ID--------------------\n";
    cout<<"\t\t\t\t--------- 3=> CALCULATE SALARY-------------------------\n";
    cout<<"\t\t\t\t--------- 4=> EXIT-------------------------------------\n";
    cout<<"\t\t\t\t_______________________________________________________\n"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"CHOICE OPTIONS : [1/2/3/4]"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>choice;
	if(choice==1)
	{
		PrintEmployee();
		system("pause");
		system("CLS");
		ManagerMenu();
	}
	else if(choice==2)
	{
		int searchID;
		cout<<"ENTER THE EMPLOYEE ID THAT YOU WANT TO SEARCH : ";
		cin>>searchID;
		SearchEmployee(searchID);
		system("pause");
		system("CLS");
		ManagerMenu();
	}
	else if(choice==3)
	{
		CalculateSal();
		system("pause");
		system("CLS");
		ManagerMenu();
	}
	else if(choice==4)
	{
		Menu();			
	}
	else
	{
		cout<<"WRONG CHOICE !!!";
		ManagerMenu();					
	}	
}
void SinglyList::AdminMenu()
{
	int choice;
	cout<<"\n\t\t\t\t_______________________________________________________\n\n";
    cout<<"\t\t\t\t\t\t>> ADMIN MENU <<";
    cout<<"\n\t\t\t\t-------------------------------------------------------\n"; 
    cout<<"\t\t\t\t--------- 1=> ENTER NEW RECORD-------------------------\n";
    cout<<"\t\t\t\t--------- 2=> DISPLAY ALL RECORD-----------------------\n";
    cout<<"\t\t\t\t--------- 3=> SEARCH EMPLOYEE BY ID--------------------\n";
    cout<<"\t\t\t\t--------- 4=> ATTENDENCE OF EMPLOYEE-------------------\n";
    cout<<"\t\t\t\t--------- 5=> DELETE EMPLOYEE--------------------------\n";
    cout<<"\t\t\t\t--------- 6=> UPDATE EMPLOYEE--------------------------\n";
    cout<<"\t\t\t\t--------- 7=> SAVE IN FILE--------------------------\n";
    cout<<"\t\t\t\t--------- 8=> EXIT-------------------------------------\n";
    cout<<"\t\t\t\t_______________________________________________________\n"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"CHOICE OPTIONS : [1/2/3/4/5/6/7/8]"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>choice;
	if(choice==1)
	{
		AddEmployeeInMenu();
		system("pause");
		system("CLS");
		AdminMenu();
	}
	else if(choice==3)
	{
		int searchID;
		cout<<"ENTER THE EMPLOYEE ID THAT YOU WANT TO SEARCH : ";
		cin>>searchID;
		SearchEmployee(searchID);
		system("pause");
		system("CLS");
		AdminMenu();
	}
	else if(choice==5)
	{
		int deleteID;
		cout<<"ENTER THE EMPLOYEE ID THAT YOU WANT TO DELETE : ";
		cin>>deleteID;
		DeleteEmployee(deleteID);
		system("pause");
		system("CLS");
		AdminMenu();
				}
	else if(choice==2)
	{
		PrintEmployee();
		system("pause");
		system("CLS");
		AdminMenu();
	}
	else if(choice==4)
	{
		Attendance();
		system("pause");
		system("CLS");
		AdminMenu();				
	}
	else if(choice==6)
	{
		system("pause");
		system("CLS");
		UpdateEmployee();
		AdminMenu();
	}
	else if(choice==7)
	{
		SaveInFile();
		system("pause");
		system("CLS");
		AdminMenu();				
	}
	else if(choice==8)
	{
		system("pause");
		system("CLS");
		AdminMenu();				
	}
	else
	{
		cout<<"WRONG CHOICE !!!";					
		system("pause");
		system("CLS");
		AdminMenu();
	}	
}
void SinglyList::EmployeeMenu()
{
	int choice;
	int Emp_ID,emp_rank,emp_WH;
	string emp_Name,emp_phone,emp_CNIC,emp_dept;
	cout<<"\t\t\t\t_____________________________________________________\n\n";
    cout<<"\t\t\t\t\t\t   >> EMPLOYEE MENU <<";
    cout<<"\n\t\t\t\t-----------------------------------------------------\n"; 
    cout<<"\t\t\t\t--------- 1=> ADD EMPLOYEE-----------------------------\n";
    cout<<"\t\t\t\t--------- 2=> SEARCH EMPLOYEE--------------------------\n";
    cout<<"\t\t\t\t--------- 3=> EXIT-------------------------------------\n";
    cout<<"\t\t\t\t_______________________________________________________\n"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"CHOICE OPTIONS : [1/2/3]"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>choice;
	if(choice==1)
	{
		AddEmployeeInMenu();	
		system("pause");
		system("CLS");
		EmployeeMenu();
	}
	else if(choice==2)
	{
		int searchID;
		cout<<"ENTER THE EMPLOYEE ID THAT YOU WANT TO SEARCH : ";
		cin>>searchID;
		SearchEmployee(searchID);
		system("pause");
		system("CLS");
		EmployeeMenu();
	}
	else if(choice==3)
	{
		system("pause");
		system("CLS");
		string op;
		cout<<"Do you want to save your changes in File Yes/No ? "<<endl;
		cin>>op;
		if(op=="Yes" || op=="yes")
			SaveInFile();
		else
			Menu();
	}
	else
	{
		cout<<"WRONG CHOICE !!!";					
		system("pause");
		system("CLS");
		EmployeeMenu();
	}	
}
void SinglyList::Menu()
{
	int option=1;
	int choice;
	int end=0;
	while(option!=0)
	{
		cout<<"\t\t\t\t_______________________________________________________\n\n";
    	cout<<"\t\t\t\t--------------|FACTORY MANAGEMENT SYSTEM|--------------\n";
    	cout<<"\t\t\t\t-------------------------------------------------------\n";
   		cout<<"\t\t\t\t--------- 1=> REGISTRATION IN FMS----------------------\n";
    	cout<<"\t\t\t\t--------- 2=> LOGIN FMS--------------------------------\n";
   	 	cout<<"\t\t\t\t--------- 3=> EXIT-------------------------------------\n";
  	  	cout<<"\t\t\t\t_______________________________________________________\n"<<endl;
	    cout<<"\t\t\t\t-------------------------------------------------------\n";
    	cout<<"CHOICE OPTIONS : [1/2/3]"<<endl;
    	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
		cout<<"ENTER YOUR CHOICE: ";
		cin>>option;
		if(option==1)
		{
			//system("pause");
			system("CLS");
			Registration();
		}
		else if(option==2)
		{
			//system("pause");
			system("CLS");
			Login();
		}
		else if(option==3)
		{
			//system("pause");
			system("CLS");
			return;
		}
		else
		{
			//system("pause");
			system("CLS");
			cout<<"\nWRONG CHOICE !!!"<<endl;
			return;
		}
	}	
	system("pause");
	system("CLS");
		
}
bool SinglyList::Registration()
{
	int choice;
	string userName,password,person;
	cout<<"\t\t\t\t_______________________________________________________\n\n";
    cout<<"\t\t\t\t\t\t  >> REGISTRATION <<";
    cout<<"\n\t\t\t\t-------------------------------------------------------\n"; 
    cout<<"\t\t\t\t--------- 1=> REGISTER AS MANAGER----------------------\n";
    cout<<"\t\t\t\t--------- 2=> REGISTER AS EMPLOYEE---------------------\n";
    cout<<"\t\t\t\t--------- 3=> REGISTER AS ADMIN------------------------\n";
    cout<<"\t\t\t\t--------- 4=> EXIT-------------------------------------\n";
    cout<<"\t\t\t\t_______________________________________________________\n"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"CHOICE OPTIONS : [1/2/3/4]"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE: ";
	cin>>choice;
	if(choice==1)
	{
		string userName,password;
		ofstream ManagerloginFile;
		ManagerloginFile.open("ManagerLoginFile",ios::app);
		system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>>  MANAGER REGISTRATION <<";
        cout << "\n\t\t\t\t\t---------------------------";
		cout<<"\n\n\t\t\t\tUSERNAME = ";
		cin>>userName;
		cout<<"\n\n\t\t\t\tPASSWORD = ";
		cin>>password;
		if(!ManagerloginFile.is_open())
		{
    		cout<<"\aThe file could not open !!!";
        	Menu();
   		}
		ManagerloginFile<<userName<<" "<<password<<endl;
		ManagerloginFile.close();
		cout<<"\nREGISTRATION AS A MANAGER IS SUCCESSFULLY SAVE...\n";
		system("pause");
		system("cls");
		ManagerMenu();
	}
	else if(choice==2)
	{
		string userName,password;
		ofstream EmployeeloginFile;
		EmployeeloginFile.open("EmployeeLoginFile",ios::app);
		system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> EMPLOYEE REGISTRATION <<";
        cout << "\n\t\t\t\t\t---------------------------";
		cout<<"\n\n\t\t\t\tUSERNAME = ";
		cin>>userName;
		cout<<"\n\n\t\t\t\tPASSWORD = ";
		cin>>password;
		if(!EmployeeloginFile.is_open())
		{
    		cout<<"\aThe file could not open !";
        	Menu();
   		}
		EmployeeloginFile<<userName<<" "<<password<<endl;
		EmployeeloginFile.close();
		
		cout<<"\nREGISTRATION AS A EMPLOYEE IS SUCCESSFULLY SAVE...\n";
		system("pause");
		system("cls");
		EmployeeMenu();
		
	}		
	else if(choice==3)
	{
		string userName,password;
		ofstream AdminloginFile;
		AdminloginFile.open("AdminLoginFile",ios::app);
		system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>>   ADMIN REGISTRATION  <<";
        cout << "\n\t\t\t\t\t---------------------------";		
		cout<<"\n\n\t\t\t\tUSERNAME = ";
		cin>>userName;
		cout<<"\n\n\t\t\t\tPASSWORD = ";
		cin>>password;
		if(!AdminloginFile.is_open())
		{
    		cout<<"\aThe file could not open !!!";
        	Menu();
   		}
		AdminloginFile<<userName<<" "<<password<<endl;
		AdminloginFile.close();
		system("cls");
		cout<<"REGISTRATION AS A ADMIN IS SUCCESSFULLY SAVE !!!";
		AdminMenu();
	}
	else if(choice==4)
	{
		system("cls");
		Menu();
	}
	else
	{
		cout<<"WRONG CHOICE !!!"<<endl;
		system("pause");
		system("cls");
		Menu();
	}
}

SinglyList::SinglyList()
{
	CurrentLocation=NULL;
}
void SinglyList::SetCurrentLocation(Node* head)
{
	this->CurrentLocation=head;
}

bool SinglyList::Login()
{
	int choice;
	cout<<"\t\t\t\t_______________________________________________________\n\n";
    cout<<"\t\t\t\t\t\t     >> LOGIN <<";
    cout<<"\n\t\t\t\t-------------------------------------------------------\n"; 
    cout<<"\t\t\t\t--------- 1=> LOGIN AS ADMIN---------------------------\n";
    cout<<"\t\t\t\t--------- 2=> LOGIN AS MANAGER-------------------------\n";
    cout<<"\t\t\t\t--------- 3=> LOGIN AS EMPLOYEE------------------------\n";
    cout<<"\t\t\t\t--------- 4=> EXIT-------------------------------------\n";
    cout<<"\t\t\t\t_______________________________________________________\n"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"CHOICE OPTIONS : [1/2/3/4]"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>choice;
	if(choice==1)
	{
			int exist;
			string userName,password,fuserName,fpassword;
			system("cls");
			cout<<"\n\t\t\t\t\t--------------------";
       		cout<<"\n\t\t\t\t\t>>  LOGIN  ADMIN  <<";
        	cout<<"\n\t\t\t\t\t--------------------";
			cout<<"\n\n\t\t\t\tUSERNAME = ";
			cin>>userName;
			cout<<"\n\n\t\t\t\tPASSWORD = ";
			cin>>password;
			ifstream AdminloginFile;
			AdminloginFile.open("AdminLoginFile");
			if(!AdminloginFile.is_open())
			{
    			cout<<"\aThe file could not open !!!";
        		Menu();
   			}
   			while(AdminloginFile>>fuserName>>fpassword)
   			{
   				if(userName==fuserName && password==fpassword)
   				{
   					exist=1;
				}
			}
			AdminloginFile.close();
			if(exist==1)
			{
				cout<<"\nLOGIN AS ADMIN IS SUCCESSFULL...\n"<<endl;
				system("pause");
				system("cls");
				AdminMenu();	
			}
			else
			{
				string forget;
				cout<<"LOGIN WAS UNSUCCESSFUL !!!"<<endl;
				cout<<"DID YOU FROGET YOUR PASSWORD Yes/No?"<<endl;
				cin>>forget;
				if(forget=="yes")
				{
					int exist=0;
					string userName,sU,sP;
					cout<<"\nENTER YOUR USERNAME : ";
					cin>>userName;
					ifstream AdminloginFile;
					AdminloginFile.open("AdminLoginFile");
					while(AdminloginFile>>sU>>sP)
					{
						if(sU==userName)
						{
							exist=1;
							break;
						}
					}
					AdminloginFile.close();
					if(exist==1)
					{
						cout<<"YOUR ACCOUNT IS FOUND !!!"<<endl;
						cout<<"YOUR PASSWORD IS : "<<sP<<endl;
						cin.get();
						system("cls");
					}
					else
					{
						cout<<"Sorry Your Account Is Not Found !!!"<<endl;
						Menu();
					}
				}
				else
				{
					system("cls");
					Menu();
				}
				
			}
			}

		else if(choice==2)
		{
			int exist;
			string userName,password,fuserName,fpassword;
			system("cls");
			cout<<"\n\t\t\t\t\t--------------------";
       		cout<<"\n\t\t\t\t\t>> LOGIN  MANAGER <<";
        	cout<<"\n\t\t\t\t\t--------------------";
			cout<<"\n\n\t\t\t\tUSERNAME = ";
			cin>>userName;
			cout<<"\n\n\t\t\t\tPASSWORD =";
			cin>>password;
			ifstream ManagerloginFile;
			ManagerloginFile.open("ManagerLoginFile");
			if(!ManagerloginFile.is_open())
			{
    			cout<<"\aThe File Could Not Open !!!";
        		Menu();
   			}
   			while(ManagerloginFile>>fuserName>>fpassword)
   			{
   				if(userName==fuserName && password==fpassword)
   				{
   					exist=1;
				}
			}
			ManagerloginFile.close();
			if(exist==1)
			{
				cout<<"\nLOGIN AS MANGER IS SUCCESSFULL...\n"<<endl;
				system("pause");
				system("cls");	
				ManagerMenu();
			}
			else
			{
				string forget;
				cout<<"LOGIN WAS UNSUCCESSFUL !!!"<<endl;
				cout<<"DID YOU FROGET YOUR PASSWORD Yes/No?"<<endl;
				cin>>forget;
				if(forget=="yes")
				{
					int exist=0;
					string userName,sU,sP;
					cout<<"\nENTER YOUR USERNAME : ";
					cin>>userName;
					ifstream ManagerloginFile;
					ManagerloginFile.open("ManagerLoginFile");
					while(ManagerloginFile>>sU>>sP)
					{
						if(sU==userName)
						{
							exist=1;
							break;
						}
					}
					ManagerloginFile.close();
					if(exist==1)
					{
						cout<<"YOUR ACCOUNT IS FOUND..."<<endl;
						cout<<"YOUR PASSWORD IS : "<<sP<<endl;
						cin.get();
						system("cls");
					}
					else
					{
						cout<<"Sorry Your Account Is Not Found !!!"<<endl;
						Menu();
					}
				}
				else
				{
					system("cls");
					Menu();
				}
				
			}
		}
		else if(choice==3)
		{
			int exist;
			string userName,password,fuserName,fpassword;
			system("cls");
			cout<<"\n\t\t\t\t\t--------------------";
       		cout<<"\n\t\t\t\t\t>> LOGIN EMPLOYEE <<";
        	cout<<"\n\t\t\t\t\t--------------------";
			cout<<"\n\n\t\t\t\tUSERNAME = ";
			cin>>userName;
			cout<<"\n\n\t\t\t\tPASSWORD = ";
			cin>>password;
			ifstream EmployeeloginFile;
			EmployeeloginFile.open("AdminLoginFile");
			if(!EmployeeloginFile.is_open())
			{
    			cout<<"\aThe File Could Not Open !!!";
        		Menu();
   			}
   			while(EmployeeloginFile>>fuserName>>fpassword)
   			{
   				if(userName==fuserName && password==fpassword)
   				{
   					exist=1;
				}
			}
			EmployeeloginFile.close();
			if(exist==1)
			{
				cout<<"\nLOGIN AS EMPLOYEE IS SUCCESSFULL...\n"<<endl;
				system("pause");
				system("cls");
				EmployeeMenu();	
			}
			else
			{
				string forget;
				cout<<"LOGIN WAS UNSUCCESSFUL !!!"<<endl;
				cout<<"DID YOU FROGET YOUR PASSWORD Yes/No?"<<endl;
				cin>>forget;
				if(forget=="yes")
				{
					int exist=0;
					string userName,sU,sP;
					cout<<"\nENETR YOUR USERNAME :";
					cin>>userName;
					ifstream EmployeeloginFile;
					EmployeeloginFile.open("EmployeeLoginFile");
					while(EmployeeloginFile>>sU>>sP)
					{
						if(sU==userName)
						{
							exist=1;
							break;
						}
					}
					EmployeeloginFile.close();
					if(exist==1)
					{
						cout<<"YOUR ACCOUNT IS FOUND !!!"<<endl;
						cout<<"YOUR PASSWORD IS : "<<sP<<endl;
						cin.get();
						system("cls");
					}
					else
					{
						cout<<"Sorry Your Account Is Not Found !!!"<<endl;
						Menu();
					}
				}
			}
		}
		
		else if(choice==4)
		{
			system("cls");
			Menu();
		}
		else
		{
			cout<<"WRONG INPUT !!!"<<endl;
			system("pause");
			system("cls");
			Menu();
		}
	
}
//Add Employee
void SinglyList::AddEmployee(string name,string phone,int ID,int rank,string cnic,string dept,int wh)
{
	Node* tempNode=CurrentLocation;
	Node* newNode=new Node();
	newNode->SetEmployeeName(name);
	newNode->SetPhoneNo(phone);
	newNode->SetEmployeeWH(wh);	
	newNode->SetEmployeeID(ID);
	newNode->SetEmployeeRank(rank);
	newNode->SetEmployeeCNIC(cnic);
	newNode->SetEmployeeDept(dept);	
	Hourlywage(newNode);
	newNode->SetNext(NULL);
	if(tempNode==NULL)
	{
		CurrentLocation=newNode;
		return;
	}
	if(tempNode->GetNext()==NULL)
	{
		if(tempNode->GetEmployeeID()==ID)
		{
			cout<<"This ID Already Exists !!!";
			return;
		}
		tempNode->SetNext(newNode);
	}
	else
	{
		while(tempNode->GetNext()!=NULL)
		{
			if(tempNode->GetEmployeeID()==ID)
			{
				cout<<"This ID Already Exists !!!";
				return;
			}
			tempNode=tempNode->GetNext();
		}
		tempNode->SetNext(newNode);
	}
}


//Print Employee
void SinglyList::PrintEmployee()
{
	Node* tempNode=CurrentLocation;
	if(tempNode==NULL)
	{
		cout<<"NO EMPLOYEE IS REGISTERED YET !!!"<<endl;
		return;
	}
	else
	{
		while(tempNode!=NULL)
		{
			cout<<"\t____________________________________________________________________________________________________\n";
	        cout<<"\t|   NAME			|\t"<<tempNode->GetEmployeeName()<<endl;
	        cout<<"\t----------------------------------------------------------------------------------------------------\n";
			cout<<"\t|   DEPARTMENT			|\t"<<tempNode->GetEmployeeDept()<<endl;
	        cout<<"\t----------------------------------------------------------------------------------------------------\n";
			cout<<"\t|   WORKING HOURS		|\t"<<tempNode->GetEmployeeWH()<<endl;			
	    	cout<<"\t----------------------------------------------------------------------------------------------------\n";
			cout<<"\t|   PHONE NUMBER		|\t"<<tempNode->GetPhoneNo()<<endl;
	        cout<<"\t----------------------------------------------------------------------------------------------------\n";
	        cout<<"\t|   CNIC			|\t"<<tempNode->GetEmployeeCNIC()<<endl;
	        cout<<"\t----------------------------------------------------------------------------------------------------\n";       
			cout<<"\t|   ID				|\t"<<tempNode->GetEmployeeID()<<endl; 	
			cout<<"\t----------------------------------------------------------------------------------------------------\n";       
			cout<<"\t|   RANK			|\t"<<tempNode->GetEmployeeRank()<<endl;
			cout<<"\t____________________________________________________________________________________________________\n\n";  
			tempNode=tempNode->GetNext();
			cout<<endl;
		}
	}
}
// Search Employee
void SinglyList::SearchEmployee(int searchID)
{
	int search=0;
	Node* tempNode=CurrentLocation;
	if(tempNode==NULL)
	{
		cout<<"THERE IS NO RECORD TO SEARCH !!!";
		return;
	}
	else
	{
		while(tempNode!=NULL)
		{
			if(tempNode->GetEmployeeID()==searchID)
			{
				search++;
				break;
			}
			tempNode=tempNode->GetNext();
		}
	}
	if(search>0)
	{
		cout<<"RECORD FOUND !!!"<<endl;
		cout<<"\t____________________________________________________________________________________________________\n";
	    cout<<"\t|   NAME			|\t"<<tempNode->GetEmployeeName()<<endl;
	    cout<<"\t----------------------------------------------------------------------------------------------------\n";
		cout<<"\t|   DEPARTMENT			|\t"<<tempNode->GetEmployeeDept()<<endl;
		cout<<"\t----------------------------------------------------------------------------------------------------\n";
		cout<<"\t|   WORKING HOURS		|\t"<<tempNode->GetEmployeeWH()<<endl;			
	    cout<<"\t----------------------------------------------------------------------------------------------------\n";
		cout<<"\t|   PHONE NUMBER		|\t"<<tempNode->GetPhoneNo()<<endl;
	    cout<<"\t----------------------------------------------------------------------------------------------------\n";
	    cout<<"\t|   CNIC			|\t"<<tempNode->GetEmployeeCNIC()<<endl;
	    cout<<"\t----------------------------------------------------------------------------------------------------\n";       
		cout<<"\t|   ID				|\t"<<tempNode->GetEmployeeID()<<endl; 	
		cout<<"\t----------------------------------------------------------------------------------------------------\n";       
		cout<<"\t|   RANK			|\t"<<tempNode->GetEmployeeRank()<<endl;
		cout<<"\t____________________________________________________________________________________________________\n\n";  
	}
	else
	{
		cout<<"RECORD NOT FOUND !!!"<<endl;
	}
	
}
//Delete Employee
void SinglyList::DeleteEmployee(int deleteID)
{
	int exist=0;
	Node* tempNode=CurrentLocation;
	Node* previous=new Node();
	//IF First Node
	if(tempNode->GetEmployeeID()==deleteID)
	{
		CurrentLocation=tempNode->GetNext();
		delete tempNode;
		exist++;
		tempNode=NULL;
	}
	//If Last Node
	else  if(tempNode->GetNext()==NULL)
	{
		delete tempNode;
		exist++;
		tempNode=NULL;
	}
	//If any other node
	else
	{
		while(tempNode!=NULL)
		{
			if(tempNode->GetEmployeeID()==deleteID)
			{
				return;
				exist++;
			}
			previous=tempNode;
			tempNode->GetNext();
		}
		previous->SetNext(tempNode->GetNext());
		delete tempNode;
		tempNode=NULL;
	}
	if(exist>0)
	{
		cout<<"RECORD DELETED SUCCESSFULLY !!!"<<endl;
	}
	else
	{
		cout<<"RECORD NOT FOUND !!!"<<endl;
	}
}
int main()
{
	cout << "\n\t\t\t\t -------------------------------------------";
    cout << "\n\t\t\t\t || WELCOME TO FACTORY MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t\t -------------------------------------------\n";
	cin.get();
	system("cls");
	SinglyList l;
	Node* n=new Node();
	l.Menu();
	return 0;
}
