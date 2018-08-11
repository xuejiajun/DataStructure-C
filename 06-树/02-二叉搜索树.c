#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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

void PostOrder(TreeNode* root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
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



void InsertTree(Tree* tree,int data)
{
    //封装data为一个树的节点
    TreeNode* pNode = (TreeNode*)malloc(sizeof(TreeNode));
    pNode->data = data;
    pNode->left = NULL;
    pNode->right = NULL;
    //如果根节点为空，则将当前节点作为根节点
    if(tree->root == NULL)
    {
        tree->root = pNode;
    }
    //如果根节点不空，如果当前值小于根节点的值，向左插入；
    else
    {
        TreeNode* pCurrent = tree->root;
        while(pCurrent != NULL)
        {   
            //插入到左侧
            if(pCurrent->data > data)
            {
                if(pCurrent->left == NULL)
                {
                    pCurrent->left = pNode;
                    return ;
                }
                else
                {
                    pCurrent = pCurrent->left;
                }
            }
            else
            {
                if(pCurrent->right == NULL)
                {
                    pCurrent->right = pNode;
                    return;
                }
                else
                {
                    pCurrent = pCurrent->right;
                }
            }
        }
    }
}

int main(void)
{
    printf("这是一个二叉搜索树的例程\n");

    char arr[] = {1,2,6,3,5,8,9,1,1,2};
    Tree t;
    t.root = NULL;
    
    for(int i=0;i<strlen(arr);i++)
    {
        InsertTree(&t,arr[i]);
    }

    printf("先序遍历\n");
    PreOrder(t.root);
    printf("中序遍历\n");
    InOrder(t.root);
    printf("后续遍历\n");
    PostOrder(t.root);

    int h = HeightTree(t.root);
    printf("Tree Height = %d\n",h);
    int maxitem = MaxItemTree(t.root);
    printf("Tree Max Item = %d\n",maxitem);
    return 0;
}
