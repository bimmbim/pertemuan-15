/**
 * @file stack.cpp
 * @mainpage Dokumentasi Project Stack Linked List
 * 
 * @section Deskripsi
 * Program ini merupakan implementasi struktur data stack (tumpukan).
 * Mendukung operasi dasar seperti:
 * - Push
 * - Pop
 * - Display
 * 
 * @section penggunaan Cara Penggunaan
 * Jalankan program dan pilih menu:
 * 1. Push
 * 2. Pop
 * 3. Display
 * 4. Exit
 * 
 * @section Penulis
 * - Nama: Bima Baraja
 * - Tanggal: 23 Juni 2025
 * - NIM: 20240140015 
 * - Kelas: A
 * 
 */

/**
 * @file stack.cpp
 * @author Bima Baraja
 * @brief Program stack
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Copyright (c) 2025
 */

 #include <iostream>
 using namespace std;
 
 // Node class representing a single node in the linked list
 /**
  * @class Node
  * @brief Class Node untuk menyimpan data dan alamat memori
  */
 class Node {
     public:
     int data; ///< variabel data dengan tipe integer 
     Node *next; ///< variabel untuk menyimpan alamat memori node berikutnya
 
     /**
      * @brief Construct a new Node object
      */
     Node() {
         next = NULL;
     }
 };
 
 // Stack class
 /**
  * @class Stack
  * @brief Class Stack menggunakan linked list
  */
 class Stack {
     private:
     Node *top; ///< Pointer to the top node of the stack
 
     public:
     /**
      * @brief Construct a new Stack object
      */
     Stack() {
         top = NULL;
     }
 
     /**
      * @brief Method push untuk menambahkan data ke stack
      * @param value untuk menerima input
      * @return int 
      */
     int push(int value) {
         Node *newNode = new Node(); ///< 1. Alokasi memori untuk node baru
         newNode->data = value; ///< 2. Isi data node dengan nilai input
         newNode->next = top; ///< 3. Arahkan next dari node baru ke top lama
         top = newNode; ///< 4. Jadikan node baru sebagai top baru
         cout << "Push value: " << value << endl;
         return value;
     }
 
     /**
      * @brief Mengecek apakah stack kosong
      * @return true jika kosong
      * @return false jika tidak kosong
      */
     bool isEmpty() {
         return top == NULL;
     }
 
     /**
      * @brief Menghapus elemen paling atas dari stack
      */
     void pop() {
         if (isEmpty()) {
             cout << "Stack is empty." << endl;
             return;
         }
         cout << "Popped value: " << top->data << endl;
         top = top->next; ///< Menggeser top ke node berikutnya setelah node terhapus
     }
 
     /**
      * @brief Menampilkan semua elemen dalam stack
      */
     void peek() {
         if (isEmpty()) {
             cout << "List is empty." << endl;
         } else {
             Node *current = top; ///< Mulai dari node paling atas
             while (current != NULL) {
                 cout << current->data << " " << endl; ///< Tampilkan data tiap node
                 current = current->next; ///< Pindah ke node berikutnya
             }
             cout << endl;
         }
     }
 };
 
 /**
  * @brief Fungsi utama program untuk menjalankan menu stack
  * @return int 
  */
 int main() {
     Stack stack; ///< Objek stack
     int choice = 0; ///< Variabel untuk menyimpan pilihan menu pengguna
     int value; ///< Variabel untuk menyimpan nilai input dari pengguna
 
     while (choice != 4) {
         cout << "1. Push\n";
         cout << "2. Pop\n";
         cout << "3. Peek\n";
         cout << "4. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;
 
         switch (choice) {
             case 1:
                 cout << "Enter the value to push: ";
                 cin >> value;
                 stack.push(value);
                 break;
             case 2:
                 stack.pop();
                 break;
             case 3:
                 stack.peek();
                 break;
             case 4:
                 cout << "Exiting program." << endl;
                 break;
             default:
                 cout << "Invalid choice. Try again." << endl;
                 break;
         }
         cout << endl;
     }
 
     return 0;
 }
 