#include <iostream>

using namespace std;

typedef struct node {
    string name;
    unsigned int id;
    struct node *next;
} node;

class List {

public:
    
    node *HEAD;
    List() {
        this->HEAD = NULL;
    }

    void insertNode(string name, unsigned int id) {
        node *temp = new node;
        temp->name = name;
        temp->id = id;
        temp->next = this->HEAD;
        this->HEAD = temp;
    }

    void printList() {
        node *temp = this->HEAD;
        while (temp) {
            cout << temp->name << '\n';
            temp = temp->next;
        }
    }

    int removeNode(unsigned int id) {
        node *temp = this->HEAD;
        node *parent = temp;
        while (temp) {
            if (temp->id == id) {
                if (temp == this->HEAD) {
                    this->HEAD = this->HEAD->next;
                } else {
                    parent->next = temp->next;
                }
                delete(temp);
                return 1;
            }
            parent = temp;
            temp = temp->next;
        }
        return -1;
    }

    void clearList() {
        node *temp = this->HEAD;
        while (this->HEAD) {
            temp = this->HEAD;
            this->HEAD = this->HEAD->next;
            delete(temp);
        }
    }

};

int main(int argc, const char * argv[]) {
    List *list = new List();

    list->insertNode("alex", 1);
    list->insertNode("natalie", 2);
    list->insertNode("sarah", 3);
    list->clearList();
    list->printList();

    delete(list);

    return 0;
}