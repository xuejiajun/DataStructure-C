#include<stdio.h>
#include<stdlib.h>

typedef struct TREENODE
{
    int data;
    struct TREENODE* left;
    struct TREENODE* right;
}TreeNode;

typedef struct TREE
{
    TreeNode* root;
}Tree;

Tree* CreatTree(void)
{
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
   
    n1->data = 10;
    n1->left = n2;
    n1->right = n3;

    n2->data = 20;
    n2->left = n4;
    n2->right = NULL;


    n3->data = 30;
    n3->left = NULL;
    n3->right = NULL;
    

    n4->data = 40;
    n4->left = NULL;
    n4->right = NULL;
    
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root = n1;
    return t;
}

void PreOrder(TreeNode* root)
{
    if(root != NULL)
    {
        printf("%d  \n",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(TreeNode* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d\n",root->data);
        InOrder(root->right);
    }
}

void PassOrder(TreeNode* root)
{
    if(root != NULL)
    {
        PassOrder(root->left);
        PassOrder(root->right);
        printf("%d\n",root->data);
    }
}

int HeightTree(TreeNode* root)
{
    if(root != NULL)
    {
        int leftheight = HeightTree(root->left);
        int rightheight = HeightTree(root->right);
        int max = leftheight > rightheight ? leftheight : rightheight;
        return max + 1;
    }
}

int MaxItemTree(TreeNode* root)
{
    if(root != NULL)
    {
        int leftmax = MaxItemTree(root->left);
        int rightmax = MaxItemTree(root->right);
        int max = leftmax > rightmax ? leftmax : rightmax;
        return max > root->data ? max : root->data;   
    }
}


int main(void)
{
    printf("这是一个树的三种遍历方式的例程\n");

    int s1 = 10;
    Tree* t  = CreatTree();
    printf("先序遍历\n");
    PreOrder(t->root);
    printf("中序遍历\n");
    InOrder(t->root);
    printf("后续遍历\n");
    PassOrder(t->root);

    int h = HeightTree(t->root);
    printf("height = %d\n",h);

    int max = MaxItemTree(t->root);
    printf("maxitem = %d\n",max);
    return 0;
}
