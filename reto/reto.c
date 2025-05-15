#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* leer_archivo(const char* nombre_archivo);
void calcular_estadisticas(const char* texto, int* caracteres, int* palabras, int* espacios, int* lineas);
void contar_vocales(const char* texto, int* a, int* e, int* i, int* o, int* u);
void contar_vocales();
char* reemplazar_palabra();
void guardar_en_archivo();

int main() {
    char nombre_archivo[100], nombre_salida[100];
    int opcion;

    do {
        printf("\nMENÚ INTERACTIVO \n");
        printf("1. Ingresar nombre del archivo .txt\n");
        printf("2. Calcular estadísticas del texto\n");
        printf("3. Contar frecuencia de vocales\n");
        printf("4. Reemplazar una palabra\n");
        printf("5. Guardar resultados en nuevo archivo\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) 
        {
            printf("Entrada inválida.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (opcion) 
        {
            case 1:
                printf("Ingrese el nombre del archivo .txt: ");
                scanf("%99s", nombre_archivo);
                free(contenido);
                free(modificado);
                contenido = leer_archivo(nombre_archivo);
                if (contenido) 
                {
                    modificado = strdup(contenido);
                    printf("Archivo cargado correctamente.\n");
                } else {
                    modificado = NULL;
                }
                break;

            case 2:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
                calcular_estadisticas();
            
                break;

            case 3:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
                contar_vocales();
                {
                    ....
                }
                break;

            case 4:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                } 
                
                char buscar[MAX_WORD], reemplazo[MAX_WORD];
                    {
                 ....
                    }
                break;

            case 5:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
               
               ....
                break;

            case 6:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }

    }
    
    while (opcion != 6);

    free(contenido);
    free(modificado);
    return 0;
}

char* leer_archivo(const char* nombre_archivo) 
{
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) 
    {
        perror("Error al abrir el archivo");
        return NULL;
    }
    

    char* contenido = malloc(tam + 1);
    if (!contenido) 
    {
        perror("Error al asignar memoria");
        fclose(archivo);
        return NULL;
    }
    
    return contenido;
}

void calcular_estadisticas(const char* texto, int* caracteres, int* palabras, int* espacios, int* lineas) {
    *caracteres = *palabras = *espacios = *lineas = 0;
    int en_palabra = 0;
    for (int i = 0; texto[i]; i++) 
    {
        if (texto[i] != '\n') (*caracteres)++;
        if (isspace((unsigned char)texto[i])) 
        {
            if (texto[i] == ' ') (*espacios)++;
            if (texto[i] == '\n') (*lineas)++;
            en_palabra = 0;
        } 
        
        else if (!en_palabra) 
        {
            en_palabra = 1;
            (*palabras)++;
        }
    }
    (*lineas)++;
}  

void contar_vocales(const char* texto, int* a, int* e, int* i, int* o, int* u) {
    *a = *e = *i = *o = *u = 0;
    for (int j = 0; texto[j]; j++) {
        char c = tolower((unsigned char)texto[j]);
        switch (c) {
            case 'a': (*a)++; break;
            case 'e': (*e)++; break;
            case 'i': (*i)++; break;
            case 'o': (*o)++; break;
            case 'u': (*u)++; break;
        }
    }
}