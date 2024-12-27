#include<stdio.h>
void swap(int A[],int i, int j)
{
    int t;
    t=A[i];
    A[i]=A[j];
    A[j]=t;
}
void sort(int A[],int n)
{
    int r,i,t;
    for(r=1;r<n;r++)
    {
        for(i=0;i<=n-1-r;i++)
        {
            if(A[i]>A[i+1])
                swap(A,i,i+1);
        }
    }
}
int countDuplicates(int A[],int n)
{
    int i=0,j=1,count=0;
    sort(A,n);
    while(j<n)
    {

        while(A[i]==A[j])
        {
            if(i+1==j)
                count++;
            j++;
            if(j==n)
                break;
        }
        i=j;
        j=j+1;
    }
    return count;
}
void printUnique(int A[],int n)
{
    int i=0,j=1;
    sort(A,n);
    while(i<n)
    {
        printf("%d ",A[i]);
        if(i==n-1)
            break;
        while(A[i]==A[j])
        {
            j++;
            if(j==n)
                break;
        }
        i=j;
        j=j+1;
    }
}
void mergeDesc(int A[],int B[],int n,int C[])
{
    int i,j,k;
    for(i=n-1, j=n-1,k=2*n-1;i>=0 && j>=0;k--)
    {
        if(A[i]>B[j])
        {
            C[k]=A[i];
            i--;
        }
        else
        {
            C[k]=B[j];
            j--;
        }
    }
    while(i>=0)
    {
        C[k]=A[i];
        i--;
        k--;
    }
    while(j>=0)
    {
        C[k]=B[j];
        j--;
        k--;
    }
}
void freq(int A[],int n)
{
     int i=0,j=1,count;
    sort(A,n);
    while(i<n)
    {
        printf("\n%d - ",A[i]);
        if(i==n-1)
            break;
        count=1;
        while(A[i]==A[j])
        {
            count++;
            j++;
            if(j==n)
                break;
        }
        printf("%d ",count);
        i=j;
        j=j+1;
    }
}
int main()
{
    int A[]={2,3,2,4,1,2,3,3,4};
    freq(A,9);
    return 0;
}