#include<iostream>
#include<conio.h>
#include<fstream>
#include<process.h>
using namespace std;

class mess{
	public:
	int a;
	int uid;
	void showdata()
	{
		cout<<"bill is: "<<a<<endl;
		
	}
	mess()
	{
		a=0;uid=0;
		
	}
	
};

int main()
{
	char ch;
	mess m;
	fstream file;
	file.open("mess4.txt",ios::app|ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"could not open file";
	}
	do{
		cout<<"Enter uid: "<<endl;
		cin>>m.uid;
		file.write((char*)&m,sizeof(m));
		cout<<"enter another person(y/n)?"<<endl;
		cin>>ch;
		
	}while( ch == 'y');
	file.seekg(0);
	int t;
	cout<<"enter t"<<endl;
	cin>>t;
	while(file)
	{  
	   int found = 0;
	   if(m.uid == t)
	   {
	   	 file.seekp(-sizeof(m),ios::cur);
	   	 cout<<"enter amount to be added"<<endl;
	   	 cin>>m.a;
	   	 found = 1;
	   	 file.write((char*)&m,sizeof(m));
		   }	
		 if(found ==1)
		 {
		 	break;
		   }  
	}
	fstream file2;
	file2.open("mess4.txt",ios::app|ios::in|ios::out|ios::binary);
	file2.seekg(0);
	
	file2.read((char*)&m,sizeof(m));
	while(file2){
		cout<<"account: "<<m.uid;
		file2.read((char*)&m,sizeof(m));
	}
	cout<<endl;
	getch();
	return 0;
}
