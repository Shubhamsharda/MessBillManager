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
	cout<<"Do you want to add a new account?(y/n)";
	cin>>ch;
	while( ch == 'y'){
		cout<<"Enter uid: "<<endl;
		cin>>m.uid;
		cout<<"enter the amount";
		cin>>m.a;
		file.write((char*)&m,sizeof(m));
		cout<<"enter another person(y/n)?"<<endl;
		cin>>ch;
		
	}

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
   
   
   /*fstream file2;
   file2.open("mess4.txt",ios::ate|ios::out|ios::in|ios::binary);   //doubt!!! binary to be added??
   cout<<endl<<"Enter the uid whose contents you want to modify"<<endl;
   int y;
   cin>>y;
   int found1 =0;
   while(!file2.eof())    //file opened in ate mode..pointer should be at the end???
   {
   	 file2.read((char*)&m,sizeof(m));
   	 if(y == m.uid)
   	 {   // file2.seekg(-sizeof(m),ios::cur) ;
				 int g=file2.tellg();
   	// 	m.modify();
        cout<<"current uid and amount is"<<endl;
        cout<<m.uid<<" : "<<m.a<<endl;
            
			 m.a=m.a+10;
	 	 	found = 1;
	 	 if(file2.eof())    //cheak the validity of this!!
             file2.clear();
            file2.seekp(g-1,ios::beg);
  // 	 	file2.seekp(-sizeof(m), ios::cur);  //doubt
             cin.get(ch);   //whats the use of this?? to eat enter. back slash n eater?????
   	 	file2.write((char*)&m,sizeof(m))<<flush; //use of flush?
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
	file3.open("mess4.txt",ios::in|ios::out|ios::binary|ios::ate); //cheak append!
	file3.seekg(0);
int d;
	cout<<"\nenter uid"<<endl;
	cin>>d;
	int found2 = 0;
	while(!file3.eof())
	   
	 {
	   if(m.uid == d)
	   {
	   	 file3.read((char*)&m,sizeof(m));
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
   
   */
   
        
/*	fstream file2;
	file2.open("mess4.txt",ios::app|ios::in|ios::out|ios::binary);
	file2.seekg(0);
	
	file2.read((char*)&m,sizeof(m));
	while(file2){
		cout<<"account: "<<m.uid<<" "<<m.a;
		file2.read((char*)&m,sizeof(m));
	}
*/	
   fstream file4;
   file4.open("mess4.txt",ios::ate|ios::in|ios::binary);
   cout<<"Enter the uid to modify"<<endl;
   int i, j;
   cin>>i;
   file4.seekg(0,ios::beg);
    while(file4.read((char*)&m,sizeof(m)))  // to modify
    {
   	  if(m.uid== i)
	 {
		   j = file4.tellg();
		  cout<<" pointer position after match found is: "<<j;
		  m.a = m.a + 10;   // make the seek function
		  break;
	 }
		
    }
   file4.close();
   fstream file5;
   file5.open("mess4.txt",ios::binary|ios::in|ios::out|ios::ate);
   
   if(file5.eof())
   file5.clear();
   file5.seekp(j-sizeof(m),ios::beg);
   cout<<"value of a before write "<<m.a<<endl;
   cout<<"pointer position before writing : "<<file5.tellp();
   //cin.get(ch);     this is not really necessary to use. no change in output was found by removing it.
   
   file5.write((char*)&m,sizeof(m));


  


 
 //To Show the updated file 
 
 file5.seekg(0);
 
  while(file5.read((char*)&m,sizeof(m)))
 {
 	cout<<"\nAccount :"<<m.uid<<" : "<<m.a<<endl;
 	
 }
 
 
 /*methods to delete an objects include- 1. just copy the new contents to a new file 2.like a que or stack  3. mark the object ready to be used.*/
 file5.close();
 // method to delete an object.
 cout<<"Do you want to delete an account?(y/n)"<<endl;
 char rr;
 cin>>rr;
 while(rr=='y')
 {
 	int z;
 	cout<<"enter the uid you want to delete"<<endl;
 	cin>>z;
 	fstream file6;
 	file6.open("mess4.txt",ios::in|ios::binary);
 	if(file6.fail())
 	{
 		cout<<"could not open mess.txt file for deleting"<<endl;
	 }
 	file6.seekg(0,ios::beg);
 	fstream file7;
	 file7.open("temp.txt",ios::out|ios::binary);
	 if(file7.fail())
	 {
	 	cout<<"could not open tem.txt file for copying"<<endl;
	 }
 	while(file6.read((char*)&m,sizeof(m)))
 	{
 		if(m.uid!=z)
 		{
 			file7.write((char*)&m,sizeof(m));
 	    }
	}
	file6.seekg(0,ios::beg);
	file7.seekp(0,ios::beg);
	file6.close();
	file7.close();
	fstream file8;
	file8.open("mess4.txt",ios::out|ios::binary);
	if(file8.fail())
	{
		cout<<"could not open file8"<<endl;
	}
	fstream file9;
	file9.open("temp.txt",ios::binary|ios::in);
	if(file8.fail())
	{
		cout<<"could not open file9"<<endl;
	}
	while(file9.read((char*)&m,sizeof(m)))
	{
		file8.write((char*)&m,sizeof(m));
		
	}
	cout<<"Do you want to delete another account?(y/n)";
	cin>>rr;
	
	 }
 	
 

 
	getch();
	return 0;
}


