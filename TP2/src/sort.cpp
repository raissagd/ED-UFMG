//---------------------------------------------------------------------
// Arquivo      : sort.cpp
// Conteúdo     : Implementação dos métodos de ordenação
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/sort.hpp"
#include <iostream>

// Construtor: inicializa a variável 'tam' com o tamanho máximo fornecido
Sort::Sort(int maxtam) {
    tam = maxtam; 
}

// Destruidor
Sort::~Sort() {
    // Nenhuma limpeza necessária pois não há alocação dinâmica de memória
}

// Função para imprimir os vértices por valor
void Sort::printVerticesByValue(Vertix* vertices, int numVertices) {
    std::cout << "1" << " "; 
    for (int i = 0; i < numVertices; i++) {
        std::cout << vertices[i].item << " "; // Imprime o item do vértice
    }
    std::cout << std::endl; 
}

// Função para trocar dois vértices de lugar
void Sort::swap(Vertix *xp, Vertix *yp) {
    Vertix temp = *xp; // Armazena temporariamente o valor de 'xp'
    *xp = *yp; // Atribui o valor de 'yp' a 'xp'
    *yp = temp; // Atribui o valor armazenado temporariamente a 'yp'
}

// Implementação do algoritmo de ordenação Bubble Sort
void Sort::bubblesort(Vertix* arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {    
        // Os últimos 'i' elementos já estão nos lugares corretos
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].color > arr[j+1].color) { // Compara as cores dos vértices
                swap(&arr[j], &arr[j+1]); // Troca se o elemento anterior for maior que o próximo
            }
        }
    }
}

// Implementação do algoritmo de ordenação Selection Sort
void Sort::selectionsort(Vertix* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Encontra o elemento mínimo no array não ordenado
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].color < arr[min_idx].color || 
                (arr[j].color == arr[min_idx].color && j < min_idx)) {
                min_idx = j; // Atualiza o índice do elemento mínimo
            }
        }

        // Troca o elemento mínimo encontrado com o primeiro elemento
        swap(&arr[min_idx], &arr[i]);
    }
}


// Implementação do algoritmo de ordenação Insertion Sort
void Sort::insertionsort(Vertix* arr, int n) {
    Vertix key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i]; // Elemento atual a ser comparado
        j = i - 1;

        /* Mova elementos de arr[0..i-1] que são maiores que a chave
        para uma posição à frente de sua posição atual */
        while (j >= 0 && arr[j].color > key.color) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Coloca a chave na posição correta
    }
}

/// Auxilia na combinação de duas submatrizes de 'arr'.
void Sort::merge(Vertix* arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Cria arrays temporários
    Vertix* L = new Vertix[n1];
    Vertix* R = new Vertix[n2];

    // Copia dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Combina os arrays temporários de volta ao arr[start..end]
    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (L[i].color <= R[j].color) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L; // Libera a memória alocada para o array temporário L
    delete[] R; // Libera a memória alocada para o array temporário R
}

void Sort::mergesort(Vertix* arr, int start, int end) {
    if (start < end) {
        // Mesmo que (start+end)/2, mas evita overflow para valores grandes de start e end
        int mid = start + (end - start) / 2;

        // Ordena as primeiras e segundas metades
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        // Combina as metades
        merge(arr, start, mid, end);
    }
}

int Sort::partition(Vertix* arr, int low, int high) {
    Vertix pivot = arr[high]; // pivô
    int i = (low - 1); // Índice do elemento menor

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor que o pivô por cor ou igual em cor, mas menor em valor do item
        if (arr[j].color < pivot.color || (arr[j].color == pivot.color && arr[j].item < pivot.item)) {
            i++; // incrementa o índice do elemento menor
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Sort::quicksort(Vertix* arr, int low, int high) {
    if (low < high) {
        /* pi é o índice de particionamento, arr[pi] está no lugar certo */
        int pi = partition(arr, low, high);

        // Ordena separadamente os elementos antes e depois da partição
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void Sort::heapify(Vertix* arr, int n, int i) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // índice do filho à esquerda = 2*i + 1
    int right = 2 * i + 2; // índice do filho à direita = 2*i + 2

    // Se o filho da esquerda for maior que a raiz
    if (left < n && (arr[left].color > arr[largest].color || 
        (arr[left].color == arr[largest].color && left < largest)))
        largest = left;

    // Se o filho da direita for maior que o maior até agora
    if (right < n && (arr[right].color > arr[largest].color ||
        (arr[right].color == arr[largest].color && right < largest)))
        largest = right;

    // Se o maior não for raiz
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Troca o raiz com o maior se necessário

        // Heapifica recursivamente a subárvore afetada
        heapify(arr, n, largest);
    }
}

void Sort::heapsort(Vertix* arr, int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai os elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o fim
        std::swap(arr[0], arr[i]);

        // chama max heapify no heap reduzido
        heapify(arr, i, 0);
    }
}

// Função personalizada para ordenação que usa Introsort
void Sort::customsort(Vertix* arr, int n) {
    introsortHelper(arr, 0, n - 1, 2 * log(n)); // Chama o assistente de introsort com profundidade máxima baseada no logaritmo do número de elementos
}

// Assistente recursivo para a execução do Introsort
void Sort::introsortHelper(Vertix* arr, int start, int end, int maxdepth) {
    if (end - start < 16) {
        insertionsort(arr + start, end - start + 1); // Insertion Sort para pequenas partições
    } else if (maxdepth == 0) {
        heapsort(arr + start, end - start + 1); // Heap Sort se a profundidade de recursão for muito alta
    } else {
        int pivot = partition(arr, start, end); // Calcula o pivô para a partição
        introsortHelper(arr, start, pivot - 1, maxdepth - 1); // Ordena os elementos antes do pivô
        introsortHelper(arr, pivot + 1, end, maxdepth - 1); // Ordena os elementos depois do pivô
    }
}