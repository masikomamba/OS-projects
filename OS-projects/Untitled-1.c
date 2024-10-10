#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0; // Shared variable across threads

void* add_numbers(void* ptr) {
    // Array of numbers to be added
    int numbers[] = {0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 10000};

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        while (sum < numbers[i]) {
            sum++;
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[10];  // Array of 10 thread IDs

    // Create 10 threads
    for (int j = 0; j < 10; j++) {
        if (pthread_create(&threads[j], NULL, add_numbers, NULL)) {
            fprintf(stderr, "Error creating thread %d\n", j);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int j = 0; j < 10; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Final sum: %d\n", sum);  // Output the final sum
    return 0;
}
