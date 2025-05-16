#include <stdio.h>
 
int main(int argc, char const *argv[])
{
    char *Nombre[30];
    int edad;
    FILE *p_archivo;
    p_archivo = fopen ("texto.txt", "w");
    fprintf(stdout,"Ingrese su nombre: \n");
    fgets(Nombre,sizeof(Nombre),stdin);
    Nombre[strlen(Nombre)-1]='\0';
    fprintf(stdout, "cuantos años tienes?\n");
    scanf("%d", &edad);
    if(p_archivo != NULL)
    {
    printf("se cea el archivo \n");
    //Escribir una cadena de caracteres
    fprintf(p_archivo, "Este texto de pruebapara el archivo texto.txt");
    //escribir trdxto y vbles
    fprintf(p_archivo, "hola %s bienvenido al curso\n",Nombre);
}
    fclose(p_archivo);
    return 0;
}