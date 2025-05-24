0---'H'---Letra 1  
1---'e'---Letra 2    
2---'l'---Letra 3  
3---'l'---Letra 4  
4---'o'---Letra 5  
5---'\0'---Terminador nulo  
  

###  ¿Qué pasa si asignas str[5] = '!'?    
`str` ya no es una cadena válida en C, y funciones como `printf("%s", str)` podrían imprimir basura o causar errores.  

### ¿Qué pasa si asignas str[6] = 'X'?  
 ¡Error de memoria! Se esta accediendo fuera del arreglo, lo que puede causar comportamiento indefinido, o extraño.  

 `char *p = "Hello";`  
   
 `"Hello"` es una cadena literal almacenada en una zona de solo lectura.

`*p` apunta a esa zona, no puedes modificar su contenido, por ejemplo, `p[0] = 'h';` causaría error.

En cambio, el arreglo `str[]` sí permite modificar los caracteres.      