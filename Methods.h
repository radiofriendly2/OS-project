#include "SearchingAlgorithms.h"
#include <omp.h>
#include <time.h>

void SerialProgramming(int arr[], int key, int n, int choice2){
    int choice;
    struct Args threadArgs;
    threadArgs.key = key;
    threadArgs.arr=(int *)malloc(sizeof(int)*n);
    memcpy(threadArgs.arr, arr, n*sizeof(int));
    threadArgs.choice = choice2;
    threadArgs.keyFound = -1;
    choice = 1;
    switch(choice){
        case 1:
        {
        	threadArgs.start = 0;
		    threadArgs.end = n;
            clock_t begin = clock();
            LinearSearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[0] = time_spent;
        }
        case 2:
        {
        	threadArgs.start = 0;
    		threadArgs.end = n;
            clock_t begin = clock();
            BinarySearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[1] = time_spent;
        }
        case 3:
        {
        	threadArgs.start = 0;
		    threadArgs.end = n;
            clock_t begin = clock();
            TernarySearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[2] = time_spent;
        }
        case 4:
        {
        	threadArgs.start = 0;
    		threadArgs.end = n;
            clock_t begin = clock();
            JumpSearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[3] = time_spent;
        }
        case 5:
        {
        	threadArgs.start = 0;
    		threadArgs.end = n;
            clock_t begin = clock();
            InterpolationSearchUsingPthreads((void*)&threadArgs);
            clock_t end = clock();
            double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
            timespent[4] = time_spent;
            break;
        }
        default:
            printf("Wrong Choice");
            break;
    }
}

void PthreadProgramming(int arr[], int key, int n, int choice){
    int m = n;
    int choice2=1;
   
    struct Args threadArgs;
    threadArgs.arr=(int *)malloc(sizeof(int)*n);
    memcpy(threadArgs.arr, arr, n*sizeof(int));
    threadArgs.key = key;
    threadArgs.choice = choice;
    threadArgs.keyFound = -1;
    int* ptr;
    int noOfThreads;
    int i; int j=0, k=0;
    for(k=0; k<3; k++){
	    noOfThreads = (k==0 ? 1 : k==1 ? 2 : k==2 ? 4 : 4);
	    pthread_t t[noOfThreads];
	    for(j=0; j<5; j++){
			clock_t begin = clock();
		   for(i=0; i<noOfThreads; i++){
			   
				threadArgs.start = (n/noOfThreads) * i;
			   threadArgs.end = (n/noOfThreads) * (i + 1);
			   
			   switch(choice2){
			       case 1:
			       {
			           pthread_create(&t[i], NULL, &LinearSearchUsingPthreads, &threadArgs);
			           break;
			       }
			       case 2:
			       {
			           pthread_create(&t[i], NULL, &BinarySearchUsingPthreads, &threadArgs);
			           break;
			       }
			       case 3:
			       {
			           pthread_create(&t[i], NULL, &TernarySearchUsingPthreads, &threadArgs);
			           break;
			       }
			       case 4:
			       {
			           pthread_create(&t[i], NULL, &JumpSearchUsingPthreads, &threadArgs);
			           break;
			       }
			       case 5:
			       {
			           pthread_create(&t[i], NULL, &InterpolationSearchUsingPthreads, &threadArgs);
			           break;
			       }
			       default:
			       {
			           break;
			       }
			   }
			   if(threadArgs.keyFound!=-1)
			   {
			       printf("Key Found at: %d\n", threadArgs.keyFound);
			       break;
			   }
			}
			clock_t end = clock();
			double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
			timespent[4+choice2] = time_spent;
			for(i=0; i<noOfThreads; i++){
				   pthread_join(t[i], NULL);
			}
			if(choice2==1){
				if(noOfThreads==1){
					(n==16) ? LST1PT[0] = time_spent : (n==256) ? LST1PT[1] = time_spent : (n==4096) ? LST1PT[2] = time_spent : (n==65536) ? LST1PT[3] = time_spent : (n==1048576) ? LST1PT[4] = time_spent : (n==16777216) ? LST1PT[5] = time_spent : (n==67108864) ? LST1PT[6] = time_spent : (n==100000000) ? (LST1PT[7] = time_spent) : (LST1PT[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? LST2PT[0] = time_spent : (n==256) ? LST2PT[1] = time_spent : (n==4096) ? LST2PT[2] = time_spent : (n==65536) ? LST2PT[3] = time_spent : (n==1048576) ? LST2PT[4] = time_spent : (n==16777216) ? LST2PT[5] = time_spent : (n==67108864) ? LST2PT[6] = time_spent : (n==100000000) ? (LST2PT[7] = time_spent) : (LST2PT[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? LST4PT[0] = time_spent : (n==256) ? LST4PT[1] = time_spent : (n==4096) ? LST4PT[2] = time_spent : (n==65536) ? LST4PT[3] = time_spent : (n==1048576) ? LST4PT[4] = time_spent : (n==16777216) ? LST4PT[5] = time_spent : (n==67108864) ? LST4PT[6] = time_spent : (n==100000000) ? (LST4PT[7] = time_spent) : (LST4PT[7] = 0);
				}
			}
			else if(choice2==2){
				if(noOfThreads==1){
					(n==16) ? BST1PT[0] = time_spent : (n==256) ? BST1PT[1] = time_spent : (n==4096) ? BST1PT[2] = time_spent : (n==65536) ? BST1PT[3] = time_spent : (n==1048576) ? BST1PT[4] = time_spent : (n==16777216) ? BST1PT[5] = time_spent : (n==67108864) ? BST1PT[6] = time_spent : (n==100000000) ? (BST1PT[7] = time_spent) : (BST1PT[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? BST2PT[0] = time_spent : (n==256) ? BST2PT[1] = time_spent : (n==4096) ? BST2PT[2] = time_spent : (n==65536) ? BST2PT[3] = time_spent : (n==1048576) ? BST2PT[4] = time_spent : (n==16777216) ? BST2PT[5] = time_spent : (n==67108864) ? BST2PT[6] = time_spent : (n==100000000) ? (BST2PT[7] = time_spent) : (BST2PT[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? BST4PT[0] = time_spent : (n==256) ? BST4PT[1] = time_spent : (n==4096) ? BST4PT[2] = time_spent : (n==65536) ? BST4PT[3] = time_spent : (n==1048576) ? BST4PT[4] = time_spent : (n==16777216) ? BST4PT[5] = time_spent : (n==67108864) ? BST4PT[6] = time_spent : (n==100000000) ? (BST4PT[7] = time_spent) : (BST4PT[7] = 0);
				}
			}
			else if(choice2==3){
				if(noOfThreads==1){
					(n==16) ? TST1PT[0] = time_spent : (n==256) ? TST1PT[1] = time_spent : (n==4096) ? TST1PT[2] = time_spent : (n==65536) ? TST1PT[3] = time_spent : (n==1048576) ? TST1PT[4] = time_spent : (n==16777216) ? TST1PT[5] = time_spent : (n==67108864) ? TST1PT[6] = time_spent : (n==100000000) ? (TST1PT[7] = time_spent) : (TST1PT[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? TST2PT[0] = time_spent : (n==256) ? TST2PT[1] = time_spent : (n==4096) ? TST2PT[2] = time_spent : (n==65536) ? TST2PT[3] = time_spent : (n==1048576) ? TST2PT[4] = time_spent : (n==16777216) ? TST2PT[5] = time_spent : (n==67108864) ? TST2PT[6] = time_spent : (n==100000000) ? (TST2PT[7] = time_spent) : (TST2PT[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? TST4PT[0] = time_spent : (n==256) ? TST4PT[1] = time_spent : (n==4096) ? TST4PT[2] = time_spent : (n==65536) ? TST4PT[3] = time_spent : (n==1048576) ? TST4PT[4] = time_spent : (n==16777216) ? TST4PT[5] = time_spent : (n==67108864) ? TST4PT[6] = time_spent : (n==100000000) ? (TST4PT[7] = time_spent) : (TST4PT[7] = 0);
				}
			}
			else if(choice2==4){
				if(noOfThreads==1){
					(n==16) ? JST1PT[0] = time_spent : (n==256) ? JST1PT[1] = time_spent : (n==4096) ? JST1PT[2] = time_spent : (n==65536) ? JST1PT[3] = time_spent : (n==1048576) ? JST1PT[4] = time_spent : (n==16777216) ? JST1PT[5] = time_spent : (n==67108864) ? JST1PT[6] = time_spent : (n==100000000) ? (JST1PT[7] = time_spent) : (JST1PT[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? JST2PT[0] = time_spent : (n==256) ? JST2PT[1] = time_spent : (n==4096) ? JST2PT[2] = time_spent : (n==65536) ? JST2PT[3] = time_spent : (n==1048576) ? JST2PT[4] = time_spent : (n==16777216) ? JST2PT[5] = time_spent : (n==67108864) ? JST2PT[6] = time_spent : (n==100000000) ? (JST2PT[7] = time_spent) : (JST2PT[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? JST4PT[0] = time_spent : (n==256) ? JST4PT[1] = time_spent : (n==4096) ? JST4PT[2] = time_spent : (n==65536) ? JST4PT[3] = time_spent : (n==1048576) ? JST4PT[4] = time_spent : (n==16777216) ? JST4PT[5] = time_spent : (n==67108864) ? JST4PT[6] = time_spent : (n==100000000) ? (JST4PT[7] = time_spent) : (JST4PT[7] = 0);
				}
			}
			else if(choice2==5){
				if(noOfThreads==1){
					(n==16) ? IST1PT[0] = time_spent : (n==256) ? IST1PT[1] = time_spent : (n==4096) ? IST1PT[2] = time_spent : (n==65536) ? IST1PT[3] = time_spent : (n==1048576) ? IST1PT[4] = time_spent : (n==16777216) ? IST1PT[5] = time_spent : (n==67108864) ? IST1PT[6] = time_spent : (n==100000000) ? (IST1PT[7] = time_spent) : (IST1PT[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? IST2PT[0] = time_spent : (n==256) ? IST2PT[1] = time_spent : (n==4096) ? IST2PT[2] = time_spent : (n==65536) ? IST2PT[3] = time_spent : (n==1048576) ? IST2PT[4] = time_spent : (n==16777216) ? IST2PT[5] = time_spent : (n==67108864) ? IST2PT[6] = time_spent : (n==100000000) ? (IST2PT[7] = time_spent) : (IST2PT[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? IST4PT[0] = time_spent : (n==256) ? IST4PT[1] = time_spent : (n==4096) ? IST4PT[2] = time_spent : (n==65536) ? IST4PT[3] = time_spent : (n==1048576) ? IST4PT[4] = time_spent : (n==16777216) ? IST4PT[5] = time_spent : (n==67108864) ? IST4PT[6] = time_spent : (n==100000000) ? (IST4PT[7] = time_spent) : (IST4PT[7] = 0);
				}
			}
			
			choice2++;
		    }
		    choice2 = 1;
	  }
}

void* LinearSearchUsingOMP(void *receivedArgs, int n){
struct Args *struct_ptr = (struct Args*) receivedArgs;
int j;
struct_ptr->start=0;
struct_ptr->end=n;
clock_t begin = clock();
#pragma omp parallel for
    for(j=struct_ptr->start; j<struct_ptr->end; j++){
        if(struct_ptr->key == struct_ptr->arr[j]){
            struct_ptr->keyFound = j;
        }
    }
clock_t end = clock();
double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
timespent[10] = time_spent;
return 0;
}

void OMPProg(int arr[], int key, int n, int choice){
    int tid, numt;
    
    struct Args threadArgs;
    threadArgs.arr=(int *)malloc(sizeof(int)*n);
    memcpy(threadArgs.arr, arr, n*sizeof(int));
    threadArgs.key = key;
    threadArgs.choice = choice;
    threadArgs.keyFound = -1;
    int choice2=2;
    int from, to;
    int i=0,j=0,noOfThreads=0;
	LinearSearchUsingOMP((void*)&threadArgs, n);
	for(j=0; j<3; j++){
		noOfThreads=(j==0 ? 1 : j==1 ? 2 : j==2 ? 4 : 4);
	    for(i=0; i<4; i++){
	    clock_t begin = clock();
	   #pragma omp parallel default(shared) private(tid) num_threads(noOfThreads)
	   {
	       tid = omp_get_thread_num();
	       numt = omp_get_num_threads();
	
	       threadArgs.start = (n/numt) * tid;
	       threadArgs.end = (n/numt) * (tid + 1);
	       switch(choice2){
	           case 2:
	           {
	               BinarySearchUsingPthreads((void*)&threadArgs);
	               break;
	           }
	           case 3:
	           {
	               TernarySearchUsingPthreads((void*)&threadArgs);
	               break;
	           }
	           case 4:
	           {
	               JumpSearchUsingPthreads((void*)&threadArgs);
	               break;
	           }
	           case 5:
	           {
	               InterpolationSearchUsingPthreads((void*)&threadArgs);
	               break;
	           }
	           default:
	           {
	               break;
	           }
	       }
	   }
		clock_t end = clock();
		double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
		timespent[9+choice2] = time_spent;
			if(choice2==2){
				if(noOfThreads==1){
					(n==16) ? BST1OMP[0] = time_spent : (n==256) ? BST1OMP[1] = time_spent : (n==4096) ? BST1OMP[2] = time_spent : (n==65536) ? BST1OMP[3] = time_spent : (n==1048576) ? BST1OMP[4] = time_spent : (n==16777216) ? BST1OMP[5] = time_spent : (n==67108864) ? BST1OMP[6] = time_spent : (n==100000000) ? (BST1OMP[7] = time_spent) : (BST1OMP[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? BST2OMP[0] = time_spent : (n==256) ? BST2OMP[1] = time_spent : (n==4096) ? BST2OMP[2] = time_spent : (n==65536) ? BST2OMP[3] = time_spent : (n==1048576) ? BST2OMP[4] = time_spent : (n==16777216) ? BST2OMP[5] = time_spent : (n==67108864) ? BST2OMP[6] = time_spent : (n==100000000) ? (BST2OMP[7] = time_spent) : (BST2OMP[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? BST4OMP[0] = time_spent : (n==256) ? BST4OMP[1] = time_spent : (n==4096) ? BST4OMP[2] = time_spent : (n==65536) ? BST4OMP[3] = time_spent : (n==1048576) ? BST4OMP[4] = time_spent : (n==16777216) ? BST4OMP[5] = time_spent : (n==67108864) ? BST4OMP[6] = time_spent : (n==100000000) ? (BST4OMP[7] = time_spent) : (BST4OMP[7] = 0);
				}
			}
			else if(choice2==3){
				if(noOfThreads==1){
					(n==16) ? TST1OMP[0] = time_spent : (n==256) ? TST1OMP[1] = time_spent : (n==4096) ? TST1OMP[2] = time_spent : (n==65536) ? TST1OMP[3] = time_spent : (n==1048576) ? TST1OMP[4] = time_spent : (n==16777216) ? TST1OMP[5] = time_spent : (n==67108864) ? TST1OMP[6] = time_spent : (n==100000000) ? (TST1OMP[7] = time_spent) : (TST1OMP[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? TST2OMP[0] = time_spent : (n==256) ? TST2OMP[1] = time_spent : (n==4096) ? TST2OMP[2] = time_spent : (n==65536) ? TST2OMP[3] = time_spent : (n==1048576) ? TST2OMP[4] = time_spent : (n==16777216) ? TST2OMP[5] = time_spent : (n==67108864) ? TST2OMP[6] = time_spent : (n==100000000) ? (TST2OMP[7] = time_spent) : (TST2OMP[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? TST4OMP[0] = time_spent : (n==256) ? TST4OMP[1] = time_spent : (n==4096) ? TST4OMP[2] = time_spent : (n==65536) ? TST4OMP[3] = time_spent : (n==1048576) ? TST4OMP[4] = time_spent : (n==16777216) ? TST4OMP[5] = time_spent : (n==67108864) ? TST4OMP[6] = time_spent : (n==100000000) ? (TST4OMP[7] = time_spent) : (TST4OMP[7] = 0);
				}
			}
			else if(choice2==4){
				if(noOfThreads==1){
					(n==16) ? JST1OMP[0] = time_spent : (n==256) ? JST1OMP[1] = time_spent : (n==4096) ? JST1OMP[2] = time_spent : (n==65536) ? JST1OMP[3] = time_spent : (n==1048576) ? JST1OMP[4] = time_spent : (n==16777216) ? JST1OMP[5] = time_spent : (n==67108864) ? JST1OMP[6] = time_spent : (n==100000000) ? (JST1OMP[7] = time_spent) : (JST1OMP[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? JST2OMP[0] = time_spent : (n==256) ? JST2OMP[1] = time_spent : (n==4096) ? JST2OMP[2] = time_spent : (n==65536) ? JST2OMP[3] = time_spent : (n==1048576) ? JST2OMP[4] = time_spent : (n==16777216) ? JST2OMP[5] = time_spent : (n==67108864) ? JST2OMP[6] = time_spent : (n==100000000) ? (JST2OMP[7] = time_spent) : (JST2OMP[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? JST4OMP[0] = time_spent : (n==256) ? JST4OMP[1] = time_spent : (n==4096) ? JST4OMP[2] = time_spent : (n==65536) ? JST4OMP[3] = time_spent : (n==1048576) ? JST4OMP[4] = time_spent : (n==16777216) ? JST4OMP[5] = time_spent : (n==67108864) ? JST4OMP[6] = time_spent : (n==100000000) ? (JST4OMP[7] = time_spent) : (JST4OMP[7] = 0);
				}
			}
			else if(choice2==5){
				if(noOfThreads==1){
					(n==16) ? IST1OMP[0] = time_spent : (n==256) ? IST1OMP[1] = time_spent : (n==4096) ? IST1OMP[2] = time_spent : (n==65536) ? IST1OMP[3] = time_spent : (n==1048576) ? IST1OMP[4] = time_spent : (n==16777216) ? IST1OMP[5] = time_spent : (n==67108864) ? IST1OMP[6] = time_spent : (n==100000000) ? (IST1OMP[7] = time_spent) : (IST1OMP[7] = 0);
				}
				else if(noOfThreads==2){
					(n==16) ? IST2OMP[0] = time_spent : (n==256) ? IST2OMP[1] = time_spent : (n==4096) ? IST2OMP[2] = time_spent : (n==65536) ? IST2OMP[3] = time_spent : (n==1048576) ? IST2OMP[4] = time_spent : (n==16777216) ? IST2OMP[5] = time_spent : (n==67108864) ? IST2OMP[6] = time_spent : (n==100000000) ? (IST2OMP[7] = time_spent) : (IST2OMP[7] = 0);
				}
				else if(noOfThreads==4){
					(n==16) ? IST4OMP[0] = time_spent : (n==256) ? IST4OMP[1] = time_spent : (n==4096) ? IST4OMP[2] = time_spent : (n==65536) ? IST4OMP[3] = time_spent : (n==1048576) ? IST4OMP[4] = time_spent : (n==16777216) ? IST4OMP[5] = time_spent : (n==67108864) ? IST4OMP[6] = time_spent : (n==100000000) ? (IST4OMP[7] = time_spent) : (IST4OMP[7] = 0);
				}
			}
		   choice2++;
		}
		choice2=2;
	}

}
