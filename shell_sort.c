#include <stdio.h>

void shell_sort(int vet[], int tam){
    for(int intervalo = (tam + 1) / 2; intervalo > 0; intervalo /= 2){
        for(int i = intervalo; i < tam; i++){
            int aux = vet[i];
            int j = i - intervalo;

            while(j >= 0 && aux < vet[j]){
                vet[j + intervalo] = vet[j];
                j -= intervalo;
            }

            vet[j + intervalo] = aux;
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

    shell_sort(vet, 5);
    imprime_vet(vet, 5);
}