#include <iostream>
#include <string.h>
using namespace std;

class Node {
    public:
        string noMhs;
        Node *next;
    };
    
    class SingleLinkedList {
        Node *START;
    public:
        SingleLinkedList() {
            START = NULL;
        }
    };