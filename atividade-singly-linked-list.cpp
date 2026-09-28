#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

No* inicio = NULL;

void inserir(int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        No* atual = inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void mostrar() {
    No* atual = inicio;
    while (atual != NULL) {
        cout << atual->valor << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL" << endl;
}

int tamanho() {
    int contador = 0;
    No* atual = inicio;

    while (atual != NULL) {
        contador = contador + 1;
        atual = atual->proximo;
    }

    return contador;
}

void removerPosicao(int posicao) {
    if (inicio == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }

    if (posicao == 0) {
        No* removido = inicio;
        inicio = inicio->proximo;
        delete removido;
        return;
    }

    No* anterior = inicio;
    for (int i = 0; i < posicao - 1; i++) {
        if (anterior->proximo == NULL) {
            cout << "Posicao invalida" << endl;
            return;
        }
        anterior = anterior->proximo;
    }

    if (anterior->proximo == NULL) {
        cout << "Posicao invalida" << endl;
        return;
    }

    No* removido = anterior->proximo;
    anterior->proximo = removido->proximo;
    delete removido;
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(40);

    cout << "Lista: ";
    mostrar();

    cout << "Tamanho: " << tamanho() << endl;

    removerPosicao(1);

    cout << "Lista depois de remover a posicao 1: ";
    mostrar();

    cout << "Tamanho: " << tamanho() << endl;

    return 0;
}