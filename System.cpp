#include <stdio.h>

int main() {
    int numEmployees, i, id;
    char name[50];
    float rate, hours, total;

    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);

    printf("\nID\tName\t\tRate\tHours\tTotal\n");
    for (i = 0; i < numEmployees; i++) {
        printf("\nEnter ID: ");
        scanf("%d", &id);
        printf("Enter Name: ");
        scanf("%s", name);
        printf("Enter Hourly Rate: ");
        scanf("%f", &rate);
        printf("Enter Hours Worked: ");
        scanf("%f", &hours);

        total = rate * hours;
        printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\n", id, name, rate, hours, total);
    }

    return 0;
}

