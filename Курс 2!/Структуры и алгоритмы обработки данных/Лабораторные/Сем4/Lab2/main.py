import matplotlib.pyplot as pyplot
import networkx

def draw_graph(node_list: list) -> None:
    graph = networkx.DiGraph()

    for nodes in node_list:
        graph.add_edge(nodes[0].strip(), nodes[1].strip())

    pos = networkx.spring_layout(graph, k=10)
    networkx.draw_networkx_nodes(graph, pos, node_size=500, node_color="yellow")
    networkx.draw_networkx_edges(graph, pos, width=2, arrowsize=25)
    networkx.draw_networkx_labels(graph, pos, font_size=12)

    pyplot.tight_layout()
    pyplot.show()

def fix_graph(node_list: list) -> list:
    fixed_edges = []
    for nodes in node_list:
        if int(nodes[0]) < int(nodes[1]):
            fixed_edges.append([nodes[0], nodes[1]])
        else: fixed_edges.append([nodes[1], nodes[0]])
    return fixed_edges

if __name__ == "__main__":

    file = open("input.txt", "r").readlines()
    count = file[0]
    f_edges = file[1:]
    f_nodes = [edge.strip().split(" ") for edge in f_edges]

    draw_graph(fix_graph(f_nodes))
