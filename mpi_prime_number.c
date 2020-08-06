# include <math.h>
# include <mpi.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main ( int argc, char *argv[] );
int prime_number ( int n, int id, int p );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PRIME_MPI.

  Discussion:

    This program calls a version of PRIME_NUMBER that includes
    MPI calls for parallel processing.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 August 2009

  Author:

    John Burkardt
*/
{
  int id;
  int ierr;
  int n;
  int n_factor;
  int n_hi;
  int n_lo;
  int p;
  int primes;
  int primes_part;
  double wtime;
  double tiempo_inicio, tiempo_final;
  double segundos=0;
  tiempo_inicio = MPI_Wtime ( );

  n_lo = 1;
  n_hi = 1000000;
  n_factor = 2;
/*
  Initialize MPI.
*/
  ierr = MPI_Init ( &argc, &argv );

  if ( ierr != 0 )
  {
    printf ( "\n" );
    printf ( "PRIME_MPI - Fatal error!\n" );
    printf ( "  MPI_Init returns nonzero IERR.\n" );
    exit ( 1 );
  }
/*
  Get the number of processes.
*/
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &p );
/*
  Determine this processes's rank.
*/
  ierr = MPI_Comm_rank ( MPI_COMM_WORLD, &id );

  if ( id == 0 )
  {
    timestamp ( );
    printf ( "\n" );
    printf ( "PRIME_MPI VERSION\n" );
    printf ( "\n" );
 
   printf ( "  Tabla de NUMEROS PRIMOS del  1 al N.\n" );
   printf ( "\n" );
   printf ( "       N      Pi        Tiempo\n" );
   printf ( "\n" );
  }

  n = n_lo;

  while ( n <= n_hi )
  {
    if ( id == 0 )
    {
      wtime = MPI_Wtime ( );
    }
    ierr = MPI_Bcast ( &n, 1, MPI_INT, 0, MPI_COMM_WORLD );

    primes_part = prime_number ( n, id, p );

    ierr = MPI_Reduce ( &primes_part, &primes, 1, MPI_INT, MPI_SUM, 0, 
      MPI_COMM_WORLD );

    if ( id == 0 )
    {
      wtime = MPI_Wtime ( ) - wtime;
      printf ( "  %8d  %8d  %14f\n", n, primes, wtime );
    }
    n = n * n_factor;
  }
/*
  Terminate MPI.
*/
  tiempo_final = MPI_Wtime ( );
  ierr = MPI_Finalize ( );
  
/*
  Terminate.
*/
  if ( id == 0 ) 
  {
    printf ( "\n");         
    printf ( "  MPI_Prime:\n");         
    printf ( "  Ejecucion normal.\n"); 
    printf ( "\n" );

    segundos = (tiempo_final - tiempo_inicio);
     /*i'm catching the time of run*/
    
    printf("  %f segundos de ejecucion \n",segundos);
    timestamp ( ); 
    printf ( "\n" );
    printf ( "\n" );       
  }

  return 0;
}
/******************************************************************************/

int prime_number ( int n, int id, int p )

/******************************************************************************/
/*
  Purpose:

    PRIME_NUMBER returns the number of primes between 1 and N.

  Discussion:

    In order to divide the work up evenly among P processors, processor
    ID starts at 2+ID and skips by P.

    A naive algorithm is used.

    Mathematica can return the number of primes less than or equal to N
    by the command PrimePi[N].

                N  PRIME_NUMBER

                1           0
               10           4
              100          25
            1,000         168
           10,000       1,229
          100,000       9,592
        1,000,000      78,498
       10,000,000     664,579
      100,000,000   5,761,455
    1,000,000,000  50,847,534

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the maximum number to check.

    Input, int ID, the ID of this process,
    between 0 and P-1.

    Input, int P, the number of processes.

    Output, int PRIME_NUMBER, the number of prime numbers up to N.
*/
{
  int i;
  int j;
  int prime;
  int total;
  

  total = 0;

  for ( i = 2 + id; i <= n; i = i + p )
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
  return total;
}
/******************************************************************************/

void timestamp ( )

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
