#include "node.h"

int main () {
    Node n{1, new Node{2, new Node{3, nullptr}}};
    Node m{4};

    m = n;
    std::cout << n << std::endl << m << std::endl << std::endl;
    n.next->next->data = 7;
    std::cout << n << std::endl << m << std::endl << std::endl;
}

