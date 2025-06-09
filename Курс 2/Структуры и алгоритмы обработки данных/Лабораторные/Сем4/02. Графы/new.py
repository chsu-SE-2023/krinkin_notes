from itertools import permutations
from tabnanny import check

import matplotlib.pyplot as pyplot
import networkx

class Graph:

    count = 0
    gr = dict()
    cycle = False
    found = False
    min_key = 0

    def __init__(self, filename):
        """
        Конструктор
        :param filename: имя файла, содержащего вершины
        """
        file = open(filename, 'r').readlines()
        self.count = int(file[0])
        f_edges = file[1:]
        for edge in f_edges: # Формирование словаря рёбер
            nodes = list(map(int, edge.split(' ')))
            if nodes[0] not in self.gr: self.gr[nodes[0]] = []
            if nodes[1] not in self.gr: self.gr[nodes[1]] = []
            self.gr[nodes[0]].append(nodes[1])
        self.min_key = min(list(self.gr.keys()))
        draw_graph(self.gr)

    def check_graph(self, nodes) -> bool:
        """
        Метод, возвращающий правильная ли текущая перестановка
        :return: булево значение правильности перестановки
        """
        for key in nodes:
            for i in nodes[key]:
                if key > i: return False
        return True

    def sort_graph(self) -> None:
        """
        Метод, перебирающий все возможные перестановки
        """
        paths = list(permutations(range(self.min_key, self.count+self.min_key), self.count))
        for path in paths:
            new_d = {}
            replaces = {}
            for i in range(len(path)):
                replaces[i+self.min_key] = path[i]
            for key in self.gr:
                new_d[replaces[key]] = []
                for i in self.gr[key]:
                    new_d[replaces[key]].append(replaces[i])
            if self.check_graph(new_d):
                self.found = True
                print(new_d)
                draw_graph(new_d)

window = 100
def draw_graph(nodes: dict) -> None:
    """
    Функция, инициализирующая отрисовку графа
    :param nodes: словарь ребер графа формата
    {'a': [b, c]} - a смежно с b и c
    """
    global window
    pyplot.figure(window)

    graph = networkx.DiGraph()

    for key in nodes:
        for i in nodes[key]:
            graph.add_edge(key, i)

    pos = networkx.spring_layout(graph, k=10, seed=0)
    networkx.draw_networkx_nodes(graph, pos, node_size=500, node_color="yellow")
    networkx.draw_networkx_edges(graph, pos, width=2, arrowsize=25)
    networkx.draw_networkx_labels(graph, pos, font_size=12)

    window += 100

def main():
    g = Graph('input.txt')
    g.sort_graph()
    if g.found: # Проверка на существование пути
        pyplot.tight_layout()
        pyplot.show()
    else:
        print("Таких нумераций не существует")

if __name__ == "__main__":
    main()