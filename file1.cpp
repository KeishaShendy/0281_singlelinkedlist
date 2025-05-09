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

    bool listEmpty() {
        return (START == NULL);
    }

    bool search(int nim, Node *previous, Node *&current) {
        previous = START;
        current = START;
        while (current != NULL && (nim != current->nim)) {
            previous = current;
            current = current->next;
        }
        return (current != NULL);
    }

    bool deleteNode(int nim) {
        Node *current, *previous;
        if (search(nim, previous, current) == false)
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse() {
        if (listEmpty()) {
            cout << "List Kosong" << endl;
            return;
        }
        Node *currentNode = START;
        while (currentNode != NULL) {
            cout << currentNode->nim << " " << currentNode->nama << endl;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList mhs;
    int nim;
    char ch;

    do {
        cout << "Menu : " << endl;
        cout << "1. Menambah data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data dalam List" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch) {
        case '1':
            mhs.addNode();
            break;

            case '2':
            if (mhs.listEmpty() == true) {
                cout << "List Kosong" << endl;
                break;
            }

            cout << "Masukkan nomor mahasiswa yang akan dihapus : ";
            cin >> nim;

            if (mhs.deleteNode(nim) == false)
                cout << "Data tidak ditemukan!" << endl;
            else
                cout << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus " << endl;
            break;

        
            case '3':
            mhs.traverse();
            break;

        case '4':
            cout << "Masukkan nim mahasiswa yang dicari : ";
            cin >> nim;

            Node *previous, *current;
            if (mhs.search(nim, previous, current) == false)
                cout << "Data tidak ditemukan!" << endl;
            else
                cout << "Nim Mahasiswa : " << current->nim << " " << current->nama << endl;
            break;

        case '5':
            break;

            default:
            cout << "Pilihan salah!" << endl;
            break;
        }
    } while (ch != '5');
}