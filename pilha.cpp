#include <iostream>
using namespace std;

class No { // cada nó possui um ponteiro para o próximo e o seu contéudo
    public: 
    No *proxNo; // referência ao índice do próximo nó
    int dado; // conteúdo
    No (){ // construtor
        proxNo = nullptr; 
    } 
};

class Pilha{ // estrutura de dados lifo
    No *topo; // objeto ponteiro do tipo nó, para armazenar o topo da pilha (último inserido), guarda o endereço do topo

    public:     
    Pilha (){
        topo = nullptr;
    }

    ~Pilha() {
        while (!PilhaVazia()) {
            Desempilha(); // Chama o método para desempilhar e liberar a memória de cada nó.
        }
    }

    bool PilhaVazia(){
        return (topo == nullptr);  
    }

    void Empilha (int NovoDado){ // adiciona um item
        No *novoNo = new No();  // instancia na memória um espaço para um obj nó;
        novoNo->dado = NovoDado; // o conteúdo dele é o novoDado (seria tipo no.dado),  usa-se '->' pq é um ponteiro
        novoNo->proxNo = topo; // o próximo dele é o que antigamente estava no topo, pq o novo passa a ficar acima do antigo topo
        topo = novoNo; // o novo nó adicionado é o novo do topo. atribuição direta por = porque os dois são ponteiros
    }

    int Desempilha() { // o item a ser retirado é o topo
        int temp_Dado = 0; // variáveis temporárias para guardar o conteúdo do nó
        No *temp_proxNo = nullptr;
        if (PilhaVazia()== false){
            temp_Dado = topo->dado;
            temp_proxNo = topo->proxNo;

            delete topo; 
            topo  = temp_proxNo;
        }
        return temp_Dado; // retorna o conteúdo do nó retirado, apenas para saber quem saiu;
    }   

    void Mostrar(){
        No* n = topo;
        if(PilhaVazia()){
            cout << "pilha vazia";
        } else {
            while(n != nullptr){
                cout << n->dado << " ";
                n = n->proxNo;
            }
        }
    }

};

int main(int argc, char *argv[]){
    Pilha p;
    cout << p.PilhaVazia()<<"\n";
    p.Empilha(5);
    p.Empilha(8);
    p.Empilha(10);
    p.Empilha(15);
    p.Mostrar(); // 15 10 8 5
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n"; // 15
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n"; // 10
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n"; // 8
    cout <<"Dado desempilhado: "<< p.Desempilha()<< "\n"; /// 5
    cout << p.PilhaVazia()<<"\n"; // 1
    return 0;
}