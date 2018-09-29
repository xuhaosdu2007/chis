#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree_node
{
    struct tree_node *left_ptr; //lef subtree
    struct tree_node *right_ptr;//right subtree
    int data;//node data

};

typedef struct tree_node TREE_NODE;

void insert_node(TREE_NODE **tree,int value)
{
    
    //tree is NULL,  malloc ,create tree
    if(*tree ==NULL)
    {
        *tree = malloc(sizeof(TREE_NODE));
        if(*tree != NULL)
        {
            (*tree)->data = value;
            (*tree)->left_ptr = NULL;
            (*tree)->right_ptr = NULL;

        }
        else
        {
            printf("malloc error\n");    
        }
    }
    else //tree is exsit
    {
        
        //cmpete insert left or right
        if(value < (*tree)->data)
        {
            insert_node(&((*tree)->left_ptr),value);   
        }
            
        else if(value > (*tree)->data)
        {
            insert_node(&((*tree)->right_ptr),value);   
        }
        else
        {
            printf("node value is dup\n");    
        }
    }

}

//serach node
TREE_NODE *serach_node(TREE_NODE *tree,int value)
{
    TREE_NODE *tmp = tree;
    while(tmp != NULL && tmp->data != value)
    {
        if(value > tmp->data)  
        {
            tmp = tree->right_ptr;    
        }
        else
        {
            tmp = tree->left_ptr;    
        }
    }

    return tmp;

}

//delete node
void delete_node(TREE_NODE **tree,int value)
{
    TREE_NODE *delete = *tree;
    TREE_NODE *parent_delete = NULL;
    TREE_NODE *sub_right_delete;
    TREE_NODE *sub_right_parent;

    //find delete and it's parent'
    while(delete != NULL && delete->data != value)
    {
        parent_delete = delete;
        if(value > delete->data)  
        {
            delete = delete->right_ptr;    
        }
        else
        {
            delete = delete->left_ptr;    
        }
    }

    // no delete
    if(delete == NULL)
    {
        printf("no node to delete\n"); 
        return;
    }

        //delete 
        //no left or right subnode
    if(delete->left_ptr == NULL && delete->right_ptr == NULL)
    {
        // root node
        if(parent_delete == NULL)    
        {
            *tree = NULL;
        }
        else if(parent_delete->left_ptr == delete)
        {
                parent_delete->left_ptr = NULL;
        }

        else //if(parent_delete->left_ptr == delete)
        {
                parent_delete->right_ptr = NULL;
        }

    } 

    //delete only have left node
    else if(delete->left_ptr != NULL && delete->right_ptr == NULL)
    {
        // root node
        if(parent_delete == NULL)    
        {
            *tree = delete->left_ptr;
        }
        else if(parent_delete->left_ptr == delete)
        {
                parent_delete->left_ptr = delete->left_ptr;
        }

        else //if(parent_delete->left_ptr == delete)
        {
                parent_delete->right_ptr = delete->left_ptr;
        }

    } 

    //delete only have right node
    else if(delete->left_ptr == NULL && delete->right_ptr != NULL)
    {
        // root node
        if(parent_delete == NULL)    
        {
            *tree = delete->right_ptr;
        }
        else if(parent_delete->left_ptr == delete)
        {
                parent_delete->left_ptr = delete->right_ptr;
        }

        else //if(parent_delete->left_ptr == delete)
        {
                parent_delete->right_ptr = delete->right_ptr;
        }

    }
    else
    {
        sub_right_parent = delete;
        sub_right_delete = delete->left_ptr;
        
        // left subtree's most right node
        while(sub_right_delete->right_ptr != NULL)
        {
            sub_right_parent = sub_right_delete;
            sub_right_delete = sub_right_delete->right_ptr;
        }
        
        //root node
        if( sub_right_parent == NULL)
        {
            *tree = delete->right_ptr;    
        }
        else if(parent_delete->left_ptr == delete)
        {
                parent_delete->left_ptr = sub_right_delete;
        }
        else //if(parent_delete->left_ptr == delete)
        {
                parent_delete->right_ptr = sub_right_delete;
        }

        //delete's right_ptr give sub_right_delete
        sub_right_delete->right_ptr = delete->right_ptr;
        
        //delete's left_ptr give sub_right_delete, sub_right_delete's left_ptr give it's parent
        if(sub_right_parent != delete)//sub not delete's sub
        {
                sub_right_delete->left_ptr = delete->left_ptr;

                if(sub_right_parent->left_ptr == sub_right_delete)
                {
                    sub_right_parent->left_ptr = sub_right_delete->left_ptr;    
                }
                else
                {
                    sub_right_parent->right_ptr = sub_right_delete->left_ptr;
                }
        }

    } 


    free(delete);
    

}

void output_tree(TREE_NODE *tree,int spaces) 
{
     
    int loop;
    while(tree != NULL)
    {
        output_tree(tree->right_ptr, spaces + 4);

        for(loop = 1;loop <= spaces;loop++)
        {
            printf(" ");
        }

        printf("%d\n",tree->data);

        output_tree(tree->left_ptr,spaces + 4);
        tree = NULL;
    }
          
}



int main(void)
{
    int arr[] = {45,83,28,97,71,40,18,77,99,92,72,69,44,32,19,11};    
    int i;
    int item;
    int total = 0;
    TREE_NODE *root = NULL;

    srand(time(NULL));//random
    printf("the numbers placed in the tree are :\n\n");
    
    for(i = 0;i < sizeof(arr) / sizeof(int);i++)
    {
        item = arr[i];
        printf("%3d",item);
        insert_node(&root,item);
    }

    printf("the tree is :\n");
    if(root == NULL)
    {
        printf("tree is empty\n");    
    }
    else
        output_tree(root,total);

    //delete  node
    while(root != NULL)
    {
        sleep(3);
        item = rand() % 16;
        printf("\n after delete %d \n\n",arr[item]);
        delete_node(&root,arr[item]);
        if(root == NULL)
            printf("empty tree\n");
        else
            output_tree(root,total);
    }

    return 0;

}
