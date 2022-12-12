#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "cpu.h"
#include "list.h"
#include "schedulers.h"


struct node *head=NULL;
struct node *curr=NULL;
struct node *temp = NULL;
struct node *tempvar = NULL;
void add(char *name,int priority,int burst) 
{ 

    //add everything to the list in order
    if(head == NULL){
        head = malloc(sizeof(struct node));
        head->task = malloc(sizeof(struct task));
        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;
        curr=head;
        
    }
    else{
        curr->next = malloc(sizeof(struct node));
        curr->next->task = malloc(sizeof(struct task));
        curr->next->task->name = name;
        curr->next->task->priority = priority;
        curr->next->task->burst = burst;

        curr=curr->next;
    }

    
} 
void schedule(){
    temp = malloc(sizeof(struct node));
    temp->task = malloc(sizeof(struct task));
    tempvar = malloc(sizeof(struct node));
    tempvar->task = malloc(sizeof(struct task));


    curr = head;
    //order the list using a bubble sort
    //once it is ordered run everything one at a time
    while(curr != NULL){
        temp=head; 
        while (temp->next !=NULL){
            if(temp->task->burst >temp->next->task->burst){
                tempvar->task = temp->task;
                temp->task = temp->next->task;// swap the data
                temp->next->task = tempvar->task;
            }
            temp = temp->next;    // move to the next element 
        }
        curr = curr->next;    // move to the next node

    }
    
    curr = head;

    while(curr!=NULL){
        run(curr->task, curr->task->burst);
        curr = curr->next;
    
        
    }

}