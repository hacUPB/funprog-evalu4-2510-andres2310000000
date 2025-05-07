1. **¿Cuál es exactamente la diferencia entre un arreglo y un puntero?**  
Un arreglo es un bloque de memoria con una cantidad fija de elementos.   
Un puntero puede apuntar a cualquier parte de la memoria y puede cambiar su dirección.  

**2. ¿Cómo están almacenados en la memoria los elementos de una matriz?**    
En orden fila por fila. Por ejemplo, en int matriz[2][3], primero se almacenan los 3 elementos de la primera fila y luego los 3 de la segunda.

**3. ¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?**    
-Evitar acceder fuera de los límites del arreglo.  
-Asegurarse de que el puntero no sea NULL.  
-Tener claro el tipo de datos y su tamaño.  
-No liberar memoria estática.
