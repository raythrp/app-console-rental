#include "FUNCTION.hpp"

int main()
{
    ConsoleRentalDatabase database;
    database.consoleStock = nullptr;

    int choice;
    do
    {
        system("cls");
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "           Manajemen Rental Konsol BUKA 08:00 - 22:00" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "Silakan masukkan angka sesuai menu yang anda pilih!" << std::endl;
        std::cout << "1. Antrean Pelanggan" << std::endl;
        std::cout << "2. Stok Konsol" << std::endl;
        std::cout << "3. Tampilkan Pembayaran" << std::endl;
        std::cout << "0. Keluar" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "Pilihan: ";
        choice = getIntegerInput();

        switch (choice)
        {
        case 1:
        {
            // Customer Queue
            int queueChoice;
            do
            {
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "                      Antrean Pelanggan" << std::endl;
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "1. Masukkin Pelanggan Baru" << std::endl;
                std::cout << "2. Tampilkan Antrean Pelanggan" << std::endl;
                std::cout << "3. Hapus Pelanggan Teratas" << std::endl;
                std::cout << "0. Kembali" << std::endl;
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "Pilihan: ";
                queueChoice = getIntegerInput();

                switch (queueChoice)
                {
                case 1:
                {
                    std::string customerName;
                    int startTime; // Modified data type
                    int duration;
                    std::string targetConsole;

                    std::cout << "Masukkan nama pelanggan: ";
                    std::cin.ignore();
                    std::getline(std::cin, customerName);
                    std::cout << "Masukkan waktu mulai (HHMM): ";
                    startTime = getIntegerInput();
                    std::cout << "Masukkan durasi penggunaan (dalam jam): ";
                    duration = getIntegerInput();
                    std::cout << "Masukkan konsol yang diinginkan: ";
                    std::cin.ignore();
                    std::getline(std::cin, targetConsole);

                    enqueueCustomer(database, customerName, startTime, duration, targetConsole);
                    break;
                }
                case 2:
                    displayCustomerQueue(database);
                    break;
                case 3:
                    if (database.customerQueue.isEmpty())
                    {
                        std::cout << "Antrean kustomer kosong." << std::endl;
                    }
                    else
                    {
                        Customer customer = dequeueCustomer(database);
                        std::cout << customer.name << " telah dihapus dari antrean dan masuk ke laporan keuangan." << std::endl;
                    }
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
                    break;
                }
            } while (queueChoice != 0);
            break;
        }
        case 2:
            // Console Stock
            int stockChoice;
            do
            {
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "                         Stok Konsol" << std::endl;
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "1. Tambah Konsol ke Stok" << std::endl;
                std::cout << "2. Tampilkan Stok Konsol" << std::endl;
                std::cout << "3. Edit Stok Konsol" << std::endl;
                std::cout << "4. Hapus Konsol" << std::endl;
                std::cout << "0. Kembali" << std::endl;
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "Pilihan: ";
                stockChoice = getIntegerInput();

                switch (stockChoice)
                {
                case 1:
                {
                    std::string consoleName;
                    float pricePerHour;
                    int maxCapacity;

                    std::cout << "Masukkan nama konsol: ";
                    std::cin.ignore();
                    std::getline(std::cin, consoleName);
                    std::cout << "Masukkan harga per jam: ";
                    pricePerHour = getIntegerInput();
                    std::cout << "Masukkan jumlah konsol: ";
                    maxCapacity = getIntegerInput();

                    addConsole(database, consoleName, pricePerHour, maxCapacity);
                    break;
                }
                case 2:
                    displayConsoleStock(database);
                    break;
                case 3:
                {
                    std::string editKonsol;
                    int jumlahBaru;
                    std::cout << "Masukkan nama konsol yang ingin diedit: ";
                    std::cin.ignore();
                    std::getline(std::cin,editKonsol);
                    std::cout << "Masukkan jumlah baru: ";
                    jumlahBaru = getIntegerInput();
                    editConsoleCapacity(database, editKonsol, jumlahBaru);
                    break;
                }
                case 4:
                {
                    std::string deleteKonsol;
                    std::cout << "Masukkan nama konsol yang ingin dihapus: ";
                    std::cin.ignore();
                    std::getline(std::cin, deleteKonsol);
                    deleteConsole(database, deleteKonsol);
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
                    break;
                }
            } while (stockChoice != 0);
            break;
        case 3:
            // Display Payment Records
            displayPaymentRecords(database);
            break;
        case 0:
            break;
        default:
            std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
            break;
        }

        system("pause");
    } while (choice != 0);

    return 0;
}