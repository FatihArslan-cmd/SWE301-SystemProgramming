
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

// Signal handler function for SIGINT
void handle_sigint(int sig) {
    // Generate and print a random number
    int random_number = rand() % 100;  // Generates a random number between 0 and 99
    printf("\nCaught SIGINT (Ctrl+C). Random number: %d\n", random_number);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Set up the signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    // Infinite loop to keep the program running
    while (1) {
        printf("Press Ctrl+C to generate a random number...\n");
        sleep(1);
    }

    return 0;
}


