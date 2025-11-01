#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define ITERATIONS 5000
#define INTERVAL 500

int main(void)
{
    char buffer[512];
    struct procinfo info;

    printf("iobound: simulating heavy I/O with memory operations...\n");

    // Fill buffer with fake data
    for (int i = 0; i < sizeof(buffer); i++)
        buffer[i] = 'a' + (i % 26);

    for (int i = 1; i <= ITERATIONS; i++) {
        // Fake "I/O" by copying data in memory
        char temp[512];
        memmove(temp, buffer, sizeof(buffer));
        memmove(buffer, temp, sizeof(buffer));

        // Add some dummy arithmetic to slow it down
        int sum = 0;
        for (int j = 0; j < 200; j++)
            sum += (buffer[j % 512] * j) % 97;

        // Print process info periodically
        if (i % INTERVAL == 0) {
            getprocinfo(getpid(), &info);
            printf("\n--- Process Info ---\n");
            printf("PID: %d\n", info.pid);
            printf("Name: %s\n", info.name);
            printf("CPU Ticks: %d\n", info.cputicks);
            printf("Scheduled Count: %d\n", info.sched_count);
            printf("Completion Time: %d\n", info.completion_time);
            printf("Queue Level: %d\n", info.qlevel);
            printf("---------------------\n");
        }
    }

    printf("\niobound: finished simulated I/O load.\n");
    exit(0);
}

