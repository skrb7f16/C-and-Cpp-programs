#include <stdio.h>
#include <stdlib.h>
struct BTnode
{
    int data;
    struct BTnode *left;
    struct BTnode *right;
};

struct BTnode *get_new_node(int x)
{
    struct BTnode *newNode = (struct BTnode *)malloc(sizeof(struct BTnode));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct BTnode *insert_node(struct BTnode *root, int x)
{
    struct BTnode *newNode = get_new_node(x);
    struct BTnode *temp;
    temp = root;
    if (root == NULL)
    {
        printf("\n Inserted data at node \n");
        return newNode;
    }
    else if (newNode->data <= temp->data)
    {
        printf("\n Went to left \n");
        temp->left = insert_node(temp->left, x);
    }
    else
    {
        printf("\n Went to right \n");
        temp->right = insert_node(temp->right, x);
    }
}
void search(struct BTnode *root, int x)
{
    if (root == NULL)
        printf("\ncant find or tree is empty :c\n");
    else if (root->data == x)
    {
        printf("FOund %d \n", root->data);
    }
    else if (x <= root->data)
    {
        printf("Went left of the node<<<\n");
        search(root->left, x);
    }
    else
    {
        printf("Went right of the node>>>\n");
        search(root->right, x);
    }
}
int main()
{
    struct BTnode *root = NULL;
    int n, option;
    printf("1. Insert\n2. Search\n3. Exit\n");
    scanf("%d", &option);
    while (1)
    {
        if (option == 1)
        {
            printf("Enter the number you wanna insert\n");
            scanf("%d", &n);
            root = insert_node(root, n);

            printf("1. Insert\n2. Search\n3. Exit\n");
            scanf("%d", &option);
        }
        else if (option == 2)
        {
            printf("Enter the number you wanna search\n");
            scanf("%d", &n);
            search(root, n);
            printf("1. Insert\n2. Search\n3. Exit\n");
            scanf("%d", &option);
        }
        else
        {
            printf("Thanks for visiting our tree :D <3\n");
            break;
        }
    }
}
