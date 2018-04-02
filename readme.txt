Keawa Rozet
916796184
CSC 415
Project 4 – Processes, Threads, and Race Conditions


Command to build and run the project:
=====================================

make -f Makefile

./threadracer


What my code does:
==================

My code creates 10 different threads that increment a global counter.
Technically, each thread is suppose to increment the counter by a total of 10, so that at the end the counter equals 100.
Since the assignment called for me to specifically induce as many race conditions as possible, I placed a nanosleep function inside of my for-loop-incrementer within each thread to achieve the desired outcome.
Instead of each thread incrementing the global counter by 10, they now each only increment it by 1 so that the final outcome is 10 instead of 100.


Example Execution
=================

> make -f Makefile
gcc -I -Wall pthread_race.c -o threadracer -lpthread
> ./threadracer
This is Thread #1	inc: 1      <--- Increments the global variable by 1
This is Thread #2	inc: 2
This is Thread #3	inc: 3
This is Thread #4	inc: 4
This is Thread #6	inc: 5
This is Thread #6	inc: 6
This is Thread #7	inc: 7
This is Thread #8	inc: 8
This is Thread #9	inc: 9
This is Thread #10	inc: 10      <--- Last increment to the global variable
