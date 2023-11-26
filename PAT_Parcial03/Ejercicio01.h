#pragma once

#include "Node.h"
#include <queue>
#include <vector>

class Ejercicio01
{
public:
    // Cambio la firma del método para aceptar un puntero a Node<Node<int>>.
    Node<int>* mergeLists(Node<Node<int>*>* lists);
};

struct CompareNode {
    // Este comparador se usa para la priority_queue.
    bool operator()(Node<int>* const& n1, Node<int>* const& n2) {
        // Asumiendo que quieres la priority_queue en orden descendente.
        return n1->value > n2->value;
    }
};
