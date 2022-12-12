#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "cpu.h"
#include "list.h"
#include "schedulers.h"


struct node *head=NULL;
struct node *curr=NULL;
int time_quantum = 10;

// lets maybe use the same add function for all schedulers because they all will do the same thing
void add(char *name,int priority,int burst) 
{ 
    
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

    // start at the beginning of the list
    // have some time quantum 10
    // go through the list
    // if burst time is less or equal to quantum:
        // run for burst time and remove from list
        // current node is next
    // run for time quantum and subtract time quantum from burst time
    // current node is next
    while(head != NULL){
        curr = head;
        while(curr!= NULL){
            if(curr->task->burst <= time_quantum){
                run(curr->task, curr->task->burst);
                delete(&head, curr->task);
                curr = curr->next;

            }
            else{
                run(curr->task, time_quantum);
                curr->task->burst -= time_quantum;
                curr = curr->next;
            }
        }
    }
}




