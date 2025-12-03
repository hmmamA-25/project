#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    string nik;
    int age;
    string address;
    string history;
    string qrCode;

    // Input data pasien (FULL GETLINE)
    void inputData() {
        cin.ignore();

        cout << "Nama   : ";
        getline(cin, name);

        cout << "NIK    : ";
        getline(cin, nik);

        cout << "Umur   : ";
        cin >> age;
        cin.ignore();

        cout << "Alamat : ";
        getline(cin, address);

        cout << "Riwayat Medis Singkat : ";
        getline(cin, history);
    }

    void display() {
        cout << "\n=== DATA PASIEN ===\n";
        cout << "Nama    : " << name << endl;
        cout << "NIK     : " << nik << endl;
        cout << "Umur    : " << age << endl;
        cout << "Alamat  : " << address << endl;
        cout << "History : " << history << endl;
        cout << "QR Code : " << qrCode << endl;
    }
};

#endif
