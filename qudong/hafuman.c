/*************************************
	https://blog.csdn.net/TW_345/article/details/50096819
	hafuman code
	hafman_tree create tree, main() set code, 
	father's left set 0 ,right set 1
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE (MAXLEAF*2 - 1)

typedef struct
{
	int bit[MAXBIT];
	int start;
}HCODETYPE; //code for haff struct

typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
}HNODETYPE;   //leaf  struct 

void huffman_tree(HNODETYPE huffnode[MAXNODE],int n)
{
	// i j ѭ��������m1 m2 ������СȨֵ ��x1 x2 ������СȨֵ�������е����
	int i,j,m1,m2,x1,x2;

	//��ʼ��huffnode[]�����еĽڵ�
	for(i = 0;i < 2 * n - 1;i++)
	{
		huffnode[i].weight = 0;// weight
		huffnode[i].parent = -1;
		huffnode[i].lchild = -1;
		huffnode[i].rchild = -1;
		huffnode[i].value = i;
	}

	//����n��Ҷ�ӵ�Ȩֵ
	for(i = 0;i < n;i++)
	{
		printf("please input weight of leaf node %d \n",i);
		scanf("%d",&huffnode[i].weight);
	}
	
	//����huffman tree
	for(i = 0;i < n-1;i++)
	{
		m1 = m2 = MAXVALUE;//m1 m2 ����Ȩֵ��С�� Ȩֵ  ���޸��ڵ�
		x1 = x2 = 0; //x1 x 2 ����Ȩֵ��С�� ���

		//�ҳ����нڵ���Ȩֵ��С�� �޸��ڵ������ �ڵ㣬��ϳ�һ��������
		for(j = 0;j < n + i;j++)
		{
			if(huffnode[j].weight < m1 && huffnode[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				m1 = huffnode[j].weight;
				x1 = j;
			}
			else if(huffnode[j].weight < m2 && huffnode[j].parent == -1)
			{
				m2 = huffnode[j].weight;
				x2 = j;
			}
			else
			{

			}
		}	
			//���� �ҵ���m1 m2 ������СȨֵ���ĸ��ڵ㡣
			huffnode[x1].parent = n + i;
			huffnode[x2].parent = n + i;
			huffnode[n + i].weight = huffnode[x1].weight + huffnode[x2].weight;
			huffnode[n + i].lchild = x1;
			huffnode[n + i].rchild = x2;
		
			printf("x1.w and x2.w ini rount %d, %d , %d ",i,huffnode[x1].weight,huffnode[x2].weight);
	//	}
	}

	//printf all
	printf("\n \n");
	for(i = 0;i < n * 2;i++)
	{
		printf("parents %d,lchild %d,rchild %d,value %d,weight %d \n",
			huffnode[i].parent,huffnode[i].lchild,huffnode[i].rchild,huffnode[i].value,huffnode[i].weight);
	}
	
}

//decodeing
void decodeing(char string[],HNODETYPE buf[],int number)
{
	int i = 0;
	int tmp = 0;
	int code[1024];

	int m = 2*number - 1;
	char *nump;
	char num[1024];

	//�ַ��� ת����111000 ��ʽ
	for(i = 0;i < strlen(string);i++)
	{
		if(string[i] == '0')
			num[i] = 0;
		else
			num[i] = 1;
	}

	//���� �����ҵ���Ӧ��� ��ӡvalue 
	i = 0;
	nump = &num[0];
	while(nump < (&num[strlen(string)]))
	{
		tmp = m - 1;
		while((buf[tmp].lchild != -1) && (buf[tmp].rchild != -1))
		{
			if(*nump == 0)
			{
				tmp = buf[tmp].lchild;
			}
			else
				tmp = buf[tmp].rchild;
			nump++;
				
		}
		printf("%d",buf[tmp].value);
	
		
	}
}

int main(int argc,char *argv[])
{
	HNODETYPE huffnode[MAXNODE]; //��� ����
	HCODETYPE huffcode[MAXLEAF]; //����ṹͼ���飬
	HCODETYPE cd;//������ʱ����
	int i,j,c,p,n;
	char pp[100];
	printf("please input n: \n");
	scanf("%d",&n);

	huffman_tree(huffnode,n);

	for(i = 0;i < n;i++)
	{
		cd.start = n -1;
		c = i;
		p = huffnode[c].parent;
		while(p != -1)
		{
			if(huffnode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = huffnode[c].parent;
		}

		//����������ʼλ
		for(j = cd.start + 1;j < n;j++)
		{
			huffcode[i].bit[j] = cd.bit[j];
			huffcode[i].start = cd.start;
		}
	}

	printf("\n");
	//����Ѿ����ڵı���
	for(i = 0;i < n;i++)
	{
		printf("%d 's huffman code is : ",i);
		for(j = huffcode[i].start + 1;j < n;j++)
		{
			printf("%d",huffcode[i].bit[j]);
		}
		printf("start: %d",huffcode[i].start);
		printf("\n");
	}

	printf("decodeing enter code:\n");
	scanf("%s",&pp);
	decodeing(pp,huffnode,n);
	getchar();
	return 0;
	
}
