# LRU-Cache-Cpp
An implementation of an LRU (Least Recently Used) Cache in C++ that supports constant time get and put operations


---

## Features
- O(1) time complexity for get and put operations.
- Automatically evicts the least recently used entry when capacity is exceeded.
- Implemented using a doubly linked list and hash map.

---

## Algorithm
- A hash map stores keys mapped to nodes of a doubly linked list.
- The doubly linked list maintains usage order.
- Most Recently Used element is placed next to head.
- Least Recently Used element is removed from the tail when  the capacity is full.
---

## Complexity
- **Time Complexity:** O(N) (where N is the number of queries) , since the put and get operations are done in constant time, This is the overall complexity to process all queries.
- **Space Complexity:** O(capacity),as the cache stores at most `capacity` key-value pairs.
---

## Input Format
- Cache Capacity
- Number of Operations
- Operations of type:
     - `put key value`
     - `get key`
---
## Files
- `LRUCache.cpp` - C++ implementation of LRU Cache.
- `input.txt` - Sample Input.
- `output.txt`- Expected Output.
