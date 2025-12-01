#include <iostream>
#include <cstdlib>
#include <ctime>

#include "HospitalSy.h"
#include "QueueSy.h"

using namespace std;
void patientMenu(HospitalSystem &hs) {
    while (true) {
        cout << "\n=== Menu Pasien ===\n";
        cout << "1. Registrasi & Buat QR\n";
        cout << "2. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        int c;
        cin >> c;

        if (c == 1) {
            cout << "\n--- Registrasi Pasien ---\n";
            hs.addPatient();   // pasien langsung inputData sendiri
        }
        else {
            break;
        }
    }
}

void adminMenu(HospitalSystem &hs, QueueSystem &qs) {
    while (true) {
        cout << "\n=== Menu Petugas ===\n";
        cout << "1. Scan QR (Masuk Antrian)\n";
        cout << "2. Lihat Antrian\n";
        cout << "3. Panggil / Hapus Antrian\n";
        cout << "4. Lihat Semua Data Pasien\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih: ";

        int c;
        cin >> c;

        if (c == 1) {
            string code;
            cout << "Masukkan QR Code: ";
            cin >> code;
            Patient* p = hs.findByQR(code);

            if (p) {
                qs.enqueue(p);
            } else {
                cout << "QR tidak ditemukan!\n";
            }
        }
        else if (c == 2) {
            qs.showQueue();
        }
        else if (c == 3) {
            if (!qs.q.empty()) {
                cout << "Memanggil: " << qs.q.front()->name << endl;
                qs.q.pop();
            } else {
                cout << "Antrian kosong.\n";
            }
        }
        else if (c == 4) {
            hs.listPatients();
        }
        else {
            break;
        }
    }
}


int main() {
    srand(time(0));   // seed QR code random
    HospitalSystem hs;
    QueueSystem qs;

    while (true) {
        cout << "\n=== QRMedQueue ===\n";
        cout << "1. Masuk sebagai Pasien\n";
        cout << "2. Masuk sebagai Petugas\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            patientMenu(hs);   // pasien daftar sendiri
        }
        else if (choice == 2) {
            adminMenu(hs, qs); // petugas scan & urus antrian
        }
        else if (choice == 3) {
            break;
        }
    }
    while (true) {
        cout << "\n=== QRMedQueue ===\n";
        cout << "1. Registrasi Pasien\n";
        cout << "2. Scan QR (Masuk Antrian)\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Lihat Semua Pasien\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            hs.addPatient();
        }
        else if (choice == 2) {
            string code;
            cout << "Masukkan QR Code: ";
            cin >> code;

            Patient* p = hs.findByQR(code);

            if (p != nullptr) {
                qs.enqueue(p);
            } else {
                cout << "QR tidak ditemukan.\n";
            }
        }
        else if (choice == 3) {
            qs.showQueue();
        }
        else if (choice == 4) {
            hs.listPatients();
        }
        else if (choice == 5) {
            break;
        }
    }
}
