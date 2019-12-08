#include<bits/stdc++.h>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

#include "admno.h"
#include "date.h"

class Student
{  private:
      Admno admsno;
      string name;
      string fname;
      string mname;
      Date dob;
      string telno;

    public:
        float total;
        float per;
        char grade;
        void enter()
        {
          cout<<"name of student :";
          cin>>name;
          cout<<"father's name :";
          cin>>fname;
          cout<<"mother's name :";
          cin>>mname;
          cout<<"telephone number :";
          cin>>telno;
          cout<<"date of birth :";
          cin>>dob.day>>dob.month>>dob.year;
          cout<<"admission number :";
          cin>>admsno.year>>admsno.branch>>admsno.rlno;

        }

        void display()
        {
          cout<<endl<<"-------------------------"<<endl;
          cout<<"THE DETAILS ARE :-"<<endl;
          cout<<"name of student :"<<" "<<name<<endl;
          cout<<"father's name :"<<" "<<fname<<endl;
          cout<<"mother's name :"<<" "<<mname<<endl;
          cout<<"telephone number :"<<" "<<telno<<endl;
          cout<<"date of birth :"<<" "<<dob.day<<"-"<<dob.month<<"-"<<dob.year<<endl;
          cout<<"admission number :"<<" "<<admsno.year<<"-"<<admsno.branch<<"-"<<admsno.rlno<<endl;
        }

        int getad( )
        {
          return admsno.rlno;
        }

        friend void add();
        friend void disp_bcs();
        friend void disp_imt();
        friend void disp_img();
        friend void del();
        friend void modify();
        friend void search();
        friend void sortper();
  };

#endif