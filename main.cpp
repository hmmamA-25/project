#include <iostream>
#include <cstdlib>
#include <ctime>

#include "HospitalSy.h"
#include "QueueSy.h"

using namespace std;

// ========== Menu Pasien ==========
void patientMenu(HospitalSystem &hs, QueueSystem &qs) {
    while (true) {
        cout << "\n=== Menu Pasien ===\n";
        cout << "1. Registrasi & Buat QR\n";
        cout << "2. Lihat Antrian Publik\n";
        cout << "3. Cek Posisi Antrian (Pakai QR)\n";
        cout << "4. Kembali\n";
        cout << "Pilih: ";

        int c; cin >> c;

        if (c == 1) {
            hs.addPatient();
        }
        else if (c == 2) {
            qs.showPublicQueue();
        }
        else if (c == 3) {
            string code;
            cout << "Masukkan QR Anda: ";
            cin >> code;

            int pos = qs.getPosition(code);
            if (pos == -1) cout << "Anda belum masuk antrian.\n";
            else cout << "Anda urutan ke-" << pos << endl;
        }
        else break;
    }
}

// ========== Menu Admin ==========
void adminMenu(HospitalSystem &hs, QueueSystem &qs) {
    while (true) {
        cout << "\n=== Menu Petugas ===\n";
        cout << "1. Scan QR (Masuk Antrian)\n";
        cout << "2. Lihat Antrian\n";
        cout << "3. Panggil Pasien (Hapus)\n";
        cout << "4. Lihat Semua Data Pasien\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";

        int c; cin >> c;

        if (c == 1) {
            string code;
            cout << "Masukkan QR Code: ";
            cin >> code;

            Patient* p = hs.findByQR(code);
            if (p) qs.enqueue(p);
            else cout << "QR tidak ditemukan.\n";
        }
        else if (c == 2) {
            qs.showQueue();
        }
        else if (c == 3) {
            if (qs.q.empty()) cout << "Antrian kosong.\n";
            else {
                cout << "Memanggil: " << qs.q.front()->name << endl;
                qs.q.pop();
            }
        }
        else if (c == 4) {
            hs.listPatients();
        }
        else break;
    }
}

// ========== MAIN ==========
int main() {
    srand(time(0));

    HospitalSystem hs;
    QueueSystem qs;

    while (true) {
        cout << "\n=== QRMedQueue ===\n";
        cout << "1. Menu Pasien\n";
        cout << "2. Menu Petugas\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";

        int c; cin >> c;

        if (c == 1) patientMenu(hs, qs);
        else if (c == 2) adminMenu(hs, qs);
        else break;
    }

    return 0;
}
