# Trabalho Prático 3

O presente trabalho se debruça sobre um problema peculiar, onde o lúdico e o matemático
se entrelaçam em uma brincadeira de transformação de pontos no plano através da
multiplicação de matrizes. Através de uma sequência de matrizes 2x2, em que cada uma
representa uma transformação linear aplicada em um instante específico, foi-se investigada
uma situação onde tais transformações afetam as coordenadas de pontos em uma folha de
papel (sendo um ponto um vetor de dimensões 2x1).
Neste cenário, duas operações se mostraram fundamentais: a atualização, que permite a
substituição de uma matriz em um dado instante, e a consulta, que visa determinar as
coordenadas finais de um ponto dado seus instantes de "nascimento" e "morte". O objetivo
final da brincadeira é determinar a posição em que o ponto morre, uma vez que você sabe o
tempo e a posição onde ele nasce, o tempo em que ele morre e as transformações que
serão aplicadas a ele. A complexidade reside em executar estas operações de maneira
eficiente, o que nos leva à adoção de uma estrutura de dados robusta e adaptada ao
problema: a árvore de segmentação, ou segtree.
A árvore de segmentação é uma estrutura de dados que permite pré-computar soluções
para subarranjos específicos, otimizando tanto consultas quanto atualizações. Neste
trabalho, a implementação desta estrutura de dados foi explorada no contexto do problema
proposto, de forma a demonstrar sua eficácia e eficiência na execução dessa brincadeira.
