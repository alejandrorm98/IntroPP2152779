# IntroPP2152779
programación en paralelo, iniciando con C y la librería openMP
En este readme abordaré primero la parte funcional del código, despues haré un paso a paso del modo de ejecución tanto en guane como en local y terminaré dando una concluciones con respecto al codigo serial.
Mi código consiste en devolverme la cantidad de numeros primos hasta N, que se compone de una funcion llamada prime_number() que recibe como parametro a N, internamente va comparando desde 2 a N respectivamente cada valor factorial de N y con ayuda del modulo determina cuantos primos hay. Lo que el código devuelve es una tabla con una secuencia de numeros hasta N dando el número de primos que alberga detrás de él y el tiempo que tardó en carcar cada uno para medir su rendimiento.//

Lo primero que hice fue analizar el código, mirar cuales eran sus posibles puntos críticos a la hora de correr en serial con muchos datos, despues al analizar un for anidado secuencial decidí ahí utilizar la libreria openMP para mejorar su rendimiento dividiendo su trabajo.//

GUANE//
Despues de saber que ya tenia mi código paralelizado desde cuane lo compilé utilizando <h6>GCC) 4.8.5 20150623 (Red Hat 4.8.5-39)</h6> hacer su compilación utlizando <h6> gcc -lm -fopenmp omp_prime_number.c -o omp_prime_number </h6>, esta sentencia la usaba para compilar y  que me dejara el codifo listo para ejecutar, tanto en guane como en local. Ya cuando lo tengo ejecutable el .c lo que hago es definir mis cpus las tareas y los nodos para un buen rendimiento a la hora de correr el código y todo eso se hace en el <h6>prime_number.sbatch</h6>. Ya cuando todo esté definido y listo para ejecutar, lo ejecuto con <h6>sbatch prime_number.sbatch</h6> y listo ya tengo en un .out mi salida y en un .err los errores por si salen.

LOCAL//



