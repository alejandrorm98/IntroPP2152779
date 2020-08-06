
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>



int main ( int argc, char *argv[] )
{
/******************************************************************************/
/*
  Purpose:

    main returns a table with the primes numbers and time of run.

  Discussion:

    The main try to set time of one by one the prime's tables and then throws the time of all code running

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 June 2020

  Author:

    Alejandro Ramirez

  Parameters:

    OUTPUT__ . time execution, table with 1 and n numbers primes
*/
double tiempo_inicio, tiempo_final;
double segundos;
tiempo_inicio = clock();
/******************************************************************************/



/******************************************************************************/

int prime_number ( int n )

/******************************************************************************/
/*
  Purpose:

    PRIME_NUMBER returns the number of primes between 1 and N.

  Discussion:

    A naive algorithm is used.

    Mathematica can return the number of primes less than or equal to N
    by the command PrimePi[N].

                N  PRIME_NUMBER      time

                1           0		..
               10           4		..
              100          25		..
            1,000         168		..
           10,000       1,229		..
          100,000       9,592		..
        1,000,000      78,498		..
       10,000,000     664,579		..
      100,000,000   5,761,455		..
    1,000,000,000  50,847,534		..

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 june 2020

  Author:

    Alejandro Ramirez

  Parameters:

    Input, int N, the maximum number to check.

    Output, int PRIME_NUMBER, the number of prime numbers up to N.
*/
{
  int i;
  int j;
  int prime;
  int total;

  total = 0;

  for ( i = 2; i <= n; i++ )
  {
    prime = 1;
    for ( j = 2; j < i; j++ )
    {
      if ( ( i % j ) == 0 )
      {
        prime = 0;
        break;
      }
    }
    total = total + prime;
  }
  //printf("%d %d ",n, total);
  return total;
}
/******************************************************************************/

void timestamp (  )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}


  int n = 1000000;
  int v=1;
  int primes;
  double t;
  
  printf ( "\n" );
 
  printf ( "  Tabla de NUMEROS PRIMOS del  1 al N.\n" );
  printf ( "\n" );
  printf ( "         N        Pi          Tiempo\n" );
  printf ( "\n" );
  //create the table of prime numbers
  while( v <= n )
  {
  	t= clock();
  	
  	primes = prime_number ( v );

    	t = ( clock()- t)/CLOCKS_PER_SEC;

   	printf ( "  %8d  %8d  %14f\n", v, primes, t );

  	v = v * 2;
  }
    

  
  
  tiempo_final = clock();

  segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC; /*i'm catching the time of run*/

  printf("%f segundos de ejecucion \n",segundos);
  timestamp (  );
return 0;
}
