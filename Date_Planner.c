#include <stdio.h>
#include <string.h>

struct userInfo{
    char name[50],pName[50];
    double budget;
    int prefTime,dateType,transportation;
};

struct userInfo myUser;

void welcomeScreen();
void userData(struct userInfo *users);

int main() {
    welcomeScreen();
    userData(&myUser);
    
    return 0;
}

void welcomeScreen(){
    printf("\n****************************************\n");
    printf("\t ROMANTIC DATE PLANNER\n");
    printf("\n****************************************\n");
    printf("Plan Your Perfect Date!");
}

void userData(struct userInfo *users){
    printf("\nEnter Your name: ");
    fgets(users->name,sizeof(users->name),stdin);
    users->name[strcspn(users->name,"\n")] = '\0';
    printf("\nEnter Partner's Name: ");
    fgets(users->pName,sizeof(users->pName),stdin);
    users->pName[strcspn(users->pName,"\n")] = '\0';
    printf("\nBudget: ");
    scanf("%lf",&users->budget);
    printf("\nPreferred Time: \n1. Morning\n2. Afternoon\n3. Evening\n\nChoice: ");
    scanf("%d",&users->prefTime);
    printf("\nPreferred Date Type: \n1. Romantic\n2. Adventure\n3. Food\n4. Outdoor\n5. Movie\nChoice: ");
    scanf("%d",&users->dateType);
    printf("\nPreferred Transportation: \n1. Walk\n2. Bike\n3. Car\n\nChoice: ");
    scanf("%d",&users->transportation);
}