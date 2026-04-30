"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node
        node_copy = Node(node.val, [])
        copies = {node: node_copy}
        q = deque([node])
        while q:
            node = q.popleft()
            for nbr in node.neighbors:
                if nbr not in copies:
                    nbr_copy = Node(nbr.val, [])
                    copies[nbr] = nbr_copy
                    q.append(nbr)
                copies[node].neighbors.append(copies[nbr])

        return node_copy
        