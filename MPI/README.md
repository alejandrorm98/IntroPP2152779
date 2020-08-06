

## OpenMP

programación en paralelo, iniciando con C y la librería openMP
En este readme abordaré primero la parte funcional del código, despues haré un paso a paso del modo de ejecución tanto en guane como en local y terminaré dando 
una concluciones con respecto al codigo serial.
Mi código consiste en devolverme la cantidad de numeros primos hasta N, que se compone de una funcion llamada prime_number() que recibe como parametro a N, 
internamente va comparando desde 2 a N respectivamente cada valor factorial de N y con ayuda del modulo determina cuantos primos hay. Lo que el código devuelve 
es una tabla con una secuencia de numeros hasta N dando el número de primos que alberga detrás de él y el tiempo que tardó en carcar cada uno para medir su 
