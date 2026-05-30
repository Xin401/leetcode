class Node:
    def __init__(self, key, val):
        self.key: int = key
        self.val: int = val
        self.next: Node = None
        self.prev: Node = None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity: int = capacity
        self.mp: dict[int, Node] = {}
        self.head: Node = Node(-1, 0)
        self.tail: Node = Node(-1, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def removeNode(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def addNode(self, node: Node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next = node
        node.next.prev = node

    def get(self, key: int) -> int:
        if key in self.mp:
            self.removeNode(self.mp[key])
            self.addNode(self.mp[key])
            return self.mp[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.mp[key].val = value
            return
        cache = Node(key, value)
        self.addNode(cache)
        self.mp[key] = cache
        if self.capacity:
            self.capacity -= 1
        else:
            oldest_key = self.tail.prev.key
            self.removeNode(self.mp[oldest_key])
            self.mp.pop(oldest_key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
