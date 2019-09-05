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

// Common functions for min and max
//functions for integer max
inline int __max_int(int x, int y){
	return ((x)>(y) ? (x) : (y));
}

inline short __max_short(short x, short y){
	return ((x)>(y) ? (x) : (y));
}

inline long __max_long(long x, long y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned int __max_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned short __max_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (x) : (y));
}

//function for float max
inline float __max_float(float x, float y){
	return ((x)>(y) ? (x) : (y));
}

//function for double max
inline double __max_double(double x, double y){
	return ((x)>(y) ? (x) : (y));
}

//function for integer min
inline int __min_int(int x, int y){
	return ((x)>(y) ? (y) : (x));
}

inline short __min_short(short x, short y){
	return ((x)>(y) ? (y) : (x));
}

inline long __min_long(long x, long y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned int __min_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned short __min_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned long __min_unsigned_long(unsigned long x, unsigned long y){
	return ((x)>(y) ? (y) : (x));
}

inline float __min_float(float x, float y){
	return ((x)>(y) ? (y) : (x));
}

inline double __min_double(double x, double y){
	return ((x)>(y) ? (y) : (x));
}



///Global Variables
static int* P;
static int** M;
static int** S;
static char** _flag_M;
static char** _flag_S;


//Local Function Declarations
int reduce_OSP_M_1(long, int, int);
int eval_M(long, int, int);
int reduce_OSP_S_1(long, int, int);
int eval_S(long, int, int);

//Memory Macros
#define P(i) P[i]
#define M(i,j) M[i][j]
#define S(i,j) S[i][j]
#define _flag_M(i,j) _flag_M[i][j]
#define _flag_S(i,j) _flag_S[i][j]

void OSP(long N, int* _local_P, int** _local_M, int** _local_S){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	P = _local_P;
	M = _local_M;
	S = _local_S;
	
	//Memory Allocation
	int mz1, mz2;
	
	char* _lin__flag_M = (char*)malloc(sizeof(char)*N^2);
	_flag_M = (char**)malloc(sizeof(char*[N+1][N+1]));
	mallocCheck(_flag_M, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_M[mz1] = &_lin__flag_M[(mz1*(N+1))];
	}
	memset(_lin__flag_M, 'N', ((N+1) * (N+1)));
	
	char* _lin__flag_S = (char*)malloc(sizeof(char)*(1 - 2 * N + N^2));
	_flag_S = (char**)malloc(sizeof(char*[N][N]));
	mallocCheck(_flag_S, (N), char*);
	for (mz1=0;mz1 < N; mz1++) {
		_flag_S[mz1] = &_lin__flag_S[(mz1*(N+1))];
	}
	memset(_lin__flag_S, 'N', ((N) * (N+1)));
	#define S0(i,j) eval_M(N,i,j)
	{
		//Domain
		//{i,j|i>=1 && N>=i && j>=1 && N>=j && N>=1}
		int c1,c2;
		for(c1=1;c1 <= N;c1+=1)
		 {
		 	for(c2=1;c2 <= N;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	#define S0(i,j) eval_S(N,i,j)
	{
		//Domain
		//{i,j|i>=1 && N>=i+1 && j>=2 && N>=j && N>=1}
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
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_M);
	free(_flag_M);
	
	free(_lin__flag_S);
	free(_flag_S);
}
int reduce_OSP_M_1(long N, int ip, int jp){
	int reduceVar = INT_MAX;
	#define S0(i,j,k) {int __temp__ = ((eval_M(N,i,k))+(eval_M(N,k+1,j)))+(((P(i-1))*(P(k)))*(P(j))); reduceVar = __min_int(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|ip>=1 && jp>=ip+1 && N>=jp && i>=1 && N>=j && k>=i && j>=k+1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
int eval_M(long N, int i, int j){
	if ( _flag_M(i,j) == 'N' ) {
		_flag_M(i,j) = 'I';
	//Body for M
		M(i,j) = (((i >= j+1))?0:(((j == i))?0:(reduce_OSP_M_1(N,i,j))));
		_flag_M(i,j) = 'F';
	} else if ( _flag_M(i,j) == 'I' ) {
		printf("There is a self dependence on M at (%d,%d) \n",i,j);
		exit(-1);
	}
	return M(i,j);
}
int reduce_OSP_S_1(long N, int ip, int jp){
	int reduceVar = INT_MAX;
	#define S0(i,j,k) {int __temp__ = ((eval_M(N,i,k))+(eval_M(N,k+1,j)))+(((P(i-1))*(P(k)))*(P(j))); reduceVar = __min_int(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|ip>=1 && jp>=ip+1 && N>=jp && i>=1 && N>=j && k>=i && j>=k+1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
int eval_S(long N, int i, int j){
	if ( _flag_S(i,j) == 'N' ) {
		_flag_S(i,j) = 'I';
	//Body for S
		S(i,j) = (((i >= j+1))?0:(((j == i))?0:(reduce_OSP_S_1(N,i,j))));
		_flag_S(i,j) = 'F';
	} else if ( _flag_S(i,j) == 'I' ) {
		printf("There is a self dependence on S at (%d,%d) \n",i,j);
		exit(-1);
	}
	return S(i,j);
}

//Memory Macros
#undef P
#undef M
#undef S
#undef _flag_M
#undef _flag_S


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
