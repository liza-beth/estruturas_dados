#include <iostream>
using namespace std;

void shellSort(int v[], int t){
    int i,j,aux,h=1;
    while(h < t/3){ // h é o gap
        h = h*3+1;
    }
    while(h>=1){
        for(int i = h; i<t; i++){
            aux = v[i];
            j = i;
            while(j >= h && v[j-h] > aux){
                v[j] = v[j-h];
                j = j - h;
            }
            v[j] = aux;
        }
        h = h/3;
    }
    cout << "array ordenado: ";
    for(int i=0; i<t; i++){
        cout << v[i] << " ";
    }
    cout << '\n';
}

int buscaBinaria(int n, int tamanho, int v[]){
    int superior = tamanho-1, inferior = 0;
    int meio = 0;
    while (superior >= inferior){
        meio = (superior + inferior)/2;
        if (n == v[meio]) {return meio;};
        if (n > v[meio]){
            inferior = meio + 1; 
        } else {
            superior = meio - 1;
        }
    }
    return -1;
}

int main(){
    int v[10] = {99,74,52,34,85,0,12,52,11,33};
    int t = sizeof(v)/sizeof(v[0]);
    shellSort(v,t);
    int indice = buscaBinaria(34, t, v); 
    if (indice > -1){
        cout << "número achado na posição " << indice << '\n'; 
    } else {
        cout << "número não foi encontrado no vetor" << '\n';
    }
    int indice2 = buscaBinaria(98, t, v); 
    if (indice2 > -1){
        cout << "número achado na posição " << indice2 << '\n'; 
    } else {
        cout << "número não foi encontrado no vetor" << '\n';
    }
}