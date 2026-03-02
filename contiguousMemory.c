#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 50

typedef struct blocks{
    int flag;
}blocks;

blocks memory[SIZE];

int store(int k){
    int count=0;
    for(int i=0; i<SIZE; i++){
        if(memory[i].flag == 0){
            count++;
        }
        else{
            count=0;
        }
        if(count >= k){
            return (i-k+2);
        }
    }
    return -1;
}
int main(){
    srand(time(NULL));
    for(int i=0; i<20; i++){
        int randInt=1+(rand()%50);
        memory[randInt-1].flag=-1;
    }
    int k;
    printf("Enter the size of the file(in blocks) to be stored: ");
    scanf("%d", &k);
    int startAddress=store(k);
    if(startAddress == -1){
        printf("\nMemory allocation failed, no space!\n");
    }
    else{
        printf("Memory allocation successful: allocated blocks = %d to %d",startAddress,startAddress+k-1);
    }
    printf("\n");
    for(int i=0; i<40; i++)printf("-");
    printf("\n");
    printf("\tMemory Layout\n");
    for(int i=0; i<SIZE; i++){
        if(i%10 == 0){
            printf("\n");
        }
        if(memory[i].flag == -1){
            printf("xx ");
        }
        else{
            printf("%02d ",i+1);
        }
    }
    return 0;
}