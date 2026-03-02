#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 50

typedef struct blocks* blockPointer;
typedef struct blocks{
    int blockNo;
    int flag;
    blockPointer next;
}blocks;

blocks memory[SIZE];

void initializeMemory(){
    for(int i=0; i<SIZE; i++){
        memory[i].blockNo=i+1;
        memory[i].flag=0;
        memory[i].next=NULL;
    }
}

void printLayout(){
    for(int i=0; i<40; i++)printf("-");
    printf("\n");
    printf("\tMemory Layout\n");
    for(int i=0; i<SIZE; i++){
        if(i%10 == 0)printf("\n");
        if(memory[i].flag == -1){
            printf("xx ");
        }
        else{
            printf("%02d ",memory[i].blockNo);
        }
    }
    printf("\n");
}

blockPointer generateBlock(){
    int randInt=0+(rand()%50);
    int alloteFlag=0;
    blockPointer node=NULL;
    while(randInt<SIZE && alloteFlag != 1){
        if(memory[randInt].flag == -1){
            randInt++;
        }
        else{
            memory[randInt].flag=-1;
            node=&memory[randInt];
            alloteFlag=1;
        }
    }
    return node;
}

blockPointer alloteMemory(int k){
    blockPointer head=generateBlock();
    while(head == NULL)head=generateBlock();
    blockPointer curr=head;
    blockPointer prev=NULL;
    int count=1;
    while(count < k){
        curr->next=generateBlock();
        while(curr->next == NULL)generateBlock();
        prev=curr;
        curr=curr->next;
        count++;
    }
    return head;
}

int main(){
    initializeMemory();
    srand(time(NULL));

    for(int i=0; i<20; i++){
        int randInt=0+(rand()%50);
        memory[randInt].flag=-1;
    }
    int k;
    printf("Enter the size of the file(in blocks) to be stored: ");
    scanf("%d", &k);
    printf("Layout before allocation:\n");
    printLayout();
    blockPointer fileHead=alloteMemory(k);
    printf("\nMemory Allocated!\n\n");
    printf("Layout after allocation:\n");
    printLayout();
    printf("\nLinked list of allocated blocks:\n");
    for(blockPointer curr=fileHead; curr; curr=curr->next){
        printf("block: %02d -> ",curr->blockNo);
    }
    printf("NULL\n");
    return 0;
}