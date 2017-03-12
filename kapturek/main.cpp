#define INT_MAX 2147483647

#include <stdio.h>
#include <string.h>

struct Vertice
{
	int index;
	int value;
	Vertice* next;

	Vertice()
	{
		next = NULL;
	}
};

struct VerticePointer
{
	Vertice* first;
	VerticePointer()
	{
		first = NULL;
	}
};

void moveUp(int* heap, int* heapVertice, int* d, int dest)
{
	int parent, child = heapVertice[dest];
	do
	{
		parent = (child - 1) / 2;
		if (d[heap[parent]] <= d[heap[child]])
		{
			break;
		}
		heap[child] ^= heap[parent];
		heap[parent] ^= heap[child];
		heap[child] ^= heap[parent];
		heapVertice[heap[child]] = child;
		heapVertice[heap[parent]] = parent;
		child = parent;
	} while (true);
}

void moveDown(int* heap, int* heapVertice, int* d, int n)
{
	int parent = 0;
	heap[0] = heap[n - 1];
	heapVertice[heap[0]] = 0;
	int pmin, left, right, dist;
	do
	{
		left = 2 * parent + 1;
		if (left >= n)
		{
			break;
		}
		pmin = parent;
		right = left + 1;
		dist = d[heap[left]];
		parent = left;
		if (right < n && d[heap[right]] < dist)
		{
			parent = right;
		}
		heap[parent] ^= heap[pmin];
		heap[pmin] ^= heap[parent];
		heap[parent] ^= heap[pmin];
		heapVertice[heap[parent]] = parent;
		heapVertice[heap[pmin]] = pmin;
	} while (true);
}

int dijkstra(VerticePointer* G, int* p, bool* S, int* d, int* heap, int* heapIndex, int n, int v, int* p2, char* incidenceMatrix, int* d2)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		d[i] = INT_MAX;
		heap[i] = i;
		heapIndex[i] = i;
	}
	memset(S, 0, n * sizeof(bool));
	memset(p, -1, n * sizeof(int));

	d[0] = 0;
	int actualV, u, newDistance;


	for (i = 0; i < n; ++i)
	{
		actualV = heap[0];
		if (actualV == n - 1)
		{
			break;
		}
		moveDown(heap, heapIndex, d, n - i);

		S[actualV] = true;

		for (Vertice* tmp = G[actualV].first; tmp; tmp = tmp->next)
		{
			u = tmp->index;
			if (!S[u])
			{
				newDistance = d[actualV] + tmp->value;
				if (newDistance > 0 && d[u] > newDistance)
				{
					// usuwanie krawędzi
					if (p2 != NULL)
					{
						if ((u == v && actualV == p2[v]) || (u == p2[v] && actualV == u))
						{
							if (incidenceMatrix[u + actualV*n] > 1 && newDistance > d2[u])
							{
								d[u] = newDistance;
								moveUp(heap, heapIndex, d, u);
								continue;
							}
							else
							{
								break;
							}
						}
						d[u] = newDistance;
						moveUp(heap, heapIndex, d, u);
					}
					else
					{
						d[u] = newDistance;
						p[u] = actualV;
						moveUp(heap, heapIndex, d, u);
					}
				}
			}
		}
	}
	return d[n - 1];
}

int DSFb(int v, int vf, VerticePointer* G, int* D, int cv, bool* bridges, char* incidenceMatrix, int n)
{
	int Low = D[v] = cv++;
	int index, tmp;
	for (Vertice* u = G[v].first; u; u = u->next)
	{
		index = u->index;
		if (index != vf)
		{
			if (!D[index])
			{
				tmp = DSFb(index, v, G, D, cv, bridges, incidenceMatrix, n);
				if (tmp < Low)
				{
					Low = tmp;
				}
			}
			else if (D[index] < Low)
			{
				Low = D[index];
			}
		}
	}
	if (vf > -1 && Low == D[v])
	{
		if (incidenceMatrix[v + vf*n] < 2)
		{
			bridges[v] = true;
			bridges[vf] = true;
		}
	}
	return Low;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	VerticePointer* G = new VerticePointer[n];
	int* p = new int[n];
	int* p2 = new int[n];
	bool* S = new bool[n];
	int* d = new int[n];
	int* d2 = new int[n];
	int* heap = new int[n];
	int* heapIndex = new int[n];
	int* D = new int[n];
	bool* bridges = new bool[n];
	char* incidenceMatrix = new char[n*n];
	int i, j, v, v1, v2, e, firstPath, secondPath, distance;

	memset(incidenceMatrix, 0, n*n * sizeof(char));
	memset(bridges, 0, n * sizeof(bool));
	memset(D, 0, n * sizeof(int));

	Vertice* vertice, *tmp;
	for (i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &v1, &v2, &e);
		vertice = G[v1].first;
		tmp = new Vertice;
		tmp->next = vertice;
		tmp->index = v2;
		tmp->value = e;
		G[v1].first = tmp;

		vertice = G[v2].first;
		tmp = new Vertice;
		tmp->next = vertice;
		tmp->index = v1;
		tmp->value = e;
		G[v2].first = tmp;

		++incidenceMatrix[v1 + v2*n];
		++incidenceMatrix[v2*n + v1];
	}

	firstPath = dijkstra(G, p, S, d, heap, heapIndex, n, -1, NULL, NULL, NULL);

	memcpy(d2, d, n * sizeof(int));

	if (firstPath == INT_MAX)
	{
		putchar('#');
		return 0;
	}

	for (i = 0; i < n; ++i)
	{
		if (!D[i])
		{
			DSFb(i, -1, G, D, 1, bridges, incidenceMatrix, n);
		}
	}

	v = n - 1;
	secondPath = INT_MAX;
	do
	{
		// sprawdzamy czy krawedz do usuniecia to most w grafie
		if (bridges[v] && bridges[p[v]] || bridges[p[v]] && bridges[v])
		{
			v = p[v];
			continue;
		}

		distance = dijkstra(G, p2, S, d, heap, heapIndex, n, v, p, incidenceMatrix, d2);

		// sprawdzanie czy druga droga zawiera sie w pierwszej
		if (distance == firstPath)
		{
			v1 = v2 = n - 1;
			while (p[v1] != 0 || p2[v2] != 0)
			{
				if (p[v1] != p2[v2])
				{
					if (secondPath > distance)
					{
						secondPath = distance;
					}
					break;
				}
				v1 = p[v1];
				v2 = p[v2];
			}
		}
		else if (secondPath > distance)
		{
			secondPath = distance;
		}
		v = p[v];
		if (v > 0)
		{
			v = p[v];
			if (v > 0)
			{
				v = p[v];
				if (v > 0)
				{
					v = p[v];
				}
			}
		}
	} while (v > 0);

	if (secondPath == INT_MAX)
	{
		putchar('#');
	}
	else
	{
		printf("%d %d", firstPath, secondPath);
	}

	delete[] incidenceMatrix;
	delete[] bridges;
	delete[] D;
	delete[] heapIndex;
	delete[] heap;
	delete[] d;
	delete[] S;
	delete[] p2;
	delete[] p;
	delete[] G;
	return 0;
}
