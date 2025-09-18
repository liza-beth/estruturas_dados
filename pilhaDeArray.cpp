#include <iostream>
using namespace std;

class PilhaDeArray{ // estrutura de dados lifo
     private: 
          int *VET; // ponteiro para os índices da pilha
          int ProximaPosicaoLivre; // manipula o índice do topo da pilha, define a posição de quem deve "entrar" ou "sair" e possibilita saber quantos elementos estão na pilha
          int MAX; // quantidade máxima da pilha
     public:
          PilhaDeArray(int qtde){ // construtor
               MAX = qtde;
               VET = new int[MAX]; // "new" aloca um array int de MAX e retorna o endereço do primeiro elemento. VET aponta para o início da memória de um array alocado dinamicamente
               ProximaPosicaoLivre = 0; // ao ser instanciada, não possui elementos ainda, então o ppl é 0 porque é o índice em que vai entrar o primeiro elemento
          }
          ~PilhaDeArray() {
               delete[] VET;
          }

          void Empilha(int n){ // adicionar item n à pilha
                if(ProximaPosicaoLivre < MAX) VET[ProximaPosicaoLivre++] = n; // se tiver "espaço", adiciona no VET[ppl] = n e depois incrementa ppl
          }

          void Mostra(){
               for(int i = 0; i<ProximaPosicaoLivre; i++){
				cout <<VET[i] <<"\n";
               }
          }

          int Desempilha(){ // retirar elemento do ropo
               if(ProximaPosicaoLivre > 0) {return VET[--ProximaPosicaoLivre];} // se tiver elementos na pilha,
               // retira 1 de ppl e retorna que vet agora aponta para o novo índice de ppl
               else {cout << "erro: pilha está vazia" ; return -1;}
          }
};
int main(int argc, char *argv[]){
     PilhaDeArray pilha(5);
     pilha.Empilha(3);
     pilha.Empilha(5);
     pilha.Empilha(7);
     pilha.Empilha(1);
     pilha.Mostra(); // 3, 5, 7, 1
     cout <<"\nDesempilha " <<pilha.Desempilha() <<".\n"; // 1, último a entrar
     cout <<"\nDesempilha " <<pilha.Desempilha() <<".\n"; // 7, novo topo da pilha
     pilha.Mostra(); // 3, 5
     return 0;
}

