# Assignment 4: CPU SCHEDULER
## Introduction
Liam Propst

002346086 | wpropst@chapman.edu

CPSC 380-01
Assignment 4

Source Files:
* CPU.c
* dirver.c 
* list.c
* Makefile
* schedule_fcfs.c
* schedule_priority.c
* schedule_sjf.c
* schedule_rr.c
* schedule_priority_rr.c

## About the problem

This project involves implementing several different process scheduling algorithms. The scheduler 
will  be  assigned  a  predefined  set  of  tasks  and  will  schedule  the  tasks  based  on  the  selected 
scheduling algorithm. Each task is assigned a priority and CPU burst. The following scheduling 
algorithms will be implemented:
* First-come, first-served (FCFS), which schedules tasks in the order in which they request 
the CPU.
* Shortest-job-first (SJF), which schedules tasks in order of the length of the tasks’ next 
CPU burst
* Priority scheduling, which schedules tasks based on priority.
* Round-robin (RR) scheduling, where each task is run for a time quantum (or for the 
remainder of its CPU burst). 

hese supporting files read in the schedule of tasks, insert 
the  tasks  into  a  list,  and  invoke  the  scheduler.  The  schedule  of  tasks  has  the  form  [task  name], [priority] [CPU burst], with the following example format:
T1, 4, 20 
T2, 2, 25 
T3, 3, 25 
T4, 3, 15 
T5, 10, 10

## Running the program

* Compile the program `make clean` and then `make {option}` where option is one of the following
    * rr
    * fcfs
    * priority
    * sjf
    * priority_rr
* Run the program `./{option} {filename}`
* Can change the given list of processes in the filename you want to run
* Example run from directorty:
    `make clean` , `make priority_rr` , `./priority_rr book.txt`

## Citations

* `malloc` man pages -> run `man malloc`
* Clarification on RR scheduling : [GeeksforGeeks](https://www.geeksforgeeks.org/program-round-robin-scheduling-set-1/)