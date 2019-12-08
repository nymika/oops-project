#include<bits/stdc++.h>
using namespace std;

#ifndef BCS_H
#define BCS_H

#include "subject.h"
#include "student.h"

class Bcs : public Student
{
private:
	Subject maths;
	Subject phy;
	Subject chem;
public:
  Bcs(Subject cs1,Subject cs2,Subject cs3)
  :maths(cs1),phy(cs2),chem(cs3)
  {
  }

  void entermarks()
  {
    cout<<"enter marks :"<<endl;
    cout<<maths.sname<<":";
    cin>>maths.marks;
    cout<<phy.sname<<":";
    cin>>phy.marks;
    cout<<chem.sname<<":";
    cin>>chem.marks;
    total =(maths.marks+phy.marks+chem.marks);
    per = (total/300) * 100;
  }

  void displaymarks()
  {
    cout<<"marks of the student are:"<<endl;
    cout<<maths.sname<<" : "<<maths.marks<<endl;
    cout<<phy.sname<<" : "<<phy.marks<<endl;
    cout<<chem.sname<<" : "<<chem.marks<<endl;
    cout<<"total marks :"<<total<<endl;
    cout<<"percentage obtained :"<<per<<endl;
    if(per>=80)  grade='A';
    else if((per>=60)&&(per<=79))  grade='B';
    else if((per>=40)&&(per<=59))  grade='C';
    else if((per>=35)&&(per<=39))  grade='D';
    else if(per<35)  grade='F';
    cout<<"grade obtained : "<<grade<<endl;
  }
};

#endif
