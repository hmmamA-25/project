#ifndef QRGENE_H
#define QRGENE_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class QRGenerator {
public:
    string generateQR() {
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string code = "QR-";

        for (int i = 0; i < 8; i++) {
            code += chars[rand() % chars.size()];
        }
        return code;
    }
};

#endif
