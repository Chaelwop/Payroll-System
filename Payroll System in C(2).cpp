#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int empID;
    char name[50];
    float hoursWorked;
    float ratePerHour;
    float grossPay;
    float tax;
    float insurance;
    float netPay;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void calculatePayroll(Employee *emp) {
    emp->grossPay = emp->hoursWorked * emp->ratePerHour;
    emp->tax = emp->grossPay * 0.10;
    emp->insurance = 200.0;
    emp->netPay = emp->grossPay - (emp->tax + emp->insurance);
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nMaximum employee limit reached!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.empID);
    getchar();
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;
    printf("Enter Hours Worked: ");
    scanf("%f", &emp.hoursWorked);
    printf("Enter Rate per Hour: ");
    scanf("%f", &emp.ratePerHour);

    calculatePayroll(&emp);

    employees[employeeCount++] = emp;
    printf("\nEmployee added successfully!\n");
}

void displayPayroll() {
    if (employeeCount == 0) {
        printf("\nNo employee records available!\n");
        return;
    }

    printf("\n===== PAYROLL DETAILS =====\n");
    for (int i = 0; i < employeeCount; i++) {
        Employee e = employees[i];
        printf("\n------------------------------\n");
        printf("        PAYSLIP\n");
        printf("------------------------------\n");
        printf("Employee ID   : %d\n", e.empID);
        printf("Name          : %s\n", e.name);
        printf("Hours Worked  : %.2f\n", e.hoursWorked);
        printf("Rate/Hour     : %.2f\n", e.ratePerHour);
        printf("Gross Pay     : %.2f\n", e.grossPay);
        printf("Tax (10%%)     : %.2f\n", e.tax);
        printf("Insurance     : %.2f\n", e.insurance);
        printf("Net Pay       : %.2f\n", e.netPay);
        printf("------------------------------\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n===== PAYROLL SYSTEM MENU =====\n");
        printf("1. Add Employee\n");
        printf("2. View Payroll Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayPayroll();
                break;
            case 3:
                printf("\nExiting Payroll System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

