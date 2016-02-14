#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

unsigned long long FastModularExponentiation(unsigned long long  a, unsigned long long  b, unsigned long long n);
unsigned long long ExtendedEuclideanAlgorithm(unsigned long long a,unsigned long long b, long long &x,long long &y);
unsigned long long ExtendedEuclideanAlgorithm(unsigned long long a,unsigned long long  b);
unsigned long long LeastCommonMultiple(unsigned long long a,unsigned long long b);
bool LehmannsPrimalyTest(unsigned long long  p);

unsigned long long BitwiseMultiplication(unsigned long long a, unsigned long long b);

#endif // RSA_H_INCLUDED
