#include<bits/stdc++.h>
using namespace std;

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b)
{
  return (a.first > b.first);
}

#include "admno.h"
#include "bcs.h"
#include "date.h"
#include "img.h"
#include "imt.h"
#include "prof.h"
#include "student.h"
#include "subject.h"

//VARIABLES USED:

Prof ach;

  Subject em("em","01",ach,0);
  Subject dms("dms","02",ach,0);
  Subject os("os","03",ach,0);
  Subject oops("oops","04",ach,0);
  Subject cn("cn","05",ach,0);
  Subject bme("bme","06",ach,0);
  Subject dbms("dbms","07",ach,0);
  Subject fcs("fcs","08",ach,0);
  Subject coa("coa","10",ach,0);

void add()
{ char choice;
  cout<<endl<<endl<<endl;
  cout<<"ENTER STUDENT DETAILS"<<endl;
  cout<<"CHOOSE STREAM :"<<endl;
  cout<<"1 for BCS"<<endl<<"2 for IMT"<<endl<<"3 for IMG"<<endl;
  cin>>choice;
  switch(choice)
  {
    case '1':
        {  
          Bcs bs(em,dms,os);
          ofstream f("Record_bcs.dat", ios::binary | ios::app);
          bs.enter();
          bs.entermarks();
          f.write((char*)&bs,sizeof(bs));
          f.close();
        }
         break;
     case '2':
        {  
          imt ms(oops,cn,bme);
          ofstream g("Record_imt.dat", ios::binary | ios::app);
          ms.enter();
          ms.entermarks();
          g.write((char*)&ms,sizeof(ms));
          g.close();
        }
           break;
     case '3':
        {   
          img gs(dbms,fcs,coa);
          ofstream h("Record_img.dat", ios::binary | ios::app);
          gs.enter();
          gs.entermarks();
          h.write((char*)&gs,sizeof(gs));
          h.close();
        }
            break;
     default:cout<<"no such stream"<<endl;
}
};

void del()
{
  char choice;
  cout<<endl<<endl<<endl;
  cout<<"which stream student do you want to delete"<<endl;
  cout<<"1 for BCS"<<endl<<"2 for IMT"<<endl<<"3 for IMG"<<endl;
  cin>>choice;
  switch(choice)
  {
    case '1':
        {
           Bcs bs(em,dms,os);
           ifstream f1("Record_bcs.dat");
           ofstream f2("Temp_bcs.dat", ios::binary);
           int roll1,flag1=0;
           if(!f1)
            cout<<"file not found"<<endl;
           else
           {
            cout<<"enter roll number of student"<<endl;
            cin>>roll1;
            while(f1.read((char*)&bs, sizeof(bs)))
            { 
              if(roll1!=bs.admsno.rlno)
              {
                f2.write((char*)&bs, sizeof(bs));
                flag1=1;
              }
            }
            if(flag1==0)
              cout<<"(done)"<<endl;
              
            else
              cout<<"(done)"<<endl;
           }
        f1.close();
        f2.close();
        remove("Record_bcs.dat");
        rename("Temp_bcs.dat","Record_bcs.dat");
      }
        break;
     case '2':
        {  imt ms(oops,cn,bme);
           ifstream f3("Record_imt.dat");
           ofstream f4("Temp_imt.dat", ios::binary);
           int roll2,flag2=0;
           if(!f3)
            cout<<"file not found"<<endl;
          else
          {
            cout<<"enter roll number of student"<<endl;
            cin>>roll2;
            while(f3.read((char*)&ms, sizeof(ms)))
            { 
              if(roll2!=ms.admsno.rlno)
              {
                f4.write((char*)&ms, sizeof(ms));
                flag2=1;
              }
            }
            if(flag2==0)
              cout<<"(done)"<<endl;
            else
              cout<<"(done)"<<endl;
        }
        f3.close();
        f4.close();
        remove("Record_imt.dat");
        rename("Temp_imt.dat","Record_imt.dat");
        }
        break;
     case '3':
        {  img gs(dbms,fcs,coa);
           ifstream f5("Record_img.dat");
           ofstream f6("Temp_img.dat", ios::binary);
           int roll3,flag3=0;
           if(!f5)
            cout<<"file not found"<<endl;
          else
          {
            cout<<"enter roll number of student"<<endl;
            cin>>roll3;
            while(f5.read((char*)&gs, sizeof(gs)))
            { 
              if(roll3!=gs.admsno.rlno)
              {
                f6.write((char*)&gs, sizeof(gs));
                flag3=1;
              }
            }
            if(flag3==0)
              cout<<"(done)"<<endl;
            else
              cout<<"(done)"<<endl;
        }
        f5.close();
        f6.close();
        remove("Record_img.dat");
        rename("Temp_img.dat","Record_img.dat");
        }
        break;
     default:cout<<"no such stream"<<endl;
}
};

void disp_bcs()
{ cout<<endl<<endl<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"List of bcs students' records"<<endl;
  Bcs bs(em,dms,os);
  ifstream f("Record_bcs.dat");
  if(!f)
  {
    cout<<"file not found"<<endl;
  }
  else
  {

  while(f.read((char*)&bs,sizeof(bs)))
  {
    bs.display();
    bs.displaymarks();
  }
}
  f.close();
};

void disp_imt()
{ cout<<endl<<endl<<endl;
  cout<<"--------------------------------"<<endl;
  cout<<"List of imt students' records"<<endl;
  imt ms(oops,cn,bme);
  ifstream g("Record_imt.dat");
  if(!g)
  {
    cout<<"file not found"<<endl;
  }
  else
  {

  while(g.read((char*)&ms,sizeof(ms)))
  {
    ms.display();
    ms.displaymarks();
  }
}
  g.close();
};

void disp_img()
{ cout<<endl<<endl<<endl;
  cout<<"-----------------------------"<<endl;
  cout<<"List of img students' records"<<endl;
  img gs(dbms,fcs,coa);
  ifstream h("Record_img.dat");
  if(!h)
  {
    cout<<"file not found"<<endl;
  }
  else
  {

  while(h.read((char*)&gs,sizeof(gs)))
  {
    gs.display();
    gs.displaymarks();
  }
}
  h.close();
};

void search()
{
   cout<<endl<<endl<<endl;
  char choice;
  cout<<"which stream student do you want to search"<<endl;
  cout<<"1 for BCS"<<endl<<"2 for IMT"<<endl<<"3 for IMG"<<endl;
  cin>>choice;
  switch(choice)
  {
    case '1':
        {
           Bcs bs(em,dms,os);
           ifstream a("Record_bcs.dat");
           int n,flag=0;
           if(!a)
              cout<<"file not found"<<endl;
           else
           {
            cout<<"enter roll number"<<endl;
            cin>>n;
            while(a.read((char*)&bs, sizeof(bs)))
            {
            if(n==bs.admsno.rlno) 
            {
              flag=1;
              bs.display();
              bs.displaymarks();
            }
            }
            if(flag==0)
              cout<<"record not found"<<endl;
          }
          a.close();
 
        }
        break;
     case '2':
        {  imt ms(oops,cn,bme);
            ifstream b("Record_imt.dat");
           int n,flag=0;
           if(!b)
              cout<<"file not found"<<endl;
           else
           {
            cout<<"enter roll number"<<endl;
            cin>>n;
            while(b.read((char*)&ms, sizeof(ms)))
            {
            if(n==ms.admsno.rlno) 
            {
              flag=1;
              ms.display();
              ms.displaymarks();
            }
            }
            if(flag==0)
              cout<<"record not found"<<endl;
          }
          b.close();
 
           
        }
        break;
     case '3':
        {  img gs(dbms,fcs,coa);
            ifstream c("Record_img.dat");
           int n,flag=0;
           if(!c)
              cout<<"file not found"<<endl;
           else
           {
            cout<<"enter roll number"<<endl;
            cin>>n;
            while(c.read((char*)&gs, sizeof(gs)))
            {
            if(n==gs.admsno.rlno) 
            {
              flag=1;
              gs.display();
              gs.displaymarks();
            }
            }
            if(flag==0)
              cout<<"record not found"<<endl;
          }
          c.close();
 
        }
        break;
     default:cout<<"no such stream"<<endl;
}
};

void sort_per()
{ cout<<endl<<endl<<endl;
  char choice;
  cout<<"which stream student do you want to sort"<<endl;
  cout<<"1 for BCS"<<endl<<"2 for IMT"<<endl<<"3 for IMG"<<endl;
  cin>>choice;
  switch(choice)
  {
    case '1':
        { Bcs bs(em,dms,os);
          ifstream x("Record_bcs.dat");
         
          if(!x)
            cout<<"file not found"<<endl;
          else
          { 
            cout<<"--------------------------"<<endl;
            cout<<"the sorted records are :"<<endl;
            std::vector<pair<int,int> > v;
            while(x.read((char*)&bs, sizeof(bs)))
            {
                v.push_back(make_pair(bs.per,bs.getad()));
            } 
            sort(v.rbegin(),v.rend());
            if(1)
            {
               for(int i =0;i <v.size();i++)
            {
               
               ifstream f("Record_bcs.dat");
              while(f.read((char*)&bs, sizeof(bs)))
              {
                if( v[i].second== bs.getad())
                {
                  
                  bs.display();
                  bs.displaymarks();
                }
              }
              f.close();
            }
          }
          }
        }

        break;
     case '2':
        {  imt ms(oops,cn,bme);
          ifstream x("Record_imt.dat");
         
          if(!x)
            cout<<"file not found"<<endl;
          else
          { 
            cout<<"---------------------------"<<endl;
            cout<<"the sorted records are :"<<endl;
            std::vector<pair<int,int> > v;
            while(x.read((char*)&ms, sizeof(ms)))
            {
                v.push_back(make_pair(ms.per,ms.getad()));
            } 
            sort(v.begin(),v.end(),sortinrev);
            if(1)
            {
               for(int i =0;i <v.size();i++)
            {
               
               ifstream f("Record_imt.dat");
              while(f.read((char*)&ms, sizeof(ms)))
              {
                if( v[i].second== ms.getad())
                {
                  
                  ms.display();
                  ms.displaymarks();
                }
              }
              f.close();
            }
          }
          }
            
        }
        break;
     case '3':
        {  img gs(dbms,fcs,coa);
          ifstream x("Record_img.dat");
         
          if(!x)
            cout<<"file not found"<<endl;
          else
          { cout<<"-----------------------------"<<endl;
            cout<<"the sorted records are :"<<endl;
            std::vector<pair<int,int> > v;
            while(x.read((char*)&gs, sizeof(gs)))
            {
                v.push_back(make_pair(gs.per,gs.getad()));
            } 
            sort(v.begin(),v.end(),sortinrev);
            if(1)
            {
               for(int i =0;i <v.size();i++)
            {
               
               ifstream f("Record_img.dat");
              while(f.read((char*)&gs, sizeof(gs)))
              {
                if( v[i].second== gs.getad())
                {
                  
                  gs.display();
                  gs.displaymarks();
                }
              }
              f.close();
            }
          }
          }
           
        }
        break;
     default:cout<<"no such stream"<<endl;

}
};

void modify()
{ cout<<endl<<endl<<endl;
  char choice;
  cout<<"which stream student do you want to modify"<<endl;
  cout<<"1 for BCS"<<endl<<"2 for IMT"<<endl<<"3 for IMG"<<endl;
  cin>>choice;
  switch(choice)
  {
    case '1':
        {
            Bcs bs(em,dms,os);
           ifstream f1("Record_bcs.dat");
           ofstream f2("Temp_bcs.dat", ios::binary);
           int roll1,flag=0;
           if(!f1)
            cout<<"file not found"<<endl;
          else
          {
            cout<<"enter roll number of student"<<endl;
            cin>>roll1;
            while(f1.read((char*)&bs, sizeof(bs)))
            { 
              if(roll1==bs.admsno.rlno)
              {
               cout<<"enter modified marks of student"<<endl;
               bs.entermarks();
               f2.write((char*)&bs, sizeof(bs));
               flag=1;
              }

              else
              {
                f2.write((char*)&bs, sizeof(bs));
              }
            }
            if(flag==0)
              cout<<"record not found"<<endl;
        }
        f1.close();
        f2.close();
        remove("Record_bcs.dat");
        rename("Temp_bcs.dat","Record_bcs.dat");
        }
        break;
     case '2':
        {  imt ms(oops,cn,bme);
           ifstream f3("Record_imt.dat");
           ofstream f4("Temp_imt.dat", ios::binary);
           int roll2,flag2=0;
           if(!f3)
            cout<<"file not found"<<endl;
          else
          {
            cout<<"enter roll number of student"<<endl;
            cin>>roll2;
            while(f3.read((char*)&ms, sizeof(ms)))
            { 
              if(roll2==ms.admsno.rlno)
              {
                cout<<"enter modified marks of student"<<endl;
                ms.entermarks();
                f4.write((char*)&ms, sizeof(ms));
                flag2=1;
              }
              else
                f4.write((char*)&ms, sizeof(ms));
            }
            if(flag2==0)
              cout<<"record not found"<<endl;
        }
        f3.close();
        f4.close();
        remove("Record_imt.dat");
        rename("Temp_imt.dat","Record_imt.dat");
        }
        break;
     case '3':
        {  img gs(dbms,fcs,coa);
           ifstream f5("Record_img.dat");
           ofstream f6("Temp_img.dat", ios::binary);
           int roll3,flag3=0;
           if(!f5)
            cout<<"file not found"<<endl;
          else
          {
            cout<<"enter roll number of student"<<endl;
            cin>>roll3;
            while(f5.read((char*)&gs, sizeof(gs)))
            { 
              if(roll3==gs.admsno.rlno)
              {
                cout<<"enter modified marks of student"<<endl;
                gs.entermarks();
                f6.write((char*)&gs, sizeof(gs));
                flag3=1;
              }
              else
                f6.write((char*)&gs, sizeof(gs));
            }
            if(flag3==0)
              cout<<"record not found"<<endl;
        }
        f5.close();
        f6.close();
        remove("Record_img.dat");
        rename("Temp_img.dat","Record_img.dat");

        break;
      }
     default:cout<<"no such stream"<<endl;
}
};

void main_menu();

int Password()
{
  char pass[5];
  pass[4]='\0';
  cout<<"Enter password"<<endl;
  for(int i=0;i<4;i++)
  {
    //pass[i]=getch();
    cin>>pass[i];
    cout<<"*";
  }
  cout<<endl;
  if(strcmp(pass,"0000")==0)
  {
    cout<<"Access granted"<<endl;
    return 1;
  }
  else
  {
    cout<<"Access denied"<<endl;
    return 0;
  }
}

void Teacher()
{ int check, a=1;
  check=Password();
  if (check)
  { cout<<endl<<endl<<endl;
  cout<<"------------------------"<<endl;
  cout<<"MENU"<<endl;
  cout<<"------------------------"<<endl;
  cout<<"1.Add a student record"<<endl;
  cout<<"2.Delete a student record"<<endl;
  cout<<"3.Modify a student record"<<endl;
  cout<<"4.display all student records of BCS"<<endl;
  cout<<"5.display all student records of IMT"<<endl;
  cout<<"6.display all student records of IMG"<<endl;
  cout<<"7.search particular student's record"<<endl;
  cout<<"8.display sorted students' records"<<endl;
  cout<<"9.go to main menu"<<endl;
  while(a)
  {
    cout<<"select an option"<<endl;
  int work1;
  cin>>work1;
  switch(work1)
  {
  case 1: add();
  break;
  case 2: del();
  break;
  case 3: modify();
  break;
  case 4: disp_bcs();
  break;
  case 5: disp_imt();
  break;
  case 6: disp_img();
  break;
  case 7:search();
  break;
  case 8: sort_per();
  break;
  case 9:a=0;
  break;
  default:cout<<"invalid choice"<<endl;
  }
}
}
else
  {cout<<"wrong password"<<endl;
  main_menu();
}
}

void Student()
{ int check, a=1;
  check=1;
  if (check)
  { cout<<endl<<endl<<endl;
  cout<<"------------------------"<<endl;
  cout<<"MENU"<<endl;
  cout<<"------------------------"<<endl;
  cout<<"1.display all student records of BCS"<<endl;
  cout<<"2.display all student records of IMT"<<endl;
  cout<<"3.display all student records of IMG"<<endl;
  cout<<"4.search particular student's record"<<endl;
  cout<<"5.display sorted students' records"<<endl;
  cout<<"6.go to main menu"<<endl;
  while(a)
  {
    cout<<"select an option"<<endl;
  int work1;
  cin>>work1;
  switch(work1)
  {
  case 1: disp_bcs();
  break;
  case 2: disp_imt();
  break;
  case 3: disp_img();
  break;
  case 4:search();
  break;
  case 5: sort_per();
  break;
  case 6:a=0;
  break;
  default:cout<<"invalid choice"<<endl;
  }
}
}
}

void Others()
{int a=1;
int check=1;
if(check)
{ cout<<endl<<endl<<endl;
  cout<<"------------------------"<<endl;
  cout<<"MENU"<<endl;
  cout<<"------------------------"<<endl;
  cout<<"1.display sorted students' records"<<endl;
  cout<<"2.display all student records of BCS"<<endl;
  cout<<"3.display all student records of IMT"<<endl;
  cout<<"4.display all student records of IMG"<<endl;
  cout<<"5.go to main menu"<<endl;
  while(a)
    {cout<<"enter an option"<<endl;
  int work3;
  cin>>work3;
  switch(work3)
  {
    case 1:sort_per();
    break;
    case 2:disp_bcs();
    break;
     case 3:disp_imt();
    break;
     case 4:disp_img();
    break;
    case 5:a=0;
    break;
    default:cout<<"invalid choice"<<endl;
  }
  }
}
}

void main_menu()
{ int t=1;
  while(t)
  { cout<<endl<<endl<<endl;
  cout<<"-------------------------------"<<endl;
  cout<<"MAIN MENU"<<endl;
  cout<<"-------------------------------"<<endl;
  cout<<"Select Designation"<<endl;
  cout<<"-------------------------------"<<endl;
  cout<<"1.Teacher"<<"\t"<<"2.Student"<<"\t"<<"3.Others"<<"\t"<<"4.exit"<<endl;;
  cout<<"enter an option:"<<endl;
  int desig;
  cin>>desig;
  switch(desig)
  {
    case 1:Teacher();
    break;
    case 2:Student();
        break;

    case 3:Others();
    break;
    case 4:
        { t=0;
          const int result1 = remove( "Record_bcs.dat" );
          const int result2 = remove( "Record_imt.dat" );
          const int result3 = remove( "Record_img.dat" );
          const int result=result1 + result2 + result3;
          if( result == 0 )
            {
           printf( "success\n" );
            }
          else
            {
           printf( "done" ); // No such file or directory
            }
          exit(0);
        }
        
    default:cout<<"wrong option"<<endl;

  }
}
}

int main()
{ 
  cout<<"---------------------------------------"<<endl;
  cout<<"WELCOME TO ACADEMIC REPORT MANAGEMENT SYSTEM"<<endl;
  main_menu();
  return 0;
}

