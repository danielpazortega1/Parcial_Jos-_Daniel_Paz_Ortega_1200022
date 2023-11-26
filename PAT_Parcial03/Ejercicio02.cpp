#include "Ejercicio02.h"
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    vector<string>* result = new vector<string>();
    if (head == nullptr) return result; 

    const int SEQUENCE_LENGTH = 10;
    Node<char>* current = head;
    unordered_map<string, int> sequenceCount;
    string dnaSequence;

    while (current && dnaSequence.length() < SEQUENCE_LENGTH) {
        if (current->value == 'A' || current->value == 'C' || current->value == 'G' || current->value == 'T') {
            dnaSequence += current->value;
        }
        current = current->next;
    }

    if (dnaSequence.length() < SEQUENCE_LENGTH) return result;
    sequenceCount[dnaSequence] = 1;

    while (current) {
        if (current->value == 'A' || current->value == 'C' || current->value == 'G' || current->value == 'T') {
            dnaSequence.erase(0, 1);
            dnaSequence += current->value;
            if (sequenceCount.find(dnaSequence) != sequenceCount.end()) {
     
                if (sequenceCount[dnaSequence] == 1) {
                    result->push_back(dnaSequence);
                }
                sequenceCount[dnaSequence]++;
            }
            else {

                sequenceCount[dnaSequence] = 1;
            }
        }
        current = current->next;
    }

    return result;
}
