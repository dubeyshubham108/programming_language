#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
void bubbleSort(int A[],int size)
{
    int r,i,t;
    for(r=1;r<=size-1;r++)
    {
        for(i=0;i<=size-1-r;i++)
        {
            if(A[i]>A[i+1])
            {
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
    }
}
void modifiedBubbleSort(int A[],int size)
{
    int r,i,t;
    bool flag;
    for(r=1;r<=size-1;r++)
    {
        flag=false;
        for(i=0;i<=size-1-r;i++)
        {
            if(A[i]>A[i+1])
            {
                flag=true;
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
        if(flag==false)
            break;
    }
}
void insertionSort(int A[],int size)
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=A[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<A[j])
                A[j+1]=A[j];
            else
                break;
        }
        A[j+1]=temp;
    }
}
int minValueIndex(int A[],int size,int j)
{
    int i,min,minIndex;
    min=A[j];
    minIndex=j;
    for(i=j+1;i<=size-1;i++)
    {
        if(min>A[i])
        {
            min=A[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void selectionSort(int A[],int size)
{
    int t,i,minIndex;
    for(i=0;i<=size-2;i++)
    {
        minIndex=minValueIndex(A,size,i);
        t=A[i];
        A[i]=A[minIndex];
        A[minIndex]=t;
    }
}
int quick(int A[],int left,int right)
{
    int loc=left,t;
    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && A[left]<=A[loc])
            left++;
        if(left==right)
            break;
        t=A[left];
        A[left]=A[loc];
        A[loc]=t;
        loc=left;
    }
    return loc;
}
void quickSort(int A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1)
        quickSort(A,l,loc-1);
    if(loc<u-1)
        quickSort(A,loc+1,u);
}
void quickSortLoop(int A[],int l,int u)
{
    int loc,i,j;
    stack <int>lower;
    stack <int>upper;
    lower.push(l);
    upper.push(u);
    while(!lower.empty())
    {
        i=lower.top();
        j=upper.top();
        loc=quick(A,i,j);
        lower.pop();
        upper.pop();
        if(loc>i+1)
        {
            lower.push(i);
            upper.push(loc-1);
        }
        if(loc<j-1)
        {
            lower.push(loc+1);
            upper.push(j);
        }
    }
}
void merging(int A[],int l,int m,int u)
{
    int L[m-l+1],R[u-m],i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 && j<u-m; k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merging(A,l,m,u);
    }
}
void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1 && j<n2;k++)
    {
        if(a[i+i1]<b[j+i2])
        {
            c[k+i3]=a[i+i1];
            i++;
        }
        else
        {
            c[k+i3]=b[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        c[k+i3]=a[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        c[k+i3]=b[j+i2];
        j++;
        k++;
    }
}
void mergepass(int SRC[],int size,int L,int DEST[])
{
    int j,mergeCount,index,R,S;
    mergeCount=size/(2*L);
    S=mergeCount*2*L;
    R=size-S;
    for(j=0;j<mergeCount;j++)
    {
        index=j*2*L;
        merge(SRC,L,index,SRC,L,index+L,DEST,index);
    }
    if(R<=L)
    {
        for(int i=0;i<R;i++)
            DEST[S+i]=SRC[S+i];
    }
    else
        merge(SRC,L,S,SRC,R-L,S+L,DEST,S);
}
void mergeSortLoop(int A[],int size)
{
    int L=1,B[size];
    while(L<size)
    {
        mergepass(A,size,L,B);
        mergepass(B,size,2*L,A);
        L=L*4;
    }
}
class Employee
{
    private:
        int emp_id;
        char name[20];
        float salary;
    public:
        void setEmpid(int id) { emp_id=id;}
        void setName(char n[]) { strcpy(name,n);}
        void setSalary(float s) { salary=s;}
        int getEmpid() { return emp_id;}
        char* getName() { return name;}
        float getSalary() { return salary;}
};
void merging(Employee A[],int l,int m,int u)
{
    Employee L[m-l+1],R[u-m];
    int i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 && j<u-m; k++)
    {
        if(L[i].getSalary()<R[j].getSalary())
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(Employee A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merging(A,l,m,u);
    }
}
void setEmployee(Employee &e,int id,char n[],float s)
{
    e.setEmpid(id);
    e.setName(n);
    e.setSalary(s);
}
void showEmployee(Employee e)
{
    cout<<endl;
    cout<<e.getEmpid()<<" "<<e.getName()<<" "<<e.getSalary();
}
void sortBySalary(Employee e[],int size)
{
    mergeSort(e,0,size-1);
}

int quick(Employee A[],int left,int right)
{
    int loc=left;
    Employee t;
    while(left<right)
    {
        while(left<right && strcmp(A[loc].getName(),A[right].getName())<=0)
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && strcmp(A[left].getName(),A[loc].getName())<=0)
            left++;
        if(left==right)
            break;
        t=A[left];
        A[left]=A[loc];
        A[loc]=t;
        loc=left;
    }
    return loc;
}
void quickSort(Employee A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1)
        quickSort(A,l,loc-1);
    if(loc<u-1)
        quickSort(A,loc+1,u);
}
void sortByName(Employee e[],int size)
{
    quickSort(e,0,size-1);
}
int main()
{
    Employee e[10];
    setEmployee(e[0],1,"Rahul",30000);
    setEmployee(e[1],2,"Dilip",40000);
    setEmployee(e[2],3,"Gajendra",50000);
    setEmployee(e[3],4,"Anjan",10000);
    setEmployee(e[4],5,"Hitesh",20000);
    setEmployee(e[5],6,"Rajesh",25000);
    setEmployee(e[6],7,"Jay",70000);
    setEmployee(e[7],8,"Jitendra",50000);
    setEmployee(e[8],9,"Sandeep",35000);
    setEmployee(e[9],10,"Aalok",5000);

    sortByName(e,10);
    for(int i=0;i<=9;i++)
        showEmployee(e[i]);

    /*int a[]={80,30,50,90,100,10,20,40,70,60};
    int i;

    quickSort(a,0,9);
    for(i=0;i<=9;i++)
        cout<<" "<<a[i];*/
    cout<<endl;
    return 0;
}