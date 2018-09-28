/******************
	erchashu.c
*******************/
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct btnode
{
	int data;
	struct btnode *lchild;
	struct btnode *rchild;
}BITNODE;

// create binary tree fun
int create_bintree(BITNODE **t)
{
	int ch;
	scanf("%d",&ch);
	if(ch == -1)
	{
		*t = NULL;
		return 0;
	}
	else
	{
		*t = (BITNODE *)malloc(sizeof(BITNODE));
		if(t == NULL)
		{
			printf("malloc failed \n");
			return 0;
		}
		else
		{
			(*t)->data = ch;
			printf("input %d left child:",ch);
			create_bintree(&((*t)->lchild));
			printf("input %d right child:",ch);
			create_bintree(&((*t)->rchild));
		}
	}
	return 1;
}

//pre printf the all 
void pre_order_bintree(BITNODE *t)
{
	if(t == NULL)
	{
		return 0;
	}
	else
	{
		printf("%d ",t->data);
		pre_order_bintree(t->lchild);
		pre_order_bintree(t->rchild);
	}
}

// mid printf the all
void mid_order_bintree(BITNODE *t)
{
	if(t == NULL)
	{
		return 0;
	}
	else
	{
		pre_order_bintree(t->lchild);
		
		printf("%d ",t->data);
		pre_order_bintree(t->rchild);
	}
}

// end printf the all
void end_order_bintree(BITNODE *t)
{
	if(t == NULL)
	{
		return 0;
	}
	else
	{
		pre_order_bintree(t->lchild);
				
		pre_order_bintree(t->rchild);
		printf("%d ",t->data);
	}
}

//deepth of er cha shu
int deep_tree(BITNODE *t)
{
	int deep = 0;
	if(t != NULL)
	{
		int leftdeep = deep_tree(t->lchild);
		int rightdeep = deep_tree(t->rchild);
		deep = leftdeep >= rightdeep ? leftdeep + 1:rightdeep + 1;
	}
	return deep;
}

//count leaf
int leaf_count(BITNODE *t)
{
	static int count;
	
	if(t != NULL)
	{
		if(t->lchild == NULL && t->rchild == NULL)
		{
			count++;
		}
		leaf_count(t->lchild);
		leaf_count(t->rchild);
	}
	return count;
}

//main
int main(int argc,const char *argv[])
{
	BITNODE *t;
	int depth = 0;
	int leafcount = 0;
	printf("input first node ,-1 is null\n");
	create_bintree(&t);

	printf("pre order bintree:\n");
	pre_order_bintree(t);
	printf("\n");

	printf("mid order bintree:\n");
	mid_order_bintree(t);
	printf("\n");

	printf("end order bintree:\n");
	end_order_bintree(t);
	printf("\n");

	depth = deep_tree(t);
	printf("deep is :%d \n",depth);

	leafcount = leaf_count(t);
	printf("leafcount is :%d \n",leafcount);

	return 0;
}
