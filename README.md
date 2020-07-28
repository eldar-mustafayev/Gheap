# Gheap
This is special d-ary heap which specifically designed for shortest path algorithms like Dijkstra and A-star.
This is fast, memory efficient and reusable!

The main difference from ordinary d-ary heap is that it uses array named "map" which store index number of vertex in underlying array of heap.
With "map" array we can perform decrease-key operation and get distance. 
Due to it's special logic, it's very reusable: The complexity of clear operation O(1)! 

>Example:

```
#include <vector>
#include <iostream>
#include "gheap.h"

typedef std::pair<unsigned, size_t> edge;

unsigned size;
std::vector<edge> G[N];

size_t dijkstra(int s, int t)
{
	unsigned v;
	size_t path;
	static Gheap<N> H;

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
