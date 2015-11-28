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
	file.open("mess4.txt",ios::app|ios::binary|ios::in|ios::out);
	if(file.fail())
	{
		cout<<"could not open file";
	}
	do{
		cout<<"Enter uid: "<<endl;
		cin>>m.uid;
		cout<<"enter the amount";
		cin>>m.a;
		file.write((char*)&m,sizeof(m));
		cout<<"enter another person(y/n)?"<<endl;
		cin>>ch;
		
	}while( ch == 'y');

	file.close();
	ifstream file1;
	file1.open("mess4.txt");
	int u;
	cout<<"enter uid"<<endl;
	cin>>u;
	int found = 0;
	while(!file1.eof())
	{  
	   file1.read((char*)&m,sizeof(m));
	   if(m.uid == u)
	   {
	   	 
		 cout<<"uid and amount is ==>";              //i should aad ate mode while opening file..
	   	 cout<<m.uid<<" and "<<m.a;
	   	 found = 1;
	   	 
		   }	
		   		   
		 if(found ==1)
		 {
		 	break;
		   } 
	
		  
	}
     if(found==0)	
	  { cout<<"uid not found";
	     
	  }
   file1.close(); 
   
        
/*	fstream file2;
	file2.open("mess4.txt",ios::app|ios::in|ios::out|ios::binary);
	file2.seekg(0);
	
	file2.read((char*)&m,sizeof(m));
	while(file2){
		cout<<"account: "<<m.uid<<" "<<m.a;
		file2.read((char*)&m,sizeof(m));
	}
*/	cout<<endl;
	getch();
	return 0;
}
