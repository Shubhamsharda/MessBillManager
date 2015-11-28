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
	file.open("mess3.txt",ios::app|ios::in|ios::out|ios::binary);
	do{
		cout<<"Enter uid: "<<endl;
		cin>>m.uid;
		file.write((char*)&m,sizeof(m));
		cout<<"enter another person(y/n)?"<<endl;
		cin>>ch;
		
	}while( ch == 'y');
	file.seekg(0);
	int t;
	cout<<"enter uid to be edited"<<endl;
	cin>>t;
	file.read((char*)&m,sizeof(m));
	while(!file.eof()){
		if(m.uid==t){
			
			int j =0;
			cout<<"enter amount to be added";
			cin>>j;
			m.a = m.a +j;
			cout<<"added";
			
			file.write((char*)&m,sizeof(m));
			cout<<"written";
			
		} 
		file.read((char*)&m,sizeof(m));
	}
	cout<<"outside first while";
	
	file.seekg(0);
	file.read((char*)&m,sizeof(m));
	cout<<"after second read";
	file.close();
	fstream file2;
	file2.open("mess3.txt",ios::app|ios::in|ios::out|ios::binary);
	file2.read((char*)&m,sizeof(m));
	while(!file2.eof())
	{
		cout<<"account: "<<m.uid<<" : "<<m.a;
		file2.read((char*)&m,sizeof(m));
	}
	
	cout<<endl;
	getch();
	return 0;
}
