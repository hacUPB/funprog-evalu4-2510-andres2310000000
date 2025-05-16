1. **¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro?**    
Pasa la dirección del primer elemento del arreglo. No todo el arreglo, sólo pasa un puntero que apunta a él.

2. **¿Qué diferencia hay entre declarar el parámetro como `int arr[]` y `int *arr`?**  
Ambas declaraciones indican que se está pasando un puntero a entero. int arr[] es solo una notación más legible cuando se espera un arreglo.  
  

3. **¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?**  
Cualquier modificación dentro de la función afecta directamente el arreglo original en el programa principal.