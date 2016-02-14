#include "functions.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//This function calculates (a^k) mod n.
unsigned long long FastModularExponentiation(unsigned long long a, unsigned long long  b, unsigned long long n)
{

    int shifts=0;
    unsigned long long  c=0, f=1;

    //Gets the number of bits of number b
    while((b>>shifts)!=0) shifts++;

    for(int i=shifts-1;i>=0;i--)
    {
        c*=2;
        f=(f*f)%n;
        if(((b>>i) & 1) == 1) //Binary shift to extract the value of bit in position i
        {
            c+=1;
            f=(f*a)%n;

        }

    }

    return f;
}


//This Function verifies whether a given number is a proven prime
bool LehmannsPrimalyTest(unsigned long long p)
{
    long long  exp,a,r;
    bool response = false;

    exp = (p-1)/2; //Calculation of the Exponent

    //Test runs 10 times
    for(int i=0;i<10;i++)
    {
        a = rand()%p;  //Select a random number less than p;

        r = FastModularExponentiation(a,exp,p);  //Performs the modulo operation


        //If a^((p-1)/2 is not either 1 or p-1, it is not prime
        if(r != 1 && r != p-1)
            return false;

        //Else, if result is not always 1, it may be prime
        else if(r == p-1)
           response = true;
    }
    return response;
}


//This functions implements the Extended Euclidean Algorithm.
//One constraint is that must be a >=b
unsigned long long ExtendedEuclideanAlgorithm(unsigned long long a,unsigned long long b, long long &x, long long &y)
{
    long long d,q,x2=1,x1=0,y2=0,y1=1,r;

    if (a<b)
    {
        unsigned long long aux = a;
        a = b;
        b = aux;
    }

    if (b==0)
    {
        d = a;
        x=1;
        y=0;
        return d;
    }

    while(b>0)
    {
        q = (a/b);
        r = a-(q*b);
        x = x2-(q*x1);
        y = y2-(q*y1);
        a = b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }

    d = a;
    x = x2;
    y = y2;
    return d;
}

unsigned long long ExtendedEuclideanAlgorithm(unsigned long long a,unsigned long long b)
{
    long long d,q,x2=1,x1=0,y2=0,y1=1,r,x,y;

    if (a<b)
    {
        long long aux = a;
        a = b;
        b = aux;
    }

    if (b==0)
    {
        d = a;
        x=1;
        y=0;
        return d;
    }

    while(b>0)
    {
        q = (a/b);
        r = a-(q*b);
        x = x2-(q*x1);
        y = y2-(q*y1);
        a = b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }


    d = a;
    x = x2;
    y = y2;
    return d;
}

unsigned long long LeastCommonMultiple(unsigned long long a,unsigned long long b)
{
    return a * (b/ExtendedEuclideanAlgorithm(a,b));
}

unsigned long long BitwiseMultiplication(unsigned long long a, unsigned long long b)
{

   unsigned long long result = 0;
   // a>b
   if (a<b)
    {
        unsigned long long aux = a;
        a = b;
        b = aux;
    }

   while(b != 0)               // Iterate the loop till b==0
   {
      if (b&01)                // Bitwise &  of the value of b with 01
        {
          result=result+a;     // Add a to result if b is odd .
        }
      a<<=1;                   // Left shifting the value contained in 'a' by 1
                               // multiplies a by 2 for each loop
      b>>=1;                   // Right shifting the value contained in 'b' by 1.
   }
   return result;
}
