#include <stdlib.h>
#include <stdio.h>
//#include <time.h>
//#include <sys/types.h>
#include <sys/time.h>

#define N_pruebas 1

// Variables globales para la ejecucion
int h=0, i=0, j=0, k=0, n=0;

// Variables para almacenamiento de matrices
int **matrizA, **matrizB, **matrizC;

// Variables para medicion de tiempo
double L1, L2, E1, E2, T_llenado, T_resolver;

// Registro de las ejecuciones
FILE* metricas;

// Cantidad de pruebas a relizar
int pruebas[5] = {10000, 500, 1000, 5000, 10000};

void get_walltime (double* wcTime) 
{
    struct timeval tp;
    gettimeofday(&tp ,NULL);
    *wcTime=(tp.tv_sec + tp.tv_usec/1000000.0);
}

void inicializaMatrices()
{
    matrizA = (int **) malloc (n*sizeof(int*));
    matrizB = (int **) malloc (n*sizeof(int*));
    matrizC = (int **) malloc (n*sizeof(int*));
    
    for ( i =0; i<n ; i++)
    {
        *(matrizA+i) = (int *) malloc(n*sizeof(int));
        *(matrizB+i) = (int *) malloc(n*sizeof(int));
        *(matrizC+i) = (int *) malloc(n*sizeof(int));
    }
}

void liberaMatrices()
{
    for ( i =0; i<n ; i++)
    {
        free(*(matrizA+i));
        free(*(matrizB+i));
        free(*(matrizC+i));
    }

    free(matrizA);
    free(matrizB);
    free(matrizC);
}

void llenarMatrices()
{
    for (i = 0 ;i < n ; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            matrizA[i][j] = rand()%6;
            matrizB[i][j] = rand()%6;
            matrizC[i][j] = 0;
        }
    }
}

void resetearMatrices()
{
    liberaMatrices();
    inicializaMatrices();
    llenarMatrices();
}

void metodo_IJK()
{
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            for (k = 0 ; k < n; ++k)
            {
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

void metodo_IKJ()
{
    for (i = 0; i < n; ++i)
    {
        for (k = 0; k < n; ++k)
        {
            for (j = 0 ; j < n; ++j)
            {
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

void metodo_JIK()
{
    for (j = 0; j < n; ++j)
    {
        for (i = 0; i < n; ++i)
        {
            for (k = 0 ; k < n; ++k)
            {
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

void metodo_JKI()
{
    for (j = 0; j < n; ++j)
    {
        for (k = 0; k < n; ++k)
        {
            for (i = 0 ; i < n; ++i)
            {
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

void metodo_KIJ()
{
    for (k = 0; k < n; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            for (j = 0 ; j < n; ++j)
            {
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

void metodo_KJI()
{
    for (k = 0; k < n; ++k)
    {
        for (j = 0; j < n; ++j)
        {
            for (i = 0 ; i < n; ++i)
            {
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
            }
        }
    }
}

void relizarPrueba()
{
    inicializaMatrices();

    //get_walltime(&L1);
    llenarMatrices();
    //get_walltime(&L2);
/*
    // Registro del tiempo de llenado
    metricas = fopen("saxpy.txt", "a");
    T_llenado = L2 - L1;
    printf("\tTiempo de llenado: %f s\n" , (T_llenado));
    fprintf(metricas, "\tTiempo de llenado: %f s\n" , (T_llenado));
    fclose(metricas);
    
    // -- metodo IJK
    get_walltime(&E1);
    metodo_IJK();
    get_walltime(&E2);

    metricas = fopen("saxpy.txt", "a");
    T_resolver = E2 - E1;
    printf("\tTiempo método ijk: %f s\n" , (T_resolver));
    fprintf(metricas, "\tTiempo método ijk: %f s\n" , (T_resolver));
    fclose(metricas);

    resetearMatrices();

    
    // -- metodo IKJ
    get_walltime(&E1);
    metodo_IKJ();
    get_walltime(&E2);

    metricas = fopen("saxpy.txt", "a");
    T_resolver = E2 - E1;
    printf("\tTiempo método ikj: %f s\n" , (T_resolver));
    fprintf(metricas, "\tTiempo método ikj: %f s\n" , (T_resolver));
    fclose(metricas);

    resetearMatrices();


    // -- metodo JIK
    get_walltime(&E1);
    metodo_JIK();
    get_walltime(&E2);

    metricas = fopen("saxpy.txt", "a");
    T_resolver = E2 - E1;
    printf("\tTiempo método jik: %f s\n" , (T_resolver));
    fprintf(metricas, "\tTiempo método jik: %f s\n" , (T_resolver));
    fclose(metricas);

    resetearMatrices();
*/

    // -- metodo JKI
    get_walltime(&E1);
    metodo_JKI();
    get_walltime(&E2);

    metricas = fopen("saxpy.txt", "a");
    T_resolver = E2 - E1;
    printf("\tTiempo método jki: %f s\n" , (T_resolver));
    fprintf(metricas, "\tTiempo método jki: %f s\n" , (T_resolver));
    fclose(metricas);

    resetearMatrices();


    // -- metodo KIJ
    get_walltime(&E1);
    metodo_KIJ();
    get_walltime(&E2);

    metricas = fopen("saxpy.txt", "a");
    T_resolver = E2 - E1;
    printf("\tTiempo método kij: %f s\n" , (T_resolver));
    fprintf(metricas, "\tTiempo método kij: %f s\n" , (T_resolver));
    fclose(metricas);

    resetearMatrices();


    // -- metodo KJI
    get_walltime(&E1);
    metodo_KJI();
    get_walltime(&E2);

    metricas = fopen("saxpy.txt", "a");
    T_resolver = E2 - E1;
    printf("\tTiempo método kji: %f s\n\n" , (T_resolver));
    fprintf(metricas, "\tTiempo método kji: %f s\n\n" , (T_resolver));
    fclose(metricas);
}

int main ( int argc, char* argv[]) 
{       
    for(h = 0; h < N_pruebas; ++h)
    {
        metricas = fopen("saxpy.txt", "a");
        n = pruebas[h];
        printf("Prueba para %i elementos:\n", n);
        fprintf(metricas, "Prueba para %i elementos:\n", n);
        fclose(metricas);
        relizarPrueba();
        liberaMatrices();    
    }
    return 0;
}
