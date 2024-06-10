#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

void tambahMahasiswa(vector<Mahasiswa*>& mahasiswas) {
    Mahasiswa* mhs = new Mahasiswa;
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin >> ws, mhs->nama);
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> mhs->nim;
    cout << "Masukkan IPK Mahasiswa: ";
    cin >> mhs->ipk;
    mahasiswas.push_back(mhs);
}

void tampilkanSemuaMahasiswa(const vector<Mahasiswa*>& mahasiswas) {
    cout << "Daftar Mahasiswa:\n";
    for (const auto& mhs : mahasiswas) {
        cout << "Nama: " << mhs->nama << ", NIM: " << mhs->nim << ", IPK: " << mhs->ipk << endl;
    }
}

int main() {
    vector<Mahasiswa*> daftarMahasiswa;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Semua Mahasiswa\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(daftarMahasiswa);
                break;
            case 2:
                tampilkanSemuaMahasiswa(daftarMahasiswa);
                break;
            case 3:
                cout << "Program Berakhir.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);

    for (auto mhs : daftarMahasiswa) {
        delete mhs;
    }

    return 0;
}