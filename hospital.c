#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient {
    char name[100];
    char gender[10];
    char disease[100];
    char address[100];
    char type[50];
    char phone[15];
    int age, room, d1, m1, y1;
} patients[100];

int patient_count = 0;

void add();
void viewall();
void search();
void del();
void read();
void write();

int main() {
    int choice;
    read();

    while (1) {
        printf("\n\nWelcome to Sanjana Hospital Management System\n\n");
        printf("\t1. Add Information\n");
        printf("\t2. View Information\n");
        printf("\t3. Search for Patient\n");
        printf("\t4. Delete Information\n");
        printf("\t5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                viewall();
                break;
            case 3:
                search();
                break;
            case 4:
                del();
                break;
            case 5:
                printf("Exiting program...\n");
                write();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add() {
    printf("Enter Patient Name: ");
    fgets(patients[patient_count].name, 100, stdin);
    patients[patient_count].name[strcspn(patients[patient_count].name, "\n")] = 0;

    printf("Enter Gender: ");
    fgets(patients[patient_count].gender, 10, stdin);
    patients[patient_count].gender[strcspn(patients[patient_count].gender, "\n")] = 0;

    printf("Enter Disease: ");
    fgets(patients[patient_count].disease, 100, stdin);
    patients[patient_count].disease[strcspn(patients[patient_count].disease, "\n")] = 0;

    printf("Enter Address: ");
    fgets(patients[patient_count].address, 100, stdin);
    patients[patient_count].address[strcspn(patients[patient_count].address, "\n")] = 0;

    printf("Enter Room Number: ");
    scanf("%d", &patients[patient_count].room);

    printf("Enter Age: ");
    scanf("%d", &patients[patient_count].age);
    getchar();

    printf("Enter Phone Number: ");
    fgets(patients[patient_count].phone, 15, stdin);
    patients[patient_count].phone[strcspn(patients[patient_count].phone, "\n")] = 0;

    patient_count++;
    printf("Patient added successfully!\n");
}

void viewall() {
    printf("\nList of Patients:\n");
    for (int i = 0; i < patient_count; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("Name: %s\n", patients[i].name);
        printf("Gender: %s\n", patients[i].gender);
        printf("Disease: %s\n", patients[i].disease);
        printf("Address: %s\n", patients[i].address);
        printf("Room Number: %d\n", patients[i].room);
        printf("Age: %d\n", patients[i].age);
        printf("Phone: %s\n", patients[i].phone);
    }
}

void search() {
    char name[100];
    printf("Enter patient name to search: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            printf("\nPatient Found:\n");
            printf("Name: %s\nGender: %s\nDisease: %s\nAddress: %s\nRoom: %d\nAge: %d\nPhone: %s\n",
                   patients[i].name, patients[i].gender, patients[i].disease, patients[i].address, patients[i].room, patients[i].age, patients[i].phone);
            return;
        }
    }
    printf("Patient not found!\n");
}

void del() {
    char name[100];
    printf("Enter patient name to delete: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patient_count--;
            printf("Patient record deleted successfully!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

void write() {
    FILE *fp = fopen("patients.dat", "wb");
    if (!fp) {
        printf("Error saving data!\n");
        return;
    }
    fwrite(&patient_count, sizeof(int), 1, fp);
    fwrite(patients, sizeof(struct Patient), patient_count, fp);
    fclose(fp);
}

void read() {
    FILE *fp = fopen("patients.dat", "rb");
    if (!fp) return;
    fread(&patient_count, sizeof(int), 1, fp);
    fread(patients, sizeof(struct Patient), patient_count, fp);
    fclose(fp);
}
