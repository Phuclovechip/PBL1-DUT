#include <bits/stdc++.h>
using namespace std;

// ==================== DISPLAY FUNCTIONS ====================

void displayHeader1() {
    cout << "\n\t\t====================================================";
    cout << "\n\t\t               He Thong Quan Ly Thu Vien               ";
    cout << "\n\t\t====================================================";
}
void displayHeader2() {
        cout << "\n\t\t=============================================";
        cout << "\n\t\t             DANG NHAP TAI KHOAN             ";
        cout << "\n\t\t=============================================\n";
    }

void displayRole1() {
    cout << "\n\t\t====================================================";
    cout << "\n\t\t               Chuc Nang Danh Cho Nhan Vien            ";
    cout << "\n\t\t====================================================";
}

void displayRole2() {
    cout << "\n\t\t====================================================";
    cout << "\n\t\t               Chuc nang danh cho Sinh Vien            ";
    cout << "\n\t\t====================================================";
}

void displayChoice() {//ham hiển thị lựa chọn
    system("cls");
    displayHeader1();
    cout << "\n\t\t1. Khach hang";
    cout << "\n\t\t2. Nhan vien";
    cout << "\n\t\t3. Thoat";
    cout << "\n\t\t----------------------------------------------------";
    cout << "\n\t\t>>> Nhap lua chon (1-3): ";
}

void displaystaffChoice() {//ham hiển thị lựa chọn cho nhân viên
    system("cls");
    displayRole1();
    cout << "\n\t\t1. Kho sach";
    cout << "\n\t\t2. Danh sach KH";
    cout << "\n\t\t3. Them sach";
    cout << "\n\t\t4. Xoa sach";
    cout << "\n\t\t5. Quay lai";
    cout << "\n\t\t----------------------------------------------------";
    cout << "\n\t\t>>> Nhap lua chon (1-5): ";
}

void displayclientChoice() { //ham hiển thị lựa chọn cho khách hàng
    system("cls");
    displayRole2();
    cout << "\n\t\t1. Kho sach";
    cout << "\n\t\t2. Muon sach";
    cout << "\n\t\t3. Tra sach";
    cout << "\n\t\t4. Sach dang muon";
    cout << "\n\t\t5. Quay lai";
    cout << "\n\t\t----------------------------------------------------";
    cout << "\n\t\t>>> Nhap lua chon (1-5): ";
}

void pressEnterToContinue() { //ham delay cho tới khi người dùng enter
    cout << "\n\t\tNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void pressEnterToContinue2() { //ham cùng tác dụng nhưng dùng cho các đoạn bị lỗi nhập 2 lần
    cout << "\n\t\tNhan Enter de tiep tuc...";
    cin.get();
}

void invalidChoice() {
    cout <<"\n\t\tLua chon khong hop le , vui long thu lai sau !";
    pressEnterToContinue2();
}

// ==================== STRUCTS ====================

<<<<<<< Updated upstream
struct RentalRecord {  // cấu trúc cho lịch sử thuê/ hủy
=======
struct RentalRecord {                 //struct luu lai lich su muon sach cua khach hang
>>>>>>> Stashed changes
    string nameRecord, authorRecord;
    string code;
    string idRecord;
    string genreRecord;

    void savefile(ofstream& outFile) const {
        outFile << nameRecord    << "\n"
                << authorRecord << "\n"
                << idRecord      << "\n"
                << code          << "\n"
                << genreRecord << "\n";
    }

    void loadfile(ifstream& inFile) {
        getline(inFile, nameRecord);
        getline(inFile, authorRecord);
        getline(inFile, idRecord);
        getline(inFile, code);
        getline(inFile, genreRecord);
    }
};

<<<<<<< Updated upstream
string generateTicketCode(const vector<RentalRecord>& rentalHistory) { //ham random tên vé, xem nó như một loại KEY để hủy vé
=======
string generateTicketCode(const vector<RentalRecord>& rentalHistory) {   //ham random code cho sach, xem no nhu mot loai KEY de tra sach
>>>>>>> Stashed changes
    srand(static_cast<unsigned int>(time(0)));
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string ticket;
    bool unique;
    do {
        ticket = "";
        for (int i = 0; i < 6; i++) {
            ticket += chars[rand() % chars.length()];
        }
        unique = true;
        for (const auto& record : rentalHistory) {
            if (record.code == ticket) {
                unique = false;
                break;
            }
        }
    } while (!unique);
    return ticket;
}

<<<<<<< Updated upstream
struct client { //struct cấu trúc cho khách hàng
=======
struct client {          //struct luu thong tin cua mot khach hang
>>>>>>> Stashed changes
    string username;
    string password;
    vector<RentalRecord> rentalBooks;

    void saveToFile1Client(ofstream& outFile) { //ham luu thong tin cua mot khach hang vao file
        outFile << username << "\n";
        outFile << password  << "\n";
        outFile << rentalBooks.size() << "\n";
        for (size_t i = 0; i < rentalBooks.size(); i++) {
            rentalBooks[i].savefile(outFile);
        }
    }

    void loadFromFile1Client(ifstream& inFile) { //ham doc thong tin cua mot khach hang tu file
        getline(inFile, username);
        getline(inFile, password);
        int num;
        inFile >> num;
        rentalBooks.resize(num);
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        if (num != 0) {
            for (int i = 0; i < num; i++) {
                rentalBooks[i].loadfile(inFile);
            }
        }
    }

<<<<<<< Updated upstream
    void display1ClientInfo() {   //ham hiển thị thông tin khách hàng
=======
    void display1ClientInfo() {//ham hien thi thong tin cua mot khach hang
>>>>>>> Stashed changes
        system("cls");
        cout << "\n\t\t==========================================================";
        cout << "\n\t\t                    THONG TIN TAI KHOAN                   ";
        cout << "\n\t\t==========================================================";
        cout << "\n\t\tTen dang nhap : " << username << endl;
        cout << "\n\t\tMat khau : "      << password  << endl;
        cout << "\n\t\t==========================================================";
        cout << "\n\t\t                   Lich su muon sach                      ";
        cout << "\n\t\t==========================================================";
        cout << "\n\t\t----------------------------------------------------------";
        if (rentalBooks.empty()) {
            cout << "\n\t\tTrong";
        } else {
            for (int i = 0; i < (int)rentalBooks.size(); i++) {
                cout << "\n\t\t| " << left << setw(20) << "STT"
                 << ": " << setw(32) << (i + 1) << " |";
            	cout << "\n\t\t| " << left << setw(20) << "ID sach"
                 << ": " << setw(32) << rentalBooks[i].idRecord << " |";
            	cout << "\n\t\t| " << left << setw(20) << "CODE sach"
                 << ": " << setw(32) << rentalBooks[i].code << " |";
            	cout << "\n\t\t| " << left << setw(20) << "Ten sach"
                 << ": " << setw(32) << rentalBooks[i].nameRecord << " |";
            	cout << "\n\t\t| " << left << setw(20) << "Tac gia"
                 << ": " << setw(32) << rentalBooks[i].authorRecord<< " |";
            	cout << "\n\t\t| " << left << setw(20) << "The loai"
                 << ": " << setw(32) << rentalBooks[i].genreRecord << " |";
                cout << "\n\t\t----------------------------------------------------------";
            }
        }
    }
};

// ==================== BOOK CLASSES ====================

<<<<<<< Updated upstream
class book {  //lop cha trừu tượng, các loại sách sẽ kế thừa từ lớp này
protected:
=======
class book {             //class cha cua cac loai sach, de tao ra cac class con
protected:               //cac thuoc tinh cua mot cuon sach
>>>>>>> Stashed changes
    string name;
    string author;
    string id;
    int    soluongconlai;
    int    soluongdamuon;
    string genre;

public:
    book() : name(""), author(""), id(""), soluongconlai(0),
             soluongdamuon(0), genre(""){}
    virtual ~book() {}
    virtual void createbook() = 0;   //ham ao, de cac class con ghi de, dung de tao ra mot cuon sach moi

    string getid()                 const { return id; }
    int    getsoluongconlai()      const { return soluongconlai; }
    int    getsoluongdamuon()      const { return soluongdamuon; }
    string getname()               const { return name; }
    string getauthor()             const { return author; }
    string getGenre()            const { return genre; }
    void   setsoluongdamuon(int sl) { soluongdamuon = sl; }
	void   setsoluongconlai(int sl) { soluongconlai = sl; }
	
    void nhapid() {
        cin.ignore();
        getline(cin, id);
    }

<<<<<<< Updated upstream
    void display1BookInfo() const { //ham hiển thị thông tin sách
=======
    void display1BookInfo() const { //ham hien thi thong tin cua mot cuon sach
>>>>>>> Stashed changes
        cout << "\n\t\t| " << left << setw(20) << "ID sach"
         << ": " << setw(32) << id            << " |";
        cout << "\n\t\t| " << left << setw(20) << "Ten sach"
         << ": " << setw(32) << name          << " |";
    	cout << "\n\t\t| " << left << setw(20) << "Tac gia"
         << ": " << setw(32) << author        << " |";
    	cout << "\n\t\t| " << left << setw(20) << "The loai"
         << ": " << setw(32) << genre       << " |";
    	cout << "\n\t\t| " << left << setw(20) << "So luong hien co"
         << ": " << setw(32) << soluongconlai << " |";
    	cout << "\n\t\t| " << left << setw(20) << "So luong da muon"
         << ": " << setw(32) << soluongdamuon << " |";
        cout << "\n\t\t----------------------------------------------------------\n";
    }

<<<<<<< Updated upstream
    void inputBook() { //ham nhập thông tin sách
=======
    void inputBook() {        //ham nhap thong tin cua mot cuon sach
>>>>>>> Stashed changes
        cin.ignore();
        do {
            cout << "\n\t\tNhap ID sach : ";
            getline(cin, id);
            if (id.empty() || id.length() > 10)
                cout << "\n\t\tID khong hop le, yeu cau nhap lai.\n";
        } while (id.empty() || id.length() > 10);

        do {
            cout << "\n\t\tNhap ten sach : ";
            getline(cin, name);
            if (name.empty())
                cout << "\n\t\tten sach khong hop le, yeu cau nhap lai.\n";
        } while (name.empty());

        do {
            cout << "\n\t\tNhap ten tac gia : ";
            getline(cin, author);
            if (author.empty())
                cout << "\n\t\tten tac gia khong hop le, yeu cau nhap lai.\n";
        } while (author.empty());

        do {
            cout << "\n\t\tNhap so luong : ";
            cin >> soluongconlai;
            if (soluongconlai <= 0)
                cout << "\n\t\tSo luong khong hop le, yeu cau nhap lai.\n";
        } while (soluongconlai <= 0);
    }

    void saveToFile1Book(ofstream& outFile) const { //ham lưu thông tin sách vào file
        outFile << genre       << "\n"
                << name          << "\n"
                << author        << "\n"
                << id            << "\n"
                << soluongconlai << "\n"
                << soluongdamuon << "\n";
    }

    void loadFromFile1Book(ifstream& inFile) { //ham tải thông tin sách từ file
        getline(inFile, name);
        getline(inFile, author);
        getline(inFile, id);
        inFile >> soluongconlai >> soluongdamuon;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

class sachkhoahoc : public book {
public:
    sachkhoahoc() { genre = "Khoa hoc"; }
    void createbook() override {
        system("cls");
        cout << "\n\t\t======================================";
        cout << "\n\t\t         THEM SACH KHOA HOC           ";
        cout << "\n\t\t======================================\n";
        book::inputBook();
    }
};

class sachvanhoc : public book {
public:
    sachvanhoc() { genre = "Van hoc"; }
    void createbook() override {
        system("cls");
        cout << "\n\t\t======================================";
        cout << "\n\t\t         THEM SACH VAN HOC            ";
        cout << "\n\t\t======================================\n";
        book::inputBook();
    }
};

class sachlichsu : public book {
public:
    sachlichsu() { genre = "Lich su"; }
    void createbook() override {
        system("cls");
        cout << "\n\t\t======================================";
        cout << "\n\t\t         THEM SACH LICH SU            ";
        cout << "\n\t\t======================================\n";
        book::inputBook();
    }
};

class sachkinhte : public book {
public:
    sachkinhte() { genre = "Kinh te"; }
    void createbook() override {
        system("cls");
        cout << "\n\t\t======================================";
        cout << "\n\t\t         THEM SACH KINH TE            ";
        cout << "\n\t\t======================================\n";
        book::inputBook();
    }
};

class sachnghethuat : public book {
public:
    sachnghethuat() { genre = "Nghe thuat"; }
    void createbook() override {
        system("cls");
        cout << "\n\t\t======================================";
        cout << "\n\t\t         THEM SACH NGHE THUAT         ";
        cout << "\n\t\t======================================\n";
        book::inputBook();
    }
};

class sachthieunhi : public book {
public:
    sachthieunhi() { genre = "Thieu nhi"; }
    void createbook() override {
        system("cls");
        cout << "\n\t\t======================================";
        cout << "\n\t\t         THEM SACH THIEU NHI          ";
        cout << "\n\t\t======================================\n";
        book::inputBook();
    }
};

// ==================== BOOK MANAGER ====================

<<<<<<< Updated upstream
class BookManager { //lop quản lý sách, quản lý khách hàng và lịch sử thuê
=======
class BookManager { //lop quan ly toan bo cac chuc nang cua he thong
>>>>>>> Stashed changes
    vector<RentalRecord> RentalHistory;
    vector<book*>        books;
    vector<client>    accounts;

public:
<<<<<<< Updated upstream
    BookManager() {// constructor, dùng để tải dữ liệu ban đầu ở file lên
=======
    BookManager() {   //constructor, dung de load du lieu tu file len
>>>>>>> Stashed changes
        loadFromFileAllBook();
        loadFromFileAllClient();
    }

<<<<<<< Updated upstream
    ~BookManager() {//ham hủy dùng để tránh bị tràn bộ nhớ
=======
    ~BookManager() {  //destructor, dung de giai phong bo nho
>>>>>>> Stashed changes
        saveToFileAllBook();
        saveToFileAllClient();
    }

    // -------------------- CLIENT FUNCTION --------------------

<<<<<<< Updated upstream
    void rentBook(int index) { //ham thuê sách, index là vị trí của khách hàng trong vector accounts
=======
    void rentBook(int index) {//ham cho phep khach hang muon sach, index la vi tri cua khach hang trong vector accounts
>>>>>>> Stashed changes
        string idbook;
        int index1;
        int choice;
        while(true) {
            bool check=false;
            system("cls");
            cout << "\n\t\tNhap ID sach ban can muon : ";
            getline(cin, idbook);
            for (int i = 0; i < books.size(); i++) {
                if (books[i]->getid() == idbook){
                    check=true;index1=i;
                    break;
                }
            }
            if (!books.empty()) {
                    if (check==true) {
                        if (books[index1]->getsoluongconlai() == 0) {
                            cout << "\n\t\tXin loi quy khach, sach nay da het.";
                            while(true) {
                                cout << "\n\t\tNhan 0 de quay lai : ";
                                cin >> choice;
                                cin.ignore();
                                if(choice==0) return;
                                else {
                                    invalidChoice();
                                }
                            }
                        } 
                        else {
                            RentalRecord a;
                            a.authorRecord = books[index1]->getauthor();
                            a.idRecord      = books[index1]->getid();
                            a.nameRecord    = books[index1]->getname();
                            a.genreRecord = books[index1]->getGenre();
                            a.code          = generateTicketCode(RentalHistory);
                            accounts[index].rentalBooks.push_back(a);
                            RentalHistory.push_back(a);
                            int sl = books[index1]->getsoluongconlai() - 1;
                            books[index1]->setsoluongconlai(sl);
                            int slm = books[index1]->getsoluongdamuon() + 1;
                            books[index1]->setsoluongdamuon(slm);
                            cout << "\n\t\tThem sach thanh cong.";
                            int i;
                            while(true) {
                                cout << "\n\t\tNhan 0 de quay lai: ";
                                cin >> i;
                                cin.ignore();
                                if (i == 0) return;
                                else {
                                    invalidChoice();
                                }
                            } 
                        }
                    }
                    else{
                        cout << "\n\t\tKhong tim thay sach.";
                            while(true) {
                                cout << "\n\t\tNhap 0 de quay lai , 1 de nhap lai : ";
                                cin >> choice;
                                cin.ignore();
                                if (choice == 0) return;
                                else if (choice == 1) break;
                                else {
                                    invalidChoice();
                                }
                            } 
                        }

                } 
            else {
                cout << "\n\t\tXin loi quy khach, hien khong co sach nay.";
                while(true) {
                    cout << "\n\t\tNhap 0 de quay lai: ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 0) return;
                    else {
                        invalidChoice();
                    }
                } 
            }
        }
    }

<<<<<<< Updated upstream
    void returnBook(int index) { //ham trả sách, index là vị trí của khách hàng trong vector accounts
=======
    void returnBook(int index) { //ham cho phep khach hang tra sach, index la vi tri cua khach hang trong vector accounts
>>>>>>> Stashed changes
        bool check=false;
        int index1;
        int choice;
        string codebook;
        system("cls");
        cout << "\n\t\tNhap ma sach can huy : ";
        getline(cin, codebook);
        for (int i = 0; i < accounts[index].rentalBooks.size(); i++) {
            if (codebook == accounts[index].rentalBooks[i].code) {
                check=true;
                index1=i;
                break;
            }
        }
        if(check==true){
            for (int k = 0; k < (int)books.size(); k++) {
                    if (books[k]->getid() ==accounts[index].rentalBooks[index1].idRecord) {
                    int sl = books[k]->getsoluongconlai() + 1;
                    books[k]->setsoluongconlai(sl);
                    int slm = books[k]->getsoluongdamuon() - 1;
                    books[k]->setsoluongdamuon(slm);
                    break;
                    }
                }
            cout << "\n\t\ttra sach "<<accounts[index].rentalBooks[index1].nameRecord<<" thanh cong.";
            accounts[index].rentalBooks.erase(accounts[index].rentalBooks.begin() + index1);
                for (int j = 0; j < (int)RentalHistory.size(); j++) {
                    if (RentalHistory[j].code == codebook) {
                        RentalHistory.erase(RentalHistory.begin() + j);
                        break;
                    }
                }
                while(true) {
                    cout << "\n\t\tNhan 0 de quay lai : ";
                    cin >> choice;
                    cin.ignore();
                    if (choice==0) return;
                    else {
                        invalidChoice();
                    }
                }
        }
        else{
            cout << "\n\t\tKhong co sach can tra.";
            while(true) {
                cout << "\n\t\tNhan 0 de quay lai: ";
                cin >> choice;
                cin.ignore();
                if(choice==0) return;
                else {
                    invalidChoice();
                }
            }
        }
    }

<<<<<<< Updated upstream
    void displayClient(int index) { //ham hiển thị thông tin khách hàng, index là vị trí của khách hàng trong vector accounts
=======
    void displayClient(int index) {  //ham hien thi thong tin cua khach hang, index la vi tri cua khach hang trong vector accounts
>>>>>>> Stashed changes
        int choice;
        accounts[index].display1ClientInfo();
        while(true) {
            cout << "\n\t\tNhan 0 de quay lai : ";
            cin>>choice;
            cin.ignore();
            if(choice==0) return;
            else {
                invalidChoice();
            }
        }
    }

<<<<<<< Updated upstream
    void displayAllBook(string a) { //ham hiển thị tất cả sách theo thể loại, a là thể loại sách
=======
    void displayAllBook(string a) {        //ham hien thi tat ca cac cuon sach theo the loai, a la the loai cua sach
>>>>>>> Stashed changes
        int choice;
        system("cls");
        cout << "\n\t\t==========================================================";
        cout << "\n\t\t                        KHO SACH                          ";
        cout << "\n\t\t==========================================================";
        if (books.empty()) {
            cout << "\n\t\tTrong\n";
        } else {
            for (int i = 0; i < (int)books.size(); i++) {
                if (books[i]->getGenre() == a)
                    books[i]->display1BookInfo();
            }
        }
        while(true) {
            cout << "\n\t\tNhap 0 de quay lai : ";
            cin>>choice;
            cin.ignore();
            if (choice == 0) return;
            else {
                invalidChoice();
            }
        } 
    }

<<<<<<< Updated upstream
    void displayAllBooks() { //ham hiển thị tất cả sách, không phân loại
=======
    void displayAllBooks() {              //ham hien thi tat ca cac cuon sach cua the loai sach ma khach hang chon
>>>>>>> Stashed changes
        int choice;
        while (true) {
            system("cls");
            cout << "\n\t\t==========================================================";
            cout << "\n\t\t                        KHO SACH                          ";
            cout << "\n\t\t==========================================================";
            cout << "\n\t\t1. Sach khoa hoc\n";
            cout << "\n\t\t2. Sach van hoc\n";
            cout << "\n\t\t3. Sach lich su\n";
            cout << "\n\t\t4. Sach kinh te\n";
            cout << "\n\t\t5. Sach nghe thuat\n";
            cout << "\n\t\t6. Sach thieu nhi\n";
            cout << "\n\t\t7. Quay lai\n";
            cout << "\n\t\tChon lua chon (1-7): ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: displayAllBook("Khoa hoc");   break;
                case 2: displayAllBook("Van hoc");    break;
                case 3: displayAllBook("Lich su");    break;
                case 4: displayAllBook("Kinh te");    break;
                case 5: displayAllBook("Nghe thuat"); break;
                case 6: displayAllBook("Thieu nhi");  break;
                case 7: return; break;
                default: 
                    invalidChoice();
            }
        } 
    }
<<<<<<< Updated upstream
    void clientFunction(int index) { //ham hiển thị chức năng cho khách hàng, index là vị trí của khách hàng trong vector accounts
=======
    void clientFunction(int index) {      //ham chinh cho phep khach hang thuc hien cac chuc nang, index la vi tri cua khach hang trong vector accounts
>>>>>>> Stashed changes
        int choice;
        while(true) {
            system("cls");
            cout << "\n\t\t=======================================================";
            cout << "\n\t\t                CHUC NANG CUA KHACH HANG               ";
            cout << "\n\t\t=======================================================\n";
            cout << "\n\t\t1. Kho sach\n";
            cout << "\n\t\t2. Muon sach\n";
            cout << "\n\t\t3. Tra sach\n";
            cout << "\n\t\t4. Lich su muon\n";
            cout << "\n\t\t5. Quay lai\n";
            cout << "\n\t\tChon lua chon (1-5): ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: displayAllBooks();          break;
                case 2: rentBook(index);    break;
                case 3: returnBook(index);       break;
                case 4: displayClient(index); break;
                case 5: return;           break;
                default: 
                    invalidChoice();
            }
        } 
    }

// -------------------- ADMIN --------------------

    bool idCheck(string id) const {                      //Hàm kiểm tra ID
        for (int i = 0; i < (int)books.size(); i++) {
            if (id == books[i]->getid()) return true;
        }
        return false;
    }

    bool bookCheck(book* bookmodle) const {              //Hàm kiểm tra sách
        for (int i = 0; i < (int)books.size(); i++) {
            if (books[i]->getGenre() == bookmodle->getGenre() &&
                books[i]->getname()    == bookmodle->getname()    &&
                books[i]->getauthor()  == bookmodle->getauthor()) {
                cout << "\n\t\tSach da ton tai, yeu cau nhap sach moi.\n";
                pressEnterToContinue2();
                return false;
                break;
            }
        }
        return true;
    }

    void addBook() {                                     //Hàm thêm sách
        int choice;
        book* bookModel;
        while(true) {
            system("cls");
            cout << "\n\t\t=======================================================";
            cout << "\n\t\t                        THEM SACH                      ";
            cout << "\n\t\t=======================================================\n";
            cout << "\n\t\t1. Sach khoa hoc\n";
            cout << "\n\t\t2. Sach van hoc\n";
            cout << "\n\t\t3. Sach lich su\n";
            cout << "\n\t\t4. Sach kinh te\n";
            cout << "\n\t\t5. Sach nghe thuat\n";
            cout << "\n\t\t6. Sach thieu nhi\n";
            cout << "\n\t\t7. Quay lai\n";
            cout << "\n\t\tChon lua chon (1-7): ";
            cin >> choice;
            switch (choice) {
                case 1:
                    bookModel = new sachkhoahoc;
                    do { bookModel->createbook(); } while (!bookCheck(bookModel));
                    while (idCheck(bookModel->getid()) == true) {
                        cout << "\n\t\tID da bi trung, vui long nhap lai ID: ";
                        bookModel->nhapid();
                    }
                    cout<<"\n\t\tThem sach thanh cong.";
                    books.push_back(bookModel);
                    pressEnterToContinue2();
                    break;
                case 2:
                    bookModel = new sachvanhoc;
                    do { bookModel->createbook(); } while (!bookCheck(bookModel));
                    while (idCheck(bookModel->getid()) == true) {
                        cout << "\n\t\tID da bi trung, vui long nhap lai ID: ";
                        bookModel->nhapid();
                    }
                    cout<<"\n\t\tThem sach thanh cong.";
                    books.push_back(bookModel);
                    pressEnterToContinue2();
                    break;
                case 3:
                    bookModel = new sachlichsu;
                    do { bookModel->createbook(); } while (!bookCheck(bookModel));
                    while (idCheck(bookModel->getid()) == true) {
                        cout << "\n\t\tID da bi trung, vui long nhap lai ID: ";
                        bookModel->nhapid();
                    }
                    cout<<"\n\t\tThem sach thanh cong.";
                    books.push_back(bookModel);
                    pressEnterToContinue2();
                    break;
                case 4:
                    bookModel = new sachkinhte;
                    do { bookModel->createbook(); } while (!bookCheck(bookModel));
                    while (idCheck(bookModel->getid()) == true) {
                        cout << "\n\t\tID da bi trung, vui long nhap lai ID: ";
                        bookModel->nhapid();
                    }
                    cout<<"\n\t\tThem sach thanh cong.";
                    books.push_back(bookModel);
                    pressEnterToContinue2();
                    break;
                case 5:
                    bookModel = new sachnghethuat;
                    do { bookModel->createbook(); } while (!bookCheck(bookModel));
                    while (idCheck(bookModel->getid()) == true) {
                        cout << "\n\t\tID da bi trung, vui long nhap lai ID: ";
                        bookModel->nhapid();
                    }
                    cout<<"\n\t\tThem sach thanh cong.";
                    books.push_back(bookModel);
                    pressEnterToContinue2();
                    break;
                case 6:
                    bookModel = new sachthieunhi;
                    do { bookModel->createbook(); } while (!bookCheck(bookModel));
                    while (idCheck(bookModel->getid()) == true) {
                        cout << "\n\t\tID da bi trung, vui long nhap lai ID: ";
                        bookModel->nhapid();
                    }
                    cout<<"\n\t\tThem sach thanh cong.";
                    books.push_back(bookModel);
                    pressEnterToContinue2();
                    break;
                case 7:
                    return;
                    break;
                default: invalidChoice();
            }
        } 
    }

    void deleteBook() {                                 //Hàm xóa sách 
        int choice;
        system("cls");
        string idModel;
        while(true) {
            cout << "\n\t\tNhap ID sach can xoa: ";
            getline(cin, idModel);
            if (idCheck(idModel) == false) {
                cout << "\n\t\tKhong tim thay ID sach can xoa.";
                while(true) {
                    cout << "\n\t\tNhap 1 de tiep tuc";
                    cout << "\n\t\tNhap 0 de quay lai";
                    cout << "\n\t\tNhap lua chon : ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) {system("cls"); break;}
                    else if (choice == 0) return;
                    else {
                        invalidChoice();
                    }
                } 
                continue;
            }
            for (int i = 0; i < books.size(); i++) {
                if (books[i]->getid() == idModel) {
                    books.erase(books.begin() + i);
                }
            }
            cout << "\n\t\tXoa sach thanh cong.";
            while(true) {
                cout << "\n\t\tNhap 0 de quay lai : ";
                cin >> choice;
                cin.ignore();
                if (choice == 0) return;
                else invalidChoice();
            } 
        }
    }
    void display1ClientAdmin() {                        //Hàm xem thông tin 1 khách hàng
        int choice;
        string username;
        while (true) {
            system("cls");
            cout << "\n\t\t=======================================================";
            cout << "\n\t\t                 THONG TIN KHACH HANG                  ";
            cout << "\n\t\t=======================================================";
            bool check=false;
            cout << "\n\t\tNhap ten tai khoan can xem thong tin: ";
            getline(cin, username);
            for (int i = 0; i < (int)accounts.size(); i++) {
                if (username == accounts[i].username) {
                    check = true;
                    accounts[i].display1ClientInfo();
                    break;
                }
            }
            if (check==true) {
                while(true) {
                    cout<<"\n\t\tNhap 0 de quay lai : ";
                    cin>>choice;
                    cin.ignore();
                    if(choice==0) return;
                    else {
                        invalidChoice();
                    }
                }
            }
            if(check==false) {
                cout << "\n\t\tKhong tim thay thong tin khach hang";
                while(true) {
                	cout << "\n\t\tNhap 1 de tiep tuc";
                    cout <<"\n\t\tNhap 0 de quay lai";
                	cout << "\n\t\tNhap lua chon : ";
                	cin>>choice;
                    cin.ignore();
                    if(choice==1) break;
                	else if(choice==0) return;
                    else {
                        invalidChoice();
                    }
				}
            }
        }
    }
    
    void displayAllClientAdmin(){
        int choice;
    	system("cls");
        cout << "\n\t\t==========================================================";
        cout << "\n\t\t                     THONG TIN KHACH HANG                   ";
        cout << "\n\t\t==========================================================\n";
        cout << "\n\t\t----------------------------------------------------------\n";
        cout << "\t\t|STT|          TEN KHACH HANG      |       MAT KHAU      |";
        for(int i = 0;i<accounts.size();i++){
        	cout << "\n\t\t|"<< left << setw(3) << i+1 <<"|"<< setw(30) << accounts[i].username <<"|"
        	<< setw(21) << accounts[i].password <<"|";
		}
	    cout << "\n\t\t----------------------------------------------------------";
        while(true) {
            cout << "\n\t\tNhap 0 de quay lai : ";
            cin >> choice;
            cin.ignore();
            if (choice == 0) return;
            else invalidChoice();
        } 
	}

    void displayAllClientAdmin(){                       //Hàm hiển thị thông tin toàn bộ khách hàng
        int choice;
    	system("cls");
        cout << "\n\t\t==========================================================";
        cout << "\n\t\t                     THONG TIN KHACH HANG                   ";
        cout << "\n\t\t==========================================================\n";
        cout << "\n\t\t----------------------------------------------------------\n";
        cout << "\t\t|STT|          TEN KHACH HANG      |       MAT KHAU      |";
        for(int i = 0;i<accounts.size();i++){
        	cout << "\n\t\t|"<< left << setw(3) << i+1 <<"|"<< setw(30) << accounts[i].username <<"|"
        	<< setw(21) << accounts[i].password <<"|";
		}
	    cout << "\n\t\t----------------------------------------------------------";
        while(true) {
            cout << "\n\t\tNhap 0 de quay lai : ";
            cin >> choice;
            cin.ignore();
            if (choice == 0) return;
            else invalidChoice();
        } 
	}

    void adminFunction() {                             //Hàm tổng hợp các chức năng của nhân viên
        int choice;
        while(true) {
        system("cls");
        cout << "\n\t\t=======================================================";
        cout << "\n\t\t                CHUC NANG CUA NHAN VIEN               ";
        cout << "\n\t\t=======================================================\n";
        cout << "\n\t\t1. Kho sach\n";
        cout << "\n\t\t2. Them sach\n";
        cout << "\n\t\t3. Xoa sach\n";
        cout << "\n\t\t4. Danh sach khach hang\n";
        cout << "\n\t\t5. Xem thong tin 1 khach hang\n";
        cout << "\n\t\t6. Quay lai\n";
        cout << "\n\t\tChon lua chon (1-6): ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: displayAllBooks();break;
            case 2: addBook();break;
            case 3: deleteBook();break;
            case 4: displayAllClientAdmin();break;
            case 5: display1ClientAdmin();break;
            case 6: return ;break;
            default: 
                invalidChoice();
            }
        } 
    }
<<<<<<< Updated upstream

=======
    
>>>>>>> Stashed changes
    
    // -------------------- AUTH --------------------


<<<<<<< Updated upstream
    bool signInClient(int& index) { //ham đăng nhập khách hàng, index là vị trí của khách hàng trong vector accounts
=======
    bool signInClient(int& index) {  //ham cho phep khach hang dang nhap, index la vi tri cua khach hang trong vector accounts
>>>>>>> Stashed changes
        int choice;
        bool check=false;
        while(true) {
            system("cls");
            displayHeader2();
            string tendangnhap, matkhauu;
            cout << "\n\t\tNhap ten dang nhap   : ";
            getline(cin, tendangnhap);
            cout << "\n\t\tNhap mat khau        : ";
            getline(cin, matkhauu);
            if (accounts.empty()) {
                cout << "\n\t\tTen dang nhap hoac mat khau khong dung.";
                while (true) {
                cout << "\n\t\t1. Tiep tuc dang nhap";
                cout << "\n\t\t2. Quay lai";
                cout<<"\n\t\tHay nhap lua chon cua ban : ";
                cin >> choice;
                cin.ignore();
                if (choice == 1) { break; }
                if (choice == 2) { return false;}
                invalidChoice();
                }
            }
            else {
                bool accountCheck=false;
                for(int i=0;i<accounts.size();i++) {
                    if(tendangnhap==accounts[i].username && matkhauu==accounts[i].password) {
                        accountCheck=true;
                        index=i;
                        break;
                    }
                }
                if (accountCheck==false) {
                    cout << "\n\t\tTen dang nhap hoac mat khau khong dung.";
                    while (true) {
                    cout << "\n\t\t1. Tiep tuc dang nhap";
                    cout << "\n\t\t2. Quay lai";
                    cout<<"\n\t\tHay nhap lua chon cua ban : ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) { break; }
                    if (choice == 2) { return false;}
                    invalidChoice();
                    }
                }
                if(accountCheck==true) {
                    cout << "\n\t\tDang nhap thanh cong.";
                    pressEnterToContinue2();
                    return true;
                }
            }
        }
    }
    void signUpClient() {          //ham dang ki tai khoan khach hang
        int choice;
        client b;
        while(true) {
            bool check=true;
            system("cls");
            displayHeader2();
            cout << "\n\t\tNhap ten dang ki   : ";
            getline(cin, b.username);
            if (accounts.empty()) {
                cout << "\n\t\tNhap mat khau        : ";
                getline(cin, b.password);
                cout << "\n\t\tDang ki thanh cong.";
                accounts.push_back(b);
                while(true) {
                    cout << "\n\t\tNhan 0 de quay lai: ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 0) return;
                    else invalidChoice();
                } 
            } else {
                for (int i = 0; i < accounts.size(); i++) {
                    if (b.username == accounts[i].username) {
                        check=false;
                        break;
                    }
                }
            }
            if(check==true){
                cout << "\n\t\tNhap mat khau        : ";
                getline(cin, b.password);
                cout << "\n\t\tDang ki thanh cong.";
                accounts.push_back(b);
                while(true) {
                    cout << "\n\t\tNhap 0 de quay lai : ";
                    cin >>choice;
                    cin.ignore();
                    if (choice==0) return;
                    else invalidChoice();
                } 
            }
            else{
                cout << "\n\t\tTen dang nhap da ton tai, yeu cau nhap lai.";
                while(true) {
                    cout << "\n\t\tNhap 1 de nhap lai,";
                    cout << "\n\t\tNhap 0 de quay lai.";
                    cout << "\n\t\t Nhap lua chon : ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) break;
                    else if (choice==0) return;
                    else invalidChoice();
                }
            }
        }
    }
<<<<<<< Updated upstream
    bool signInAdmin() { //ham đăng nhập nhân viên
=======
    bool signInAdmin() {  //ham cho phep quan ly dang nhap
>>>>>>> Stashed changes
        int choice;
        string adminPassword;
        while(true) {
            cout << "\n\t\tHay nhap mat khau quan ly thu vien: ";
            getline(cin, adminPassword);
            if (adminPassword== "admin") {
                cout<<"\n\t\tDa dang nhap thanh cong";
                pressEnterToContinue2();
                return true;
            }
            else {
                cout<<"\n\t\tMat khau khong dung , vui long thu lai sau !";
                while(true) {
                    cout<<"\n\t\tNhap 1 de tiep tuc.";
                    cout<<"\n\t\tNhap 0 de quay lai.";
                    cout<<"\n\t\tHay nhap lua chon cua ban : ";
                    cin>>choice;
                    cin.ignore();
                    if(choice==1) {system("cls");break;}
                    else if (choice==0) return false;
                    else {
                        invalidChoice();
                    }
                }
            }
        }
    }
<<<<<<< Updated upstream
    void dsignin1() { //ham hiển thị chức năng đăng nhập khách hàng
=======
    void dsignin1() {     //ham cho phep khach hang dang nhap hoac dang ki tai khoan
>>>>>>> Stashed changes
        int choice;
        while(true) {
            system("cls");
            displayHeader2();
            cout << "\n\t\t1. Dang nhap.\n";
            cout << "\n\t\t2. Dang ki.\n";
            cout << "\n\t\t3. Quay lai.\n";
            cout << "\n\t\tNhap lua chon (1-3): ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: {
                    int index;
                    if(signInClient(index)) clientFunction(index);
                    else continue;
                    break;
                }   
                case 2: signUpClient(); break;
                case 3: return; break;
                default: invalidChoice();
            }
        }
    }
<<<<<<< Updated upstream
    void dsignin2() { //ham hiển thị chức năng đăng nhập nhân viên
=======
    void dsignin2() {      //ham cho phep quan ly dang nhap
>>>>>>> Stashed changes
        int choice;
        while(true) {
            system("cls");
            displayHeader2();
            cout << "\n\t\t1. Dang nhap.\n";
            cout << "\n\t\t2. Quay lai.\n";
            cout << "\n\t\tNhap lua chon (1-2): ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: 
                if(signInAdmin()) {adminFunction(); return;}
                else continue;
                break;
                case 2: return; break;
                default:
                    invalidChoice();
            }
        } 
    }

    // -------------------- FILE I/O --------------------

<<<<<<< Updated upstream
    void saveToFileAllClient() { //ham lưu thông tin tất cả khách hàng vào file
=======
    void saveToFileAllClient() {   //ham luu tat ca thong tin cua khach hang vao file client.txt
>>>>>>> Stashed changes
        ofstream outFile("client.txt");
        if (!outFile.is_open()) return;
        outFile << accounts.size() << "\n";
        for (int i = 0; i < (int)accounts.size(); i++) {
            accounts[i].saveToFile1Client(outFile);
        }
        outFile.close();
    }

<<<<<<< Updated upstream
    void loadFromFileAllClient() {//ham tải thông tin tất cả khách hàng từ file
=======
    void loadFromFileAllClient() { //ham doc tat ca thong tin cua khach hang tu file client.txt
>>>>>>> Stashed changes
        ifstream inFile("client.txt");
        if (!inFile.is_open()) return;
        int num;
        inFile >> num;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        accounts.resize(num);
        if (num != 0) {
            for (int i = 0; i < num; i++) {
                accounts[i].loadFromFile1Client(inFile);
            }
        }
        inFile.close();
    }

<<<<<<< Updated upstream
    void saveToFileAllBook() { //ham lưu thông tin tất cả sách vào file
=======
    void saveToFileAllBook() { //ham luu tat ca thong tin cua sach vao file books.txt
>>>>>>> Stashed changes
        ofstream outFile("books.txt");
        if (!outFile.is_open()) return;
        outFile << books.size() << "\n";
        for (int i = 0; i < (int)books.size(); i++) {
            books[i]->saveToFile1Book(outFile);
        }
        outFile.close();
    }

<<<<<<< Updated upstream
    void loadFromFileAllBook() {//ham tải thông tin tất cả sách từ file
=======
    void loadFromFileAllBook() { //ham doc tat ca thong tin cua sach tu file books.txt
>>>>>>> Stashed changes
        ifstream inFile("books.txt");
        if (!inFile.is_open()) return;
        int num;
        inFile >> num;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < num; i++) {
            string theloai;
            book*  bookModel;
            getline(inFile, theloai);
            if      (theloai == "Khoa hoc")   {bookModel = new sachkhoahoc;}
            else if (theloai == "Van hoc")    {bookModel = new sachvanhoc;}
            else if (theloai == "Lich su")    {bookModel = new sachlichsu;}
            else if (theloai == "Kinh te")    {bookModel = new sachkinhte;}
            else if (theloai == "Nghe thuat") {bookModel = new sachnghethuat;}
            else if (theloai == "Thieu nhi")  {bookModel = new sachthieunhi;}
            bookModel->loadFromFile1Book(inFile);
            books.push_back(bookModel);
        }
        inFile.close();
    }

    // -------------------- mainMenu --------------------

<<<<<<< Updated upstream
    void mainMenu() { //ham hiển thị menu chính
=======
    void mainMenu() { //ham hien thi menu chinh cua he thong
>>>>>>> Stashed changes
        int choice;
        while(true) {
            system("cls");
            displayHeader1();
            displayChoice();
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: dsignin1(); break;
                case 2: dsignin2(); break;
                case 3:
                    cout << "\n\t\tThoat he thong...\n";
                    pressEnterToContinue2();
                    return;
                    break;
                default:
                    invalidChoice();
            }
        } 
    }
};

int main() {
    BookManager a;
    a.mainMenu();
}