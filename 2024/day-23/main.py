import sys
adj = [tuple(str(x).split('-')) for x in sys.stdin.read().strip().split()]

def bron_kerbosch(R, P, X, graph, cliques):
    if not P and not X:
        cliques.append(R)
        return
    for vertex in list(P):
        bron_kerbosch(
            R.union([vertex]),
            P.intersection(graph[vertex]),
            X.intersection(graph[vertex]),
            graph,
            cliques
        )
        P.remove(vertex)
        X.add(vertex)

def enumerate_all_cliques(graph):
    def bron_kerbosch_all(R, P, X, graph, all_cliques):
        all_cliques.append(R)
        for vertex in list(P):
            bron_kerbosch_all(
                R.union([vertex]),
                P.intersection(graph[vertex]),
                X.intersection(graph[vertex]),
                graph,
                all_cliques
            )
            P.remove(vertex)
            X.add(vertex)
    
    all_cliques = []
    bron_kerbosch_all(set(), set(graph.keys()), set(), graph, all_cliques)
    return all_cliques

graph = {}
for (u, v) in adj:
    if u not in graph:
        graph[u] = set()
    if v not in graph:
        graph[v] = set()
    graph[u].add(v)
    graph[v].add(u)

cliques = enumerate_all_cliques(graph)
# print(*cliques, sep='\n')

# part one
triangles = [clique for clique in cliques if len(clique) == 3]
ans = 0
for clique in triangles:
    for u in clique:
        if u[0] == 't':
            ans += 1
            break
print(ans)

# part two
max_clique = list(max(cliques, key=len))
max_clique.sort()

print(",".join(max_clique))