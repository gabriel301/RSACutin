#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "RSA.h"
using namespace std;


//This function generates the private (d) and public keys (n,e).
void KeyGeneration(unsigned long long &n, unsigned long long &e,unsigned long long &d)
{
    unsigned long long p=0,q=0,r, number,phi;
    long long  x,y;
    bool stop = false;

    //Selects the prime numbers p and q in the range 10000 - 100000
    while(!stop)
    {
        r = rand();
        number = 10000 + (r * 90000) / RAND_MAX; //It generates a number in the range 10000 - 100000

        if(number%2==0)
            continue;

        //Select the number primes
        if(LehmannsPrimalyTest(number))
        {
            if(p==0)
                p = number;
            else if(p!= number)
            {
                q = number;
                stop = true;
            }
        }

    }
    cout<<"Prime Numbers: "<<p<<" "<<q<<endl;

    //Sets phi(n)
    phi = (p-1)*(q-1);

    stop = false;

    //Selects a Random e such as gcd(phi(n),e)==1 and d, using the Extended Euclidean Algorithm
    while(!stop)
    {
        r = rand()%phi;

        if(r==0)
            continue;

        /*if phi(n)*x + e*y == 1
          It gives e modular inverse (y)
          phi(n)*x mod e = 1
          e*y mod phi(n) = 1

        Y must be greater than 0, otherwise the FastModuloExponentiation procedure just
        enter in a infinite loop (I do not know why, and I tried to perform this operation just with a long long variable)
        This part of code selects e and d*/
        if (ExtendedEuclideanAlgorithm(phi,r,x,y)==1 && y>0)
        {
            e=r;
            d=y;
            stop = true;
        }

    }
    n = p*q;
}


//Encrypts one number (or letter)
unsigned long long Encrypt(unsigned long long message, unsigned long long e, unsigned long long n)
{
    return FastModularExponentiation(message,e,n);
}

//Decrypts one number (or letter)
unsigned long long Decrypt(unsigned long long cipher, unsigned long long d, unsigned long long n)
{
    return FastModularExponentiation(cipher,d,n);
}


