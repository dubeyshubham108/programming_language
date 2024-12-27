#include<stdio.h>
#include<string.h>
struct Time
{
    int hr,min,sec;
};
int isGreater(struct Time t1,struct Time t2)
{
    if(t1.hr>t2.hr)
        return 1;
    else if(t1.hr<t2.hr)
        return 0;
    else if(t1.min>t2.min)
        return 1;
    else if(t1.min<t2.min)
        return 0;
    else if(t1.sec>t2.sec)
        return 1;
    else 
        return 0; 
}
struct Time difference(struct Time t1,struct Time t2)
{
    struct Time t3;
    if(isGreater(t1,t2))
    {
        if(t1.sec<t2.sec){
            t1.sec+=60;
            if(t1.min>0)
                t1.min-=1;
            else{
                t1.min+=60;
                t1.hr-=1;
            }
        }
        t3.sec=t1.sec-t2.sec;
        if(t1.min<t2.min)
        {
            t1.min+=60;
            t1.hr-=1;
        }
        t3.min=t1.min-t2.min;
        t3.hr=t1.hr-t2.hr;
    }
    else
    {
        if(t2.sec<t1.sec){
            t2.sec+=60;
            if(t2.min>0)
                t2.min-=1;
            else{
                t2.min+=60;
                t2.hr-=1;
            }
        }
        t3.sec=t2.sec-t1.sec;
        if(t2.min<t1.min)
        {
            t2.min+=60;
            t2.hr-=1;
        }
        t3.min=t2.min-t1.min;
        t3.hr=t2.hr-t1.hr;
    }
    return t3;
}
void f1()
{
    struct Time t1={3,25,40},t2={4,10,30};
    struct Time t3;
    t3=difference(t1,t2);
    printf("%d:%d:%d",t3.hr,t3.min,t3.sec);
}
struct Student
{
    int rollno;
    char name[20];
};
struct Student inputStudent()
{
    struct Student s;
    printf("Enter Student roll no and name");
    scanf("%d",&s.rollno);
    fflush(stdin);
    fgets(s.name,20,stdin);
    s.name[strlen(s.name)-1]='\0';
    return s;
}
void displayStudent(struct Student s)
{
    printf("\n%d  %s",s.rollno,s.name);
}
void inputNStudents(struct Student s[],int n)
{
    int i;
    for(i=0;i<n;i++)
        s[i]=inputStudent();
}
void displayNStudents(struct Student s[],int n)
{
    int i;
    for(i=0;i<n;i++)
        displayStudent(s[i]);
}
void f2()
{
    struct Student s[10];
    inputNStudents(s,10);
    displayNStudents(s,10);

}
struct Marks{
    int rollno;
    char name[20];
    int chem_marks;
    int maths_marks;
    int phy_marks;
};
struct Marks inputMarks()
{
    struct Marks mark;
    printf("Enter marks data");
    scanf("%d",&mark.rollno);
    fflush(stdin);
    fgets(mark.name,20,stdin);
    mark.name[strlen(mark.name)-1]='\0';
    scanf("%d",&mark.chem_marks);
    scanf("%d",&mark.maths_marks);
    scanf("%d",&mark.phy_marks);
    return mark;
}
float percentage(struct Marks m)
{
    return (m.chem_marks+m.maths_marks+m.phy_marks)/3.0;
}
void f4()
{
    struct Marks m[5];
    int i;
    for(i=0;i<=4;i++)
        m[i]=inputMarks();
    for(i=0;i<=4;i++)
        printf("%d %s %f",m[i].rollno,m[i].name,percentage(m[i]));

}