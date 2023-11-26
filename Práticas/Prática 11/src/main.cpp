#include <iostream>
#include <string>
#include "../include/AVLTree.hpp"

int main() {
    std::string palavra;
    int pagina;
    AVLTree meuIndice;

    // The loop reads from the standard input until there is no more data to read
    while (std::cin >> palavra >> pagina) {
        meuIndice.insert(palavra, pagina);
    }

    meuIndice.printInOrder();

    return 0;
}