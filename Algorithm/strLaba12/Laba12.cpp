    #include <iostream> 
    #include <queue> 
    #include <stack> 

    const int V = 10; // Количество вершин в графе 

    // Матрица смежности 
    int adjacencyMatrix[V][V] = { {0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
                                  {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                                  {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                  {0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                                  {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 1, 0, 0, 1, 0, 0, 0, 0} };

    void BFS(int start) {
        bool visited[V] = { false };
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            std::cout << vertex + 1 << " "; // Выводим вершину (нумерация от 1) 

            for (int i = 0; i < V; ++i) {
                if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        std::cout << std::endl;
    }

    void DFS(int start) {
        bool visited[V] = { false };
        std::stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                std::cout << vertex + 1 << " "; // Выводим вершину (нумерация от 1) 
                visited[vertex] = true;
            }

            for (int i = 0; i < V; ++i) {
                if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
        std::cout << std::endl;
    }

    int main() {
        int startVertex = 0; // Начальная вершина (нумерация от 0) 

        std::cout << "BFS: ";
        BFS(startVertex);

        std::cout << "DFS: ";
        DFS(startVertex);

        return 0;
    }