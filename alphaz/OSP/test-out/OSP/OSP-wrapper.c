// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <omp.h>


// Common Macros
#define max(x, y)   ((x)>(y) ? (x) : (y))
#define MAX(x, y)	((x)>(y) ? (x) : (y))
#define min(x, y)   ((x)>(y) ? (y) : (x))
#define MIN(x, y)	((x)>(y) ? (y) : (x))
#define CEILD(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define ceild(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define FLOORD(n,d) (int)floor(((double)(n))/((double)(d)))
#define floord(n,d) (int)floor(((double)(n))/((double)(d)))
#define CDIV(x,y)    CEILD((x),(y))
#define div(x,y)    CDIV((x),(y))
#define FDIV(x,y)    FLOORD((x),(y))
#define LB_SHIFT(b,s)  ((int)ceild(b,s) * s)
#define MOD(i,j)   ((i)%(j))
#define mallocCheck(v,s,d) if ((v) == NULL) { printf("Failed to allocate memory for %s : size=%lu\n", "sizeof(d)*(s)", sizeof(d)*(s)); exit(-1); }
#define EPSILON 1.0E-9







//Memory Macros
#define P(i) P[i]
#define M(i,j) M[i][j]
#define S(i,j) S[i][j]

#define M_verify(i,j) M_verify[i][j]
#define S_verify(i,j) S_verify[i][j]
#define var_M(i,j) M(i,j)
#define var_M_verify(i,j) M_verify(i,j)
#define var_S(i,j) S(i,j)
#define var_S_verify(i,j) S_verify(i,j)

//function prototypes
void OSP(long, int*, int**, int**);
void OSP_verify(long, int*, int**, int**);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 1) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting N\n");
		exit(0);
	}
	
	char *end = 0;
	char *val = 0;
	//Read Parameters
	//Initialisation of N
	errno = 0;
	end = 0;
	val = argv[1];
	long N = strtol(val,&end,10);
	if ((errno == ERANGE && (N == LONG_MAX || N == LONG_MIN)) || (errno != 0 && N == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N: Converted part: %ld, non-convertible part: %s\n", N, end);
		exit(EXIT_FAILURE);
	}
	
	
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2;
	int* P = (int*)malloc(sizeof(int[N+1][N+1]));
	mallocCheck(P, (N+1), int);
	int* _lin_M = (int*)malloc(sizeof(int)*N^2);
	int** M = (int**)malloc(sizeof(int*[N+1][N+1]));
	mallocCheck(M, (N+1), int*);
	for (mz1=0;mz1 < N+1; mz1++) {
		M[mz1] = &_lin_M[(mz1*(N+1))];
	}
	int* _lin_S = (int*)malloc(sizeof(int)*(1 - 2 * N + N^2));
	int** S = (int**)malloc(sizeof(int*[N][N]));
	mallocCheck(S, (N), int*);
	for (mz1=0;mz1 < N; mz1++) {
		S[mz1] = &_lin_S[(mz1*(N+1))];
	}
	#ifdef VERIFY
		int* _lin_M_verify = (int*)malloc(sizeof(int)*N^2);
		int** M_verify = (int**)malloc(sizeof(int*[N+1][N+1]));
		mallocCheck(M_verify, (N+1), int*);
		for (mz1=0;mz1 < N+1; mz1++) {
			M_verify[mz1] = &_lin_M_verify[(mz1*(N+1))];
		}
		int* _lin_S_verify = (int*)malloc(sizeof(int)*(1 - 2 * N + N^2));
		int** S_verify = (int**)malloc(sizeof(int*[N][N]));
		mallocCheck(S_verify, (N), int*);
		for (mz1=0;mz1 < N; mz1++) {
			S_verify[mz1] = &_lin_S_verify[(mz1*(N+1))];
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i) (P(i) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%d", &P(i))
			#else
				#define S0(i) printf("P(%ld)=",(long) i); scanf("%d", &P(i))
			#endif
		#else
			#define S0(i) (P(i) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	OSP(N, P, M, S);

	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;

	// timing information
	printf("Execution time : %lf sec.\n", elapsed_time);
	
	#ifdef TIMING
		FILE * fp = fopen( "trace.dat","a+");
		if (fp == NULL) {
				printf("I couldn't open trace.dat for writing.\n");
				exit(EXIT_FAILURE);
		}
		fprintf(fp, "%ld\t%lf\n",N,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	OSP_verify(N, P, M_verify, S_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%lf\n",N,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		
		{
			#ifdef NO_PROMPT
				#define S0(i,j) printf("%d\n",var_M(i,j))
			#else
				#define S0(i,j) printf("M(%ld,%ld)=",(long) i,(long) j);printf("%d\n",var_M(i,j))
			#endif
			int c1,c2;
			for(c1=1;c1 <= N;c1+=1)
			 {
			 	for(c2=1;c2 <= N;c2+=1)
			 	 {
			 	 	S0((c1),(c2));
			 	 }
			 }
			#undef S0
		}
		
		{
			#ifdef NO_PROMPT
				#define S0(i,j) printf("%d\n",var_S(i,j))
			#else
				#define S0(i,j) printf("S(%ld,%ld)=",(long) i,(long) j);printf("%d\n",var_S(i,j))
			#endif
			int c1,c2;
			if ((N >= 2)) {
				{
					for(c1=1;c1 <= N-1;c1+=1)
					 {
					 	for(c2=2;c2 <= N;c2+=1)
					 	 {
					 	 	S0((c1),(c2));
					 	 }
					 }
				}
			}
			#undef S0
		}
	#elif VERIFY
		//Compare outputs for verification
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(i,j) if (var_M_verify(i,j)!=var_M(i,j)) _errors_++;
			int c1,c2;
			for(c1=1;c1 <= N;c1+=1)
			 {
			 	for(c2=1;c2 <= N;c2+=1)
			 	 {
			 	 	S0((c1),(c2));
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for M PASSED\n");
			}else{
				printf("TEST for M FAILED. #Errors: %d\n", _errors_);
			}
		}
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(i,j) if (var_S_verify(i,j)!=var_S(i,j)) _errors_++;
			int c1,c2;
			if ((N >= 2)) {
				{
					for(c1=1;c1 <= N-1;c1+=1)
					 {
					 	for(c2=2;c2 <= N;c2+=1)
					 	 {
					 	 	S0((c1),(c2));
					 	 }
					 }
				}
			}
			#undef S0
			if(_errors_ == 0){
				printf("TEST for S PASSED\n");
			}else{
				printf("TEST for S FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(P);
	free(_lin_M);
	free(M);
	free(_lin_S);
	free(S);
	#ifdef VERIFY
		free(_lin_M_verify);
		free(M_verify);
		free(_lin_S_verify);
		free(S_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef P
#undef M
#undef S


//Common Macro undefs
#undef max
#undef MAX
#undef min
#undef MIN
#undef CEILD
#undef ceild
#undef FLOORD
#undef floord
#undef CDIV
#undef FDIV
#undef LB_SHIFT
#undef MOD
#undef EPSILON
