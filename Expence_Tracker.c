#include <stdio.h>
#include <string.h>

#define MAX 100

//Structures
struct Expense
{
    char date[15];
    char category[30];
    float amount;
    char description[100];
};

struct Expense expenses[MAX];

//Functions
void printMenu(int *choice);
void addExpense(struct Expense *exp);
void viewExpense(struct Expense exp);
void searchExpense();
void editExpense();
void deleteExpense();
void statistics();
void saveFile();
void loadFile();


//Global Variables
int count = 0;

int main() {
    int choice = 0;

    while (choice != 9)
    {
        printMenu(&choice);

        switch (choice)
        {
        case 1:
            if (count==MAX)
            {
                printf("The Database is Full!");
                break;
            }
            addExpense(&expenses[count]);
            count++;
            break;
        case 2:
            viewExpense(expenses[count]);
            break;
        // case 3:
        //     searchExpense();
        //     break;
        // case 4:
        //     editExpense();
        //     break;
        // case 5:
        //     deleteExpense();
        //     break;
        // case 6:
        //     statistics();
        //     break;
        // case 7:
        //     saveFile();
        //     break;
        // case 8:
        //     loadFile();
        //     break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
    

    return 0;
}

void printMenu(int *choice){
    printf("\n========== Expense Tracker =========\n");
    printf("\n1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Search\n");
    printf("4. Edit\n");
    printf("5. Delete\n");
    printf("6. Statistics\n");
    printf("7. Save\n");
    printf("8. Load\n");
    printf("9. Exit\n");
    printf("\nChoice: ");
    scanf("%d",choice);
}

void addExpense(struct Expense *exp){
    while(getchar()!='\n');
    printf("\n========== Add Expense =========\n");
    printf("\nDate (DD/MM/YYYY): ");
    fgets(exp->date,sizeof(exp->date),stdin);
    exp->date[strcspn(exp->date,"\n")] = '\0';
    printf("\nCategory: ");
    fgets(exp->category,sizeof(exp->category),stdin);
    exp->category[strcspn(exp->category,"\n")] = '\0';
    do
    {
        printf("\nAmount: ");
        scanf("%f", &exp->amount);
        while(getchar()!='\n');
        if (exp->amount <0)
        {
            printf("Amount Can not Be Negative!");
        }
        
    } while (exp->amount<0);
    printf("\nDescription: ");
    fgets(exp->description,sizeof(exp->description),stdin);
    exp->description[strcspn(exp->description,"\n")] = '\0';
    printf("\nExpense Added Successfully!\n");
}

void viewExpense(struct Expense exp){

}