#include <iostream>
#include <string.h>
using namespace std;

class Node {
    public:
        int nim;
        string nama;
        Node *next;
    };
    
class LinkedList {
    Node *START;

public:
    LinkedList() {
        START = NULL;
    }

    void addNode() {
        int nim;
        string nama;
        cout << "Masukkan Nomor Mahasiswa : ";
        cin >> nim;
        cout << "Masukkan Nama Mahasiswa : ";
        cin >> nama;

        Node *nodebaru = new Node();
        nodebaru->nim = nim;
        nodebaru->nama = nama;

        if (START == NULL || nim < START->nim) {
            nodebaru->next = START;
            START = nodebaru;
            return;
        } else {
            Node *previous, *current;
            current = START;
            previous = NULL;
            while (current != NULL && nim > current->nim) {
                previous = current;
                current = current->next;
            }

            nodebaru->next = current;
            previous->next = nodebaru;
        }
    }

    