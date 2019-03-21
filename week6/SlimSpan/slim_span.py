class Graph:

    def __init__(self):
        self.vertices = {}

    def add_vertex(self, key):
        vertex = Vertex(key)
        self.vertices[key] = vertex

    def get_vertex(self, key):
        return self.vertices[key]

    def __contains__ (self, key):
        return key in self.vertices

    def add_edge(self, src, dest, weight = 1):
        self.vertices[src].add_neighbor(self.vertices[dest], weight)

    def vertex_exist(self, key):
        return key in self.vertices

    def edge_exist(self, src, dest):
        return self.vertices[src].is_neighbor(self.vertices[dest])

    def display(self):
    print('Vertices: ', end='')
    for v in self:
        print(v.get_key(), end=' ')
    print()

    print('Edges: ')
    for v in self:
        for dest in v.get_neighbours():
            w = v.get_weight(dest)
            print('(src={}, dest={}, weight={}) '.format(v.get_key(), dest.get_key(), w))

    def __len__(self):
        return len(self.vertices)

    def __iter__(self):
        return iter(self.vertices.values())

class Vertex:

    def __init__(self):
        
