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
static float*** X;
static char*** _flag_X;


//Local Function Declarations
float eval_X(long, long, int, int, int);

//Memory Macros
#define X(t,i,j) X[MOD(t,2)][i][j]
#define _flag_X(t,i,j) _flag_X[MOD(t,2)][i][j]

void star_verify(long N, long T, float*** _local_X){
	///Parameter checking
	if (!((T >= 6 && N >= 10))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	X = _local_X;
	
	//Memory Allocation
	int mz1, mz2, mz3;
	
	char* _lin__flag_X = (char*)malloc(sizeof(char)*((2) * (N) * (N)));
	mallocCheck(_lin__flag_X, ((2) * (N) * (N)), char);
	_flag_X = (char***)malloc(sizeof(char**)*(2));
	mallocCheck(_flag_X, (2), char**);
	for (mz1=0;mz1 < 2; mz1++) {
		_flag_X[mz1] = (char**)malloc(sizeof(char*)*(N));
		mallocCheck(_flag_X[mz1], (N), char*);
		for (mz2=0;mz2 < N; mz2++) {
			_flag_X[mz1][mz2] = &_lin__flag_X[(mz1*((N) * (N))) + (mz2*(N))];
		}
	}
	memset(_lin__flag_X, 'N', ((2) * (N) * (N)));
	#define S0(t,i,j) eval_X(N,T,t,i,j)
	{
		//Domain
		//{t,i,j|i>=0 && j>=0 && N>=i+1 && N>=j+1 && t>=0 && T>=t+1 && T>=6 && N>=10}
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
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_X);
	for (mz1=0;mz1 < 2; mz1++) {
		free(_flag_X[mz1]);
	}
	free(_flag_X);
}
float eval_X(long N, long T, int t, int i, int j){
	if ( _flag_X(t,i,j) == 'N' ) {
		_flag_X(t,i,j) = 'I';
	//Body for X
		X(t,i,j) = ((((eval_X(N,T,t-1,i,j))+(eval_X(N,T,t-1,i-1,j)))+(eval_X(N,T,t-1,i,j-1)))+(eval_X(N,T,t-1,i+1,j)))+(eval_X(N,T,t-1,i,j+1));
		_flag_X(t,i,j) = 'F';
	} else if ( _flag_X(t,i,j) == 'I' ) {
		printf("There is a self dependence on X at (%d,%d,%d) \n",t,i,j);
		exit(-1);
	}
	return X(t,i,j);
}

//Memory Macros
#undef X
#undef _flag_X


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
