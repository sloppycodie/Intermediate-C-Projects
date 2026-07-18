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
void printMenu(int *choice);//Done
void addExpense(struct Expense *exp);//Done
void viewExpense();//Done
void searchExpense();//Done
void editExpense();
void deleteExpense();
void statistics();
void saveFile();//Done
void loadFile();//Done


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
            viewExpense();
            break;
        case 3:
            searchExpense();
            break;
        // case 4:
        //     editExpense();
        //     break;
        // case 5:
        //     deleteExpense();
        //     break;
        // case 6:
        //     statistics();
        //     break;
        case 7:
            saveFile();
            break;
        case 8:
            loadFile();
            break;
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

void viewExpense(){
    if (count== 0)
    {
        printf("No Data Found!\n");
        return;
    }
    
    printf("\n========== All Expenses =========\n");
    printf("---------------------------------------------------------------\n");
    printf("%-4s %-15s %-12s %-20s %-7s\n", "No.","Date","Category","Description","Amount");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-4d %-15s %-12s %-20s %-7.2f\n", 
            i+1,
            expenses[i].date,
            expenses[i].category,
            expenses[i].description,
            expenses[i].amount);
    }
    
}

void searchExpense(){
    int srcChoice;
    int found = 0;
    char srcName[50];
    char srcDate[15];
    if (count == 0)
    {
        printf("No Data Found!\n");
        return;
    }
    
    while(getchar() != '\n');
    printf("\n========== Search Expense =========\n");
    printf("Choose Your Preferred Option:\n");
    printf("1. Category\n");
    printf("2. Date\n");
    printf("Choice: ");
    scanf("%d",&srcChoice);
    while(getchar()!='\n');
    switch (srcChoice)
    {
    case 1:
        printf("Enter Category: ");
        fgets(srcName,sizeof(srcName),stdin);
        srcName[strcspn(srcName,"\n")] = '\0';
        printf("---------------------------------------------------------------\n");
        printf("%-4s %-15s %-12s %-20s %-7s\n", "No.","Date","Category","Description","Amount");
        printf("---------------------------------------------------------------\n");
        for (int i = 0; i < count; i++)
        {
            if (strcmp(srcName, expenses[i].category)==0)
            {
                found = 1;
                printf("%-4d %-15s %-12s %-20s %7.2f\n", 
                    i+1,expenses[i].date,
                    expenses[i].category,
                    expenses[i].description,
                    expenses[i].amount);
            }
        }
        if (found==0)
        {
            printf("No Results Found!\n");
        }
        printf("---------------------------------------------------------------\n");
        break;
    case 2:
        printf("Enter Date: ");
        fgets(srcDate,sizeof(srcDate),stdin);
        srcDate[strcspn(srcDate,"\n")] = '\0';
        printf("---------------------------------------------------------------\n");
        printf("%-4s %-15s %-12s %-20s %-7s\n", "No.","Date","Category","Description","Amount");
        printf("---------------------------------------------------------------\n");
        for (int i = 0; i < count; i++)
        {
            if (strcmp(srcDate, expenses[i].date)==0)
            {
                found = 1;
                printf("%-4d %-15s %-12s %-20s %7.2f\n", 
                    i+1,
                    expenses[i].date,
                    expenses[i].category,
                    expenses[i].description,
                    expenses[i].amount);
            }
        }
        if (found==0)
        {
            printf("No Results Found!\n");
        }
        printf("---------------------------------------------------------------\n");
        break;
    default:
        printf("Invalid Input.\n");
        break;
    }
}

void saveFile(){
    FILE *fp;
    fp = fopen("expenses.txt","w");

    if (fp == NULL)
    {
        printf("Couldn't Open File!\n");
        return;
    }
    printf("Saving Expenses.....\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp,"%s,%s,%.2f,%s\n",
            expenses[i].date,
            expenses[i].category,
            expenses[i].amount,
            expenses[i].description);
    }
    fclose(fp);
    printf("Expenses Saved Successfully!\n");
}

void loadFile(){
    FILE *fp;
    fp = fopen("expenses.txt","r");
    if (fp ==NULL)
    {
        printf("Couldn't Open File!\n");
        return;
    }
    count=0;
    while (count<MAX && fscanf(fp,"%14[^,],%29[^,],%f,%99[^\n]\n",
                    expenses[count].date,
                    expenses[count].category,
                    &expenses[count].amount,
                    expenses[count].description)==4)
    {
        count++;
    }
    fclose(fp);
    printf("Files Loaded Successfully!\n");
}
