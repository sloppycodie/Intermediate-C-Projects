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