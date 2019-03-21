#include <vector>
#include <iostream>

using namespace std;

struct Edge {
  char startingVertex;
  char endingVertex;
};

struct Vertex {
  char upperCaseLetter;
  vector<Vertex*> adjVertices;
};

class graph {
  private:
    vector<Vertex*> vertices;
    vector<Edge*> edges;
    vector<char*> path;

    Vertex *getVertex(char *v);
    bool isInPath(char*);

  public:
    graph();
    Vertex* addVertex(char *vertex);
    void addEdge(char *startingVertex, char *endingVertex);

    bool hasAdjVertex(char *currVertex);
    char *getAdjVertex(char *currVertex);

    vector<char*> findHamiltonianPath(char*, char*);

    void insertToPath(char *currVertex);
    vector<char*> getPath();

    void graphDestroy();
};

graph::graph() {}

Vertex* graph::addVertex(char *vertex) {
  Vertex *v = new Vertex();
  v->upperCaseLetter = *vertex;
  vertices.push_back(v);
  return v;
}

void graph::addEdge(char *startingVertex, char *endingVertex) {
  Vertex *first_v;
  Vertex *second_v;
  if ((first_v = getVertex(startingVertex)) == NULL) {
    first_v = addVertex(startingVertex);
  }

  if ((second_v = getVertex(endingVertex)) == NULL) {
    second_v = addVertex(endingVertex);
  }

  first_v->adjVertices.push_back(second_v);

  Edge *edge = new Edge();
  edge->startingVertex = *startingVertex;
  edge->endingVertex = *endingVertex;
  edges.push_back(edge);
}

Vertex* graph::getVertex(char *v) {
  for (unsigned i = 0; i < vertices.size(); i++) {
    if (vertices[i]->upperCaseLetter == *v) {
      return vertices[i];
    }
  }

  return NULL;
}

bool graph::hasAdjVertex(char *currVertex) {
  Vertex *v = getVertex(currVertex);
  vector<Vertex*> adjVertices = v->adjVertices;

  for (unsigned i = 0; i < adjVertices.size(); i++) {
    if (adjVertices[i]->upperCaseLetter - *currVertex == 1) {
      return true;
    }
  }

  return false;
}

char* graph::getAdjVertex(char *currVertex) {
  Vertex *v = getVertex(currVertex);
  vector<Vertex*> adjVertices = v->adjVertices;

  for (unsigned i = 0; i < adjVertices.size(); i++) {
    if (adjVertices[i]->upperCaseLetter - *currVertex == 1) {
      return &adjVertices[i]->upperCaseLetter;
    }
  }

  return NULL;
}

vector<char*> graph::findHamiltonianPath(char *currVertex, char *endVertex) {
  if (currVertex == NULL || endVertex == NULL) {
    if (currVertex == NULL) {
      cout << "current vertex is NULL" << endl;
    }

    if (endVertex == NULL) {
      cout << "end vertex is NULL" << endl;
    }

    return vector<char*>();
  }

  insertToPath(currVertex);
  if (*currVertex == *endVertex) {
    return getPath();
  }

  if (hasAdjVertex(currVertex)) {
    char *adjVertex = getAdjVertex(currVertex);
    insertToPath(adjVertex);

    return findHamiltonianPath(adjVertex, endVertex);
  }

  return vector<char*>();
}

void graph::insertToPath(char *currVertex) {
  if (currVertex == NULL) {
    return;
  } else if (isInPath(currVertex)) {
    return;
  }

  path.push_back(currVertex);
}

bool graph::isInPath(char *currVertex) {
  for (unsigned i = 0; i < path.size(); i++) {
    if (*path[i] == *currVertex) {
      return true;
    }
  }

  return false;
}

vector<char*> graph::getPath() {
  if (path.size() == 0) {
    return vector<char*>();
  }

  return path;
}

void graph::graphDestroy() {
  for (unsigned i = 0; i < edges.size(); i++) {
    free(edges[i]);
  }

  for (unsigned i = 0; i < vertices.size(); i++) {
    free(vertices[i]);
  }
}

int main() {
  char a = 'A';
  char b = 'B';
  char c = 'C';
  char d = 'D';
  char e = 'E';

  graph g;

  g.addEdge(&a, &b);
  g.addEdge(&a, &c);
  g.addEdge(&b, &c);
  g.addEdge(&c, &d);
  g.addEdge(&b, &d);
  g.addEdge(&a, &b);

  vector<char*> path = g.findHamiltonianPath(&a, &d);
  if (path.size() == 0) {
    cout << "no path exists" << endl;
  } else {
    for (unsigned i = 0; i < path.size(); i++) {
      cout << *(path[i]) << endl;
    }
  }
  g.graphDestroy();
}
