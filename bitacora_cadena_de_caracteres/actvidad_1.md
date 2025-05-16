Investiga y prepara un informe breve (puedes usar texto, código y ejemplos gráficos) sobre las siguientes funciones:  
### De `<string.h>`:

- `strlen`, `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, `strchr`, `strstr`, `strtok`

### De `<ctype.h>`:

- `isalpha`, `isdigit`, `isalnum`, `islower`, `isupper`, `tolower`, `toupper`

Rspuestas:   
  ### De `<string.h>`:  

`strlen`:  
Propósito: Calcula la longitud de una cadena sin incluir el carácter nulo '\0'.

Prototipo: `size_t strlen(const char *str);`

Parámetro: str es un puntero a una cadena de caracteres.  


```
#include <stdio.h>
#include <string.h>

int main() {
    char texto[] = "Hola mundo";
    printf("Longitud: %zu\n", strlen(texto)); // Salida: 10
    return 0;
}
```  

`strcpy`  
Propósito: Copia una cadena en otra.

Prototipo: char *strcpy(char *dest, const char *src);

Parámetros:

dest: cadena destino.

src: cadena fuente.

Ejemplo:
```
#include <stdio.h>
#include <string.h>

int main() {
    char destino[20];
    strcpy(destino, "Copiado");
    printf("Resultado: %s\n", destino);
    return 0;
}

```  

`strncpy`  
Propósito: Copia los primeros n caracteres de una cadena.

Prototipo: `char *strncpy(char *dest, const char *src, size_t n);`

Parametros:  
`dest`: Puntero al arreglo destino donde se copiará el contenido.

`src`: Puntero a la cadena fuente que se va a copiar.

`n`: Número máximo de caracteres que se van a copiar desde `src`

Ejemplo:  
```
#include <stdio.h>
#include <string.h>

int main() {
    char destino[20];
    strncpy(destino, "Hola mundo", 4);
    destino[4] = '\0';
    printf("Resultado: %s\n", destino); // Salida: Hola
    return 0;
}

```  

`strcat` 
Propósito: Concatenar parte de una cadena (n caracteres).

Prototipo: char *strncat(char *dest, const char *src, size_t n);  

Parametros: 
`dest`: Cadena destino a la que se añadirá el contenido de `src`. Debe tener espacio suficiente.

`src`: Cadena que se añadirá al final de `dest`.

Ejemplo:
```
#include <stdio.h>
#include <string.h>

int main() {
    char base[20] = "Hola ";
    strncat(base, "mundo cruel", 5);
    printf("%s\n", base); // Salida: Hola mundo
    return 0;
}

```

`strncat`  
Propósito: Concatenar parte de una cadena (n caracteres).

Prototipo: char *strncat(char *dest, const char *src, size_t n);

Parametros:   
`dest`: Puntero al arreglo destino donde se copiará el contenido.

`src`: Puntero a la cadena fuente que se va a copiar.

`n`: Número máximo de caracteres que se van a copiar desde `src`  

Ejemplo:
```
#include <stdio.h>
#include <string.h>

int main() {
    char base[20] = "Hola ";
    strncat(base, "mundo cruel", 5);
    printf("%s\n", base); // Salida: Hola mundo
    return 0;
}

```

`strcmp`   
Propósito: Compara dos cadenas.

Prototipo:   
`int strcmp(const char *s1, const char *s2);`

Parámetros:

`s1`: Primera cadena a comparar.

`s2`: Segunda cadena a comparar.  

Ejemplo:  
```
#include <stdio.h>
#include <string.h>

int main() {
    if (strcmp("hola", "hola") == 0)
        printf("Iguales\n");
    return 0;
}

```

`strncmp`      
Propósito: Compara los primeros n caracteres de dos cadenas.

Prototipo:   
`int strncmp(const char *s1, const char *s2, size_t n);`   

Parametros:  
`s1`: Primera cadena a comparar.

`s2`: Segunda cadena a comparar.   

`n`: Número de caracteres a comparar.  

Ejemplo:
```
#include <stdio.h>
#include <string.h>

int main() {
    if (strncmp("hola", "holanda", 3) == 0)
        printf("Coinciden los primeros 3\n");
    return 0;
}

```

`strchr`   
Propósito: Busca la primera aparición de un carácter.

Prototipo:   
`char *strchr(const char *str, int c);`  

Parametros:  
`str`: Cadena donde se busca el carácter.

`c`: Carácter a encontrar (como int, pero es convertido a char).  

Ejemplo:  
```
#include <stdio.h>
#include <string.h>

int main() {
    char *p = strchr("Hola", 'l');
    if (p) printf("Encontrado: %s\n", p);
    return 0;
}

```

`strstr`    
Propósito: Busca una subcadena.

Prototipo:   
`char *strstr(const char *haystack, const char *needle);`  

Parametros:    
`haystack`: Cadena principal donde se busca.

`needle`: Subcadena que se desea encontrar.

Ejemplo:
```
#include <stdio.h>
#include <string.h>

int main() {
    char *p = strstr("Hola mundo", "mun");
    if (p) printf("Subcadena: %s\n", p); // Salida: mundo
    return 0;
}

```

`strtok`  
Propósito: Divide una cadena en tokens usando delimitadores.

Prototipo:   
`char *strtok(char *str, const char *delim);`    
Parametros:  
`str`: Cadena a dividir (solo en la primera llamada; luego se pasa `NULL`).

`delim`: Conjunto de delimitadores (por ejemplo, `","` o `" "`).  

Ejemplo: 
```
#include <stdio.h>
#include <string.h>

int main() {
    char texto[] = "uno,dos,tres";
    char *token = strtok(texto, ",");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}

```    

### De `<ctype.h>`:

`isalpha`  
Propósito: Verifica si el carácter es alfabético.

Prototipo:   
`int isalpha(int c);  `  

Parametros:     
`c`: Carácter a evaluar (como `int`, normalmente del tipo `char`).

Ejemplo:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("%d\n", isalpha('a')); // 1
    printf("%d\n", isalpha('1')); // 0
    return 0;
}

```
`isdigit`  
Propósito: Verifica si es un dígito (0–9).

Prototipo:   
`int isdigit(int c);`

Parametros:   
`c`: Carácter a evaluar.

Ejemplos:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = '5';
    if (isdigit(ch)) {
        printf("%c es un dígito\n", ch);
    } else {
        printf("%c no es un dígito\n", ch);
    }
    return 0;
}

```



`isalnum`   
Propósito: Verifica si es letra o número.

Prototipo:   
`int isalnum(int c);`  

Parametros:   
`c`: Carácter a evaluar. 

Ejemplos:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = '9';
    if (isalnum(ch)) {
        printf("%c es alfanumérico\n", ch);
    } else {
        printf("%c no es alfanumérico\n", ch);
    }
    return 0;
}

```
`islower`   
Propósito: Verifica si es minúscula.

Prototipo:  
`int islower(int c);`


Parametros:   
`c`: Carácter a evaluar. 

Ejemplos:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'm';
    if (islower(ch)) {
        printf("%c es minúscula\n", ch);
    } else {
        printf("%c no es minúscula\n", ch);
    }
    return 0;
}

``` 
`isupper`     
Propósito: Verifica si es mayúscula.

Prototipo: 
`int isupper(int c);`  

Parametros:   
`c`: Carácter convertir. 

Ejemplos:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'G';
    if (isupper(ch)) {
        printf("%c es mayúscula\n", ch);
    } else {
        printf("%c no es mayúscula\n", ch);
    }
    return 0;
}

``` 
`tolower`    
Propósito: Convierte a minúscula.

Prototipo:   
`int tolower(int c);`

Parametros:   


Ejemplos:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'P';
    printf("Minúscula de %c es %c\n", ch, tolower(ch));
    return 0;
}

``` 
`toupper`    
Propósito: Convierte a mayúscula.

Prototipo:   
`int toupper(int c);`

Parametros:  
`c`: Carácter a evaluar.   

Ejemplos:  
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'r';
    printf("Mayúscula de %c es %c\n", ch, toupper(ch));
    return 0;
}

``` 











