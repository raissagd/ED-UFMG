import matplotlib.pyplot as plt

# Números de vértices
vertex_counts = [100, 500, 1000]

# Tempos de execução em segundos para cada método e número de vértices
times_bubble_sort = [4.86e-05, 7.03e-05, 0.0001532]
times_selection_sort = [4.96e-05, 8.56e-05, 0.0001715]
times_insertion_sort = [4.72e-05, 7.07e-05, 0.0001228]
times_quicksort = [4.67e-05, 7.11e-05, 0.0001381]
times_mergesort = [4.89e-05, 8.76e-05, 0.0001577]
times_heapsort = [4.88e-05, 7.16e-05, 0.0002123]
times_custom_sort = [4.73e-05, 0.0001147, 0.0001233]

# Cria o gráfico de linhas
plt.figure(figsize=(10, 8))

plt.plot(vertex_counts, times_bubble_sort, marker='o', label='Bubble Sort')
plt.plot(vertex_counts, times_selection_sort, marker='o', label='Selection Sort')
plt.plot(vertex_counts, times_insertion_sort, marker='o', label='Insertion Sort')
plt.plot(vertex_counts, times_quicksort, marker='o', label='Quicksort')
plt.plot(vertex_counts, times_mergesort, marker='o', label='Mergesort')
plt.plot(vertex_counts, times_heapsort, marker='o', label='Heapsort')
plt.plot(vertex_counts, times_custom_sort, marker='o', label='Custom Sort')

# Adiciona títulos e rótulos
plt.xlabel('Número de Vértices')
plt.ylabel('Tempo de Execução (segundos)')
plt.title('Variação do Tempo de Execução com o Aumento de Vértices')
plt.legend()

# Define os limites para o eixo X
plt.xticks(vertex_counts)

# Mostra o gráfico
plt.show()
