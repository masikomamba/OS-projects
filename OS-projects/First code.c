#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int thread_num = 10;
int thread_sum[10];
int range = 1000;

void* add_numbers(void* ptr) {
    int k = *((int*)ptr);  // Thread-specific index
    int start = k * range;
    int end = start + range;

    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += i;
    }

    thread_sum[k] = sum;  // Store the sum for this thread

    free(ptr);  // Free dynamically allocated memory for thread index
    return NULL;
}

int main() {
    pthread_t threads[10];  // Array of 10 thread IDs
    int total_sum = 0;

    // Create 10 threads
    for (int j = 0; j < 10; j++) {
        int* thread_id = malloc(sizeof(int));  // Allocate memory for thread index
        *thread_id = j;  // Assign thread index
        if (pthread_create(&threads[j], NULL, add_numbers, thread_id)) {
            fprintf(stderr, "Error creating thread %d\n", j);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int j = 0; j < 10; j++) {
        pthread_join(threads[j], NULL);
        total_sum += thread_sum[j];  // Add each thread's sum
    }

    printf("Final sum: %d\n", total_sum);  // Output the final sum
    return 0;
}
