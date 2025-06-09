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
        draw_graph(self.gr) # Отрисовка изначального графа

    def check_graph(self) -> bool:
        """
        Метод, возвращающий существуют ли циклы в графе
        :return: булево значение не существуют ли циклы
        """
        def dfs(current):
            colors[current-self.min_key] = 1
            for neighbor in self.gr[current]:
                if colors[neighbor-self.min_key] != 2:
                    dfs(neighbor)
                else:
                    self.cycle = True
                    break
            colors[current-self.min_key] = 2

        for start_node in range(self.min_key, self.count+self.min_key):
            # Цвета для вершин: 0 - белый, 1 - серый, 2 - чёрный
            colors = [0 for _ in range(self.count)]
            dfs(start_node)
        return not self.cycle

    def dfs_paths(self) -> list:
        """
        Метод, возвращающий все возможные обходы в глубину
        :return: список обходов
        """
        all_paths = []

        def dfs(path, current):
            # Если обойдены все вершины графа
            if len(path) == self.count:
                all_paths.append(path[::-1])
                return
            for neighbor in self.gr[current]:
                if not visited[neighbor-self.min_key]:
                    # Занесение в путь
                    visited[neighbor-self.min_key] = True
                    path.append(neighbor)
                    dfs(path, neighbor)

        # Начало обхода из разных вершин
        for start_node in range(self.min_key, self.count+self.min_key):
            visited = [False] * self.count
            visited[start_node-self.min_key] = True
            dfs([start_node], start_node)

        return all_paths

    def sort_graph(self) -> None:
        """
        Метод, производящий топографическую сортировку графа
        """
        paths = self.dfs_paths()
        if len(paths) > 0: self.found = True
        for path in paths:
            renames = {} # Словарь переименований
            for i in range(len(path)):
                new = path.pop()
                renames[new] = i
            new_d = {}
            for new in renames:
                new_d[renames[new]] = self.gr[new]
                for i in range(len(new_d[renames[new]])):
                    new_d[renames[new]][i] = renames[new_d[renames[new]][i]]
            draw_graph(new_d) # Отрисовка вариации переименований

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
    if not g.check_graph(): # Проверка графа на циклы
        g.sort_graph()
        if g.found: # Проверка на существование пути
            pyplot.tight_layout()
            pyplot.show()
        else:
            print("Таких нумераций не существует")
    else:
        print("Таких нумераций не существует. Обнаружен цикл")

if __name__ == "__main__":
    main()