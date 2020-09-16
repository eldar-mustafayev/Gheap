# Gheap
This is a special d-ary heap which specifically designed for the shortest path algorithms like Dijkstra and A-star.

The main difference from ordinary d-ary heap is that it uses additional array, namely "map" which stores the indexes of vertices from underlying array of heap.
As a result, it is faster(the delete & insert operation replaced with more convenient operation (decrease-key)), more memory efficient(there is no need to declare the distance array outside, as it can be used from inside of the heap) and more reusable(due to special trick, the complexity of clear operation O(1))!

>Example:

```
#include <vector>
#include <iostream>
#include "gheap.h"

typedef std::pair<unsigned, size_t> edge;

unsigned n_edges, n_nodes;
std::vector<edge> G[N];

size_t dijkstra(int s, int t)
{
	unsigned v;
	size_t path;
	
	static unsigned n_childs = std::max(n_edges / n_nodes, 2U);
	static Gheap<N> H(n_childs);

	H.insert(s, 0);
	while (!H.empty())
	{
		s = H.top().first; path = H.top().second;
		H.pop();

		if (s == t)
		{
			H.clear();
			return path;
		}
			
		for (edge& i : G[s])
		{
			v = i.first;
			path = H.dist(s) + i.second;
			if (path < H.dist(v))
				H.insert(v, path);
		}
	}
}
```
