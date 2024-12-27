#include<stdio.h>
void swapStrings(char s1[],char s2[])
{
    char temp[100];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
}
void sort(int *ptr,int size)
{
    int r,i,t;
    for(r=1;r<size;r++)
    {
        for(i=0;i<=size-1-r;i++)
        {
            if(ptr[i]>ptr[i+1])
            {
                t=ptr[i];
                ptr[i]=ptr[i+1];
                ptr[i+1]=t;
            }
        }
    }
}
void merge(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<size1 && j<size2;k++)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
        }
        else
        {
           arr3[k]=arr2[j];
           j++; 
        }
    }
    while(i<size1)
    {
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }
}
int f4(int A[],int size)
{
    int left,right,loc,temp;
    left=0;
    right=size-1;
    loc=0;

    while(left<right)
    {
        while(left<right&&A[loc]<A[right])
            right--;
        if(left==right)
            break;
        temp=A[right];
        A[right]=A[loc];
        A[loc]=temp;
        loc=right;
        while(left<right&&A[left]<A[loc])
            left++;
        if(left==right)
            break;
        temp=A[left];
        A[left]=A[loc];
        A[loc]=temp;
        loc=left;
    }
    return loc;
}
int highestMarks(int **p,int no_of_classes,int num_of_students[])
{
    int max,i,j;
    max=p[0][0];
    for(i=0;i<no_of_classes;i++)
    {
        for(j=0;j<num_of_students[i];j++)
            if(max<p[i][j])
                max=p[i][j];
    }
    return max;
}


//Extension of problem 5

#include <stdio.h>
#include <stdlib.h>

// Function to find the highest marks
int highestMarks(int **p, int no_of_classes, int num_of_students[]) {
    int max, i, j;
    max = p[0][0];  // Initialize max to the first student's marks in the first class
    for (i = 0; i < no_of_classes; i++) {
        for (j = 0; j < num_of_students[i]; j++) {
            if (max < p[i][j]) {
                max = p[i][j];  // Update max if a higher mark is found
            }
        }
    }
    return max;  // Return the highest mark
}

int main() {
    int no_of_classes = 3;  // Example: 3 classes
    int num_of_students[] = {4, 3, 5};  // Class 1 has 4 students, Class 2 has 3 students, Class 3 has 5 students

    // Dynamically allocate memory for the 2D array (array of pointers)
    int **marks = (int**)malloc(no_of_classes * sizeof(int*));
    if (marks == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each class
    for (int i = 0; i < no_of_classes; i++) {
        marks[i] = (int*)malloc(num_of_students[i] * sizeof(int));
        if (marks[i] == NULL) {
            printf("Memory allocation failed for class %d\n", i);
            return 1;
        }
    }

    // Example marks initialization for each class and student
    marks[0][0] = 85; marks[0][1] = 90; marks[0][2] = 88; marks[0][3] = 92;  // Class 1 marks
    marks[1][0] = 76; marks[1][1] = 80; marks[1][2] = 78;                      // Class 2 marks
    marks[2][0] = 89; marks[2][1] = 91; marks[2][2] = 95; marks[2][3] = 87; marks[2][4] = 93;  // Class 3 marks

    // Call the function to find the highest marks
    int highest = highestMarks(marks, no_of_classes, num_of_students);

    // Print the highest marks
    printf("The highest marks among all students are: %d\n", highest);

    // Free the allocated memory
    for (int i = 0; i < no_of_classes; i++) {
        free(marks[i]);  // Free memory for each class
    }
    free(marks);  // Free memory for the array of pointers

    return 0;
}
