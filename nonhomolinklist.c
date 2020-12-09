#include <stdio.h>
#include <stdlib.h>

struct Node
{
    void *data;
    char type;
    struct Node *next;
};

struct Node *root = NULL;

void insert(void *data, char type)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->data = data;
    tempNode->type = type;
    tempNode->next=NULL;
    if (root == NULL)
    {
        root = tempNode;
        return;
    }
    struct Node *ptr;
    ptr = root;
    while (1)
    {
        if(ptr->next==NULL){
            ptr->next=tempNode;
            break;
        }
        ptr = ptr->next;
    }
    return;
}

void print()
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->type == 'c')
        {
            printf("%s", ptr->data);
        }
        else if (ptr->type == 'i')
        {
            printf("[ ");
            for (int i = 1; i <= *((int *)ptr->data); i++)
            {
                printf("%d, ", *((int *)ptr->data + i));
            }
            printf(" ]");
        }
        printf("\n");
        ptr=ptr->next;
    }
    
}

int main()
{
    int ch;
    int size;
    printf("1.insert an integer array\n2. insert a string\n3. Print the list\n");
    scanf("%d",&ch);
    while (1)
    {
        
        switch (ch)
        {
        case 1:
            printf("Please enter the size of array you wanna enter\n if you wanna enter just one number pls type 1 and then the number\n");
            scanf("%d",&size);
            printf("Please enter the numbers\n");
            int *a=(int*)malloc((size+1)*sizeof(int));
            a[0]=size;
            for (int i = 1; i < size+1; i++)
            {
                scanf("%d",&a[i]);
            }
            insert((void*)a,'i');
            break;
        case 2:
            printf("Please enter the length of string you wanna enter");
            scanf("%d",&size);
            printf("Please enter the string\n");
            char *s=(char*)malloc((size)*sizeof(char));
            scanf("%s",s);
            insert((void*)s,'c');
            break;
            break;
        case 3:
            print();
        default:
            break;
        }
        printf("1.insert an integer array\n2. insert a string\n3. Print the list\n");
        scanf("%d",&ch);
    }
}