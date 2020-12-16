#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char name[20];
    int priority;
    struct Node *next;
};

struct Node *front;

void insert()
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    printf("Please enter you name and tell us you are \n 1. Normal checkup\n2. Some normal wounds\n3. Emergency room\n4. Pregnancy\n");
    scanf("%s", newNode->name);
    scanf("%d", &newNode->priority);
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        return;
    }

    temp = front;

    if(front->priority<newNode->priority){
        newNode->next=front;
        front=newNode;
        return;
    }
    while (1)
    {
        if(temp->next!=NULL){
            if(temp->next->priority>=newNode->priority){
                temp=temp->next;
                break;
            }
            else{
                temp=temp->next;
            }
        }
        else{
            break;
        }
    }

    if(temp->next==NULL){
        temp->next=newNode;
        return;
    }

    else{
        newNode=temp->next;
        temp->next=newNode;
    }




    

    

        
}

void show(){
    
    struct Node * temp;
    temp=front;
    while (1)
    {
        if(temp==NULL){
            break;
        }
        else{
            printf("\n%s\n",temp->name);
            printf("%d\n\n",temp->priority);
            temp=temp->next;
        }
    }
    
    
}



int main()
{
    front=NULL;
    int option;
    while (1)
    {
        printf("Select options to do\n1. insert\n2. show\n3. exit\n");
        scanf("%d",&option);
        if(option==1){
            insert();
        }
        else if(option==2){
            show();
        }
        else{
            break;
        }
    }
    
}