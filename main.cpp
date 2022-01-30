#include <iostream>

using namespace std;

struct Node {
public:
    int data;
    Node *next;

    Node() {
        this->next = nullptr;
        this->data = -1;
    }

    Node(int data) {
        this->next = nullptr;
        this->data = data;
    }

    Node(int data, Node *next) {
        this->next = next;
        this->data = data;
    }
};


class LL {
public:
    Node *start, *trv;

    LL() {
        start = nullptr;
        resetTRV();
    }

    void resetTRV() {
        trv = start;
    }

    void insertAtBeg(int data) {
        Node *tmp = new Node(data, start);
        start = tmp;
    }

    void insertAtEnd(int data) {
        if (isEmpty()) {
            insertAtBeg(data);
        } else {
            resetTRV();
            while (trv->next != nullptr) {
                trv = trv->next;
            }
            Node *tmp = new Node(data, nullptr);
            trv->next = tmp;
        }
    }

    bool isEmpty() {
        if (start == nullptr)
            return true;
        return false;
    }

    int getLastPos() {
        int count = 0;
        resetTRV();
        if (isEmpty()) {
            return 0;
        } else {

            while (trv != nullptr) {
                trv = trv->next;
                count++;
            }
            return count;
        }
    }

    void insertAtNth(int data, int pos) {

        if (pos == 1) {
            insertAtBeg(data);
        } else if (pos > getLastPos()) {
            if (pos == getLastPos() + 1) {
                insertAtEnd(data);
            } else {
                cout << "Position is too big" << endl;
            }
        }  else {
            resetTRV();
            int currentPos = 1;
            while (currentPos != pos - 1) {
                trv = trv->next;
                currentPos++;
            }
            Node *tmp = new Node(data, trv->next);
            trv->next = tmp;
        }

    }

    void printLL() {
        if (isEmpty()) {
            cout << "Underflow";
        } else {
            resetTRV();
            while (trv != nullptr) {
                cout << trv->data << " -> ";
                trv = trv->next;
            }
            cout << "null";
        }
        cout << endl;
    }

    void deleteAtBeg() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        Node *tmp = start;
        start = tmp->next;
        free(tmp);
    }

    void deleteAtEnd() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        resetTRV();
        while (trv->next->next != nullptr) {
            trv = trv->next;
        }
        Node *tmp = trv->next;
        free(tmp);
        trv->next = nullptr;
    }

    void deleteAtNth(int pos) {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        } else if (pos < 1) {
            cout << "Invalid Position" << endl;
            return;
        } else if (pos > getLastPos()) {
            cout << "Invalid Position, its too big" << endl;
            return;
        } else if (pos == 1) {
            deleteAtBeg();
        } else if (pos == getLastPos()) {
            deleteAtEnd();
        } else {
            resetTRV();
            int currentPos = 1;
            while (currentPos != pos - 1) {
                trv = trv->next;
                currentPos++;
            }
            Node *tmp = trv->next;
            trv->next = tmp->next;
            free(tmp);
        }
    }

    int getSum() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return 0;
        }
        resetTRV();
        int sum = 0;
        while (trv != nullptr) {
            sum = sum + trv->data;
            trv = trv->next;
        }
        return sum;

    }

    int getAvg() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return 0;
        }
        resetTRV();
        int sum = 0;
        while (trv != nullptr) {
            sum = sum + trv->data;
            trv = trv->next;
        }
        return sum / getLastPos();

    }


};

int main() {
    LL l1;
    l1.insertAtBeg(4);
    l1.insertAtBeg(5);
    l1.insertAtBeg(6);
    l1.insertAtBeg(7);
    l1.printLL();
    l1.insertAtNth(69,4);
    l1.printLL();


    return 0;
}




