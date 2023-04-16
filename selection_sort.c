#include <stdio.h>

void troca(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void selection_sort(int vet[], int tam){
    for(int i = 0; i < tam - 1; i++){
        int menor = i;

        for(int j = i + 1; j < tam; j++){
            if(vet[j] < vet[menor])
                menor = j;
        }

        if(menor != i)
            troca(&vet[i], &vet[menor]);
    }
}

void imprime_vet(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

int main(){
    int vet[] = {9, 1, 3, 5, 7};

    selection_sort(vet, 5);
    imprime_vet(vet, 5);
}