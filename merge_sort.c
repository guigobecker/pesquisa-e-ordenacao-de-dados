#include <stdio.h>

// combina dois sub-vetores L e M em vet

void merge(int v1[], int p, int q, int r){
    // cria v2[p, q] e v3[q + 1, r]

    int tam1 = q- p + 1;
    int tam2 = r - q;

    int v2[tam1], v3[tam2];

    for(int i = 0; i < tam1; i++)
        v2[i] = v1[p + i];
    
    for(int j = 0; j < tam2; j++)
        v3[j] = v1[q + 1 + j];

    // ponteiros para o índice atual dos sub-vetores e de vet

    int i = 0;
    int j = 0;
    int k = p;

    //  até chegar ao fim de v2 ou v3, encontra o menor dentre v2 e v3 e copia em A[p..r]

    while(i < tam1 && j < tam2){
        if(v2[i] <= v3[j]){
            v1[k] = v2[i];
            i++;
        }

        else{
            v1[k] = v3[j];
            j++;
        }

        k++;
    }

    // quando acabarem os elementos em v2 ou v3, copia o restante dos elementos em A[p..r]

    while(i < tam1){
        v1[k] = v2[i];
        i++;
        k++;
    }

    while(j < tam2){
        v1[k] = v3[j];
        j++;
        k++;
    }
}

void merge_sort(int v1[], int i, int f){
    if(i < f){
        int m = i + (f - i) / 2;

        merge_sort(v1, i, m);
        merge_sort(v1, m + 1, f);

        merge(v1, i, m, f);
    }
}

void imprime_vet(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

int main(){
    int vet[] = {9, 1, 3, 5, 7};

    merge_sort(vet, 0, 4);
    imprime_vet(vet, 5);
}