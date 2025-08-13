#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float hourlyRate;
    float hoursWorked;
} Employee;

float calculatePayroll(Employee emp) {
    return emp.hourlyRate * emp.hoursWorked;
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int numEmployees, i;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    for (i = 0; i < numEmployees; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Hourly Rate: ");
        scanf("%f", &employees[i].hourlyRate);
        printf("Hours Worked: ");
        scanf("%f", &employees[i].hoursWorked);
    }

    printf("\nPayroll Information:\n");
    printf("ID\tName\t\tHourly Rate\tHours Worked\tTotal Pay\n");
    for (i = 0; i < numEmployees; i++) {
        float totalPay = calculatePayroll(employees[i]);
        printf("%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", 
               employees[i].id, employees[i].name, 
               employees[i].hourlyRate, employees[i].hoursWorked, totalPay);
    }

    return 0;
}
