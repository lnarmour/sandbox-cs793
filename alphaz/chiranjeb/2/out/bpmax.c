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
double reduce_bpmax_C_1(long, int, int, double**, double**);
double reduce_bpmax_D_1(long, int, int, double**, double**);

//Memory Macros
#define A(i,j) A[i][j]
#define B(i,j) B[i][j]
#define D(i,j) D[i][j]

void bpmax(long N, double** A, double** B, double** D){
	///Parameter checking
	if (!((N >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	
	#define S0(i,j,i2) D(j+7,i2+17) = reduce_bpmax_C_1(N,j,i2,A,B)
	#define S1(i,j,i2) D(j,i2) = reduce_bpmax_D_1(N,j,i2,A,B)
	{
		//Domain
		//{i,j,i2|i==N+1 && N>=2 && j>=0 && N>=j+1 && i2>=0 && N>=i2+1}
		//{i,j,i2|i==N+1 && N>=2 && j>=0 && N>=j+1 && i2>=0 && N>=i2+1}
		int c2,c3;
		for(c2=0;c2 <= N-1;c2+=1)
		 {
		 	for(c3=0;c3 <= N-1;c3+=1)
		 	 {
		 	 	S0((N+1),(c2),(c3));
		 	 	S1((N+1),(c2),(c3));
		 	 }
		 }
	}
	#undef S0
	#undef S1
	
	//Memory Free
}
double reduce_bpmax_C_1(long N, int ip, int jp, double** A, double** B){
	double reduceVar = 0;
	#define S1(i,j,k) reduceVar = (reduceVar)+((A(i,k))*(B(k,j)))
	{
		//Domain
		//{i,j,k|N>=2 && ip>=0 && N>=ip+1 && jp>=0 && N>=jp+1 && i>=0 && k>=0 && N>=i+1 && N>=k+1 && j>=0 && N>=j+1 && ip==i && jp==j}
		int c3;
		for(c3=0;c3 <= N-1;c3+=1)
		 {
		 	S1((ip),(jp),(c3));
		 }
	}
	#undef S1
	return reduceVar;
}
double reduce_bpmax_D_1(long N, int ip, int jp, double** A, double** B){
	double reduceVar = 0;
	#define S2(i,j,k) reduceVar = (reduceVar)+((A(i,k))*(B(k,j)))
	{
		//Domain
		//{i,j,k|N>=2 && ip>=0 && N>=ip+1 && jp>=0 && N>=jp+1 && i>=0 && k>=0 && N>=i+1 && N>=k+1 && j>=0 && N>=j+1 && ip==i && jp==j}
		int c3;
		for(c3=0;c3 <= N-1;c3+=1)
		 {
		 	S2((ip),(jp),(c3));
		 }
	}
	#undef S2
	return reduceVar;
}

//Memory Macros
#undef A
#undef B
#undef D


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
