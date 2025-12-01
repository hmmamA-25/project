#ifndef QUEUESY_H
#define QUEUESY_H

#include <queue>
#include "Patient.h"
using namespace std;

class QueueSystem {
public:
    queue<Patient*> q;

    void enqueue(Patient *p) {
        q.push(p);
        cout << p->name << " masuk antrian.\n";
    }

    void showQueue() {
        if (q.empty()) {
            cout << "Antrian kosong.\n";
            return;
        }

        queue<Patient*> temp = q;
        int no = 1;

        cout << "\n=== Antrian Lengkap ===\n";
        while (!temp.empty()) {
            cout << no << ". " << temp.front()->name 
                 << " (" << temp.front()->qrCode << ")\n";
            temp.pop();
            no++;
        }
    }

    void showPublicQueue() {
        if (q.empty()) {
            cout << "Antrian kosong.\n";
            return;
        }

        queue<Patient*> temp = q;
        int no = 1;

        cout << "\n=== Antrian Publik ===\n";
        while (!temp.empty()) {
            cout << no << ". " << temp.front()->name << endl;
            temp.pop();
            no++;
        }
    }

    int getPosition(string qr) {
        queue<Patient*> temp = q;
        int pos = 1;

        while (!temp.empty()) {
            if (temp.front()->qrCode == qr)
                return pos;
            temp.pop();
            pos++;
        }
        return -1;
    }
};

#endif
