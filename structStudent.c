#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct Student
// {
//     char name[10];
//     char id[10];
//     int grades[5];
//     int age;
// };

typedef struct
{
    char name[10];  // or char *name;
    char id[10];  // or char *id;
    int grades[5];
    int age;
}Student;    //  creating a datatype Student which is a struct


typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    int *array;
} Data;


void print_points(Point points[]);


void print_student(Student studentdata);
int main()
{
    // struct Student kevin;'
    Student kevin;
    kevin.age = 18;
    strcpy(kevin.id,"0001230450");  // or  kevin.id = "0001230450"
    strcpy(kevin.name,"Kevin");  // or kevin.name = "Kevin"
    kevin.grades[0] = 1;
    kevin.grades[1] = 2;
    kevin.grades[2] = 3;
    kevin.grades[3] = 4;
    kevin.grades[4] = 5;

    print_student(kevin);

    Point p1 = {5, 6};

    Point p2 = {
        .y = 7,
        .x = 9
    };

    printf("p1.x: %d\n", p1.x);
    printf("p1.y: %d\n", p1.y);

    printf("p2.x: %d\n", p2.x);
    printf("p2.y: %d\n", p2.y);

    p1 = p2;

    printf("p1.x: %d\n", p1.x);
    printf("p1.y: %d\n", p1.y);

    Point points[10];

    for (int i = 0; i < 10; i++){
        points[i].x = i;
        points[i].y = 10 - i;
    }

    print_points(points);


    Data x;
    Data y;

    x.array = malloc(sizeof(int) * 5);
    y.array = malloc(sizeof(int) * 5);

    x.array[0] = 1;
    x.array[1] = 2;
    x.array[2] = 3;
    x.array[3] = 4;
    x.array[4] = 5;

    y.array[0] = 9;
    y.array[1] = 9;
    y.array[2] = 9;
    y.array[3] = 9;
    y.array[4] = 9;

    x = y;

    y.array[0] = 15;

    for(int i = 0; i < 5; i++)
        printf(" x.array[%d] = %d\n", i, x.array[i]);
    printf("\n");
    for(int i = 0; i < 5; i++)
        printf(" y.array[%d] = %d\n", i, y.array[i]);




    return 0;
}


void print_student(Student studentdata)
{
    printf("Name: %s\n", studentdata.name);
    printf("ID: %s\n", studentdata.id);
    printf("Age: %d\n", studentdata.age);
    printf("Grades: ");
    for (int q; q < 5; q++)
        printf("%d ",studentdata.grades[q]);

    
    printf("\n");
}
void print_points(Point points[]){
    for (int i = 0; i < 10; i++)
    printf("p%d = (%d,%d)\n",i , points[i].x, points[i].y);
}