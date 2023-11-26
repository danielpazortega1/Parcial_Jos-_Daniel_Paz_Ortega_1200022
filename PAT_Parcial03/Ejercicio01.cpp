#include "Ejercicio01.h"

Node<int>* Ejercicio01::mergeLists(Node<Node<int>> lists)
{
    if (!lists || !lists->value) return nullptr;

    std::priority_queue<Node<int>, std::vector<Node<int>>, CompareNode> queue;

    Node<Node<int>> currentList = lists;

    while (currentList) {
        if (currentList->value) queue.push(currentList->value);
        currentList = currentList->next;
    }

    Node<int>* resultHead = nullptr;
    Node<int>* currentResult = nullptr;

    while (!queue.empty()) {
        Node<int>* nextNode = queue.top();
        queue.pop();

        if (!resultHead) {
            resultHead = nextNode;
            currentResult = nextNode;
        }
        else {
            currentResult->next = nextNode;
            currentResult = currentResult->next;
        }

        if (nextNode->next) queue.push(nextNode->next);
    }

    if (currentResult) currentResult->next = nullptr;

    return resultHead;
}

