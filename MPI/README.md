
# IntroPP2152779

## MPI

programación en paralelo, iniciando con C y la librería MPI
En este readme abordaré primero la parte funcional del código, despues haré un paso a paso del modo de ejecución tanto en guane como en local y terminaré dando 
una concluciones con respecto al codigo serial.
Mi código consiste en devolverme la cantidad de numeros primos hasta N, que se compone de una funcion llamada prime_number() que recibe como parametro a N, 
internamente va comparando desde 2 a N respectivamente cada valor factorial de N y con ayuda del modulo determina cuantos primos hay. Lo que el código devuelve 
es una tabla con una secuencia de numeros hasta N dando el número de primos que alberga detrás de él y el tiempo que tardó en carcar cada uno para medir su 
rendimiento.

Lo primero que hice fue analizar el código, mirar cuales eran sus posibles puntos críticos a la hora de correr en serial con muchos datos, despues a diferencia de Openmp, me tocó analizar dentro del main donde podía implementar MPI. El tiempo de ejecucion comparandolo contra omp no superó las espectativas, proponiedno una solución, se pude hibridizar el código omp con mpi y se pueden optener buenos resultados. 

### * GUANE

Despues de saber que ya tenia mi código paralelizado desde guane lo compilé utilizando el compilador de MPI **devtools/mpi/openmpi/3.1.4** hacer su compilación 
utlizando **mpicc mpi_prime_number.c -o mpi_prime_number**, esta sentencia la usaba para compilar y  que me dejara el codido listo para 
ejecutar. Ya cuando tengo ejecutable el .c lo que hago es definir mis cpus, las tareas y los nodos para un buen rendimiento. Al correr el codigo declarando todos los atributos de ejecucion se hace por medio de **prime_number.sbatch**. Adentro del .sbatch de al correr el ejecutable se define el nuemro de procesos con **-np** y se corre con **mpirun -np 1 mpi_prime_number**.  Ya cuando todo esté definido y listo para ejecutar, lo ejecuto con 
**sbatch prime_number.sbatch** y listo ya tengo en un .out mi salida y en un .err los errores por si salen. 
