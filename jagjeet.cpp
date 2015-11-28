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
	void modify()
	{
		cout<<"enter amount to be added"<<endl;
		int o;
		cin>>o;
		a = a + o;
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
   
   
                                                              //modify
   
   
   fstream file2;
   file2.open("mess4.txt",ios::ate|ios::out|ios::in|ios::app);
   cout<<endl<<"Enter the uid whose contents you want to modify"<<endl;
   int y;
   cin>>y;
   int found1 =0;
   while(!file2.eof())
   {
   	 file2.read((char*)&m,sizeof(m));
   	 if(y == m.uid)
   	 {    file2.seekg(-sizeof(m),ios::cur) ;
				 int g=file2.tellg();
   	// 	m.modify();
        cout<<"current uid and amount is"<<endl;
        cout<<m.uid<<" : "<<m.a<<endl;
            
			 m.a=m.a+10;
	 	 	found = 1;
	 	 if(file2.eof())
             file2.clear();
            file2.seekp(g);
  // 	 	file2.seekp(-sizeof(m), ios::cur);  //doubt
             cin.get(ch);
   	 	file2.write((char*)&m,sizeof(m))<<flush; 
			cout<<"\nafter modification "<<" uid :"<<m.uid<<" u.a "<<m.a;
			             
		}
	if( found == 1)
	{
		break;
	}	
   	
   }
   if( found == 0)
   {
   	cout<< "uid not found for writing"<<endl;
   }
   file2.close();
                                                      
													    //read update value
    
    
	
	fstream file3;
	file3.open("mess4.txt",ios::in|ios::out|ios::binary|ios::app);
	file3.seekg(0);
int d;
	cout<<"\nenter uid"<<endl;
	cin>>d;
	int found2 = 0;
	while(!file3.eof())
	   
	 {
	   if(m.uid == u)
	   {
	   	 
		 cout<<"uid and amount is ==>";              //i should aad ate mode while opening file..
	   	 cout<<m.uid<<" and "<<m.a;
	   	 found2 = 1;
	   	 
	   }	
		   		   
		 if(found2 ==1)
		 {
		 	break;
		   } 
	
		  
	}
     if(found2==0)	
	  { cout<<"uid not found";
	     
	  }

     file3.close();
   
   
   
        
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
