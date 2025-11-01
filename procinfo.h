#ifndef PROCINFO_H
#define PROCINFO_H

struct procinfo {
  int pid;                 // Process ID
  int cputicks;            // Total CPU ticks consumed
  int sched_count;         // Number of times scheduled
  int completion_time;     // Completion time (ticks since start)
  int qlevel;              // Queue level (for MLFQ or other schedulers)
  char name[16];           // Process name
};

#endif
