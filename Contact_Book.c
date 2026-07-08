#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact
{
    char name[50];
    char phoneNumber[20];
    char email[50];
};

struct Contact contacts[MAX];

//Functions
void menu(int *input);
void searchContact();
void addContact(struct Contact *c);
void displayContact();
void editContact();
void deleteContact();

//Universal variables
int count = 0;

int main() {
    int input;

    while (1)
    {
        menu(&input);
        if (input == 6)
        {
            break;
        }

        switch (input)
        {
        case 1:
            if (count>=MAX)
            {
                printf("The Contactbook Is Full!");
                break;
            }
            addContact(&contacts[count]);
            count++;
            break;
        case 2:
            displayContact();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            editContact();
            break;
        case 5:
            deleteContact();
            break;
        default:
            printf("\nThe input is not valid!");
            break;
        }
    }
    return 0;
}

void menu(int *input){
    printf("\n===== CONTACT BOOK =====\n");
    printf("\n1.Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Edit Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("\nChoose: ");
    scanf("%d",input);//input is already a pointer
}

void addContact(struct Contact *c){
    while(getchar() != '\n');   // Clear leftover newline from scanf()
    printf("Please Enter the Following Information:\n");
    printf("\nName: ");
    fgets(c->name,sizeof(c->name),stdin);
    c->name[strcspn(c->name,"\n")] = '\0';
    printf("\nPhone Number: ");
    fgets(c->phoneNumber,sizeof(c->phoneNumber),stdin);
    c->phoneNumber[strcspn(c->phoneNumber,"\n")] = '\0';
    printf("\nE-mail: ");
    fgets(c->email,sizeof(c->email),stdin);
    c->email[strcspn(c->email,"\n")] = '\0';
    printf("\nContact added successfully!\n");
}

void displayContact(){
    if (count == 0)
    {
        printf("No Contacts Found.");
        return;
    }
    printf("\n===== CONTACT LIST =====\n");
    for (int i = 0; i < count; i++)
    {
        printf("\nContact %d\n",i+1);
        printf("\nName        : %s",contacts[i].name);
        printf("\nPhone Number: %s",contacts[i].phoneNumber);
        printf("\nE-mail      : %s",contacts[i].email);
    }
}

void searchContact(){
    char srcName[50];
    char srcNum[20];
    int found = 0;
    int option;
    printf("Please Choose your Preferred Option:\n");
    printf("1. Name\n2. Phone Number\n");
    printf("Choice: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        while(getchar()!='\n');
        printf("Enter The Name: ");
        fgets(srcName,sizeof(srcName),stdin);
        srcName[strcspn(srcName,"\n")] = '\0';
        for (int i = 0; i < count; i++)
        {
            if(strcmp(srcName,contacts[i].name)==0)
            {
                found = 1;
                printf("\nContact %d\n",i+1);
                printf("Name        : %s\n",contacts[i].name);
                printf("Phone Number: %s\n",contacts[i].phoneNumber);
                printf("E-mail      : %s\n",contacts[i].email);
                break;
            }
        }
        if (found ==0)
        {   
            printf("\nContact Not Found!");
        }
        break;
    
    case 2:
        while(getchar()!='\n');
        printf("Enter The Phone Number: ");
        fgets(srcNum,sizeof(srcNum),stdin);
        srcNum[strcspn(srcNum,"\n")] = '\0';
        for (int i = 0; i < count; i++)
        {
            if(strcmp(srcNum,contacts[i].phoneNumber)==0)
            {
                found = 1;
                printf("\nContact %d\n",i+1);
                printf("Name        : %s\n",contacts[i].name);
                printf("Phone Number: %s\n",contacts[i].phoneNumber);
                printf("E-mail      : %s\n",contacts[i].email);
            }
        }
        if (found ==0)
        {   
            printf("\nContact Not Found!");
        }
        break;
    default:
        printf("\nInvalid Choice!");
        break;
    }
}

void editContact(){
    char srcName[50];
    char srcNum[20];
    int found = 0;
    int option;
    printf("Please Choose your Preferred Option:\n");
    printf("1. Name\n2. Phone Number\n");
    printf("Choice: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        while(getchar()!='\n');
        printf("Enter The Name: ");
        fgets(srcName,sizeof(srcName),stdin);
        srcName[strcspn(srcName,"\n")] = '\0';
        for (int i = 0; i < count; i++)
        {
            if(strcmp(srcName,contacts[i].name)==0)
            {
                found = 1;
                printf("Enter The New Information:\n");
                printf("\nName: ");
                fgets(contacts[i].name,sizeof(contacts[i].name),stdin);
                contacts[i].name[strcspn(contacts[i].name,"\n")] = '\0';
                printf("\nPhone Number: ");
                fgets(contacts[i].phoneNumber,sizeof(contacts[i].phoneNumber),stdin);
                contacts[i].phoneNumber[strcspn(contacts[i].phoneNumber,"\n")] = '\0';
                printf("\nE-mail: ");
                fgets(contacts[i].email,sizeof(contacts[i].email),stdin);
                contacts[i].email[strcspn(contacts[i].email,"\n")] = '\0';
                printf("\nContact Updated Successfully!\n");
                break;
            }
        }
        if (found ==0)
        {   
            printf("\nContact Not Found!");
        }
        break;
    
    case 2:
        while(getchar()!='\n');
        printf("Enter The Phone Number: ");
        fgets(srcNum,sizeof(srcNum),stdin);
        srcNum[strcspn(srcNum,"\n")] = '\0';
        for (int i = 0; i < count; i++)
        {
            if(strcmp(srcNum,contacts[i].phoneNumber)==0)
            {
                found = 1;
                printf("Enter The New Information:\n");
                printf("\nName: ");
                fgets(contacts[i].name,sizeof(contacts[i].name),stdin);
                contacts[i].name[strcspn(contacts[i].name,"\n")] = '\0';
                printf("\nPhone Number: ");
                fgets(contacts[i].phoneNumber,sizeof(contacts[i].phoneNumber),stdin);
                contacts[i].phoneNumber[strcspn(contacts[i].phoneNumber,"\n")] = '\0';
                printf("\nE-mail: ");
                fgets(contacts[i].email,sizeof(contacts[i].email),stdin);
                contacts[i].email[strcspn(contacts[i].email,"\n")] = '\0';
                printf("\nContact Updated Successfully!\n");
                break;
            }
        }
        if (found ==0)
        {   
            printf("\nContact Not Found!");
        }
        break;
    default:
        printf("\nInvalid Choice!");
        break;
    }
}
