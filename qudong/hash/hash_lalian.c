// la lian hash
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
//
typedef struct node
{
    char *name; // name
    char *desc; //description
    struct node *next; //pointer
}node;

#define HASHSIZE 100 // hash chang

static node *hashtable[HASHSIZE]; // data arrary

unsigned int hash(char *s)
{
    unsigned int h = 0;
    for(;*s;s++)
        h = *s + h*31; // calc  hash key
    return h%HASHSIZE;
}

node *lookup(char *str)
{
    unsigned int hashvalue = hash(str); 
    node *np = hashtable[hashvalue]; //array yuansu linked-list head
    for(;np != NULL;np = np->next)
    {
        if(!strcmp(np->name,str))    
            return np;
    }
}

char* search(char *name)
{
    node *np = lookup(name) ;
    if(np == NULL)
        return NULL;
    else
        return np->desc;
}

node *malloc_node(char *name,char *desc)
{
    node *np = (node *)malloc(sizeof(node));
    if(np == NULL)
        return NULL;
    np->name = name;
    np->desc = desc;
    np->next = NULL;
    return np;

}

int insert(char *name, char *desc)
{
    unsigned int hashvalue;
    hashvalue = hash(name);

    //no head make this is head, else make current next, make this head
    node *np = malloc_node(name,desc);
    if(np == NULL)
        return 0;
    np->next = hashtable[hashvalue];
    hashtable[hashvalue] = np;
    return 1;
}

void displayhashtable()
{
    node *np,tmp;
    unsigned int hashvalue;
    for(int i = 0;i < HASHSIZE;++i)
    {
        if(hashtable[i] != NULL) 
        {
            np = hashtable[i];  
            printf("\nhashvalue:%d (",i);
            for(;np != NULL;np = np->next)
                printf("(%s.%s)",np->name,np->desc);
            printf(")\n");
        }
    }
}

void cleanup()
{
    node *np,*tmp;
    for(int i = 0;i < HASHSIZE;++i)
    {
        if(hashtable[i] != NULL)
        {
            np = hashtable[i]; 
            while(np != NULL)
            {
                tmp = np->next;
              //  free(np->name);
              //  free(np->desc);
                free(np);
                np = tmp;
            }
        }
    }
}

int main()
{
    char *names[] = {"first name","last name","address",
    "phone","k101","k110"};
    char *descs[] = {"kobe","bryant","usa","26300778",
    "value1","value2"};

    for(int i = 0;i < 6;++i)
        insert(names[i],descs[i]);
    printf("search k110 %s\n",search("k110"));
    insert("phone","943234556");
    printf("k101is %s and phoe is %s \n",search("k101"),search("phone"));
    displayhashtable();
    cleanup();
    return 0;
}
