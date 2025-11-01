#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/procinfo.h"


int
main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: procinfo <pid>\n");
    exit(1);
  }

  int pid = atoi(argv[1]);
  struct procinfo info;

  if (getprocinfo(pid, &info) < 0) {
    printf("getprocinfo failed for pid %d\n", pid);
    exit(1);
  }

  printf("\n--- Process Info ---\n");
  printf("PID: %d\n", info.pid);
  printf("Name: %s\n", info.name);
  printf("CPU Ticks: %d\n", info.cputicks);
  printf("Scheduled Count: %d\n", info.sched_count);
  printf("Completion Time: %d\n", info.completion_time);
  printf("Queue Level: %d\n", info.qlevel);
  printf("---------------------\n");

  exit(0);
}
