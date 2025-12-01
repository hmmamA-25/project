#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    string nik;
    int age;
    string address;
    string qrCode;
    string history;

    void inputData() {
        cout << "Nama   : ";
        cin >> name;
        cout << "NIK    : ";
        cin >> nik;
        cout << "Umur   : ";
        cin >> age;
        cout << "Alamat : ";
        cin >> address;
        cout << "Riwayat Medis : ";
        cin >> history;
    }

    void display() {
        cout << "Nama          : " << name << endl;
        cout << "NIK           : " << nik << endl;
        cout << "Umur          : " << age << endl;
        cout << "Alamat        : " << address << endl;
        cout << "Riwayat Medis : " << history << endl;
        cout << "QR     : " << qrCode << endl;
        cout << "-----------------------------" << endl;
    }
};

#endif
