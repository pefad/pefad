#include <string>
#include<iostream>
using namespace std;
int main(){
    
///-----------------------------BASIC INFORMATION OF STUDENT-------------------------------------
    int NoOfCourses;
	char name[300],department[300],level[100];
    cout <<"\n>>>>>>>>>Student Cgpa Grading system using c++<<<<<<<<<";
    cout<< "Enter name of Student: "<<endl;
    cin.getline(name,300);
    cout<<"Enter Department of student: "<<endl;
    cin.getline(department, 300);
    cout<<"Enter Level of student: "<<endl;
    cin.getline(level,100);
///------------------------------NUMBER OF COURSES OFFERED BY STUDENT------------------------------------
    cout<<"Enter Number Of Courses Done By "<<name<<": ";
    cin>>NoOfCourses;
        int unit[11];
    int i,sum=0,marks[NoOfCourses];
    string nameofcourse;
    float TotalGrade;
    int gpa[11];
    int Totalunit;
    int Dividebyunitofcourse;
///-------------------------PERFORM COLLECTION OF INFORMATION ON EACH COURSES-----------------------------------------

    for(i=0;i<NoOfCourses;i++){
///--------------------------COLLECT NAME OF COURSE----------------------------------------

            cout<<""<<i+1<<". Enter Name Of Course of Study Without Space: "<<endl;
    cin>>nameofcourse;
///--------------------------------COLLECT UNIT OF COURSE----------------------------------

        cout<<""<<i+1<<". Enter Unit Of "<<nameofcourse<<": ";
            cin>>unit[i];
///----------------------------COLLECT SCORE OF COURSE--------------------------------------

        cout<<""<<i+1<<". Enter the Score of "<<name<<" in "<<nameofcourse<<": ";
        cin>>marks[i];
        sum=marks[i];
///-----------------------[PERFORM OPERATION ON SCORE TO GIVE EQUIVALENT GRADE POINT]-------------------------------------------

    if (sum>=75){
        marks[i]=4.00;}
        else{
          if(sum>=70 && sum<=74){
        marks[i]=3.50;
        } else{

        if(sum>=65 && sum<=69){
        marks[i]=3.25;
        }else{

            if(sum>=60 && sum<=64){
        marks[i]=3;}else{
        if(sum>=55 && sum<=59){
        marks[i]=2.75;
        }else{
        if(sum>=50 && sum<=54){
        marks[i]=2.50;}else{
        if(sum>=45 && sum<=49){
        marks[i]=2.25;}else{
        if (sum>=40 && sum<=44){
        marks[i]=2;}
        else{
            if(sum>=35 && sum<=39){
        marks[i]=1.75;}else{
           if(sum>=30 && sum<=34){
        marks[i]=1.50;}
        else{
            if(sum>=25 && sum<=29){
        marks[i]=1.25;}else{
            if(sum>=20 && sum<=24){
        marks[i]=1;}else{
            if(sum>=15 && sum<=19){
        marks[i]=0.75;}else{
            if(sum>=10 && sum<=14){
        marks[i]=0.50;}else{
            if(sum>=0 && sum<=9){
        marks[i]=0;}

        }
        }
        }
        }
        }
        }

        }
        }
        }
        }
        }
        }}
        }
///-------------------[PERFORM MUTIPLICATION OF ALL MARKS AND UNIT OF ALL COURSE TO GET GPA]-----------------------------------------------

        gpa[i]=(marks[i]*unit[i]);
        TotalGrade+=gpa[i];
        Totalunit+=unit[i];
    }
///--------------------[DISPLAY OUTPUT OF CALCULATED GRADING POINT OF STUDENT]----------------------------------------------

cout<<"\n";
cout<<"SHOWING THE RESULT OF "<<name<<" FROM DEPARTMENT OF "<<department<<" "<<level;
cout<<"\n";
    Dividebyunitofcourse=TotalGrade/Totalunit;
    cout<<"Total courses Offered is: "<<NoOfCourses<<endl;
    cout<<"Total unit of all courses is: "<<Totalunit<<endl;
    if(Dividebyunitofcourse>=4){
    cout<<"The Cum. Grade Point{CGPA} is: "<<Dividebyunitofcourse<<endl;
        cout<<"REMARK CREDIT OF "<<name<<" is: "<< "DISTINTION!\n";
    }else{
    if(Dividebyunitofcourse>=3.00 && Dividebyunitofcourse<=3.50){
    cout<<"The Cum. Grade Point{CGPA} is: "<<Dividebyunitofcourse<<endl;
        cout<<"REMARK CREDIT OF "<<name<<" is: "<< "UPPER CREDIT!\n";
    }else{
    if(Dividebyunitofcourse>=2.00 &&Dividebyunitofcourse<=2.99){
    cout<<"The Cum. Grade Point{CGPA} is: "<<Dividebyunitofcourse<<endl;
        cout<<"REMARK CREDIT OF "<<name<<" is: "<< "LOWER CREDIT!\n";
    }else{
         if(Dividebyunitofcourse>=1.00 &&Dividebyunitofcourse<=1.99){
    cout<<"The Cum. Grade Point{CGPA} is: "<<Dividebyunitofcourse<<endl;
        cout<<"REMARK CREDIT OF "<<name<<" is: "<< "PASS!\n";
    }else{
     if(Dividebyunitofcourse>=0.00 &&Dividebyunitofcourse<=0.99){
    cout<<"The Cum. Grade Point{CGPA} is: "<<Dividebyunitofcourse<<endl;
        cout<<"REMARK CREDIT OF "<<name<<" is: "<< "RUSTICATED!!!\n";
    }else{
    cout<<"The Cum. Grade Point{CGPA} is: "<<Dividebyunitofcourse<<endl;
        cout<<"REMARK CREDIT OF "<<name<<" is: "<< "RUSTICATED!!!\n";

    }
    }
    }
    }
    }
///------------------------END PROGRAM AFTER SUCCESS EXECUTION, IF USER PRESS ANY KEY ------------------------------------------
  
///------------------------SCRIPT BY PETER + KINGSCONCEPT TEAM ------------------------------------------
  

    cin.ignore();
    cin.ignore();
return 0;
}
