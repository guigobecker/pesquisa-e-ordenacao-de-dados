#include <stdio.h>

void troca(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int vet[], int tam, int no){
    int maior = no;
    int esq = 2 * no + 1;
    int dir = 2 * no + 2;

    if(esq < tam && vet[esq] > vet[maior])
        maior = esq;
    
    if(dir < tam && vet[dir] > vet[maior])
        maior = dir;

    if(maior != no){
        troca(&vet[no], &vet[maior]);
        heapify(vet, tam, maior);
    }
}

void heap_sort(int vet[], int tam){
    for(int i = tam / 2 - 1; i >= 0; i--)
        heapify(vet, tam, i);

    for(int j = tam - 1; j >= 0; j--){
        troca(&vet[0], &vet[j]);
        heapify(vet, j, 0);
    }
}

void imprime_vet(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

int main(){
    int vet[] = {9, 1, 3, 5, 7};

    heap_sort(vet, 5    );
    imprime_vet(vet, 5);
}