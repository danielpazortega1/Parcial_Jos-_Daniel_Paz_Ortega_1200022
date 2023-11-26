#include "Ejercicio02.h"
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    vector<string>* result = new vector<string>();
    if (head == nullptr) return result; // Early return for empty list.

    const int SEQUENCE_LENGTH = 10;
    Node<char>* current = head;
    unordered_map<string, int> sequenceCount;
    string dnaSequence;

    // Initialize the first sequence if there are enough nodes.
    while (current && dnaSequence.length() < SEQUENCE_LENGTH) {
        if (current->value == 'A' || current->value == 'C' || current->value == 'G' || current->value == 'T') {
            dnaSequence += current->value;
        }
        current = current->next;
    }

    // If there weren't enough valid nodes to form a sequence, return the empty result.
    if (dnaSequence.length() < SEQUENCE_LENGTH) return result;

    // Add the first sequence to the count.
    sequenceCount[dnaSequence] = 1;

    // Go through the rest of the nodes, sliding the window.
    while (current) {
        if (current->value == 'A' || current->value == 'C' || current->value == 'G' || current->value == 'T') {
            // Remove the first character of the sequence and add the new valid character.
            dnaSequence.erase(0, 1);
            dnaSequence += current->value;

            // Check if this sequence has already been seen.
            if (sequenceCount.find(dnaSequence) != sequenceCount.end()) {
                // If this is the second time we've seen this sequence, add it to the result.
                if (sequenceCount[dnaSequence] == 1) {
                    result->push_back(dnaSequence);
                }
                sequenceCount[dnaSequence]++;
            }
            else {
                // If it's a new sequence, start the count at 1.
                sequenceCount[dnaSequence] = 1;
            }
        }
        current = current->next;
    }

    return result;
}