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
static int* D;
static int** X;
static int** Y;
static char** _flag_X;
static char** _flag_Y;


//Local Function Declarations
int eval_X(long, int, int);
int eval_Y(long, int, int);

//Memory Macros
#define D(i) D[i]
#define X(i,j) X[i][j]
#define Y(i,j) Y[i][j]
#define _flag_X(i,j) _flag_X[i][j]
#define _flag_Y(i,j) _flag_Y[i][j]

void Sched0(long N, int* _local_D, int** _local_X, int** _local_Y){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	D = _local_D;
	X = _local_X;
	Y = _local_Y;
	
	//Memory Allocation
	int mz1, mz2;
	
	char* _lin__flag_X = (char*)malloc(sizeof(char)*((N+1) * (N+1)));
	mallocCheck(_lin__flag_X, ((N+1) * (N+1)), char);
	_flag_X = (char**)malloc(sizeof(char*)*(N+1));
	mallocCheck(_flag_X, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_X[mz1] = &_lin__flag_X[(mz1*(N+1))];
	}
	memset(_lin__flag_X, 'N', ((N+1) * (N+1)));
	
	char* _lin__flag_Y = (char*)malloc(sizeof(char)*((N) * (N)));
	mallocCheck(_lin__flag_Y, ((N) * (N)), char);
	_flag_Y = (char**)malloc(sizeof(char*)*(N));
	mallocCheck(_flag_Y, (N), char*);
	for (mz1=0;mz1 < N; mz1++) {
		_flag_Y[mz1] = &_lin__flag_Y[(mz1*(N))];
	}
	memset(_lin__flag_Y, 'N', ((N) * (N)));
	#define S0(i,j) eval_X(N,i,j)
	{
		//Domain
		//{i,j|i>=0 && j>=0 && N>=i+j && N>=1}
		int c1,c2;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	for(c2=0;c2 <= -c1+N;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	#define S0(i,j) eval_Y(N,i,j)
	{
		//Domain
		//{i,j|i>=0 && j>=0 && N>=i+j+1 && N>=1}
		int c1,c2;
		for(c1=0;c1 <= N-1;c1+=1)
		 {
		 	for(c2=0;c2 <= -c1+N-1;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_X);
	free(_flag_X);
	
	free(_lin__flag_Y);
	free(_flag_Y);
}
int eval_X(long N, int i, int j){
	if ( _flag_X(i,j) == 'N' ) {
		_flag_X(i,j) = 'I';
	//Body for X
		X(i,j) = (((i+j == N))?D(i):(((j == 0))?0:((eval_Y(N,j-1,i))+(7))));
		_flag_X(i,j) = 'F';
	} else if ( _flag_X(i,j) == 'I' ) {
		printf("There is a self dependence on X at (%d,%d) \n",i,j);
		exit(-1);
	}
	return X(i,j);
}
int eval_Y(long N, int i, int j){
	if ( _flag_Y(i,j) == 'N' ) {
		_flag_Y(i,j) = 'I';
	//Body for Y
		Y(i,j) = (((i == 0))?1:((eval_X(N,j,i-1))+(3)));
		_flag_Y(i,j) = 'F';
	} else if ( _flag_Y(i,j) == 'I' ) {
		printf("There is a self dependence on Y at (%d,%d) \n",i,j);
		exit(-1);
	}
	return Y(i,j);
}

//Memory Macros
#undef D
#undef X
#undef Y
#undef _flag_X
#undef _flag_Y


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
