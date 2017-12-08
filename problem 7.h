#ifndef PRIMES_H
#define PRIMES_H

struct Prime{
   unsigned short prime;
   unsigned short power;
};

struct Primes{
   Prime *prime;
   unsigned short nPrimes;
};

#endif
