#include<stdio.h>
#include<string.h>
char* trim(char str[])
{
    char temp[200];
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
void f1()
{
    char str[]="mysirg education services and this is a learning platform for students";
    char s[20][20],temp[100][20];
    int i,j,no_of_words;
    no_of_words=splitToStrings(str,temp,strlen(str));
    for(i=0,j=0;i<no_of_words;i++)
    {
        if(temp[i][strlen(temp[i])-1]=='s')
        {
            strcpy(s[j],temp[i]);
            j++;
        }
    }
    for(i=0;i<j;i++)
        printf("\n%s",s[i]);
}
char maxFreqCharacter(char s[][20],int n)
{
    int freq[256]={0};
    int i,j,max;
    char ch;
    for(i=0;i<n;i++)
    {
        for(j=0;s[i][j];j++)
            freq[s[i][j]]++;
    }
    max=freq[0];
    ch=0;
    for(i=1;i<256;i++)
        if(max<freq[i])
        {
            max=freq[i];
            ch=i;
        }
    return ch;
}
int isAnagram(char s1[],char s2[])
{
    int f1[256]={0},f2[256]={0};
    int i;
    for(i=0;s1[i];i++)
        f1[s1[i]]++;
    for(i=0;s2[i];i++)
        f2[s2[i]]++;
    for(i=0;i<256;i++)
        if(f1[i]!=f2[i])
            return 0;
    return 1;
}
void f4()
{
    char str[]="mysirg education services and this is a learning platform for students";
    char s[20][20],temp[100][20];
    int i,j,no_of_words;
    no_of_words=splitToStrings(str,temp,strlen(str));
    for(i=0,j=0;i<no_of_words;i++)
    {
        if(temp[i][0]=='a')
        {
            strcpy(s[j],temp[i]);
            j++;
        }
    }
    for(i=0;i<j;i++)
        printf("\n%s",s[i]);
}
int countGmail(char s[][50],int n)
{
    char text[]="@gmail.com";
    int i,count=0,j,k;
    for(i=0;i<n;i++)
    {
        if(strlen(s[i])>10)
        {
            for(k=0,j=strlen(s[i])-10;s[i][j];j++,k++)
                if(text[k]!=s[i][j])
                    break;
            if(!text[k])
                count++;
        }
    }
    return count;
}
int main()
{
    char emailids[][50]={
        "kelly@hotmail.com",
        "iamsupercool@gmail.com",
        "roopesh.bhatnagar@gmail.com",
        "smitapurohit@yahoo.com",
        "ajayahuja@gmail.com",
        "wangchuk@gmail.com",
        "rashmi@yahoo.co.in"
    };
    printf("%d ",countGmail(emailids,7));
    printf("\n");
    return 0;
}