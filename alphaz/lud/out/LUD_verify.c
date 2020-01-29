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
static float** A;
static float** L;
static float** U;
static char** _flag_L;
static char** _flag_U;


//Local Function Declarations
float reduce_LUD_verify_U_1(long, int, int);
float eval_U(long, int, int);
float reduce_LUD_verify_L_1(long, int, int);
float eval_L(long, int, int);

//Memory Macros
#define A(i,j) A[i][j]
#define L(i,j) L[i][j]
#define U(i,j) U[i][j]
#define _flag_L(i,j) _flag_L[i][j]
#define _flag_U(i,j) _flag_U[i][j]

void LUD_verify(long N, float** _local_A, float** _local_L, float** _local_U){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	A = _local_A;
	L = _local_L;
	U = _local_U;
	
	//Memory Allocation
	int mz1, mz2;
	
	char* _lin__flag_L = (char*)malloc(sizeof(char)*((N+1) * (N)));
	mallocCheck(_lin__flag_L, ((N+1) * (N)), char);
	_flag_L = (char**)malloc(sizeof(char*)*(N+1));
	mallocCheck(_flag_L, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_L[mz1] = &_lin__flag_L[(mz1*(N))];
	}
	memset(_lin__flag_L, 'N', ((N+1) * (N)));
	
	char* _lin__flag_U = (char*)malloc(sizeof(char)*((N+1) * (N+1)));
	mallocCheck(_lin__flag_U, ((N+1) * (N+1)), char);
	_flag_U = (char**)malloc(sizeof(char*)*(N+1));
	mallocCheck(_flag_U, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_U[mz1] = &_lin__flag_U[(mz1*(N+1))];
	}
	memset(_lin__flag_U, 'N', ((N+1) * (N+1)));
	#define S0(i,j) eval_L(N,i,j)
	{
		//Domain
		//{i,j|i>=2 && N>=i && j>=1 && i>=j+1 && N>=1}
		int c1,c2;
		if ((N >= 2)) {
			{
				for(c1=2;c1 <= N;c1+=1)
				 {
				 	for(c2=1;c2 <= c1-1;c2+=1)
				 	 {
				 	 	S0((c1),(c2));
				 	 }
				 }
			}
		}
	}
	#undef S0
	#define S0(i,j) eval_U(N,i,j)
	{
		//Domain
		//{i,j|j>=1 && N>=j && i>=1 && j>=i && N>=1}
		int c1,c2;
		for(c1=1;c1 <= N;c1+=1)
		 {
		 	for(c2=c1;c2 <= N;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_L);
	free(_flag_L);
	
	free(_lin__flag_U);
	free(_flag_U);
}
float reduce_LUD_verify_U_1(long N, int ip, int jp){
	float reduceVar = 0;
	#define S0(i,j,k) reduceVar = (reduceVar)+((eval_L(N,i,k))*(eval_U(N,k,j)))
	{
		//Domain
		//{i,j,k|N>=jp && ip>=2 && N>=ip && jp>=1 && jp>=ip && N>=1 && i>=2 && N>=i && k>=1 && i>=k+1 && j>=i && j>=1 && N>=j && j>=k && ip==i && jp==j}
		int c3;
		for(c3=1;c3 <= ip-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
float eval_U(long N, int i, int j){
	if ( _flag_U(i,j) == 'N' ) {
		_flag_U(i,j) = 'I';
	//Body for U
		U(i,j) = (((i == 1))?A(i,j):((A(i,j))-(reduce_LUD_verify_U_1(N,i,j))));
		_flag_U(i,j) = 'F';
	} else if ( _flag_U(i,j) == 'I' ) {
		printf("There is a self dependence on U at (%d,%d) \n",i,j);
		exit(-1);
	}
	return U(i,j);
}
float reduce_LUD_verify_L_1(long N, int ip, int jp){
	float reduceVar = 0;
	#define S0(i,j,k) reduceVar = (reduceVar)+((eval_L(N,i,k))*(eval_U(N,k,j)))
	{
		//Domain
		//{i,j,k|N>=jp && ip>=2 && N>=ip && jp>=2 && ip>=jp+1 && N>=1 && k>=1 && j>=k+1 && i>=j+1 && i>=2 && N>=i && N>=j && i>=k+1 && j>=2 && ip==i && jp==j}
		int c3;
		for(c3=1;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
float eval_L(long N, int i, int j){
	if ( _flag_L(i,j) == 'N' ) {
		_flag_L(i,j) = 'I';
	//Body for L
		L(i,j) = (((j == 1))?(A(i,j))/(eval_U(N,j,j)):(((A(i,j))-(reduce_LUD_verify_L_1(N,i,j)))/(eval_U(N,j,j))));
		_flag_L(i,j) = 'F';
	} else if ( _flag_L(i,j) == 'I' ) {
		printf("There is a self dependence on L at (%d,%d) \n",i,j);
		exit(-1);
	}
	return L(i,j);
}

//Memory Macros
#undef A
#undef L
#undef U
#undef _flag_L
#undef _flag_U


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
