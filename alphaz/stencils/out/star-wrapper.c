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
#define X(t,i,j) X[MOD(t,2)][i][j]

#define X_verify(t,i,j) X_verify[MOD(t,2)][i][j]
#define var_X(t,i,j) X(t,i,j)
#define var_X_verify(t,i,j) X_verify(t,i,j)

//function prototypes
void star(long, long, float***);
void star_verify(long, long, float***);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 2) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting N,T\n");
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
	
	//Initialisation of T
	errno = 0;
	end = 0;
	val = argv[2];
	long T = strtol(val,&end,10);
	if ((errno == ERANGE && (T == LONG_MAX || T == LONG_MIN)) || (errno != 0 && T == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for T\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter T: Converted part: %ld, non-convertible part: %s\n", T, end);
		exit(EXIT_FAILURE);
	}
	
	
	///Parameter checking
	if (!((T >= 6 && N >= 10))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2, mz3;
	float* _lin_X = (float*)malloc(sizeof(float)*((2) * (N) * (N)));
	mallocCheck(_lin_X, ((2) * (N) * (N)), float);
	float*** X = (float***)malloc(sizeof(float**)*(2));
	mallocCheck(X, (2), float**);
	for (mz1=0;mz1 < 2; mz1++) {
		X[mz1] = (float**)malloc(sizeof(float*)*(N));
		mallocCheck(X[mz1], (N), float*);
		for (mz2=0;mz2 < N; mz2++) {
			X[mz1][mz2] = &_lin_X[(mz1*((N) * (N))) + (mz2*(N))];
		}
	}
	#ifdef VERIFY
		float* _lin_X_verify = (float*)malloc(sizeof(float)*((2) * (N) * (N)));
		mallocCheck(_lin_X_verify, ((2) * (N) * (N)), float);
		float*** X_verify = (float***)malloc(sizeof(float**)*(2));
		mallocCheck(X_verify, (2), float**);
		for (mz1=0;mz1 < 2; mz1++) {
			X_verify[mz1] = (float**)malloc(sizeof(float*)*(N));
			mallocCheck(X_verify[mz1], (N), float*);
			for (mz2=0;mz2 < N; mz2++) {
				X_verify[mz1][mz2] = &_lin_X_verify[(mz1*((N) * (N))) + (mz2*(N))];
			}
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	star(N, T, X);

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
		fprintf(fp, "%ld\t%ld\t%lf\n",N,T,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	star_verify(N, T, X_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%ld\t%lf\n",N,T,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		
		{
			#ifdef NO_PROMPT
				#define S0(t,i,j) printf("%0.2f\n",var_X(t,i,j))
			#else
				#define S0(t,i,j) printf("X(%ld,%ld,%ld)=",(long) t,(long) i,(long) j);printf("%0.2f\n",var_X(t,i,j))
			#endif
			int c1,c2,c3;
			for(c1=0;c1 <= T-1;c1+=1)
			 {
			 	for(c2=0;c2 <= N-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N-1;c3+=1)
			 	 	 {
			 	 	 	S0((c1),(c2),(c3));
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
			#define S0(t,i,j) if (fabsf(1.0f - var_X_verify(t,i,j)/var_X(t,i,j)) > EPSILON) _errors_++;
			int c1,c2,c3;
			for(c1=0;c1 <= T-1;c1+=1)
			 {
			 	for(c2=0;c2 <= N-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N-1;c3+=1)
			 	 	 {
			 	 	 	S0((c1),(c2),(c3));
			 	 	 }
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for X PASSED\n");
			}else{
				printf("TEST for X FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(_lin_X);
	for (mz1=0;mz1 < 2; mz1++) {
		free(X[mz1]);
	}
	free(X);
	#ifdef VERIFY
		free(_lin_X_verify);
		for (mz1=0;mz1 < 2; mz1++) {
			free(X_verify[mz1]);
		}
		free(X_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef X


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
