Ejercicio 1:  
```
#include <stdio.h>

int main() {
    int arreglo[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for (int i = 0; i < 10; i++) 
    {
        printf("%d\n",arreglo[i]);
    }

    return 0;
}
```  

Ejercicio 2:  
```
#include <stdio.h>

int main() {
    int arreglo[5] = {2, 4, 6, 8, 10};

    for (int i = 4; i >= 0; i--) 
    {
        printf("%d\n",arreglo[i]);
    }

    return 0;
}
```  

Ejercicio 3:  
```
#include <stdio.h>

int main() {
    int numeros[10];
    int suma ;
    int resta;
    int multiplicacion=1;

    printf("Ingresa 10 números:\n");

    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
        multiplicacion *= numeros[i];
     if (i == 0) 
     {
            resta = numeros[i];  
     } 
     else 
     {
            resta -= numeros[i];
     }
    }
     printf("\nResultados:\n");
    printf("Suma: %d\n", suma);
    printf("Resta acumulada: %d\n", resta);
    printf("Multiplicación acumulada: %d\n", multiplicacion);
    
return 0;
    
}
```  

Ejercicio 4:  
```
#include <stdio.h>

int main() {
    int a[5], b[5], c[10];

    printf("Ingresa 10 números:\n");

    for (int i = 0; i < 5; i++) 
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 5; i++) 
    {
        printf("Número %d: ", i + 6);
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 5; i++) 
    {
        c[i] = a[i];
        c[i + 5] = b[i];
    }

    printf("arreglo combinado:\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("c[%d] = %d\n", i, c[i]);
    }

    return 0;
}
```  

Ejercicio 5:  
```
#include <stdio.h>
void analizarNotas(float notas[], int cantidad) 
{
    float suma = 0;
    int aprobados = 0;
    int reprobados = 0;
    int sobresalientes = 0;

    for (int i = 0; i < cantidad; i++) 
    {
        suma += notas[i];

        if (notas[i] >= 3.0) 
        {
            aprobados++;
        } 
        
        else 
        {
            reprobados++;
        }

        if (notas[i] >= 4.0) 
        {
            sobresalientes++;
        }
    }

    float promedio = suma / cantidad;
    printf("\n--- Resultados ---\n");
    printf("Promedio general del curso: %.2f\n", promedio);
    printf("Cantidad de estudiantes aprobados: %d\n", aprobados);
    printf("Cantidad de estudiantes reprobados: %d\n", reprobados);
    printf("Cantidad con nota >= 4.0: %d\n", sobresalientes);
}

int main() 
{
    float notas[24];

    printf("Ingresa las notas de los 24 estudiantes:\n");
    for (int i = 0; i < 24; i++) {
        printf("Nota del estudiante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    analizarNotas(notas, 24);

    return 0;
}
```  
Ejercicio 6:  
```
#include <stdio.h>

int main() 
{
    int columnas = 8;
    int filas = 4;  
    float matriz[4][9]; 

    printf("Ingrese los porcentajes (deben sumar 100):\n");
    for (int j = 0; j < columnas; j++) 
    {
        printf("Porcentaje #%d: ", j + 1);
        scanf("%f", &matriz[0][j]);
        matriz[0][j] /= 100.0f; 
    }

    for (int i = 1; i < filas; i++) 
    {
        printf("\nIngrese las notas del estudiante %d:\n", i);
        for (int j = 0; j < columnas; j++) 
        {
            printf("Nota #%d: ", j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    for (int i = 1; i < filas; i++) 
    {
        float definitiva = 0.0f;
        for (int j = 0; j < columnas; j++) {
            definitiva += matriz[i][j] * matriz[0][j]; 
        }
        matriz[i][columnas] = definitiva;  
    }
    printf("\nNotas definitivas de los estudiantes:\n");
    for (int i = 1; i < filas; i++) {
        printf("Estudiante %d: %.2f\n", i, matriz[i][columnas]);
    }

    return 0;
}
```