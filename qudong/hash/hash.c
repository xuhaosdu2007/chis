#include <stdio.h>>

#define LEN 13
#define N 11

int data[N] = {10,85,72,9,8,7,5,4,6,3,2,1,95}; //yuan data 
int hash[LEN] = {0};//hash data

void create()
{
    for(int i = 0;i < N;i++)
    {
        int j = data[i] % LEN;// calculate hash key 
        while(hash[j])
            j = (++j) % LEN;//xian xing tan ce
        hash[j] = data[i];           
    }
    
}

int hash_sou(int key)
{
    int i = key % LEN; //calculate hash key
    while(hash[i] && hash[i] != key) // shi fou chong tu
        i = (++i) % LEN; 
    if(hash[i] == 0)
        return -1;
    else
        return i; //return key
}

int main(void)
{
    int key;
    create();//create
    printf("hash value:\n");
    for(int i = 0;i < LEN;i++)
        printf("%d ",hash[i]);
    printf("\n");
    printf("intput find value: ");
    scanf("%d",&key);

    int pos = hash_sou(key);// calculate key
    if(pos > 0)
    {
        printf("find ok ,hash key is %d\n",pos);    
    }
    else
    {
        printf("find error\n");    
    }
    return 0;
}

