#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//It defines the max student can be 100. If you want to increase the number later you can just change this
#define MAX 100

//It makes the structure for the student information
struct Student{
    int id;
    char name[50];
    double physics, chemistry, math;
    double average;
    char grade;
};

//Number of students can be MAX
struct Student students[MAX];

//It counts the students
int count = 0;

//It calculates the grade of the students. We used pointers to let this function edit the file. Otherwise these functions make a copy of the data.
void gradeCalculation(struct Student *Students);

//It searches the student id and returns the id serial number.
int searchStudents(int id);

//It takes the student information from the user
void addStudent();

//The main function
int main() {
    
    return 0;
}

void gradeCalculation(struct Student *Students){
    students->average = (students->chemistry + students->math + students->physics)/3.0;
    if (students->average >80)
    {
        students->grade = "A";
    }
    else if (students->average >70)
    {
        students->grade = "B";
    }
    else if (students->average >60)
    {
        students->grade = "C";
    }
    else if (students->average >50)
    {
        students->grade = "D";
    }
    else
    {
        students->grade = "F";
    }
}

int searchStudents(int id){
    for (int i = 0; i < MAX; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
    }
    return -1;//We used -1 because array starts with 0. so -1 is not any id number.
}

void addStudent(){
    if (count>MAX)
    {
        printf("!!!Database Full!!!");
        return;//It exits the function immediately
    }

    printf("Please Enter The Details of the students.");
    printf("Student ID: ");
    scanf("%d", &students[count].id);
    
    //Searches if the student ID exists or not. If the id doesn't exist the function will return 0
    if (searchStudents(students[count].id)!=-1)
    {
        printf("This ID already exists.");
        return;
    }
    
    printf("Name: ");
    fgets(students[count].name,sizeof(students[count].name),stdin);
    students[count].name[strcspn(students[count].name,"\n")] = '\0';

    printf("Math: ");
    scanf("%lf", &students[count].math);

    printf("Physics: ");
    scanf("%lf", &students[count].physics);

    printf("Chemistry: ");
    scanf("%lf", &students[count].chemistry);

    gradeCalculation(&students[count]);

    count++;
    
    printf("Student's Information Added Successfully.\n");
}
