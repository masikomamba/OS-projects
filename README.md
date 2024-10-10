# Multithreaded sum calculation

the program uses pthreads to calculate the sum of numbers from 0 to 9999 using multiple threads. Each thread add numbers with a range of 1000, for example o to 999, 1000 to 1999 and so on. Once all the threads have completed their calculations, all the sums from each thread are added together to get the total sum and print it. 

## Overview

### Creating threads
* The program creates 10 threads and each thread is responsible for calculating the sum of numbers in a certain range, for thread 1, the program adds numbers from 0 to 999 and so on until all threads have added numbers.

### Executing threads
* Each thread executes the add_numbers function which is the function responsuble for adding the numbers up to a specified range.
* The result of each thread is stored in an array

### Main thread
* The main thread waits for all the threads to finish
* The elements of the array that contains the sums of each thread are added together to calculate the total sum.
* The total sum is printed

## Compilation
* To complie the program, you can use the following commands:
  gcc "yourfilename.c" -o "Filename"
* To run the program:
  - make sure the code compiles
  ./"Filename"

## Key Functions and variables
* pthread_t threads[10]- is an array that holds the thread IDs for ten 10 threads
* thread_sum[10]- an array that stores te sum of each thread
* add_numbers()- the function executed by the threads that calcualtes the sum of the numbers.
* pthread_create()- used to create threads
* pthread_join()- used to make the main thread wait for all threads to finish
