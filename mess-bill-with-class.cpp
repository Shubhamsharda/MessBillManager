#include<iostream>
#include<conio.h>
#include<fstream>
#include<process.h>
using namespace std;
class mess
{
     public:
            int a;
            void addmeal( int i)
            {
              if(i == 1)
              a=a+35;
              else if( i==2 )
              a= a+70;
              }
              void showbill()
              { 
                   cout<<a<<"hi"<<endl;
              }     
                   
};

int main()
{
    fstream file;
    file.open("mess.txt",ios::in|ios::out);
    if( file.fail())
    {cout<<"Could not open the file";
     }
    mess m;
    int e;
    cout<<"Do you want to reset the bill? If yes then press 1";
    cin>>e;
    if( e== 1)
    { cout<<"resetting"<<endl;
        m.a=0;
    }    
    //file.read( (char*)&m, sizeof(m) );
    //m.showbill();
    int q;
    cout<<"Do you want to add to the bill? then press 1"<<endl;
    cin>>q;
    if(q==1)
    {      int w; 
           cout<<" Press 1 for simple meal and press 2 for special meal"<<endl;
           cin>>w;
           if(w == 1)
           {
                cout<<"simple meal it is"<<endl;
                m.addmeal(1);
                cout<<m.a;
                //file.write( (char*)&m,sizeof(m));
                cout<<"Add more";
                m.addmeal(1);
                file.write( (char*)&m,sizeof(m));
                file.seekg(0,ios::beg);
                //m.showbill();
               //file.close();
           }
           else if( w== 2)
           {    
                cout<<"special meal it is"<<endl;
                m.addmeal(2);
                file.write( (char*)&m,sizeof(m));
                file.seekg(0,ios::beg);
               // file.close();
           }
         //  fstream file2("mess.txt");
           //mess t;
           file.read((char*)&m,sizeof(m));
           //while(!file.eof())
           //{
   //        file.read((char*)&m,sizeof(m));
           
           cout<<"the modified bill is:"<<endl;
           m.showbill();
}       
           file.close();
           
           
     
     
     getch();
     return 0;
               
}                   
                                                  
