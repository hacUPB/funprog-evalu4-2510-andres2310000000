#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototipos
char* leer_archivo(const char* nombre_archivo);
char* calcular_estadisticas(const char* contenido);
char* contar_vocales(const char* contenido);
char* reemplazar_palabra(const char* origen, const char* palabraOriginal, const char* nuevaPalabra);
void guardar_resultados(const char* archivo_salida, const char* contenido, const char* estadisticas, const char* vocales);

// Función principal
int main() {
    char* contenido = NULL;
    char* estadisticas = NULL;
    char* vocales = NULL;
    int opcion;
    char nombre_archivo[100];

    do {
        printf("\n--- Menú ---\n");
        printf("1. Ingresar archivo\n");
        printf("2. Calcular estadísticas\n");
        printf("3. Contar vocales\n");
        printf("4. Reemplazar palabra\n");
        printf("5. Guardar resultados\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) 
        {
            printf("Entrada inválida.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // limpia \n

        switch (opcion) 
        {
            case 1:
                printf("Ingrese el nombre del archivo: ");
                fgets(nombre_archivo, sizeof(nombre_archivo), stdin);
                nombre_archivo[strcspn(nombre_archivo, "\n")] = '\0';

                free(contenido);
                contenido = leer_archivo(nombre_archivo);

                if (contenido) 
                {
                    printf("Archivo cargado con éxito.\n");
                }
                break;

            case 2:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
                free(estadisticas);
                estadisticas = calcular_estadisticas(contenido);
                printf("%s", estadisticas);
                break;

            case 3:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
                free(vocales);
                vocales = contar_vocales(contenido);
                printf("%s", vocales);
                break;

            case 4:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
                {
                    char buscar[50], reemplazo[50];
                    printf("Palabra a buscar: ");
                    fgets(buscar, sizeof(buscar), stdin);
                    buscar[strcspn(buscar, "\n")] = '\0';

                    printf("Palabra de reemplazo: ");
                    fgets(reemplazo, sizeof(reemplazo), stdin);
                    reemplazo[strcspn(reemplazo, "\n")] = '\0';

                    char* nuevo = reemplazar_palabra(contenido, buscar, reemplazo);
                    if (nuevo) {
                        free(contenido);
                        contenido = nuevo;
                        printf("Reemplazo completo.\n");
                    }
                }
                break;

            case 5:
                if (!contenido) 
                {
                    printf("Error: no se ha ingresado ningún archivo.\n");
                    break;
                }
                {
                    char salida[100];
                    printf("Nombre del archivo de salida: ");
                    fgets(salida, sizeof(salida), stdin);
                    salida[strcspn(salida, "\n")] = '\0';

                    guardar_resultados(salida, contenido, estadisticas, vocales);
                }
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);

    // Liberar memoria
    free(contenido);
    free(estadisticas);
    free(vocales);

    return 0;
}

// Lectura dinámica
char* leer_archivo(const char* nombre_archivo) 
{
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) 
    {
        perror("Error al abrir el archivo");
        return NULL;
    }

    char buffer[1024];
    size_t capacidad = 1024;
    size_t longitud = 0;
    char* contenido = malloc(capacidad);
    if (!contenido) {
        perror("Error al asignar memoria");
        fclose(archivo);
        return NULL;
    }
    contenido[0] = '\0';

    while (fgets(buffer, sizeof(buffer), archivo)) 
    {
        size_t len = strlen(buffer);
        if (longitud + len + 1 >= capacidad) 
        {
            capacidad *= 2;
            char* nuevo = realloc(contenido, capacidad);
            if (!nuevo) {
                perror("Error al redimensionar memoria");
                free(contenido);
                fclose(archivo);
                return NULL;
            }
            contenido = nuevo;
        }
        strcat(contenido, buffer);
        longitud += len;
    }

    fclose(archivo);
    return contenido;
}

// Estadísticas
char* calcular_estadisticas(const char* contenido) 
{
    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int en_palabra = 0;

    for (int i = 0; contenido[i]; i++) 
    {
        char c = contenido[i];
        if (c != '\n') caracteres++;
        if (c == ' ') espacios++;
        if (c == '\n') lineas++;

        if (!isspace(c) && !en_palabra) 
        {
            en_palabra = 1;
            palabras++;
        } 
        
        else if (isspace(c)) 
        {
            en_palabra = 0;
        }
    }

    char* resultado = malloc(200);
    sprintf(resultado,
            "Caracteres (sin \\n): %d\nPalabras: %d\nEspacios: %d\nLíneas: %d\n",
            caracteres, palabras, espacios, lineas + 1);
    return resultado;
}

// Vocales
char* contar_vocales(const char* contenido) 
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    for (int j = 0; contenido[j]; j++) 
    {
        switch (tolower(contenido[j])) 
        {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }

    char* resultado = malloc(100);
    sprintf(resultado, "a: %d\ne: %d\ni: %d\no: %d\nu: %d\n", a, e, i, o, u);
    return resultado;
}

// Reemplazo de palabra
char* reemplazar_palabra(const char* origen, const char* palabraOriginal, const char* nuevaPalabra) 
{
    if (!origen || !palabraOriginal || !nuevaPalabra) 
    {
        printf("Error: punteros nulos.\n");
        return NULL;
    }

    char* resultado = NULL;
    int tamanoTexto = strlen(origen);
    int tamanoOriginal = strlen(palabraOriginal);
    int tamanoNueva = strlen(nuevaPalabra);
    int ocurrencias = 0;

    // Contar ocurrencias
    const char* temp = origen;
    while ((temp = strstr(temp, palabraOriginal)) != NULL) 
    {
        ocurrencias++;
        temp += tamanoOriginal;
    }

    // Calcular nuevo tamaño
    int nuevoTamano = tamanoTexto + ocurrencias * (tamanoNueva - tamanoOriginal) + 1;

    resultado = (char*)malloc(nuevoTamano);
    if (!resultado) 
    {
        perror("Error al asignar memoria");
        return NULL;
    }

    const char* ptrOrigen = origen;
    char* ptrResultado = resultado;

    while ((temp = strstr(ptrOrigen, palabraOriginal)) != NULL) 
    {
        int lenAntes = temp - ptrOrigen;
        strncpy(ptrResultado, ptrOrigen, lenAntes);
        ptrResultado += lenAntes;

        strcpy(ptrResultado, nuevaPalabra);
        ptrResultado += tamanoNueva;

        ptrOrigen = temp + tamanoOriginal;
    }

    strcpy(ptrResultado, ptrOrigen); // copiar el resto
    return resultado;
}

// Guardar resultados hechos en 2-3-4
void guardar_resultados(const char* archivo_salida, const char* contenido, const char* estadisticas, const char* vocales) {
    FILE* out = fopen(archivo_salida, "w");
    if (!out) 
    {
        perror("Error al guardar archivo");
        return;
    }

    fprintf(out, "Contenido del archivo:\n%s\n", contenido);
    if (estadisticas)
        fprintf(out, "\nEstadísticas:\n%s", estadisticas);
    if (vocales)
        fprintf(out, "\nFrecuencia de vocales:\n%s", vocales);

    fclose(out);
    printf("Resultados guardados en %s\n", archivo_salida);
}