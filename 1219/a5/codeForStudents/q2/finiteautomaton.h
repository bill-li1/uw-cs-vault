#ifndef FINITEAUTOMATON_H
#define FINITEAUTOMATON_H

#include <memory>
#include <string>
#include <vector>

class FiniteAutomaton {
    public:
    /* Note: Define node however you wish. Its public and private APIs are
     * entirely yours to define. */
    class Node;

    /* Note: You may not extend the *public* API of FiniteAutomaton. However,
     * adding a default constructor is not extending the public API, since an
     * automatic default constructor exists without defining one. So, if you
     * need a constructor, you may define a default constructor. */

    // Add a new node to this finite automaton
    Node *addNode();

    // Add an edge (link) to the graph
    void addEdge(Node *a, Node *b, char c);

    // Search for strings of a given length
    std::vector<std::string> search(Node *start, int len);
};

#endif
