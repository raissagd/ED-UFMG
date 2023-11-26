#include <iostream>
#include <string>
#include "../include/AVLTree.hpp"
#include "../include/PageAVLTree.hpp"

int main() {
    std::string palavra;
    int pagina;
    AVLTree meuIndice;

    while (std::cin >> palavra >> pagina) {
        meuIndice.insert(palavra, pagina);
    }

    meuIndice.printInOrder();

    return 0;
}