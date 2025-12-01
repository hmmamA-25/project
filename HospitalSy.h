#ifndef HOSPITALSY_H
#define HOSPITALSY_H

#include <vector>
#include <fstream>
#include "Patient.h"
#include "QrGene.h"
using namespace std;

class HospitalSystem {
public:
    vector<Patient> database;
    QRGenerator qr;

    void addPatient() {
        Patient p;
        p.inputData();
        p.qrCode = qr.generateQR();

        cout << "QR Code Pasien: " << p.qrCode << "\n\n";
        database.push_back(p);
    }

    Patient* findByQR(string code) {
        for (auto &p : database) {
            if (p.qrCode == code) return &p;
        }
        return nullptr;
    }

    void listPatients() {
        for (auto &p : database) {
            p.display();
        }
    }
};

#endif
