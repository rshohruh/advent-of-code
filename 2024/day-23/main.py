import sys
import networkx as nx  # pip install networkx

G = nx.Graph()
G.add_edges_from(tuple(str(x).split('-')) for x in sys.stdin.read().strip().split())


# part one
triangles = [clique for clique in nx.enumerate_all_cliques(G) if len(clique) == 3]
ans = 0
for clique in triangles:
    for u in clique:
        if u[0] == 't':
            ans += 1
            break
print(ans)
#part two
cliques = list(nx.find_cliques(G))
max_clique = max(cliques, key=len)
max_clique.sort()

print(",".join(max_clique))