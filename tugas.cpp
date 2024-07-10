#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi buku
struct Book {
    string title;
    string author;
    int year;
    string isbn;
};

// Vector untuk menyimpan daftar buku
vector<Book> books;

// Fungsi untuk menambah buku baru
void addBook() {
    Book newBook;
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Masukkan Penulis Buku: ";
    getline(cin, newBook.author);
    cout << "Masukkan Tahun Terbit: ";
    cin >> newBook.year;
    cout << "Masukkan ISBN: ";
    cin >> newBook.isbn;
    books.push_back(newBook);
    cout << "Buku berhasil ditambahkan!\n";
}

// Fungsi untuk mencari buku berdasarkan judul atau penulis
void searchBook() {
    string keyword;
    cout << "Masukkan kata kunci (judul atau penulis): ";
    cin.ignore();
    getline(cin, keyword);
    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos) {
            cout << "Judul: " << book.title << ", Penulis: " << book.author << ", Tahun: " << book.year << ", ISBN: " << book.isbn << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Buku tidak ditemukan.\n";
    }
}

// Fungsi untuk memperbarui informasi buku
void updateBook() {
    string isbn;
    cout << "Masukkan ISBN buku yang ingin diupdate: ";
    cin >> isbn;
    for (auto& book : books) {
        if (book.isbn == isbn) {
            cout << "Masukkan Judul Buku Baru: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "Masukkan Penulis Buku Baru: ";
            getline(cin, book.author);
            cout << "Masukkan Tahun Terbit Baru: ";
            cin >> book.year;
            cout << "Informasi buku berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Buku tidak ditemukan.\n";
}

// Fungsi untuk menghapus buku
void deleteBook() {
    string isbn;
    cout << "Masukkan ISBN buku yang ingin dihapus: ";
    cin >> isbn;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            books.erase(it);
            cout << "Buku berhasil dihapus!\n";
            return;
        }
    }
    cout << "Buku tidak ditemukan.\n";
}

// Fungsi untuk menampilkan daftar semua buku
void displayBooks() {
    if (books.empty()) {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }
    for (const auto& book : books) {
        cout << "Judul: " << book.title << ", Penulis: " << book.author << ", Tahun: " << book.year << ", ISBN: " << book.isbn << endl;
    }
}

// Program utama
int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Cari Buku\n";
        cout << "3. Update Informasi Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Tampilkan Daftar Buku\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                displayBooks();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (choice != 6);
    return 0;
}
