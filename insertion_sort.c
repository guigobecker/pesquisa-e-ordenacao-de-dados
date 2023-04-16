#include <stdio.h>

void insertion_sort(int vet[], int tam){
    for(int i = 1; i < tam; i++){
        int aux = vet[i];
        int j = i - 1;

        while(aux < vet[j] && j >= 0){
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = aux;
    }
}

void imprime_vet(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

int main(){
    int vet[] = {9, 1, 3, 5, 7};

    insertion_sort(vet, 5);
    imprime_vet(vet, 5);
}