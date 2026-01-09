#include <stdio.h>
#include "students.h"



int main(){

    int choice;

    
    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Record");
        printf("\n2. Update Record");
        printf("\n3. Delete Record");
        printf("\n4. Display All Records");
        printf("\n5. Search Record by ID");
        printf("\n6. Save to File");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            // case 2: updateRecord(); break;
            case 3: deleteRecord(); break;
            case 4: displayAll(); break;
            // case 5: searchByID(); break;
            case 6: saveToFile(); break;
            case 7: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}