/* 
 *  This file is for computing the value of n choose k recursively, using the well known combinatorial 
 *  identity C(n,k)=C(n-1,k)+C(n-1,k-1) and is written by Sahil Sharma, CS12B060 on 9/8/2013
 */
#include<stdio.h>
#define MAXSIZE 10010
#define big 1000000007
#include<algorithm>

long long int inverse[MAXSIZE];

long long int exp( long long int n , long long int a )
{
     if ( n == 0 )
     return 1;
     else if ( n == 1 )
     return a ;
     else if ( n % 2 == 0 )
     {
          long long int x = exp ( n/2 , a );
          return  ( x * x ) % big ;
     }
     else if ( n % 2 == 1 )
     {
          long long int x = exp ( n/2 , a );
          return ( ( (x*x) % big ) * a ) % big ;
     }
}     

void compute_inverse()
{
    inverse[0] = 1;
    inverse[1] = 1;
    long long int i=2;
    for(; i< MAXSIZE ; i++)
    inverse[i] = exp ( (long long )(big - 2) , i ) ; 
}


long long int ar[MAXSIZE];

long long answer ( int n , int k ) 
{
    
     //Now we have an array of numbers from 0 to n-1 
     long long int i = k-1 , choose = 1, sum = 0;
     for ( ; i <= n-1 ; i++ )
     {
         sum = ( sum + (choose * ar[i])%big )%big ;
         choose = ( choose * ( i+1) ) % big;
         choose = (choose * inverse[i-k+2])%big;
     }
     return sum ;      
} 


int main()
{
    compute_inverse();
  
     int n = 0 , k = 0 , t , i=0, j=1;
    scanf("%d",&t);
    while(t--)
    {    
         scanf("%d %d",&n,&k);
         for(i=0;i<n;i++)
         scanf("%lld",&ar[i]);
          std::sort( ar , ar + n );
         printf("Case #%d: %lld\n",j++,answer(n,k));     
    }
    
}                  
