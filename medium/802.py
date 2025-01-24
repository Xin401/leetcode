class Solution(object):
    # 1. visited[i] = 0, not visited
    # 2. visited[i] = 1, safe
    # 3. visited[i] = -1, unsafe
    def dfs(self, graph, node, visited, path):
        if graph[node] == [] or visited[node] == 1:
            visited[node] = 1
            return True
        elif visited[node] == -1 or node in path:
            return False
        path.append(node)
        for neighbor in graph[node]:
            if visited[neighbor] == -1:
                visited[node] = -1
                return False
            if visited[neighbor] == 0:
                if not self.dfs(graph, neighbor, visited, path):
                    visited[node] = -1
                    return False
        visited[node] = 1
        return True
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        visited = [0] * len(graph)
        for node in range(len(graph)):
            path = []
            if visited[node] == 0:
                self.dfs(graph, node, visited, path)
        return [i for i in range(len(graph)) if visited[i] == 1]

        
if __name__ == '__main__':
    # graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    print(Solution().eventualSafeNodes(graph))
