#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int salary;
    struct Node* left;
    struct Node* right;
}Node;

Node* create()
{
    int k;
    printf("\nEnter the salary ");
    scanf("%d", &k);
    if(k==-1)
        return NULL;
    Node* x=(Node*)malloc(sizeof(Node));
    x->salary=k;
    x->left=create();
    x->right=create();
    return x;
}

Node* inOrder(Node* temp)
{
    if(temp!=NULL)
    {
        inOrder(temp->left);
        printf("%d ",temp->salary);
        inOrder(temp->right);
    }
    return NULL;
}
Node* preOrder(Node *t)		
{
	if(t!=NULL)
	{
		printf("\n%d",t->salary);	
		preOrder(t->left);	
		preOrder(t->right);	
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
    Node* root;
    Node* n;
    int c;
    while(1)
    {
        printf("\nPress 1 for creating a node in depth order\nPress 2 for inorder traversal\nPress 3 for preorder traversal\nPress 4 for postorder traversal\nPress 5 for exit\nEnter your choice ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                root=create();
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
    return 0;
}
