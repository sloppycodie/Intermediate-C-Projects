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

struct Student students[MAX];

//It counts the students
int count = 0;


int main() {
    
    return 0;
}