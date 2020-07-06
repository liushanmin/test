#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef	char ElemType;			//数据类型
typedef	int	Status;			//返回值类型

//定义二叉树结构
typedef struct BiTNode{
	ElemType	data;			//数据域
	struct BiTNode	*lChild, *rChild;	//左右子树域
}BiTNode, *BiTree;

//先序创建二叉树
Status CreateBiTree(BiTree *T)
{
	ElemType ch;

	scanf("%c%*c", &ch);

	if ('#' == ch)
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T))//没有分配到内存 
			exit(-1);

		(*T)->data = ch;
		printf("输入%c的左子节点：", ch);
		CreateBiTree(&(*T)->lChild);
		printf("输入%c的右子节点：", ch);
		CreateBiTree(&(*T)->rChild);
	}

	return 1;
}

//先序遍历二叉树
void PreOrderBiTree(BiTree T)
{
	if (NULL == T)
		return ;
	printf("%c ", T->data);
	PreOrderBiTree(T->lChild);
	PreOrderBiTree(T->rChild);

}

//中序遍历二叉树
void InOrderBiTree(BiTree T)
{
	if (NULL == T)
		return ;
	InOrderBiTree(T->lChild);
	printf("%c ", T->data);
	InOrderBiTree(T->rChild);
}

//后序遍历二叉树
void PostOrderBiTree(BiTree T)
{
	if (NULL == T)
		return ;
	PostOrderBiTree(T->lChild);
	PostOrderBiTree(T->rChild);
	printf("%c ", T->data);

}

//二叉树的深度
int TreeDeep(BiTree T)
{
	int deep = 0;
	if(T)
	{
		int leftdeep = TreeDeep(T->lChild);
		int rightdeep = TreeDeep(T->rChild);
		deep = leftdeep>=rightdeep?leftdeep+1:rightdeep+1;
	}
	return deep;
}

//求二叉树叶子结点个数
int Leafcount(BiTree T,int &num)
{
	if(T)
	{
		if(T->lChild ==NULL && T->rChild==NULL)	
			num++;
		Leafcount(T->lChild,num);
		Leafcount(T->rChild,num);
	}
	return num;
}

//后序遍历销毁二叉树
void FreeTree(BiTree root)
{
    if (root!=NULL)
    {
        if (root->lChild)
        {
            FreeTree(root->lChild);
            root->lChild = NULL;
        }
        if (root->rChild)
        {
            FreeTree(root->rChild);
            root->rChild = NULL;
        }
        if (root!=NULL)
        {
            free(root);
            root=NULL;
        }
    }
}
//层序遍历_队列实现
void LevelOrderBiTree(BiTree Tree)
{
    queue < BiTree> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //根节点进队列
    }

    while (q.empty() == false)  //队列不为空判断
    {
        printf("%c ",q.front()->data); 
		
        if (q.front()->lChild != NULL)   //如果有左孩子，左孩子入队列
        {
            q.push(q.front()->lChild);   
        }

        if (q.front()->rChild != NULL)   //如果有右孩子，右孩子入队列
        {
            q.push(q.front()->rChild);
        }
        q.pop();  //已经遍历过的节点出队列
    }
}

//主函数
int main(void)
{
	BiTree T;
	BiTree *p = (BiTree*)malloc(sizeof(BiTree));
	int deepth,num=0 ;
	CreateBiTree(&T);
	
	printf("先序遍历二叉树:\n");
	PreOrderBiTree(T);
	printf("\n");
	
	printf("中序遍历二叉树:\n");
	InOrderBiTree(T);
	printf("\n");
	
	printf("后序遍历二叉树:\n");
	PostOrderBiTree(T);
	printf("\n");
	
	printf("层次遍历二叉树:\n");
	LevelOrderBiTree(T);
	printf("\n");
	
	deepth=TreeDeep(T);
	printf("树的深度为:%d",deepth);
	printf("\n");
	
	Leafcount(T,num);
	printf("树的叶子结点个数为:%d",num);
	printf("\n");
	
	FreeTree(T);
	return 0;
}
