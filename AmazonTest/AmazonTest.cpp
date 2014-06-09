// AmazonTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define STEP 10

/**
 *	Calculate number to the power of n .
 *	@param p_nExponent : current pow round
 *	@param p_nNumber : the number in exponentiation
 */
int pow(int p_nExponent, int p_nNumber)
{
	if (p_nExponent == 1) 
		return p_nNumber;
	else 
		return pow(p_nExponent - 1, p_nNumber) * p_nNumber;
}

/**
 *	Resolve the recursive different polynomial, such as k, kk, kkk etc.
 *	@param p_nRepeatCount : The times of num repeats in the polynomial.
 *	@param p_nNum : The digit that repeats in sequence.
 */
int recursiveDiff(int p_nRepeatCount, int p_nNum)
{
	if (p_nRepeatCount == 1)
		return p_nNum;
	else
		return recursiveDiff(p_nRepeatCount - 1, p_nNum) + pow(p_nRepeatCount - 1, STEP) * p_nNum;
}

/**
 *	Calculate the sum of the polynomials. sum = k + kk + kkk + ...
 *	@param p_nRecursiveCount : The times of the N-sequence occurrence.
 *	@patam p_nNum : The digit that repeats in sequence.
 */
int polynomialSum(int p_nRecursiveCount, int p_nNum)
{
	if (p_nRecursiveCount == 1)
		return p_nNum;
	else
		return polynomialSum(p_nRecursiveCount - 1, p_nNum) + recursiveDiff(p_nRecursiveCount, p_nNum);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m,n = 0;
	while(scanf("%d %d", &m, &n) != EOF)
		printf("%d\n", polynomialSum(n, m));	
	return 0;
}

