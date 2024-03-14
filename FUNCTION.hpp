#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>

struct Customer
{
    std::string name;
    int startTime;
    int duration;
    std::string targetConsole;
};

struct QueueNode
{
    Customer customer;
    QueueNode *next;
};

struct PriorityQueue
{
    QueueNode *front;
    PriorityQueue()
    {
        front = nullptr;
    }

    void enqueue(const Customer &customer)
    {
        QueueNode *newNode = new QueueNode;
        newNode->customer = customer;

        if (front == nullptr || customer.startTime < front->customer.startTime)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            QueueNode *current = front;
            while (current->next != nullptr && customer.startTime >= current->next->customer.startTime)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    Customer dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Antrean kosong!" << std::endl;
            exit(1);
        }

        QueueNode *temp = front;
        Customer customer = temp->customer;
        front = front->next;
        delete temp;
        return customer;
    }
};

struct StackNode
{
    Customer customer;
    StackNode *next;
};

struct PaymentRecordStack
{
    StackNode *top;

    PaymentRecordStack()
    {
        top = nullptr;
    }

    void push(const Customer &customer)
    {
        StackNode *newNode = new StackNode;
        newNode->customer = customer;
        newNode->next = top;
        top = newNode;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    Customer pop()
    {
        if (isEmpty())
        {
            std::cerr << "Laporan keuangan kosong!" << std::endl;
            exit(1);
        }

        Customer customer = top->customer;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return customer;
    }
};

struct Console
{
    std::string name;
    float pricePerHour;
    int maxCapacity;
    int currentUsage;

    Console *next;
};

struct ConsoleRentalDatabase
{
    PriorityQueue customerQueue;
    PaymentRecordStack paymentRecordStack;
    Console *consoleStock;
};

int getIntegerInput()
{
    int value;
    while (!(std::cin >> value))
    {
        std::cout << "Masukkan angka!\n";
        std::cin.clear(); // Hapus input error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

void enqueueCustomer(ConsoleRentalDatabase &database, const std::string &name, int startTime, int duration, const std::string &targetConsole)
{
    if (database.consoleStock == nullptr)
    {
        std::cout << "Stok konsol kosong. Tambah konsol terlebih dahulu di stok sebelum menambahkan kostumer pada antrian" << std::endl;
        return;
    }

    // Cek target konsol user
    Console *console = database.consoleStock;
    bool isValidConsole = false;
    while (console != nullptr)
    {
        if (console->name == targetConsole)
        {
            isValidConsole = true;
            break;
        }
        console = console->next;
    }

    if (!isValidConsole)
    {
        std::cout << "Konsol tidak terdapat di stok. Pilih konsol yang tersedia di stok." << std::endl;
        return;
    }

    // Toko buka dari jam 8 sampe jam 22
    if (startTime < 800 || startTime > 2200)
    {
        std::cout << "Rental masih tutup. Pilih waktu pada jam buka rental 08.00 - 22.00" << std::endl;
        return;
    }

    // Cek waktu mainnya ngelewatin jam 22 gk
    int endTime = startTime + (duration * 100);
    if (endTime > 2200)
    {
        std::cout << "Durasi invalid. Pastikan waktu selesai maksimal pada 22.00" << std::endl;
        return;
    }

    // Cek konsolnya udah dipake sama customer lain belom
    int customersUsingConsole = 0;
    QueueNode *current = database.customerQueue.front;
    while (current != nullptr)
    {
        if (current->customer.targetConsole == targetConsole)
        {
            /*if (startTime >= current->customer.startTime && startTime < current->customer.startTime + (current->customer.duration * 100))
            {
                customersUsingConsole++;
            }*/
            if (current->customer.startTime >= startTime && current->customer.startTime < startTime + (duration * 100))
            {
                //std::cout << "Waktu main yang dipilih bertabrakan dengan kostumer lain. Tolong pilih jam atau konsol lain." << std::endl;
                customersUsingConsole++;
                
            }
            else if (startTime >= current->customer.startTime && startTime < current->customer.startTime + (current->customer.duration * 100))
            {
                customersUsingConsole++;
                //std::cout << "Waktu main yang dipilih bertabrakan dengan kostumer lain. Tolong pilih jam atau konsol lain." << std::endl;
            }
        }
        current = current->next;
    }

    if (customersUsingConsole >= console->maxCapacity)
    {
        std::cout << "Konsol sudah penuh pada jam tersebut, pilih jam atau konsol lain." << std::endl;
        return;
    }

    // Cek playtime customer baru ngemakan playtime customer yang ada di queue gk
    /*current = database.customerQueue.front;
    while (current != nullptr)
    {
        if (current->customer.targetConsole == targetConsole)
        {
            if (current->customer.startTime >= startTime && current->customer.startTime < startTime + (duration * 100))
            {
                std::cout << "Waktu main yang dipilih bertabrakan dengan kostumer lain. Tolong pilih jam atau konsol lain." << std::endl;
                return;
            }
            if (startTime >= current->customer.startTime && startTime < current->customer.startTime + (current->customer.duration * 100))
            {
                std::cout << "Waktu main yang dipilih bertabrakan dengan kostumer lain. Tolong pilih jam atau konsol lain." << std::endl;
                return;
            }
        }
        current = current->next;
    }*/

    // Masukin ke queuenya
    Customer newCustomer;
    newCustomer.name = name;
    newCustomer.startTime = startTime;
    newCustomer.duration = duration;
    newCustomer.targetConsole = targetConsole;

    database.customerQueue.enqueue(newCustomer);
    std::cout << "Kustomer " << name << " telah ditambahkan ke antrean\n";
}

Customer dequeueCustomer(ConsoleRentalDatabase &database)
{
    if (database.customerQueue.isEmpty())
    {
        std::cerr << "Antrean kustomer kosong!" << std::endl;
        exit(1);
    }

    QueueNode *temp = database.customerQueue.front;
    Customer customer = temp->customer;
    database.customerQueue.front = database.customerQueue.front->next;
    delete temp;

    // Masukin customer yang udah di dequeue ke catatan keuangan
    database.paymentRecordStack.push(customer);

    return customer;
}

void addConsole(ConsoleRentalDatabase &database, const std::string &name, float pricePerHour, int maxCapacity)
{
    Console *newConsole = new Console;
    newConsole->name = name;
    newConsole->pricePerHour = pricePerHour;
    newConsole->maxCapacity = maxCapacity;
    newConsole->currentUsage = 0;
    newConsole->next = nullptr;

    if (database.consoleStock == nullptr)
    {
        database.consoleStock = newConsole;
    }
    else
    {
        Console *current = database.consoleStock;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newConsole;
    }

    std::cout << "Konsol " << name << " telah ditambahkan distok." << std::endl;
}

void editConsoleCapacity(ConsoleRentalDatabase &database, const std::string &consoleName, int newCapacity) {
    if (database.consoleStock == nullptr) {
        std::cout << "Stok konsol kosong!" << std::endl;
        return;
    }

    Console *current = database.consoleStock;
    while (current != nullptr) {
        if (current->name == consoleName) {
            /*if (newCapacity < current->currentUsage) {
                std::cout << "Kapasitas tidak dapat dikurangi sampai semua kustomer selesai menggunakan konsol." << std::endl;
                return;
            }*/
            current->maxCapacity = newCapacity;
            std::cout << "Kapasitas konsol " << consoleName << " telah diubah menjadi " << newCapacity << std::endl;
            return;
        }
        current = current->next;
    }

    std::cout << "Konsol " << consoleName << " tidak ditemukan pada stok." << std::endl;
}


void deleteConsole(ConsoleRentalDatabase &database, const std::string &consoleName)
{
    if (database.consoleStock == nullptr)
    {
        std::cout << "Stok konsol kosong!." << std::endl;
        return;
    }

    // Kalo konsol tujuan delete, konsol pertama
    if (database.consoleStock->name == consoleName)
    {
        Console *temp = database.consoleStock;
        database.consoleStock = database.consoleStock->next;
        delete temp;
        std::cout << "Konsol " << consoleName << " telah dihapus dari stok." << std::endl;
        return;
    }

    // Nyari konsol yang mau di delete
    Console *current = database.consoleStock;
    Console *prev = nullptr;
    while (current != nullptr && current->name != consoleName)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "Konsol " << consoleName << " tidak ditemukan pada stok." << std::endl;
        return;
    }

    // Delete konsol
    prev->next = current->next;
    delete current;
    std::cout << "Konsol " << consoleName << " telah dihapus dari stok." << std::endl;
}

void displayConsoleStock(ConsoleRentalDatabase &database)
{
    if (database.consoleStock == nullptr)
    {
        std::cout << "Stok konsol kosong." << std::endl;
        return;
    }

    std::cout << "Stok Konsol:" << std::endl;
    Console *current = database.consoleStock;
    while (current != nullptr)
    {
        std::cout << "Nama: " << current->name;

        // Biar nominalnya keluarnya xx.xxx
        std::stringstream ss;
        ss << std::fixed << std::setprecision(0) << current->pricePerHour;
        std::string priceFormatted = ss.str();
        std::string priceWithSeparators;
        int length = priceFormatted.length();
        for (int i = 0; i < length; ++i) {
            priceWithSeparators.push_back(priceFormatted[i]);
            if ((length - i - 1) % 3 == 0 && i != length - 1) {
                priceWithSeparators.push_back('.');
            }
        }

        std::cout << ", Harga per jam: Rp" << priceWithSeparators;
        std::cout << ", Kapasitas: " << current->maxCapacity << std::endl;
        current = current->next;
    }
}

void displayCustomerQueue(ConsoleRentalDatabase &database)
{
    if (database.customerQueue.isEmpty())
    {
        std::cout << "Antrean kustomer kosong." << std::endl;
        return;
    }

    std::cout << "Antrean kustomer:" << std::endl;
    QueueNode *current = database.customerQueue.front;
    while (current != nullptr)
    {
        std::cout << "Nama: " << current->customer.name; 
        std::cout << ", Jam Mulai: ";

        // Masukin jam dan menit ke variabel baru
        int hours = current->customer.startTime / 100;
        int minutes = current->customer.startTime % 100;

        // output biar ada HH:MM
        std::cout << std::setfill('0') << std::setw(2) << hours << ":" 
                  << std::setfill('0') << std::setw(2) << minutes;
        
        std::cout << ", Durasi: " << current->customer.duration << ", Konsol: " << current->customer.targetConsole << std::endl;
        current = current->next;
    }
}

void displayPaymentRecords(ConsoleRentalDatabase &database)
{
    if (database.paymentRecordStack.isEmpty())
    {
        std::cout << "Laporan keuangan kosong." << std::endl;
        return;
    }

    std::cout << "Laporan keuangan:" << std::endl;
    StackNode *current = database.paymentRecordStack.top;
    Console *temp = database.consoleStock;
    float totalPayment = 0.0;
    int totalCustomer = 0;

    while (current != nullptr)
    {
        // Nyari customernya pake konsol apa
        Console *targetConsole = nullptr;
        temp = database.consoleStock;
        while (temp != nullptr)
        {
            if (temp->name == current->customer.targetConsole)
            {
                targetConsole = temp;
                break;
            }
            temp = temp->next;
        }

        if (targetConsole == nullptr)
        {
            std::cout << "Konsol tidak ditemukan." << current->customer.name << std::endl;
            current = current->next;
            continue;
        } 
        // Ngaliin harga, buat jumlah bayaran percustomer
        float paymentAmount = current->customer.duration * targetConsole->pricePerHour;

        // Ngetotalin pendapatan
        totalPayment += paymentAmount;
        totalCustomer++;

        // Tampilan pembayaran
        std::cout << '\n' << totalCustomer << ".";
        std::cout << "\n--------------------\n";
        std::cout << "     Bon Rental";
        std::cout << "\n--------------------\n";
        std::cout << "Nama: " << current->customer.name 
                  << "\nJam Mulai: ";

        // Masukin jam dan menit ke variabel baru
        int hours = current->customer.startTime / 100;
        int minutes = current->customer.startTime % 100;

        // output biar ada HH:MM
        std::cout << std::setfill('0') << std::setw(2) << hours << ":" 
                  << std::setfill('0') << std::setw(2) << minutes;

        std::cout << "\nDurasi: " << current->customer.duration << " jam" 
                  << "\nKonsol: " << current->customer.targetConsole; 

        // Biar nominalnya keluarnya xx.xxx
        std::stringstream ss;
        ss << std::fixed << std::setprecision(0) << paymentAmount;
        std::string paymentFormatted = ss.str();
        std::string paymentWithSeparators;
        int length = paymentFormatted.length();
        for (int i = 0; i < length; ++i) {
            paymentWithSeparators.push_back(paymentFormatted[i]);
            if ((length - i - 1) % 3 == 0 && i != length - 1) {
                paymentWithSeparators.push_back('.');
            }
        }

        std::cout << "\nRp" << paymentWithSeparators;
        std::cout << "\n--------------------\n";


        current = current->next;
    }

    std::cout << "\nTotal Harga: Rp";
    // Biar nominalnya keluarnya xx.xxx
    std::stringstream ss;
    ss << std::fixed << std::setprecision(0) << totalPayment;
    std::string totalPaymentFormatted = ss.str();
    std::string totalPaymentWithSeparators;
    int length = totalPaymentFormatted.length();
    for (int i = 0; i < length; ++i) {
        totalPaymentWithSeparators.push_back(totalPaymentFormatted[i]);
        if ((length - i - 1) % 3 == 0 && i != length - 1) {
            totalPaymentWithSeparators.push_back('.');
        }
    }
    std::cout << totalPaymentWithSeparators << std::endl;
    std::cout << "Total Pelanggan: " << totalCustomer << std::endl;
}