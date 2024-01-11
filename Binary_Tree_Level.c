#include <stdio.h>
#include <stdlib.h>  
typedef struct Node
{
    int salary;
    struct Node* left, * right;
}Node;
  
Node* newNode(int salary)
{
    struct Node* node = (Node*)malloc(sizeof(Node));
    node->salary = salary;
    node->left = node->right = NULL;
    return (node);
}
  
Node* insert(int arr[], Node* root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        Node* temp = newNode(arr[i]);
        root = temp;
  
        // insert left child
        root->left = insert(arr, root->left, 2 * i + 1, n);
  
        // insert right child
        root->right = insert(arr, root->right, 2 * i + 2, n);
    }
    return root;
}
  
// Function to print tree nodes in InOrder fashion
Node* inOrder(Node* temp)
{
    if (temp != NULL)
    {
        inOrder(temp->left);
        printf("%d\t", temp->salary );
        inOrder(temp->right);
    }
}
Node* preOrder(Node* temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->salary);
        preOrder(temp->left);
        preOrder(temp->right);
    }
    return NULL;
}
Node* postOrder(Node* temp)
{
    if(temp!=NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d ",temp->salary);

    }
    return NULL;
}
int main()
{
    int arr[100];
    int i,s,c;
    Node* n;
    int count=0;
    Node* root;
    while(1)
    {
        printf("\nPress 1 for creating nodes in level order\nPress 2 for inorder traversal\nPress 3 for preorder traversal\nPress 4 for postorder traversal\nPress 5 for exit\nEnter your choice ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                if(count==0)
                {
                    printf("\nEnter the number of employees whose salary you want to insert "); 
                    scanf("%d",&s);
                    for(i=0;i<s;i++)
                    {
                        printf("\nEnter the salary of the %dth employee: ",i+1);
                        scanf("%d",&arr[i]);
                    }
                    root = insert(arr, root, 0, s);
                    count++;
                }
                else
                {
                    printf("\nTree already created, to create a new tree exit the program and run again");
                }
                break;
            case 2:
                if(root==NULL)
                    printf("\nThe tree is not yet created\n");
                else
                    n=inOrder(root);
            break;
            case 3:
                if(root==NULL)
                    printf("\nThe tree is not yet created\n");
                else
                {
                    n=preOrder(root);
                }
            break;
            case 4:
                if(root==NULL)
                    printf("\nThe tree is not yet created\n");
                else 
                    n=postOrder(root);
            break;
            case 5:
                exit(1);
            break;
            default:
                printf("\nWrong choice");
        }
    }
}
  
