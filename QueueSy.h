#ifndef QUEUESY_H
#define QUEUESY_H

#include <queue>
#include "Patient.h"
using namespace std;

class QueueSystem {
public:
    queue<Patient*> q;

    void enqueue(Patient* p) {
        q.push(p);
        cout << "Pasien ditambahkan ke antrian.\n";
    }

    void showQueue() {
        if (q.empty()) {
            cout << "Antrian kosong.\n";
            return;
        }

        queue<Patient*> temp = q;
        int no = 1;

        cout << "\n=== Daftar Antrian ===\n";
        while (!temp.empty()) {
            cout << no++ << ". " 
                 << temp.front()->name 
                 << " (" << temp.front()->qrCode << ")\n";
            temp.pop();
        }
        cout << "======================\n";
    }
};

#endif
