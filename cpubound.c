#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define LIMIT 1000000   // calculate primes up to 1 million
#define INTERVAL 50000  // print procinfo 
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int count = 0;
    struct procinfo info;

    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime(i)) count++;

        // Print procinfo at intervals
        if (i % INTERVAL == 0) {
            getprocinfo(getpid(), &info);
            printf("--- Process Info ---\n");
            printf("PID: %d\n", info.pid);
            printf("Name: %s\n", info.name);
            printf("CPU Ticks: %d\n", info.cputicks);
            printf("Scheduled Count: %d\n", info.sched_count);
            printf("Completion Time: %d\n", info.completion_time);
            printf("Queue Level: %d\n", info.qlevel);
            printf("---------------------\n");
        }
    }
    
    
    printf("Total primes up to %d: %d\n", LIMIT, count);
    exit(0);
}
