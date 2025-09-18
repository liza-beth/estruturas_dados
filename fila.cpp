#include <iostream>
using namespace std;

class No{ // classe Nó, que representa cada item da fila
    public:
        No *proxNo;
        int dado;
    No() {
        proxNo = nullptr;
    }
};

class Fila{
    No *fim;
    No *inicio;

    public:
    Fila() {
        fim = nullptr;    // o topo agora está aopontando para o fim da fila
        inicio = nullptr; // está apontando para o começo da fila
    }

    ~Fila() {
        while (!FilaVazia()) {
            Retira(); // Chama o método para desempilhar e liberar a memória de cada nó.
        }
    }

    bool FilaVazia(){
        return (inicio == nullptr);
    }
    void Insere(int NovoDado){
        No *novoNo = new No(); // com o new, o nó passa a existir na memória
        novoNo->dado = NovoDado;
        if (FilaVazia() == true){
            inicio = novoNo;
            fim = novoNo;
        }  else {
            fim->proxNo = novoNo; 
            fim = novoNo; // o novo nó inserido passa a ser o último da fila
        }
    }

    int Retira() {
        if (FilaVazia()){
            cout << "fila vazia";
            return 0;
        }

        int temp_Dado = 0;
        No *temp_proxNo = nullptr;
        if (FilaVazia() == false){
            temp_Dado = inicio->dado;
            temp_proxNo = inicio->proxNo;
            delete inicio;        // apagando o conteúdo do objeto q esta sendo apontado
            inicio = temp_proxNo; // porque o topo esta sem referencia e agora eu estou redirecionando-o
            if (inicio == nullptr)
                fim = nullptr;
        }
        return temp_Dado;
    }
};

int main(int argc, char *argv[])
{
    Fila p;
    cout << p.FilaVazia() << "\n"; // 1
    p.Insere(5);
    p.Insere(56);
    cout << "Dado retirado: " << p.Retira() << "\n"; // 5
    cout << "Dado retirado: " << p.Retira() << "\n"; // 56

    p.Insere(8);
    p.Insere(10);
    p.Insere(12);
    p.Insere(13);
    cout << "Dado retirado: " << p.Retira() << "\n"; // 8
    cout << "Dado retirado: " << p.Retira() << "\n"; // 10
    cout << "Dado retirado: " << p.Retira() << "\n"; // 12
    cout << "Dado retirado: " << p.Retira() << "\n"; // 13
    cout << p.FilaVazia() << "\n";
}