#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    int roll;
    char name[50];
    char class[10];
    float mark;
};

void main() {
    int ch = 0, i = 0;
    struct student s[50];

    do {
        printf("\n---Main Menu---\n1.Add New Student Details\n2.Display Student Details\n3.Exit\n\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("\nEnter student details:\n");
                printf("\nRoll No\t: ");
                scanf("%d", &s[i].roll);
                getchar();
                printf("Name\t: ");
                fgets(s[i].name, sizeof(s[i].name), stdin);
                s[i].name[strcspn(s[i].name, "\n")] = '\0';
                printf("Class\t: ");
                fgets(s[i].class, sizeof(s[i].class), stdin);
                s[i].class[strcspn(s[i].class, "\n")] = '\0';
                printf("Mark\t: ");
                scanf("%f", &s[i].mark);
                i++;
                break;
            case 2:
                if(i == 0)
                    printf("No student record found!!!\n");
                else {
                    for(int j = 0; j < i; j++) {
                        printf("\n---STUDENT %d DETAILS---\nRoll No\t: %d\nName\t: %s\nClass\t: %s\nMark\t: %.2f\n", j+1, s[j].roll, s[j].name, s[j].class, s[j].mark);
                    }
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice !!\n");
        }
        
    } while(ch < 4 && ch > 0);
}
