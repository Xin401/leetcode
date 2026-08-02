from collections import deque
from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors: list[Node] = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None
        q = deque([node])
        mp: dict[Node, Node] = {node: Node(node.val)}
        while q:
            size = len(q)
            for _ in range(size):
                curr = q.popleft()
                for n in curr.neighbors:
                    if n not in mp:
                        mp[n] = Node(n.val)
                        q.append(n)
                    mp[curr].neighbors.append(mp[n])
        return mp[node]
