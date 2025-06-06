import matplotlib.pyplot as pyplot
import networkx

class Graph:

    window = 100
    count = 0
    gr = dict()
    color = list()
    stack = list()

    def __init__(self, filename):
        file = open(filename, 'r').readlines()
        self.count = int(file[0])
        f_edges = file[1:]
        for edge in f_edges:
            nodes = list(map(int, edge.split(' ')))
            if nodes[0] not in self.gr: self.gr[nodes[0]] = []
            if nodes[1] not in self.gr: self.gr[nodes[1]] = []
            self.gr[nodes[0]].append(nodes[1])
        self.color = [0 for _ in range(self.count)]

    def draw_graph(self) -> None:
        pyplot.figure(self.window)

        graph = networkx.DiGraph()

        for key in self.gr:
            for i in self.gr[key]:
                graph.add_edge(key, i)

        pos = networkx.spring_layout(graph, k=10, seed=0)
        networkx.draw_networkx_nodes(graph, pos, node_size=500, node_color="yellow")
        networkx.draw_networkx_edges(graph, pos, width=2, arrowsize=25)
        networkx.draw_networkx_labels(graph, pos, font_size=12)

        self.window *= (self.window // 100) + 1

    def __dfs(self, i: int) -> None:
        self.color[i] += 1
        for j in self.gr[i+1]:
            if self.color[j-1] != 2:
                self.__dfs(j-1)
        self.color[i] = 2
        self.stack.append(i)

    def sort_graph(self) -> None:
        for key in self.gr:
            if self.color[key-1] != 2:
                self.__dfs(key-1)
        renames = {}
        for i in range(len(self.stack)):
            new = self.stack.pop()
            renames[new+1] = i+1
        new_d = {}
        for new in renames:
            new_d[renames[new]] = self.gr[new]
            for i in range(len(new_d[renames[new]])):
                new_d[renames[new]][i] = renames[new_d[renames[new]][i]]
        self.gr = new_d

if __name__ == "__main__":
    g = Graph('input_habr.txt')
    g.draw_graph()
    g.sort_graph()
    g.draw_graph()

    pyplot.tight_layout()
    pyplot.show()