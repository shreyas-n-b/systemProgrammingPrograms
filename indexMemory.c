#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 50

typedef struct blocks{
    int blockNo;
    int flag;
}blocks;

blocks memory[SIZE];

typedef struct indexBlock{
    blocks* pointers[SIZE];
}indexBlock;

void initializeMemory(){
    for(int i=0; i<SIZE; i++){
        memory[i].blockNo=i;
        memory[i].flag=0;
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

indexBlock alloteMemory(int k){
    int count=0; int i=0; int j=0;
    indexBlock ib={{NULL}};
    while(i<SIZE && count<k){
        if(memory[i].flag == 0){
            ib.pointers[j++]=&memory[i];
            count++;
            memory[i].flag=-1;
        }
        i++;
    }
    return ib;
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
    indexBlock fileIndex=alloteMemory(k);
    printf("\nMemory Allocated!\n\n");
    printf("Layout after allocation:\n");
    printLayout();
    printf("\ncontents of index block:\n");
    for(int i=0; i<k; i++){
        printf("block: %d\n",(*(fileIndex.pointers[i])).blockNo);
    }
    return 0;
}