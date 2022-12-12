#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "cpu.h"
#include "list.h"
#include "schedulers.h"


struct node *head=NULL;
struct node *curr=NULL;
void add(char *name,int priority,int burst) 
{ 
    //add everything to the list in order
    if(head == NULL){
        head = malloc(sizeof(struct node));
        head->task = malloc(sizeof(struct task));
        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;
        curr = head;
    }
    else{
        curr->next = malloc(sizeof(struct node));
        curr->next->task = malloc(sizeof(struct task));
        curr->next->task->name = name;
        curr->next->task->priority = priority;
        curr->next->task->burst = burst;
        curr = curr->next;

    }

    
} 
void schedule(){
    //run everything in order
    curr = head;
    while(curr!=NULL){
        run(curr->task, curr->task->burst);
        curr = curr->next;
    }
    


}