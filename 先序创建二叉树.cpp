#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef	char ElemType;			//��������
typedef	int	Status;			//����ֵ����

//����������ṹ
typedef struct BiTNode{
	ElemType	data;			//������
	struct BiTNode	*lChild, *rChild;	//����������
}BiTNode, *BiTree;

//���򴴽�������
Status CreateBiTree(BiTree *T)
{
	ElemType ch;

	scanf("%c%*c", &ch);

	if ('#' == ch)
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T))//û�з��䵽�ڴ� 
			exit(-1);

		(*T)->data = ch;
		printf("����%c�����ӽڵ㣺", ch);
		CreateBiTree(&(*T)->lChild);
		printf("����%c�����ӽڵ㣺", ch);
		CreateBiTree(&(*T)->rChild);
	}

	return 1;
}

//�������������
void PreOrderBiTree(BiTree T)
{
	if (NULL == T)
		return ;
	printf("%c ", T->data);
	PreOrderBiTree(T->lChild);
	PreOrderBiTree(T->rChild);

}

//�������������
void InOrderBiTree(BiTree T)
{
	if (NULL == T)
		return ;
	InOrderBiTree(T->lChild);
	printf("%c ", T->data);
	InOrderBiTree(T->rChild);
}

//�������������
void PostOrderBiTree(BiTree T)
{
	if (NULL == T)
		return ;
	PostOrderBiTree(T->lChild);
	PostOrderBiTree(T->rChild);
	printf("%c ", T->data);

}

//�����������
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

//�������Ҷ�ӽ�����
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

//����������ٶ�����
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
//�������_����ʵ��
void LevelOrderBiTree(BiTree Tree)
{
    queue < BiTree> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //���ڵ������
    }

    while (q.empty() == false)  //���в�Ϊ���ж�
    {
        printf("%c ",q.front()->data); 
		
        if (q.front()->lChild != NULL)   //��������ӣ����������
        {
            q.push(q.front()->lChild);   
        }

        if (q.front()->rChild != NULL)   //������Һ��ӣ��Һ��������
        {
            q.push(q.front()->rChild);
        }
        q.pop();  //�Ѿ��������Ľڵ������
    }
}

//������
int main(void)
{
	BiTree T;
	BiTree *p = (BiTree*)malloc(sizeof(BiTree));
	int deepth,num=0 ;
	CreateBiTree(&T);
	
	printf("�������������:\n");
	PreOrderBiTree(T);
	printf("\n");
	
	printf("�������������:\n");
	InOrderBiTree(T);
	printf("\n");
	
	printf("�������������:\n");
	PostOrderBiTree(T);
	printf("\n");
	
	printf("��α���������:\n");
	LevelOrderBiTree(T);
	printf("\n");
	
	deepth=TreeDeep(T);
	printf("�������Ϊ:%d",deepth);
	printf("\n");
	
	Leafcount(T,num);
	printf("����Ҷ�ӽ�����Ϊ:%d",num);
	printf("\n");
	
	FreeTree(T);
	return 0;
}
