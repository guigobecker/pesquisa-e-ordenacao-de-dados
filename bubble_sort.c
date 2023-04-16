#include <stdio.h>

void troca(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int vet[], int tam){
    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(vet[j] > vet[j + 1])
                troca(&vet[j], &vet[j + 1]);
        }
    }
}

void imprime_vet(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

int main(){
    int vet[] = {9, 1, 3, 5, 7};

    bubble_sort(vet, 5);
    imprime_vet(vet, 5);
}