#include<stdio.h>

int totalFelinos(int numCrias,int proporcion, int yearsRemaining); //Total De Felinos En Una Lapso Determinado
int felinos(int numCrias,int proporcion, int yearsRemaining); // Cantidad De Felinos Que Naceran En Un Año En Especifico
void formatoImpresión(int actualYear,int years, int crias,int proporcion);

int main(){
    int crias,years,startYear=1;
    float porcentaje;
    printf("Cantidad De Nacimientos Por Hembra: "); 
    scanf("%d",&crias);
    printf("\nPorcentaje De Hembras Por Nacimiento: "); 
    scanf("%f",&porcentaje);
    printf("\nCantidad De Años A Calcular: "); 
    scanf("%d",&years);
    int proporcion=(int)(crias*(porcentaje/100));
    formatoImpresión(startYear,years,crias,proporcion);
    return 0;
}

int totalFelinos(int numCrias, int proporcion, int yearsRemaining){
    if(yearsRemaining>1){
        return numCrias + totalFelinos(numCrias*proporcion,proporcion,yearsRemaining-1);
    }
    else
        return numCrias;
}

int felinos(int numCrias, int proporcion, int yearsRemaining){
    if(yearsRemaining>1){
        return felinos(numCrias*proporcion,proporcion,yearsRemaining-1);
    }
    else
        return numCrias;
}

void formatoImpresión(int actualYear,int years, int crias,int proporcion){
    for(int idx=0;idx<years;idx++){
        printf("Año %d: ",actualYear+idx);
        for(int jdx=0;jdx<=idx;jdx++){
            printf("%d ",felinos(crias,proporcion,jdx+1));
            if(jdx<idx)
                printf("+ ");
        }
        printf("\n");
    }
    printf("Total De Felinos Al Final De Los %d Años: %d\n",years,totalFelinos(crias,proporcion,years));
}