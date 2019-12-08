#include<bits/stdc++.h>
using namespace std;

#ifndef IMG_H
#define IMG_H

#include "subject.h"
#include "student.h"

class img : public Student
{
private:
	Subject s1;
	Subject s2;
	Subject s3;
public:
	img(Subject cs1,Subject cs2,Subject cs3)
	:s1(cs1),s2(cs2),s3(cs3)
	{
	}

  void entermarks()
  {
    cout<<"enter marks :"<<endl;
    cout<<s1.sname<<":";
    cin>>s1.marks;
    cout<<s2.sname<<":";
    cin>>s2.marks;
    cout<<s3.sname<<":";
    cin>>s3.marks;
    total =(s1.marks+s2.marks+s3.marks);
    per = (total/300) * 100;
  }

  void displaymarks()
  {
    cout<<"marks of the student are:"<<endl;
    cout<<s1.sname<<" : "<<s1.marks<<endl;
    cout<<s2.sname<<" : "<<s2.marks<<endl;
    cout<<s3.sname<<" : "<<s3.marks<<endl;
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