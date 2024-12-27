#include<stdio.h>
#include<string.h>
void inputStrings(char str[][20],int n)
{
    int i,l;
    for(i=0;i<n;i++)
    {
        fgets(str[i],20,stdin);
        for(l=0;str[i][l];l++);
        str[i][l-1]='\0';
    }
}
void countVowels(char str[][20],int n)
{
    char v[]="aeiouAEIOU";
    int i,j,k,count;
    inputStrings(str,n);
    for(i=0;i<n;i++)
    {
        for(j=0,count=0;str[i][j];j++)
            for(k=0;v[k];k++)
                if(str[i][j]==v[k])
                    count++;
        printf("Vowels in %s are %d",str[i],count);
    }
}
void sort(char str[][20],int n)
{
    int r,i;
    char temp[20];
    for(r=1;r<=n-1;r++)
    {
        for(i=0;i<=n-1-r;i++)
        {
            if(strcmp(str[i],str[i+1])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[i+1]);
                strcpy(str[i+1],temp);
            }
        }
    }
}
void display(char str[][20],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("\n%s",str[i]);
}
char* trim(char str[])
{
    char temp[50];
    int i;
    for(i=0;str[i];i++)
    {
        if(str[i]!=' ')
            break;
    }
    if(str[i]!='\0')
        strcpy(temp,str+i);
    for(i=0;temp[i];i++);
    i--;
    while(temp[i]==' ')
        i--;
    temp[i+1]='\0';
    strcpy(str,temp);
    return str;
}

int countWords(char str[])
{
    int i,count=0;
    trim(str);
    for(i=0;str[i];i++)
        if(str[i]==' ')
            count++;
    return count+1;
}
int splitToStrings(char str[],char s[][20],int n)
{
    int i,j=-1,no_of_words,k;
    
    no_of_words=countWords(str);
    if(no_of_words<=n)
        for(i=0;i<no_of_words;i++)
        {
            for(j++,k=0;str[j]!=' '&&str[j]!='\0';j++,k++)
                s[i][k]=str[j];
            s[i][k]='\0';        
        }

    return no_of_words;
}
int remove_duplicate(char s[][20],int n)
{
    int i,j,k=0;
    char temp[n][20];
    sort(s,n);
    strcpy(temp[k],s[0]);
    for(i=0;i<n-1;)
    {
        for(j=i+1;j<n;j++)
            if(strcmp(s[i],s[j])==0)
                continue;
            else
            {
                i=j;
                k++;
                strcpy(temp[k],s[j]);
                break;
            }
        if(j==n)
            break;
    }
    for(i=0;i<=k;i++)
        strcpy(s[i],temp[i]);
    return k+1;
}
int main()
{
    char s[10][20]={
        "Bhopal","Bhopal","Delhi","Delhi","Delhi","Jaipur",
        "Kanpur","Kanpur","Manglore","Manglore"
    };
    int n;
    n=remove_duplicate(s,10);

    display(s,n);
    printf("\n");
    return 0;
}