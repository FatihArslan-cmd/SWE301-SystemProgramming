#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void signal_handler(int signum) {
    static int counter = 0;
    counter++;

    if (counter % 2 == 1) {
        int random_odd = (rand() % 50) * 2 + 1;
        printf("Tekil saniye: %d\n", random_odd);
    } else {
        int random_even = (rand() % 50) * 2;
        printf("Çift saniye: %d\n", random_even);
    }
}

int main() {

    srand(time(NULL));
    signal(SIGALRM, signal_handler);


    while (1) {
        sleep(1);
        alarm(1);
    }

    return 0;
}
