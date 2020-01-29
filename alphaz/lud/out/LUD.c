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
#include <omp.h>
#include <immintrin.h>
#include <malloc.h>


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
// Reduction Operators
#define RADD(x,y)    ((x)+=(y))
#define RMUL(x,y)    ((x)*=(y))
#define RMAX(x,y)    ((x)=MAX((x),(y)))
#define RMIN(x,y)    ((x)=MIN((x),(y)))

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





//Local Function Declarations
float reduce_LUD_U_1(long, int, int, float**, float**);
float reduce_LUD_L_1(long, int, int, float**, float**);

//Memory Macros
#define A(i,j) A[i][j]
#define L(i,j) L[i][j]
#define U(i,j) U[i][j]

void LUD(long N, float** A, float** L, float** U){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j) U(i,j) = A(i,j)
	#define S1(i,j) U(i,j) = (A(i,j))-(reduce_LUD_U_1(N,i,j,L,U))
	#define S2(i,j) L(i,j) = (A(i,j))/(U(j,j))
	#define S3(i,j) L(i,j) = ((A(i,j))-(reduce_LUD_L_1(N,i,j,L,U)))/(U(j,j))
	{
		//Domain
		//{i,j|i==1 && N>=1 && j>=1 && N>=j}
		//{i,j|i>=2 && N>=1 && N>=j && N>=i && j>=1 && j>=i}
		//{i,j|j==1 && N>=1 && i>=2 && N>=i}
		//{i,j|j>=2 && N>=1 && i>=2 && N>=i && N>=j && i>=j+1}
		int c1,c2;
		for(c2=1;c2 <= N;c2+=1)
		 {
		 	S0((1),(c2));
		 }
		if ((N >= 2)) {
			{
				S2((2),(1));
				for(c2=2;c2 <= N;c2+=1)
				 {
				 	S1((2),(c2));
				 }
			}
		}
		for(c1=3;c1 <= N;c1+=1)
		 {
		 	S2((c1),(1));
		 	for(c2=2;c2 <= c1-1;c2+=1)
		 	 {
		 	 	S3((c1),(c2));
		 	 }
		 	for(c2=c1;c2 <= N;c2+=1)
		 	 {
		 	 	S1((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	
	//Memory Free
}
float reduce_LUD_U_1(long N, int ip, int jp, float** L, float** U){
	float reduceVar = 0;
	#define S0(i,j,k) reduceVar = (reduceVar)+((L(i,k))*(U(k,j)))
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
float reduce_LUD_L_1(long N, int ip, int jp, float** L, float** U){
	float reduceVar = 0;
	#define S0(i,j,k) reduceVar = (reduceVar)+((L(i,k))*(U(k,j)))
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

//Memory Macros
#undef A
#undef L
#undef U


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
#undef RADD
#undef RMUL
#undef RMAX
#undef RMIN
