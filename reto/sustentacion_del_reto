# Sustentación Técnica - Reto Unidad 4

## Análisis del problema

El problema plantea el desarrollo de una aplicación en lenguaje C orientada al procesamiento de archivos de texto. Este programa debe permitir al usuario interactuar a través de un menú para realizar diversas operaciones sobre un archivo .txt, tales como analizar estadísticas del texto, contar vocales, reemplazar palabras y guardar los resultados.

### Decisiones clave tomadas
Lectura dinámica del archivo
Se uso malloc y realloc para construir dinámicamente un arreglo de caracteres que almacene el contenido completo del archivo. Esto permite leer archivos de cualquier tamaño sin desperdiciar memoria.

### Interfaz por menú interactivo
La aplicación se estructura en torno a un ciclo do-while con opciones numeradas, guiando al usuario paso a paso según la funcionalidad requerida. Esta estructura evita errores y permite validar entradas (como asegurarse de que el archivo fue cargado antes de continuar).

### Manejo de estadísticas textuales
Las métricas solicitadas (caracteres, palabras, líneas, espacios) se calcularon usando un recorrido completo del arreglo de texto, implementando un autómata básico que distingue palabras por espacios y nuevas líneas por \n.

### Conteo de vocales
Se normalizó la comparación de caracteres con ayuda de funciones de la biblioteca <ctype.h>, como tolower, para asegurar que vocales en mayúsculas y minúsculas sean tratadas por igual.

### Reemplazo de palabras
Para esta funcionalidad, analizamos cuántas veces aparece la palabra original para calcular el tamaño necesario del nuevo texto y usamos memoria dinámica para construir el resultado sin sobrescribir el texto original.

### Salida a archivo externo
Se implementó una opción final que permite exportar el texto modificado junto con las estadísticas y el conteo de vocales a un archivo .txt, usando fprintf y estructura clara del reporte.
### Forma simplificada
* Leer el contenido de un archivo de texto (1).
* Calcular estadísticas como número de caracteres, palabras, líneas y espacios (2).
* Contar la cantidad de veces aparece cada vocal (3).
* Reemplazar palabras específicas por otras (4).
* Guardar los resultados obtenidos en un archivo nuevo (5).

La estrategia consistió en dividir cada funcionalidad en una función específica para mantener la modularidad, facilitar pruebas y aumentar la claridad del código. Esta división también nos ayudó a reutilizar código y reducir errores.

---


## Estrategia de solución

El programa está dividido en funciones que se conectan a través de un menú principal:

* `leer_archivo`: Lee el archivo completo y almacena su contenido en memoria dinámica.
* `calcular_estadisticas`: Cuenta los caracteres, palabras, líneas y espacios.
* `contar_vocales`: Cuenta la cantidad de vocales en el texto.
* `reemplazar_palabra`: Reemplaza una palabra que el usuario de por otra en todo el texto.
* `guardar_resultados`: Guarda en un archivo de salida el texto todos los cambios hechos.

Adicional a esto cada opción del menú verifica en las funciones primero si el contenido que se cargo si tenga algo en el archivo, para asegurar el buen funcionamiento de las operaciones en las funciones. También se implementó manejo de errores (como punteros nulos o fallos de asignación de memoria) para reducir errores.

---

##  Tabla de variables

### Función: `leer_archivo`

| Variable        | Tipo         | Rol                |
| --------------- | ------------ | ------------------ |
| nombre\_archivo | const char\* | Entrada            |
| contenido       | char\*       | Salida             |
| buffer          | char\[]      | Temporal           |
| capacidad       | size\_t      | Control de memoria |
| longitud        | size\_t      | Control de memoria |

---

### Función: `calcular_estadisticas`

| Variable    | Tipo         | Rol                              |
| ----------- | ------------ | -------------------------------- |
| contenido   | const char\* | Entrada                          |
| resultado   | char\*       | Salida                           |
| caracteres  | int          | Contador                         |
| palabras    | int          | Contador                         |
| espacios    | int          | Contador                         |
| lineas      | int          | Contador                         |
| en\_palabra | int          | Lógica de separación de palabras |

---

### Función: `contar_vocales`

| Variable      | Tipo         | Rol                               |
| ------------- | ------------ | --------------------------------- |
| contenido     | const char\* | Entrada                           |
| resultado     | char\*       | Salida                            |
| a, e, i, o, u | int          | Contadores individuales por vocal |

---

### Función: `reemplazar_palabra`

| Variable        | Tipo         | Rol                              |
| --------------- | ------------ | -------------------------------- |
| origen          | const char\* | Entrada                          |
| palabraOriginal | const char\* | Entrada                          |
| nuevaPalabra    | const char\* | Entrada                          |
| resultado       | char\*       | Salida                           |
| temp, ptrOrigen | const char\* | Control de búsqueda              |
| ptrResultado    | char\*       | Posicionamiento en resultado     |
| ocurrencias     | int          | Contador de ocurrencias          |
| tamanoTexto     | int          | Tamaño del texto original        |
| tamanoOriginal  | int          | Tamaño de la palabra original    |
| tamanoNueva     | int          | Tamaño de la nueva palabra       |
| nuevoTamano     | int          | Tamaño calculado del nuevo texto |

---

### Función: `guardar_resultados`

| Variable        | Tipo         | Rol               |
| --------------- | ------------ | ----------------- |
| archivo\_salida | const char\* | Entrada           |
| contenido       | const char\* | Entrada           |
| estadisticas    | const char\* | Entrada           |
| vocales         | const char\* | Entrada           |
| out             | FILE\*       | Archivo de salida |

---

## 📌 Pseudocódigo general del menú principal

```plaintext
Mientras el usuario no elija "Salir":
    Mostrar menú
    Leer opción del usuario

    Si opción = 1:
        Pedir nombre del archivo
        Llamar a leer_archivo()
    Si opción = 2:
        Veficar contenido
        Llamar a calcular_estadisticas()
    Si opción = 3:
        Verificar contenido
        Llamar a contar_vocales()
    Si opción = 4:
        Verificar contenido
        Pedir palabras a buscar y reemplazar
        Llamar a reemplazar_palabra()
    Si opción = 5:
        Verificar contenido
        Pedir nombre del archivo de salida
        Llamar a guardar_resultados()
```
