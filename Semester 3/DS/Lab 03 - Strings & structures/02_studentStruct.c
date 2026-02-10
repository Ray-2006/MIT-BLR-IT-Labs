/*
2.  Write a C program to define a student structure with the data members to store name, 
    roll no and grade of the student. Also write the required functions to read, display, 
    and sort student information according to the roll number of the student. All the member 
    functions will have array of objects as arguments.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int rollNo;
    char grade;
} Student;

void readStudent(Student *student) {
    printf("Enter student name: ");
    fgets(student->name, NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0; // Remove newline character

    printf("Enter roll number: ");
    scanf("%d", &student->rollNo);
    getchar(); // Consume newline character left by scanf

    printf("Enter grade: ");
    scanf(" %c", &student->grade);
    getchar(); // Consume newline character
}

void displayStudent(const Student *student) {
    printf("Name: %s, Roll No: %d, Grade: %c\n", student->name, student->rollNo, student->grade);
}

void sortStudentsByRollNo(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    char choice;

    do {
        if (count >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }

        readStudent(&students[count]);
        count++;

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline character
    } while (choice == 'y' || choice == 'Y');

    printf("\nStudent Information:\n");
    for (int i = 0; i < count; i++) {
        displayStudent(&students[i]);
    }

    sortStudentsByRollNo(students, count);
    printf("\nSorted Student Information by Roll No:\n");
    for (int i = 0; i < count; i++) {
        displayStudent(&students[i]);
    }

    return 0;
}
