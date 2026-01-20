#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        int height = 0;
        if (n == 1)
        {
            return {0};
        }
        vector<unordered_set<int>> graph(n);
        for (auto edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }
        while (n > 2)
        {
            height++;
            n -= leaves.size();
            vector<int> newLeaves;
            for (auto leaf : leaves)
            {
                graph[*graph[leaf].begin()].erase(leaf);
                if (graph[*graph[leaf].begin()].size() == 1)
                {
                    newLeaves.push_back(*graph[leaf].begin());
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    std::vector<int> result = s.findMinHeightTrees(4, edges);
    for (auto i : result)
    {
        std::cout << i << " ";
    }
}

/*
這是因為我們從葉子節點開始，逐層向內進行廣度優先搜索（BFS）。每一次迭代，我們都刪除當前的葉子節點，並更新它們的鄰居節點。這種方法相當於將樹的外圍剝掉一層。當我們剝掉所有的層時，最後剩下的一個或兩個節點就是樹的中心，也就是最小高度樹的根節點。

如果一個樹的根節點不在樹的中心，那麼樹的高度將會比中心的高度更高。所以，最小高度樹的根節點一定在樹的中心。

在一個無向圖中，樹的中心最多有兩個節點。所以，最後剩下的一個或兩個節點就是最小高度樹的根節點。

最小高度數的高度就是剝掉的層數！！
*/