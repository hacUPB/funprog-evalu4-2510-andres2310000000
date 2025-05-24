```
int main(void)
{
    int n;
    float *resistencias;
    float sumaInversos = 0.0f, req;

    printf("¿Cuántas resistencias en paralelo deseas ingresar? ");
    scanf("%d", &n);
    
    resistencias = (float *)calloc(n, sizeof(float));
   
    
    for (int i = 0; i < n; i++) {
        printf("Ingresa el valor de la resistencia #%d (ohmios): ", i + 1);
        scanf("%f", &resistencias[i]);

         sumaInversos += 1.0f / resistencias[i];
    }
    req = 1.0f / sumaInversos;
    printf("Resistencia equivalente:%f",req);
    free (resistencias);
    
    return 0;
    
    }
```  

```
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int nombrel, apellidol;
printf("cuantas letras tiene tu nombre?\n");
scanf("%d",&nombrel);
printf("cuantas letras tiene tu apellido?\n");
scanf("%d",&apellidol);

char *nombre=(char*)malloc((nombrel+1)*sizeof(char));
char *apellido=(char*)malloc((apellidol+1)*sizeof(char));

getchar();

    printf("Ingresa tu nombre: ");
    fgets(nombre, nombrel + 1, stdin);
    
    getchar();

    printf("Ingresa tu apellido: ");
    fgets(apellido, apellidol + 2, stdin);

    printf("¡Hola %s %s!\n", nombre, apellido);

    free(nombre);
    free(apellido);

    return 0;
}
   /*
   preguntamos al usuario cuantas letras tien su nombre y apellido
   Reservamos memoria para almacenar esos datos(malloc)
   le pedimos al usuarion que ingrese su nombre y aoellido y lo 
   imprimimos en pantalla con un saludo adicional.
   */

```