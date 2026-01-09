#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define NUM_GRADES 3



typedef struct {

    int studentID;
    char name[50];
    int grades[NUM_GRADES];
    char address[100];
    char phone[20];
    
} Student;


void addRecord();
void updateRecord();
void deleteRecord();
void displayAll();
// void searchByID();
void saveToFile();
// void loadFromFile();
int findIndex(int id);

#endif