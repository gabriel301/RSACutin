#include <iostream>
#include "RSA.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main()
{
    unsigned long long n,e,d,cipher;
    srand(time(NULL));
    cout<<"****The overflows occurs some times, so just hit enter a few times and one time the error will be occur***\n\n";
    while(true)
    {


        KeyGeneration(n,e,d);
        cout<<"\n***Public Key***\n";
        cout<<"E: "<<e<<endl;
        cout<<"N: "<<n<<endl;

        cout<<"***Private Key***\n";
        cout<<"D: "<<d<<endl;


        cipher=Encrypt(65,e,n);
        cout<<"\nOriginal Message: 65\nMessage Encrypted: "<<cipher<<endl;
        cout<<"Message Decrypted: "<<Decrypt(cipher,d,n)<<endl;
        cout<<"\nPress Enter to generate another key or Ctrl+C to stop execution\n";

        cin.get();
    }
    return 0;
}
