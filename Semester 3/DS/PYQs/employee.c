/*
Define a structure Employee having following members
    i) Name -a char array type
    ii) Empcode-an int type
    iii) Age- an int type( at the time of join)
    iv) Joining date -a pointer to a structure
    Date which has three integer members for storing day, month and year.
    v) Salary-a float type.
Write a C program to create an array of structure of type Employee to hold details of 'n'
employees. Read the data into the structure array and display the same in main function.
Write a function Retire which takes a pointer of the type structure Employee and
compute the retirement year of each employee and the salary at that time considering
20% hike per year. (standard age of retirement is 60). Test this function from the main
function.
*/

#include <stdio.h>
#include <stdlib.h>

/* ------------ Date Structure ------------- */
typedef struct Date {
    int day, month, year;
} Date;

/* ------------ Employee Structure ------------- */
typedef struct Employee {
    char name[30];
    int empcode;
    int age;               // at the time of joining
    Date *joiningDate;     // pointer to Date structure
    float salary;
} Employee;

/* ------------ Retire Function ------------- */
/*
   Takes an employee pointer and computes:
   - retirement year
   - salary at retirement with 20% hike per year
*/
void Retire(Employee *e) {

    int years_to_retire = 60 - e->age;
    int retirement_year = e->joiningDate->year + years_to_retire;

    float salary = e->salary;

    for (int i = 0; i < years_to_retire; i++) {
        salary = salary + (salary * 0.20f);    // 20% hike every year
    }

    printf("\nRetirement Details for %s (Empcode %d):\n", e->name, e->empcode);
    printf("Retirement Year : %d\n", retirement_year);
    printf("Salary at Retirement: %.2f\n", salary);
}

/* ------------ MAIN FUNCTION ------------- */
int main() {
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee emp[n];

    for (int i = 0; i < n; i++) {
        emp[i].joiningDate = (Date*)malloc(sizeof(Date));  // allocate Date structure

        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Empcode: ");
        scanf("%d", &emp[i].empcode);

        printf("Age at joining: ");
        scanf("%d", &emp[i].age);

        printf("Joining Date (day month year): ");
        scanf("%d %d %d",
              &emp[i].joiningDate->day,
              &emp[i].joiningDate->month,
              &emp[i].joiningDate->year);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    /* -------- Displaying Entered Details -------- */
    printf("\n\n---- Employee Details ----\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("Empcode: %d\n", emp[i].empcode);
        printf("Age at Joining: %d\n", emp[i].age);
        printf("Joining Date: %02d-%02d-%d\n",
               emp[i].joiningDate->day,
               emp[i].joiningDate->month,
               emp[i].joiningDate->year);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    /* -------- Test Retire() function -------- */
    printf("\n\n---- Retirement Calculations ----\n");
    for (int i = 0; i < n; i++) {
        Retire(&emp[i]);
    }

    /* Free dynamically allocated Date pointers */
    for (int i = 0; i < n; i++) {
        free(emp[i].joiningDate);
    }

    return 0;
}
