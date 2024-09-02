#include<stdio.h>

int felinos(int numCrias,int proporcion, int yearsRemaining); // Cantidad De Felinos Que Naceran En Un Año En Especifico
void formatoImpresión(int actualYear,int years, int crias,int proporcion,int criasTotales);

int main(){
    int crias,years,startYear=1,criasTotales=0;
    float porcentaje;
    printf("Cantidad De Nacimientos Por Hembra: "); 
    scanf("%d",&crias);
    printf("\nPorcentaje De Hembras Por Nacimiento: "); 
    scanf("%f",&porcentaje);
    printf("\nCantidad De Años A Calcular: "); 
    scanf("%d",&years);
    int proporcion=(int)(crias*(porcentaje/100));
    formatoImpresión(startYear,years,crias,proporcion,criasTotales);
    return 0;
}

/*
La función calcula la cantidad de crias que naceran en un año especifico, a la vez que imprimime la cantidad
de crias de crias del año anterior para posteriormente calcular las del siguiente año, así hasta calcular la cantidad de años
que se solicitaron.
*/
int felinos(int numCrias, int proporcion, int yearsRemaining){
    if(yearsRemaining>1){
        printf(" %d +",numCrias);
        return felinos(numCrias*proporcion,proporcion,yearsRemaining-1);
    }
    else{
        printf(" %d\n",numCrias);
        return numCrias;
    }
}

/*
La siguiente función imprime la cantidad de crias que han nacido en un año especifico más las que nacieron en años anteriores
con el sigueinte formato:

Año 1: numeroDeCriasIniciales
Año 2: numeroDeCriasIniciales + numCriasDelAño2
Año 3: numeroDeCriasIniciales + numCriasDelAño2 + numCriasDelAño3
.
.
.
Año n: numeroDeCriasIniciales + numCriasDelAño2 + numCriasDelAño3 + ... + numCriasDelAño n
y forma adicional, obtiene la cantidad de crias totales que existiran al final del lapso de tiempo indicado.
*/
void formatoImpresión(int actualYear,int totalYears, int crias,int proporcion,int criasTotales){
    if(actualYear<=totalYears){
        printf("Año %d:",actualYear);
        criasTotales+=felinos(crias,proporcion,actualYear);
        formatoImpresión(actualYear+1,totalYears,crias,proporcion,criasTotales);
    }
    else
        printf("Total De Felinos Al Final De Los %d Años: %d\n",totalYears,criasTotales);
}

/*
Nombre: Brayan López Mercado
Matrícula: 1280838
Fecha DE Entrega: 4 De Septiembre De 2024
Materia: Algoritmos y Estructura De Datos
Grupo: 552
Practica 2: Aplicando Recursividad
*/