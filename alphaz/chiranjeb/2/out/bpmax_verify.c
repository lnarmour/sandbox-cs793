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

#include "external_functions.h"

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
static int* seq1;
static int* seq2;
static double** S1;
static double** S2;
static double**** NR_FTable;
static double**** FTable;
static char**** _flag_FTable;
static char** _flag_S1;
static char** _flag_S2;
static char**** _flag_NR_FTable;


//Local Function Declarations
double reduce_bpmax_S1_1(long, long, int, int);
double eval_S1(long, long, int, int);
double reduce_bpmax_S2_1(long, long, int, int);
double eval_S2(long, long, int, int);
double eval_FTable(long, long, int, int, int, int);
double reduce_bpmax_NR_FTable_1(long, long, int, int, int, int);
double eval_NR_FTable(long, long, int, int, int, int);

//Memory Macros
#define seq1(i) seq1[i]
#define seq2(i) seq2[i]
#define S1(i,j) S1[i][j]
#define S2(i,j) S2[i][j]
#define NR_FTable(i1,j1,i2,j2) NR_FTable[i1][j1][i2][j2]
#define FTable(i1,j1,i2,j2) FTable[i1][j1][i2][j2]
#define _flag_FTable(i1,j1,i2,j2) _flag_FTable[i1][j1][i2][j2]
#define _flag_S1(i,j) _flag_S1[i][j]
#define _flag_S2(i,j) _flag_S2[i][j]
#define _flag_NR_FTable(i1,j1,i2,j2) _flag_NR_FTable[i1][j1][i2][j2]

void bpmax(long M, long N, int* _local_seq1, int* _local_seq2, double**** _local_FTable){
	///Parameter checking
	if (!((M >= 3 && N >= 3))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	seq1 = _local_seq1;
	seq2 = _local_seq2;
	FTable = _local_FTable;
	
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	
	double* _lin_S1 = (double*)malloc(sizeof(double)*((M) * (M)));
	mallocCheck(_lin_S1, ((M) * (M)), double);
	S1 = (double**)malloc(sizeof(double*)*(M));
	mallocCheck(S1, (M), double*);
	for (mz1=0;mz1 < M; mz1++) {
		S1[mz1] = &_lin_S1[(mz1*(M))];
	}
	
	double* _lin_S2 = (double*)malloc(sizeof(double)*((N) * (N)));
	mallocCheck(_lin_S2, ((N) * (N)), double);
	S2 = (double**)malloc(sizeof(double*)*(N));
	mallocCheck(S2, (N), double*);
	for (mz1=0;mz1 < N; mz1++) {
		S2[mz1] = &_lin_S2[(mz1*(N))];
	}
	
	double* _lin_NR_FTable = (double*)malloc(sizeof(double)*((M-1) * (M) * (N-1) * (N)));
	mallocCheck(_lin_NR_FTable, ((M-1) * (M) * (N-1) * (N)), double);
	NR_FTable = (double****)malloc(sizeof(double***)*(M-1));
	mallocCheck(NR_FTable, (M-1), double***);
	for (mz1=0;mz1 < M-1; mz1++) {
		NR_FTable[mz1] = (double***)malloc(sizeof(double**)*(M));
		mallocCheck(NR_FTable[mz1], (M), double**);
		for (mz2=0;mz2 < M; mz2++) {
			NR_FTable[mz1][mz2] = (double**)malloc(sizeof(double*)*(N-1));
			mallocCheck(NR_FTable[mz1][mz2], (N-1), double*);
			for (mz3=0;mz3 < N-1; mz3++) {
				NR_FTable[mz1][mz2][mz3] = &_lin_NR_FTable[(mz1*((M) * (N-1) * (N))) + (mz2*((N-1) * (N))) + (mz3*(N))];
			}
		}
	}
	
	char* _lin__flag_FTable = (char*)malloc(sizeof(char)*((M) * (M) * (N) * (N)));
	mallocCheck(_lin__flag_FTable, ((M) * (M) * (N) * (N)), char);
	_flag_FTable = (char****)malloc(sizeof(char***)*(M));
	mallocCheck(_flag_FTable, (M), char***);
	for (mz1=0;mz1 < M; mz1++) {
		_flag_FTable[mz1] = (char***)malloc(sizeof(char**)*(M));
		mallocCheck(_flag_FTable[mz1], (M), char**);
		for (mz2=0;mz2 < M; mz2++) {
			_flag_FTable[mz1][mz2] = (char**)malloc(sizeof(char*)*(N));
			mallocCheck(_flag_FTable[mz1][mz2], (N), char*);
			for (mz3=0;mz3 < N; mz3++) {
				_flag_FTable[mz1][mz2][mz3] = &_lin__flag_FTable[(mz1*((M) * (N) * (N))) + (mz2*((N) * (N))) + (mz3*(N))];
			}
		}
	}
	memset(_lin__flag_FTable, 'N', ((M) * (M) * (N) * (N)));
	
	char* _lin__flag_S1 = (char*)malloc(sizeof(char)*((M) * (M)));
	mallocCheck(_lin__flag_S1, ((M) * (M)), char);
	_flag_S1 = (char**)malloc(sizeof(char*)*(M));
	mallocCheck(_flag_S1, (M), char*);
	for (mz1=0;mz1 < M; mz1++) {
		_flag_S1[mz1] = &_lin__flag_S1[(mz1*(M))];
	}
	memset(_lin__flag_S1, 'N', ((M) * (M)));
	
	char* _lin__flag_S2 = (char*)malloc(sizeof(char)*((N) * (N)));
	mallocCheck(_lin__flag_S2, ((N) * (N)), char);
	_flag_S2 = (char**)malloc(sizeof(char*)*(N));
	mallocCheck(_flag_S2, (N), char*);
	for (mz1=0;mz1 < N; mz1++) {
		_flag_S2[mz1] = &_lin__flag_S2[(mz1*(N))];
	}
	memset(_lin__flag_S2, 'N', ((N) * (N)));
	
	char* _lin__flag_NR_FTable = (char*)malloc(sizeof(char)*((M-1) * (M) * (N-1) * (N)));
	mallocCheck(_lin__flag_NR_FTable, ((M-1) * (M) * (N-1) * (N)), char);
	_flag_NR_FTable = (char****)malloc(sizeof(char***)*(M-1));
	mallocCheck(_flag_NR_FTable, (M-1), char***);
	for (mz1=0;mz1 < M-1; mz1++) {
		_flag_NR_FTable[mz1] = (char***)malloc(sizeof(char**)*(M));
		mallocCheck(_flag_NR_FTable[mz1], (M), char**);
		for (mz2=0;mz2 < M; mz2++) {
			_flag_NR_FTable[mz1][mz2] = (char**)malloc(sizeof(char*)*(N-1));
			mallocCheck(_flag_NR_FTable[mz1][mz2], (N-1), char*);
			for (mz3=0;mz3 < N-1; mz3++) {
				_flag_NR_FTable[mz1][mz2][mz3] = &_lin__flag_NR_FTable[(mz1*((M) * (N-1) * (N))) + (mz2*((N-1) * (N))) + (mz3*(N))];
			}
		}
	}
	memset(_lin__flag_NR_FTable, 'N', ((M-1) * (M) * (N-1) * (N)));
	#define S0(i1,j1,i2,j2) eval_FTable(M,N,i1,j1,i2,j2)
	{
		//Domain
		//{i1,j1,i2,j2|i1>=0 && j1>=i1 && M>=j1+1 && i2>=0 && j2>=i2 && N>=j2+1 && M>=3 && N>=3}
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
	}
	#undef S0
	
	//Memory Free
	free(_lin_S1);
	free(S1);
	
	free(_lin_S2);
	free(S2);
	
	free(_lin_NR_FTable);
	for (mz1=0;mz1 < M-1; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(NR_FTable[mz1][mz2]);
		}
		free(NR_FTable[mz1]);
	}
	free(NR_FTable);
	
	free(_lin__flag_FTable);
	for (mz1=0;mz1 < M; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(_flag_FTable[mz1][mz2]);
		}
		free(_flag_FTable[mz1]);
	}
	free(_flag_FTable);
	
	free(_lin__flag_S1);
	free(_flag_S1);
	
	free(_lin__flag_S2);
	free(_flag_S2);
	
	free(_lin__flag_NR_FTable);
	for (mz1=0;mz1 < M-1; mz1++) {
		for (mz2=0;mz2 < M; mz2++) {
			free(_flag_NR_FTable[mz1][mz2]);
		}
		free(_flag_NR_FTable[mz1]);
	}
	free(_flag_NR_FTable);
}
double reduce_bpmax_S1_1(long M, long N, int ip, int jp){
	double reduceVar = INT_MIN;
	#define S0(i,j,k) {double __temp__ = (eval_S1(M,N,i,k))+(eval_S1(M,N,k+1,j)); reduceVar = __max_double(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|M>=3 && N>=3 && ip>=0 && M>=jp+1 && jp>=ip+4 && M>=ip+1 && jp>=0 && j>=i+4 && M>=i+1 && j>=k+1 && i>=0 && k>=i && M>=k+1 && M>=j+1 && k>=-1 && j>=0 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
double eval_S1(long M, long N, int i, int j){
	if ( _flag_S1(i,j) == 'N' ) {
		_flag_S1(i,j) = 'I';
	//Body for S1
		S1(i,j) = (((i >= j-3))?0:(__max_double((eval_S1(M,N,i+1,j-1))+(e_intra_score(seq1(i),seq1(j))),reduce_bpmax_S1_1(M,N,i,j))));
		_flag_S1(i,j) = 'F';
	} else if ( _flag_S1(i,j) == 'I' ) {
		printf("There is a self dependence on S1 at (%d,%d) \n",i,j);
		exit(-1);
	}
	return S1(i,j);
}
double reduce_bpmax_S2_1(long M, long N, int ip, int jp){
	double reduceVar = INT_MIN;
	#define S0(i,j,k) {double __temp__ = (eval_S2(M,N,i,k))+(eval_S2(M,N,k+1,j)); reduceVar = __max_double(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|M>=3 && N>=3 && ip>=0 && N>=jp+1 && jp>=ip+4 && jp>=0 && N>=ip+1 && j>=i+4 && j>=0 && j>=k+1 && i>=0 && k>=i && N>=k+1 && N>=j+1 && k>=-1 && N>=i+1 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
double eval_S2(long M, long N, int i, int j){
	if ( _flag_S2(i,j) == 'N' ) {
		_flag_S2(i,j) = 'I';
	//Body for S2
		S2(i,j) = (((i >= j-3))?0:(__max_double((eval_S2(M,N,i+1,j-1))+(e_intra_score(seq2(-i+N-1),seq2(-j+N-1))),reduce_bpmax_S2_1(M,N,i,j))));
		_flag_S2(i,j) = 'F';
	} else if ( _flag_S2(i,j) == 'I' ) {
		printf("There is a self dependence on S2 at (%d,%d) \n",i,j);
		exit(-1);
	}
	return S2(i,j);
}
double eval_FTable(long M, long N, int i1, int j1, int i2, int j2){
	if ( _flag_FTable(i1,j1,i2,j2) == 'N' ) {
		_flag_FTable(i1,j1,i2,j2) = 'I';
	//Body for FTable
		FTable(i1,j1,i2,j2) = (((0 == -1))?eval_S1(M,N,i1,j1):(((0 == -1))?eval_S2(M,N,i2,j2):(((j2 == i2 && j1 == i1))?e_inter_score(seq1(i1),seq2(-i2+N-1)):(__max_double((((j1 >= i1+4))?(eval_FTable(M,N,i1+1,j1-1,i2,j2))+(e_intra_score(seq1(i1),seq1(j1))):(0)),__max_double((((j2 >= i2+4))?(eval_FTable(M,N,i1,j1,i2+1,j2-1))+(e_intra_score(seq2(-i2+N-1),seq2(-j2+N-1))):(0)),__max_double((eval_S1(M,N,i1,j1))+(eval_S2(M,N,i2,j2)),(((j2 >= i2+1 && j1 >= i1+1))?eval_NR_FTable(M,N,i1,j1,i2,j2):(0)))))))));
		_flag_FTable(i1,j1,i2,j2) = 'F';
	} else if ( _flag_FTable(i1,j1,i2,j2) == 'I' ) {
		printf("There is a self dependence on FTable at (%d,%d,%d,%d) \n",i1,j1,i2,j2);
		exit(-1);
	}
	return FTable(i1,j1,i2,j2);
}
double reduce_bpmax_NR_FTable_1(long M, long N, int i1p, int j1p, int i2p, int j2p){
	double reduceVar = INT_MIN;
	#define S0(i1,j1,i2,j2,k1,k2) {double __temp__ = (eval_FTable(M,N,i1,k1,i2,k2))+(eval_FTable(M,N,k1+1,j1,k2+1,j2)); reduceVar = __max_double(reduceVar,__temp__); }
	{
		//Domain
		//{i1,j1,i2,j2,k1,k2|M>=3 && N>=3 && i1p>=0 && j1p>=i1p+1 && M>=j1p+1 && i2p>=0 && j2p>=i2p+1 && N>=j2p+1 && j1p+j2p>=i1p+i2p+1 && k1>=i1 && j1>=k1+1 && k2>=i2 && j2>=k2+1 && j1>=i1+1 && j2>=i2+1 && i1>=0 && N>=j2+1 && M>=k1+1 && i2>=0 && k2>=-1 && N>=k2+1 && M>=j1+1 && k1>=-1 && j1+j2>=i1+i2+1 && i1p==i1 && j1p==j1 && i2p==i2 && j2p==j2}
		int c5,c6;
		for(c5=i1p;c5 <= j1p-1;c5+=1)
		 {
		 	for(c6=i2p;c6 <= j2p-1;c6+=1)
		 	 {
		 	 	S0((i1p),(j1p),(i2p),(j2p),(c5),(c6));
		 	 }
		 }
	}
	#undef S0
	return reduceVar;
}
double eval_NR_FTable(long M, long N, int i1, int j1, int i2, int j2){
	if ( _flag_NR_FTable(i1,j1,i2,j2) == 'N' ) {
		_flag_NR_FTable(i1,j1,i2,j2) = 'I';
	//Body for NR_FTable
		NR_FTable(i1,j1,i2,j2) = reduce_bpmax_NR_FTable_1(M,N,i1,j1,i2,j2);
		_flag_NR_FTable(i1,j1,i2,j2) = 'F';
	} else if ( _flag_NR_FTable(i1,j1,i2,j2) == 'I' ) {
		printf("There is a self dependence on NR_FTable at (%d,%d,%d,%d) \n",i1,j1,i2,j2);
		exit(-1);
	}
	return NR_FTable(i1,j1,i2,j2);
}

//Memory Macros
#undef seq1
#undef seq2
#undef S1
#undef S2
#undef NR_FTable
#undef FTable
#undef _flag_FTable
#undef _flag_S1
#undef _flag_S2
#undef _flag_NR_FTable


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
