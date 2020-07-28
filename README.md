# Gheap
This is special d-ary heap which specifically designed for shortest path algorithms like Dijkstra and A-star.
This is fast, memory efficient and reusable!

The main difference from ordinary d-ary heap is that it uses array named "map" which store index number of vertex in underlying array of heap.
With "map" array we can perform decrease-key operation and get distance.
Due to it's special logic, it's very reusable: The complexity of clear operation O(1)!
