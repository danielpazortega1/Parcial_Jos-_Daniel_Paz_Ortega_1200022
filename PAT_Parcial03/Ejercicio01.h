#pragma once

#include "Node.h"
#include <queue>
#include <vector>

class Ejercicio01
{
public:
	Node<int>* mergeLists(Node<Node<int>> lists);
};

struct CompareNode {
	bool operator()(Node<int>* const& n1, Node<int>* const& n2) {
		return n1->value < n2->value;
	}
};