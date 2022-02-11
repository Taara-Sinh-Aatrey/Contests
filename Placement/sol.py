import sys
sys.stdout = open('out', 'w')
import networkx as nx
import matplotlib.pyplot as plt
import warnings; warnings.simplefilter('ignore')

A = nx.Graph()
A.add_edge(1, 2)
A.add_edge(2, 3)
A.add_edge(3, 4)
A.add_edge(4, 1)
A.add_edge(3, 5)
A.add_edge(5, 6)
A.add_edge(5, 7)
print("               Network A\n");
for i in range(1, 8):
    print(("Clustering coefficients of" if i == 1 else "                          "), i, ":", nx.clustering(A, i))
print("Average clustering =", nx.average_clustering(A))
print()
total_degree = 0
for i in range(1, 8):
    print(("Degree of" if i == 1 else "         "), i, ":", nx.degree(A, i))
    total_degree += nx.degree(A, i)
print("Average Degree =", total_degree / 7)
print()
print("Degree Centrality : ", nx.degree_centrality(A))
print()
print("Eigen Value Centrality :", nx.eigenvector_centrality(A))
print()

B = nx.Graph()
B.add_edge(1, 2)
B.add_edge(2, 5)
B.add_edge(5, 7)
B.add_edge(7, 6)
B.add_edge(6, 3)
B.add_edge(3, 1)
B.add_edge(4, 1)
B.add_edge(4, 2)
B.add_edge(4, 3)
B.add_edge(4, 5)
B.add_edge(4, 6)
B.add_edge(4, 7)


print("               Network B\n");
for i in range(1, 8):
    print(("Clustering coefficients of" if i == 1 else "                          "), i, ":", nx.clustering(B, i))
print("Average clustering =", nx.average_clustering(B))
print()
total_degree = 0
for i in range(1, 8):
    print(("Degree of" if i == 1 else "         "), i, ":", nx.degree(B, i))
    total_degree += nx.degree(B, i)
print("Average Degree =", total_degree / 7)
print()
print("Degree Centrality : ", nx.degree_centrality(B))
print()
print("Eigen Value Centrality :", nx.eigenvector_centrality(B))
print()
    