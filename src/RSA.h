#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED
#include "functions.h"



void KeyGeneration(unsigned long long  &n, unsigned long long &e, unsigned long long &d);
unsigned long long Encrypt(unsigned long long message, unsigned long long e, unsigned long long n);
unsigned long long Decrypt(unsigned long long cipher, unsigned long long d, unsigned long long n);




#endif // RSA_H_INCLUDED
