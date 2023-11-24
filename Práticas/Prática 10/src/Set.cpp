#include "../include/Set.hpp"

using namespace std;

StringSet::~StringSet(){
    delete[] tabela;
}

StringSet::StringSet(int tamanho){
    tamanhoOriginal = tamanho;
    tamanhoTabela = tamanho;
    tamanhoConjunto = 0;
    tabela = new ElementoTabela[tamanhoTabela];
    for(int i = 0; i < tamanhoTabela; i++){
        tabela[i].vazio = true;
        tabela[i].retirada = false;
    }
}

int StringSet::Hash(string s){
    int h = 0;
    for(int i = 0; i < s.size(); i++){
        h += s[i];
    }
    return h % tamanhoTabela;
}

void StringSet::Rehash(int pos){
    int i = 1;
    int h = Hash(tabela[pos].dado);
    while(!tabela[h].vazio && i < tamanhoTabela){
        h = (h + i) % tamanhoTabela;
        i++;
    }
    if(i < tamanhoTabela){
        tabela[h].dado = tabela[pos].dado;
        tabela[h].vazio = false;
        tabela[h].retirada = false;
    }
    else{
        Resize(tamanhoTabela * 2);
        Inserir(tabela[pos].dado);
    }
}

void StringSet::Resize(size_t tamanho){
    ElementoTabela* novaTabela = new ElementoTabela[tamanho];
    for(int i = 0; i < tamanho; i++){
        novaTabela[i].vazio = true;
        novaTabela[i].retirada = false;
    }
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada){
            int h = Hash(tabela[i].dado);
            int j = 1;
            while(!novaTabela[h].vazio){
                h = (h + j) % tamanho;
                j++;
            }
            novaTabela[h].dado = tabela[i].dado;
            novaTabela[h].vazio = false;
            novaTabela[h].retirada = false;
        }
    }
    delete[] tabela;
    tabela = novaTabela;
    tamanhoTabela = tamanho;
}

void StringSet::Inserir(string s){
    int h = Hash(s);
    int i = 1;
    while(!tabela[h].vazio && i < tamanhoTabela){
        if(tabela[h].dado == s && !tabela[h].retirada)
            return;
        h = (h + i) % tamanhoTabela;
        i++;
    }
    if(i < tamanhoTabela){
        tabela[h].dado = s;
        tabela[h].vazio = false;
        tabela[h].retirada = false;
        tamanhoConjunto++;
    }
    else{
        Resize(tamanhoTabela * 2);
        Inserir(s);
    }
}

void StringSet::Remover(string s){
    int h = Hash(s);
    int i = 1;
    while(!tabela[h].vazio && i < tamanhoTabela){
        if(tabela[h].dado == s && !tabela[h].retirada){
            tabela[h].retirada = true;
            tamanhoConjunto--;
            return;
        }
        h = (h + i) % tamanhoTabela;
        i++;
    }
}

bool StringSet::Pertence(string s){
    int h = Hash(s);
    int i = 1;
    while(!tabela[h].vazio && i < tamanhoTabela){
        if(tabela[h].dado == s && !tabela[h].retirada)
            return true;
        h = (h + i) % tamanhoTabela;
        i++;
    }
    return false;
}

StringSet* StringSet::Intersecao(StringSet* S){
    StringSet* intersecao = new StringSet(tamanhoOriginal);
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada && S->Pertence(tabela[i].dado))
            intersecao->Inserir(tabela[i].dado);
    }
    return intersecao;
}

StringSet* StringSet::Uniao(StringSet* S){
    StringSet* uniao = new StringSet(tamanhoOriginal);
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada)
            uniao->Inserir(tabela[i].dado);
    }
    for(int i = 0; i < S->tamanhoTabela; i++){
        if(!S->tabela[i].vazio && !S->tabela[i].retirada)
            uniao->Inserir(S->tabela[i].dado);
    }
    return uniao;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S){
    StringSet* difSimetrica = new StringSet(tamanhoOriginal);
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada && !S->Pertence(tabela[i].dado))
            difSimetrica->Inserir(tabela[i].dado);
    }
    for(int i = 0; i < S->tamanhoTabela; i++){
        if(!S->tabela[i].vazio && !S->tabela[i].retirada && !Pertence(S->tabela[i].dado))
            difSimetrica->Inserir(S->tabela[i].dado);
    }
    return difSimetrica;
}

void StringSet::Imprimir(){
    cout << "{";
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada){
            cout << tabela[i].dado;
            if(i < tamanhoTabela - 1)
                cout << ", ";
        }
    }
    cout << "}\n";
}

// Path: src/main.cpp