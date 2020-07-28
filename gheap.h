#pragma once

#include<climits>
#include<utility>

template<unsigned N>
class Gheap
{
    public:
        Gheap(unsigned n_childs = 2) : n_childs(n_childs), size(0), reverse_iterator(N) { }

        bool empty() { return size == 0; }

        void insert(unsigned key, size_t value);

        size_t dist(unsigned key);

        void pop();

        pair<unsigned, size_t> top() const { return arr[0]; }

        void clear() { reverse_iterator = N; size = 0; }

        ~Gheap() { }

    private:
        void shiftup(unsigned i);

        void shiftdown(unsigned i);

        unsigned map[N];
        pair<unsigned, size_t> arr[N];
        unsigned n_childs, size, reverse_iterator;
};


//implementation
template<unsigned N>
void Gheap<N>::shiftup(unsigned i)
{
	static unsigned parent;
	while (true)
	{
		parent = (i - 1) / n_childs;
		if (i > 0 and arr[i].second < arr[parent].second)
		{
			std::swap(arr[i], arr[parent]);
			std::swap(map[arr[i].first], map[arr[parent].first]);
			i = parent;
		}
		else
			return;
	}
}

template<unsigned N>
void Gheap<N>::shiftdown(unsigned i)
{
	static unsigned index, child, k;
	index = i;

	while (true)
	{
		child = i * n_childs;
		for (k = 0; k < n_childs; ++k)
		{
			child += 1;
			if (child < size)
			{
				if (arr[child].second < arr[index].second)
					index = child;
			}
			else
				break;
		}

		if (i != index)
		{
			std::swap(arr[i], arr[index]);
			std::swap(map[arr[i].first], map[arr[index].first]);
			i = index;
		}
		else
			return;
	}
}

template<unsigned N>
inline size_t Gheap<N>::dist(unsigned key)
{
	static unsigned index;
	index = map[key];

	if ((index < size or index >= reverse_iterator) and arr[index].first == key)
		return arr[index].second;
	return INT_MAX;
}

template<unsigned N>
void Gheap<N>::insert(unsigned key, size_t value)
{
	static unsigned index;
	index = map[key];

	if (index < size and arr[index].first == key)
	{
		arr[index].second = value;
		shiftup(index);
	}
	else
	{
		arr[size] = { key,value };
		map[key] = size;
		shiftup(size);
		size += 1;
	}
}

template<unsigned N>
void Gheap<N>::pop()
{
	if (size != 0)
	{
		size -= 1;
		reverse_iterator -= 1;

		map[arr[0].first] = reverse_iterator;
		arr[reverse_iterator] = arr[0];
	}

	if (size != 0)
	{
		map[arr[size].first] = 0;
		arr[0] = arr[size];
		shiftdown(0);
	}
}
