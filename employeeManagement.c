#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    char name[20];
    int id;
    int salary;
    char departmentName[20];
    struct Employee *next;
};

struct Employee *readEmployee(struct Employee *employeeTop)
{
    char response[1];
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    printf("Enter the first name\n");
    scanf("%s", newEmployee->name);
    printf("Enter the id\n");
    scanf("%d", &(newEmployee->id));
    printf("Enter the department name in one word\n");
    scanf("%s", newEmployee->departmentName);
    printf("Enter the salary of person\n");
    scanf("%d", &(newEmployee->salary));
    newEmployee->next = employeeTop;
    employeeTop = newEmployee;
    printf("do you wanna add more(y/n)");
    scanf("%s", response);
    if (response[0] == 'n')
        return employeeTop;
    else
        return readEmployee(employeeTop);
}

void showEmployee(struct Employee *employeeTop)
{
    struct Employee *ptr = (struct Employee *)malloc(sizeof(struct Employee));
    ptr = employeeTop;
    while (ptr != NULL)
    {
        printf("name: %s\nid: %d\nDepartment: %s\nSalary: %d\n", ptr->name, ptr->id, ptr->departmentName, ptr->salary);
        printf("--------------------------------------------------\n");
        ptr = ptr->next;
    }
    free(ptr);
}

int totalEmployee(struct Employee *employeeTop)
{
    struct Employee *ptr = (struct Employee *)malloc(sizeof(struct Employee));
    ptr = employeeTop;
    int n = 0;
    while (ptr->next != NULL)
    {
        n++;
        ptr = ptr->next;
    }
    free(ptr);
    return n + 1;
}
void calculateTotalSalary(struct Employee *employeeTop)
{
    int n = totalEmployee(employeeTop);
    struct Employee *ptr = (struct Employee *)malloc(sizeof(struct Employee));
    ptr = employeeTop;
    char *type[10];
    for (int i = 0; i < 10; i++)
    {
        type[i] = (char *)malloc(20 * sizeof(char));
    }
    int counter = 0;
    type[counter] = employeeTop->departmentName;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(type[counter], ptr->departmentName) != 0)
        {
            counter += 1;
            type[counter] = ptr->departmentName;
        }
        ptr = ptr->next;
    }
    ptr = employeeTop;
    int tempSalary = 0;
    for (int i = 0; i < counter + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(type[i], ptr->departmentName) == 0)
            {
                tempSalary += ptr->salary;
            }
            ptr = ptr->next;
        }
        printf("Total salary in %s department:%d\n ", type[i], tempSalary);
        tempSalary = 0;
        ptr = employeeTop;
    }
}

int main()
{
    printf("Welcome to our employee management system please enter the deatils of employeees!!!\n");
    struct Employee *employeeTop = NULL;
    employeeTop = readEmployee(employeeTop);
    showEmployee(employeeTop);
    calculateTotalSalary(employeeTop);
}