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
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(i,j) S1[i][j]
#define S2(i,j) S2[i][j]
#define NR_FTable(i1,j1,i2,j2) NR_FTable[i1][j1][i2][j2]
#define FTable(i1,j1,i2,j2) FTable[i1][j1][i2][j2]

#define FTable_verify(i1,j1,i2,j2) FTable_verify[i1][j1][i2][j2]
#define var_FTable(i1,j1,i2,j2) FTable(i1,j1,i2,j2)
#define var_FTable_verify(i1,j1,i2,j2) FTable_verify(i1,j1,i2,j2)

//function prototypes
void bpmax(long, long, int*, int*, double****);
void bpmax_verify(long, long, int*, int*, double****);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 2) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting M,N\n");
		exit(0);
	}
	
	char *end = 0;
	char *val = 0;
	//Read Parameters
	//Initialisation of M
	errno = 0;
	end = 0;
	val = argv[1];
	long M = strtol(val,&end,10);
	if ((errno == ERANGE && (M == LONG_MAX || M == LONG_MIN)) || (errno != 0 && M == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for M\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter M: Converted part: %ld, non-convertible part: %s\n", M, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of N
	errno = 0;
	end = 0;
	val = argv[2];
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
	if (!((M >= 3 && N >= 3))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	int* seq1 = (int*)malloc(sizeof(int)*(M));
	mallocCheck(seq1, (M), int);
	int* seq2 = (int*)malloc(sizeof(int)*(N));
	mallocCheck(seq2, (N), int);
	double* _lin_FTable = (double*)malloc(sizeof(double)*((M) * (M) * (N) * (N)));
	mallocCheck(_lin_FTable, ((M) * (M) * (N) * (N)), double);
	double**** FTable = (double****)malloc(sizeof(double***)*(M));
	mallocCheck(FTable, (M), double***);
	for (mz1=0;mz1 < M; mz1++) {
		FTable[mz1] = (double***)malloc(sizeof(double**)*(M));
		mallocCheck(FTable[mz1], (M), double**);
		for (mz2=0;mz2 < M; mz2++) {
			FTable[mz1][mz2] = (double**)malloc(sizeof(double*)*(N));
			mallocCheck(FTable[mz1][mz2], (N), double*);
			for (mz3=0;mz3 < N; mz3++) {
				FTable[mz1][mz2][mz3] = &_lin_FTable[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
			}
		}
	}
	#ifdef VERIFY
		double* _lin_FTable_verify = (double*)malloc(sizeof(double)*((M) * (M) * (N) * (N)));
		mallocCheck(_lin_FTable_verify, ((M) * (M) * (N) * (N)), double);
		double**** FTable_verify = (double****)malloc(sizeof(double***)*(M));
		mallocCheck(FTable_verify, (M), double***);
		for (mz1=0;mz1 < M; mz1++) {
			FTable_verify[mz1] = (double***)malloc(sizeof(double**)*(M));
			mallocCheck(FTable_verify[mz1], (M), double**);
			for (mz2=0;mz2 < M; mz2++) {
				FTable_verify[mz1][mz2] = (double**)malloc(sizeof(double*)*(N));
				mallocCheck(FTable_verify[mz1][mz2], (N), double*);
				for (mz3=0;mz3 < N; mz3++) {
					FTable_verify[mz1][mz2][mz3] = &_lin_FTable_verify[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
				}
			}
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i) (seq1(i) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%d", &seq1(i))
			#else
				#define S0(i) printf("seq1(%ld)=",(long) i); scanf("%d", &seq1(i))
			#endif
		#else
			#define S0(i) (seq1(i) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= M-1;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	{
		#if defined (RANDOM)
			#define S0(i) (seq2(i) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%d", &seq2(i))
			#else
				#define S0(i) printf("seq2(%ld)=",(long) i); scanf("%d", &seq2(i))
			#endif
		#else
			#define S0(i) (seq2(i) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= N-1;c1+=1)
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
	
	bpmax(M, N, seq1, seq2, FTable);

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
		fprintf(fp, "%ld\t%ld\t%lf\n",M,N,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	bpmax_verify(M, N, seq1, seq2, FTable_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%ld\t%lf\n",M,N,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		
		{
			#ifdef NO_PROMPT
				#define S0(i1,j1,i2,j2) printf("%0.2lf\n",var_FTable(i1,j1,i2,j2))
			#else
				#define S0(i1,j1,i2,j2) printf("FTable(%ld,%ld,%ld,%ld)=",(long) i1,(long) j1,(long) i2,(long) j2);printf("%0.2lf\n",var_FTable(i1,j1,i2,j2))
			#endif
			int c1,c2,c3,c4;
			for(c1=0;c1 <= M-1;c1+=1)
			 {
			 	for(c2=c1;c2 <= M-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N-1;c3+=1)
			 	 	 {
			 	 	 	for(c4=c3;c4 <= N-1;c4+=1)
			 	 	 	 {
			 	 	 	 	S0((c1),(c2),(c3),(c4));
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
			#define S0(i1,j1,i2,j2) if (fabs(1.0 - var_FTable_verify(i1,j1,i2,j2)/var_FTable(i1,j1,i2,j2)) > EPSILON) _errors_++;
			int c1,c2,c3,c4;
			for(c1=0;c1 <= M-1;c1+=1)
			 {
			 	for(c2=c1;c2 <= M-1;c2+=1)
			 	 {
			 	 	for(c3=0;c3 <= N-1;c3+=1)
			 	 	 {
			 	 	 	for(c4=c3;c4 <= N-1;c4+=1)
			 	 	 	 {
			 	 	 	 	S0((c1),(c2),(c3),(c4));
			 	 	 	 }
			 	 	 }
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for FTable PASSED\n");
			}else{
				printf("TEST for FTable FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(seq1);
	free(seq2);
	free(_lin_FTable);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(FTable[mz1][mz2]);
		}
		free(FTable[mz1]);
	}
	free(FTable);
	#ifdef VERIFY
		free(_lin_FTable_verify);
		for (mz1=0;mz1 < M; mz1++) {
			for (mz2=0;mz2 < M; mz2++) {
				free(FTable_verify[mz1][mz2]);
			}
			free(FTable_verify[mz1]);
		}
		free(FTable_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef NR_FTable
#undef FTable


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
