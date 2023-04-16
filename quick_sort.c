#include <stdio.h>

void troca(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int vet[], int inicio, int fim){
    int pivo = vet[fim];
    int aux = inicio - 1;

    for(int i = inicio; i < fim; i++){
        if(vet[i] <= pivo){
            aux++;
            troca(&vet[aux], &vet[i]);
        }
    }

    troca(&vet[aux + 1], &vet[fim]);

    return aux + 1;
}

void quick_sort(int vet[], int inicio, int fim){
    if(inicio < fim){
        int pos_pivo = particionar(vet, inicio, fim);
        quick_sort(vet, inicio, pos_pivo - 1);
        quick_sort(vet, pos_pivo + 1, fim);
    }
}

void imprime_vet(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

int main(){
    int vet[] = {9, 1, 3, 5, 7};

    quick_sort(vet, 0, 4);
    imprime_vet(vet, 5);
}