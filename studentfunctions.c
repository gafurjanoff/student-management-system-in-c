#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 


#include "studentsheaders.h"


Student database[MAX_STUDENTS];


int count = 0;


int findIndex(int id){

    for(int i = 0; i < count; i ++){

        if(database[i].studentID == id){return i;
        }
    }
    return -1;
}




void addRecord(){

    if(count >= MAX_STUDENTS){
        printf("\n[Error] Database full!\n");
        return;
    }

    Student s;

    printf("Enter Student ID: "); scanf("%d", &s.studentID);
    getchar();

    printf("Enter Student Name: "); 
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;


    for(int i=0;  i < NUM_GRADES; i++){
        printf("Enter Grade %d: ", i + 1);
        scanf("%d", &s.grades[i]);
    }
    getchar();

    printf("Enter Student Address: ");
    fgets(s.address, 100, stdin);
    s.address[strcspn(s.address, "\n")] = 0;


    printf("Enter Phone Number: ");
    fgets(s.phone, 20, stdin);
    s.phone[strcspn(s.phone, "\n")] = 0;

    database[count++] = s;
    printf("Student Record Added Successfully!✅");

}


int isYes(char *input) {

    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
    return (strcmp(input, "y") == 0 || strcmp(input, "yes") == 0);
}


void updateRecord() {
    int id, idx;
    char choice[10];

    printf("\nEnter ID to update: "); 
    scanf("%d", &id);
    getchar(); 

    idx = findIndex(id);

    if (idx == -1) {
        printf("Student ID not found.\n");
        return;
    }

    printf("\nUpdating record for: %s\n", database[idx].name);


    printf("Update Name? (y/n): ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0;
    if (isYes(choice)) {
        printf("Enter New Name: ");
        fgets(database[idx].name, 50, stdin);
        database[idx].name[strcspn(database[idx].name, "\n")] = 0;
    }


    printf("Update Grades? (y/n): ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0;
    if (isYes(choice)) {
        for (int i = 0; i < NUM_GRADES; i++) {
            printf("Enter Grade %d: ", i + 1);
            scanf("%d", &database[idx].grades[i]);
        }
        getchar(); // clear newline left by last scanf
    }

   
    printf("Update Address? (y/n): ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0;
    if (isYes(choice)) {
        printf("Enter New Address: ");
        fgets(database[idx].address, 100, stdin);
        database[idx].address[strcspn(database[idx].address, "\n")] = 0;
    }

   
    printf("Update Phone? (y/n): ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0;
    if (isYes(choice)) {
        printf("Enter New Phone Number: ");
        fgets(database[idx].phone, 20, stdin);
        database[idx].phone[strcspn(database[idx].phone, "\n")] = 0;
    }

    printf("\nRecord updated successfully! ✅\n");
}




void deleteRecord(){
    int idx, id;

    printf("\nEnter ID to delete: "); scanf("%d", &id);
    idx = findIndex(id);

    if(idx!=-1){
        for(int i=idx; i<count-1; i ++){
            database[i] = database[i + 1];
        }
        count --;
        printf("Record deleted successfully.\n");
    }

    else {
        printf("Student ID not found.\n");
    }
}





void searchByID() {
    int id, idx;
    printf("\nEnter ID to search: "); scanf("%d", &id);
    idx = findIndex(id);

    if (idx != -1) {
        printf("\n--- Record Found ---\n");
        printf("ID: %d\nName: %s\nGrades: %d, %d, %d\nAddress: %s\nPhone: %s\n",
               database[idx].studentID, database[idx].name,
               database[idx].grades[0], database[idx].grades[1], database[idx].grades[2],
               database[idx].address, database[idx].phone);
    } else {
        printf("Student ID not found.\n");
    }
}

void displayAll() {
    if (count == 0) {
        printf("\nNo records to display.\n");
        return;
    }
    printf("\n%-10s %-20s %-30s %-10s %-10s %-10s\n", "ID", "Name", "Address", "G1", "G2", "G3");
    printf("-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s  %-30s %-10d %-10d %-10d\n", 
               database[i].studentID, database[i].name, database[i].address,
               database[i].grades[0], database[i].grades[1], database[i].grades[2]);
    }
}


void saveToFile(){

    FILE *fp = fopen("students.txt", "w");

    if(!fp) return;

    for(int i=0; i<count; i ++){
        fprintf(fp, "%d|%s|%d|%d|%d|%s|%s\n",                 
                database[i].studentID, database[i].name, 
                database[i].grades[0], database[i].grades[1], database[i].grades[2],
                database[i].address, database[i].phone);
    }

    fclose(fp);
    printf("Records saved to 'students.txt'.\n");


}


void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if (!fp) return;

    count = 0;
    while (count < MAX_STUDENTS && 
           fscanf(fp, "%d|%[^|]|%d|%d|%d|%[^|]|%[^\n]\n", 
           &database[count].studentID, database[count].name, 
           &database[count].grades[0], &database[count].grades[1], 
           &database[count].grades[2], database[count].address, 
           database[count].phone) == 7) {
        count++;
    }
    fclose(fp);
}