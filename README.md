Keawa Rozet

916796184

CSC 415

Project 4 – Processes, Threads, and Race Conditions



# Command to build and run the project:

make -f Makefile

./threadracer



# What my code does:

My code creates 10 different threads that increment a global counter. Technically, each thread is suppose to increment the counter by a total of 10, so that at the end the counter equals 100.

Since the assignment called for me to specifically induce as many race conditions as possible, I placed a nanosleep function inside of my for-loop-incrementer within each thread to achieve the desired outcome.

Instead of each thread incrementing the global counter by 10, they now each only increment it by 1 so that the final outcome is 10 instead of 100.



# Example Execution
```
> make -f Makefile
gcc -I -Wall pthread_race.c -o threadracer -lpthread
> ./threadracer
ThreadID: 140071363852032	inc: 1			<--- the first thread is called
ThreadID: 140071355459328	inc: 2			<--- note all the ThreadIDs are different
ThreadID: 140071347066624	inc: 3
ThreadID: 140071338673920	inc: 4
ThreadID: 140071330281216	inc: 5
ThreadID: 140071321888512	inc: 6
ThreadID: 140071313495808	inc: 7
ThreadID: 140071305103104	inc: 8
ThreadID: 140071296710400	inc: 9
ThreadID: 140071288317696	inc: 10			<--- the final increment
```
