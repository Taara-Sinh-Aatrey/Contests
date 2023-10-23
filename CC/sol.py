import networkx as nx
dg = nx.DiGraph()
dg.add_weighted_edges_from([(1, 4, 0.5)])
dg.add_weighted_edges_from([(3, 1, 0.75)])
print(dg.out_degree(1))
