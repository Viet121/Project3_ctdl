#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

class BOOK {
protected:
    string masach, tensach, tacgia, nhaxuatban, ngaynhapkho;
    int tinhtrangsach, giaban, namphathanh, sotrang;
public:
    string getmasach() { return masach; }
    string gettensach() { return tensach; }
    string gettacgia() { return tacgia; }
    string getnhaxuatban() { return nhaxuatban; }
    int getgiaban() { return giaban; }
    int getnamphathanh() { return namphathanh; }
    int getsotrang() { return sotrang; }
    string getngaynhapkho() { return ngaynhapkho; }
    int gettinhtrangsach() { return tinhtrangsach; }

    void setmasach(char _masach) { masach = _masach; }
    void settensach(char _tensach) { tensach = _tensach; }
    void settacgia(char _tacgia) { tacgia = _tacgia; }
    void setnhaxuatban(char _nhaxuatban) { nhaxuatban = _nhaxuatban; }
    void setgiaban(int _giaban) { giaban = _giaban; }
    void setnamphathanh(int _namphathanh) { namphathanh = _namphathanh; }
    void setsotrang(int _sotrang) { sotrang = _sotrang; }
    void setngaynhapkho(char _ngaynhapkho) { ngaynhapkho = _ngaynhapkho; }
    void settinhtrangsach(int _tinhtrangsach) { tinhtrangsach = _tinhtrangsach; }

    BOOK(string _masach = "", string _tensach = "", string _tacgia = "", string _nhaxuatban = "", int _giaban = '/0', int _namphathanh = '/0', int _sotrang = '/0', string _ngaynhapkho = "", int _tinhtrangsach = '/0') {
        masach = _masach;
        tensach = _tensach;
        tacgia = _tacgia;
        nhaxuatban = _nhaxuatban;
        giaban = _giaban;
        namphathanh = _namphathanh;
        sotrang = _sotrang;
        ngaynhapkho = _ngaynhapkho;
        tinhtrangsach = _tinhtrangsach;
    }

    BOOK(const BOOK& a) {
        masach = a.masach;
        tensach = a.tensach;
        tacgia = a.tacgia;
        nhaxuatban = a.nhaxuatban;
        giaban = a.giaban;
        namphathanh = a.namphathanh;
        sotrang = a.sotrang;
        ngaynhapkho = a.ngaynhapkho;
        tinhtrangsach = a.tinhtrangsach;
    }

    ~BOOK(){}
    void ReadFile(ifstream& FileIn)
    {
        FileIn >> masach;
        FileIn >> tensach;
        FileIn >> tacgia;
        FileIn >> nhaxuatban;
        FileIn >> giaban;
        FileIn >> namphathanh;
        FileIn >> sotrang;
        FileIn >> ngaynhapkho;
        FileIn >> tinhtrangsach;
    }
};

class CARD :public BOOK{
private:
    string MSSV;
    string HoTen, ntn;
public:
    string getMSSV() { return MSSV; }
    string getHoTen() { return HoTen; }
    string getntn() { return ntn; }

    void setMuon(char msv[], string Ma) {
        MSSV = msv;
        BOOK::masach = Ma;
    }

    void setTra(char msv[], string Ma) {
        MSSV = msv;
        BOOK::masach = Ma;
    }
    CARD(string hoten = "", string mssv = "", string ms = "", string ntnn = "", int tinhtrang = 1) {
        HoTen = hoten;
        MSSV = mssv;
        masach=ms;
        ntn = ntnn;
        tinhtrangsach = tinhtrang;
    }
    CARD(const CARD& a) {
        HoTen = a.HoTen;
        MSSV = a.MSSV;
        masach = a.masach;
        ntn = a.ntn;
        tinhtrangsach = a.tinhtrangsach;
    }
    void ReadFile(ifstream& FileIn)
    {
        FileIn >> HoTen;
        FileIn >> MSSV;
        FileIn >> masach;
        FileIn >> ntn;
        FileIn >> tinhtrangsach;
    }
};


//ham doi mau chu 
void textColor(int x);

//ham hien thi man hinh dang nhap
void DangNhap();

//ham nhap user va password
void DangNhapHeThong(string& u, string& p);

//ham kiem tra user va password co chinh xac khong
bool KiemTra(string u, string p, string& uf, string& pf);

//ham duyet dang nhap, neu dung thi tiep tuc chuong trinh, sai thi nhap lai
void DuyetDangNhap(string u, string p, string& uf, string& pf);

//ham di chuyen con tro 
void goToXY(int x, int y);

void Menu();

void Quanlysach();

void duyetQuanLySach();

void Xemtoanbosach();

void ThemSach();

void XoaSach();

void backQuanlysach();

void backMenu();

void Quanlyphieumuon();

void duyetQuanlyphieumuon();

void backQuanlyphieumuon();

void xemToanbophieumuon();

void muonSach();

void traSach();

void Suatinhtrangsach(string ms, int n);

int main() {

    string u, p, uf, pf;
    DangNhap();
    DangNhapHeThong(u, p);
    DuyetDangNhap(u, p, uf, pf);

	return 0;
}

void textColor(int x) {
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, x);
}

void DangNhap()
{
    textColor(6);
    cout << "\t\t\t\t\t*****************************" << endl;
    cout << "\t\t\t\t\t*    ";
    textColor(10);
    cout << " DANG NHAP HE THONG    ";
    textColor(6);
    cout << "*" << endl;
    cout << "\t\t\t\t\t*****************************" << endl;
    textColor(15);
}

void DangNhapHeThong(string& u, string& p) {
    cout << "User: ";
    cin >> u;
    cout << endl;
    cout << "Password: ";
    cin >> p;
}

bool KiemTra(string u, string p, string& uf, string& pf) {
    ifstream input;
    input.open("UserAdmin.txt");
    input >> uf >> pf;
    input.close();
    if (u == uf && p == pf) {
        return true;
    }
    else return false;
}

void DuyetDangNhap(string u, string p, string& uf, string& pf) {
    if (KiemTra(u, p, uf, pf)) {
        system("cls");
        cout << "OK" << endl;
        Menu();
    }
    else { //lan 1
        system("cls");
        DangNhap();
        textColor(4);
        cout << "          BAN DA SAI LAN 1" << endl;
        cout << "          MOI DANG NHAP LAI" << endl;
        textColor(15);
        DangNhapHeThong(u, p);
        if (KiemTra(u, p, uf, pf)) {
            system("cls");
            cout << "OK" << endl;
            Menu();
        }
        else { //lan 2
            system("cls");
            DangNhap();
            textColor(4);
            cout << "          BAN DA SAI LAN 2" << endl;
            cout << "          MOI DANG NHAP LAI" << endl;
            textColor(15);
            DangNhapHeThong(u, p);
            if (KiemTra(u, p, uf, pf)) {
                system("cls");
                cout << "OK" << endl;
                Menu();
            }
            else { //lan 3
                system("cls");
                DangNhap();
                textColor(4);
                cout << "          BAN DA SAI LAN 3" << endl;
                cout << "          MOI DANG NHAP LAI" << endl;
                textColor(15);
                DangNhapHeThong(u, p);
                if (KiemTra(u, p, uf, pf)) {
                    system("cls");
                    cout << "OK" << endl;
                    Menu();
                }
                else { //lan 4
                    system("cls");
                    cout << endl << endl;
                    textColor(4);
                    cout << "           BAN DA DANG NHAP SAI HON 3 LAN !!!" << endl;
                    cout << "           BAN KHONG THE DANG NHAP DUOC NUA " << endl;
                    textColor(15);
                }
            }
        }
    }
}

void Menu()
{
    textColor(6);
    cout << "\t\t\t\t\t****************************" << endl;
    cout << "\t\t\t\t\t*           ";
    textColor(10);
    cout << "MENU           ";
    textColor(6);
    cout << "*" << endl;
    cout << "\t\t\t\t\t****************************" << endl;
    textColor(15);
    cout << "Co 2 chuc nang chinh: " << endl;
    cout << "1. QUAN LI SACH " << endl;
    cout << "2. QUAN LI PHIEU MUON" << endl;
    cout << "Moi ban chon chuc nang (vui long an phim 1,2 hoac an phim 0 de thoat chuong trinh) ";
    int n;
    cin >> n;
    if (n == 1) {
        system("cls");
        Quanlysach();
    }
    else if (n == 2) {
        system("cls");
        Quanlyphieumuon();
    }
    else if (n == 0) {
        system("cls");
        textColor(6);
        cout << "\t\t\t\t\t*****************************" << endl;
        cout << "\t\t\t\t\t*        ";
        textColor(10);
        cout << "HEN GAP LAI        ";
        textColor(6);
        cout << "*" << endl;
        cout << "\t\t\t\t\t*****************************" << endl;
        textColor(15);
    }
}

void goToXY(int x, int y){
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Quanlysach(){
    textColor(6);
    cout << "\t\t\t\t\t****************************" << endl;
    cout << "\t\t\t\t\t*       ";
    textColor(10);
    cout << "QUAN LY SACH       ";
    textColor(6);
    cout << "*" << endl;
    cout << "\t\t\t\t\t****************************" << endl;
    textColor(15);
    cout << "Co 3 chuc nang chinh: " << endl;
    cout << "1. XEM TOAN BO SACH" << endl;
    cout << "2. THEM SACH" << endl;
    cout << "3. XOA SACH" << endl;
    cout << "Moi ban chon chuc nang (vui long an phim 1,2,3 hoac an phim 0 de tro ve menu): ";
    duyetQuanLySach();
}

void duyetQuanLySach() {
    int n;
    cin >> n;
    if (n == 1) {
        system("cls");
        Xemtoanbosach();
    }
    else if (n == 2) {
        system("cls");
        ThemSach();
    }
    else if (n == 3) {
        system("cls");
        XoaSach(); 
    }
    else if (n == 0) {
        backMenu();
    }
}

void Xemtoanbosach() {
    char MS[10], tensach[100], tacgia[100], nhaxuatban[100], ngaynhapkho[100];
    int giaban, namxb, sotrang, tinhtrang = 0;
    ifstream intput;
    intput.open("Books.txt");
    while (!intput.eof()) {
        intput >> MS ;
        intput >> tensach ;
        intput >> tacgia ;
        intput >> nhaxuatban ;
        intput >> giaban ;
        intput >> namxb ;
        intput >> sotrang ;
        intput >> ngaynhapkho ;
        intput >> tinhtrang ;
        cout << "- Ma sach: ";
        cout << MS << endl;
        cout << "- Ten sach: ";
        cout << tensach << endl;
        cout << "- Ten tac gia: ";
        cout << tacgia << endl;
        cout << "- Ten nha xuat ban: ";
        cout << nhaxuatban << endl;
        cout << "- Nhap ngay nhap kho: ";
        cout << ngaynhapkho << endl;
        cout << "- Nhap nam phat hanh: ";
        cout << namxb << endl;
        cout << "- Gia ban: ";
        cout << giaban << endl;
        cout << "- So trang: ";
        cout << sotrang << endl;
        cout << "- Tinh trang: ";
        cout << tinhtrang << endl;
        cout << endl;
    }
    intput.close();
    backQuanlysach();
}

void ThemSach() {
    cout << "\t\tNhap them mot cuon sach" << endl;
    cout << endl;
    char MS[10], tensach[100], tacgia[100], nhaxuatban[100], ngaynhapkho[100];
    int giaban, namxb, sotrang, tinhtrang=0;
    cin.ignore();
    cout << "- Nhap ma sach: ";
    cin.getline(MS, 10);
    cout << "- Nhap ten sach: ";
    cin.getline(tensach, 100);
    cout << "- Nhap ten tac gia: ";
    cin.getline(tacgia, 100);
    cout << "- Nhap ten nha xuat ban: ";
    cin.getline(nhaxuatban, 100);
    cout << "- Nhap ngay nhap kho: ";
    cin.getline(ngaynhapkho, 100);
    cout << "- Nhap nam phat hanh: ";
    cin >> namxb;
    cout << "- Nhap gia ban: ";
    cin >> giaban;
    cout << "- Nhap so trang: ";
    cin >> sotrang;
    BOOK New(MS,tensach,tacgia,nhaxuatban,giaban,namxb,sotrang,ngaynhapkho);
    cout << endl;
    cout << "\t\tThem sach thanh cong ^^" << endl;
    fstream saveSach;
    saveSach.open("Books.txt", ios::out | ios::app);
    //saveSach.open("Books.txt");
    saveSach << endl;
    saveSach << MS << endl;
    saveSach << tensach << endl;
    saveSach << tacgia << endl;
    saveSach << nhaxuatban << endl;
    saveSach << giaban << endl;
    saveSach << namxb << endl;
    saveSach << sotrang << endl;
    saveSach << ngaynhapkho << endl;
    saveSach << tinhtrang ;
    saveSach.close();
    backQuanlysach();
}

void backQuanlysach() {
    cout << "DE TRO LAI CAC CHUC NANG VUI LONG AN PHIM 0 ";
    int n;
    cin >> n;
    if (n == 0) {
        system("cls");
        Quanlysach();
    }
}

void backMenu() {
        system("cls");
        Menu();
}

void XoaSach(){
    BOOK* x;
    cout << "Moi nhap ma sach can xoa: ";
    string MSxoa;
    cin >> MSxoa;
    ifstream FileIn;
    FileIn.open("Books.txt", ios_base::in);
    ofstream FileOut;
    FileOut.open("ChangeBooks.txt", ios_base::out);
    while (!FileIn.eof()){
        x = new BOOK();
        x->ReadFile(FileIn);
        if (x->getmasach() != MSxoa ){
            FileOut << x->getmasach() << endl << x->gettensach() << endl << x->gettacgia() << endl << x->getnhaxuatban() << endl << x->getgiaban() << endl << x->getnamphathanh() << endl << x->getsotrang() << endl << x->getngaynhapkho() << endl << x->gettinhtrangsach();
        }
    }
    FileIn.close();
    FileOut.close();

    BOOK* y;
    ifstream In;
    In.open("ChangeBooks.txt", ios_base::in);
    ofstream Out;
    Out.open("Books.txt", ios_base::out);
    while (!In.eof()){
        y = new BOOK();
        y->ReadFile(In);
        if (y->getmasach() != "") {
            Out << y->getmasach() << endl << y->gettensach() << endl << y->gettacgia() << endl << y->getnhaxuatban() << endl << y->getgiaban() << endl << y->getnamphathanh() << endl << y->getsotrang() << endl << y->getngaynhapkho() << endl << y->gettinhtrangsach() ;
        }
    }
    In.close();
    Out.close();
    cout << "Xoa sach thanh cong !!!" << endl;
    backQuanlysach();
}

void Quanlyphieumuon() {
    textColor(6);
    cout << "\t\t\t\t\t****************************" << endl;
    cout << "\t\t\t\t\t*    ";
    textColor(10);
    cout << "QUAN LY PHIEU MUON    ";
    textColor(6);
    cout << "*" << endl;
    cout << "\t\t\t\t\t****************************" << endl;
    textColor(15);
    cout << "Co 3 chuc nang chinh: " << endl;
    cout << "1. XEM TOAN BO PHIEU MUON" << endl;
    cout << "2. MUON SACH" << endl;
    cout << "3. TRA SACH" << endl;
    cout << "Moi ban chon chuc nang (vui long an phim 1,2,3 hoac an phim 0 de tro ve menu): ";
    duyetQuanlyphieumuon();
}

void duyetQuanlyphieumuon() {
    int n;
    cin >> n;
    if (n == 1) {
        system("cls");
        xemToanbophieumuon();
    }
    else if (n == 2) {
        system("cls");
        muonSach();
    }
    else if (n == 3) {
        system("cls");
        traSach();
    }
    else if (n == 0) {
        backMenu();
    }
}

void backQuanlyphieumuon() {
    cout << "DE TRO LAI CAC CHUC NANG VUI LONG AN PHIM 0 ";
    int n;
    cin >> n;
    if (n == 0) {
        system("cls");
        Quanlyphieumuon();
    }
}

void xemToanbophieumuon() {
    char ten[10], mssv[20], ms[10], ntn[20];
    int sophieu  ;
    ifstream in;
    in.open("PhieuMuon.txt");
    while (!in.eof()) {
        in >> ten;
        in >> mssv;
        in >> ms;
        in >> ntn;
        in >> sophieu;
        cout << "- Ten sinh vien muon sach: ";
        cout << ten << endl;
        cout << "- Ma so sinh vien muon sach: ";
        cout << mssv << endl;
        cout << "- Ma sach sinh vien muon: ";
        cout << ms << endl;
        cout << "- Ngay thang nam muon sach: ";
        cout << ntn << endl;
        cout << "- Tinh trang phieu muon sach: ";
        cout << sophieu << endl;
        cout << endl;
    }
    in.close();
    backQuanlyphieumuon();
}

void muonSach() {
    char ten[10], mssv[20], ms[10], ntn[20];
    int sophieu = 1;
    int n = 1;
    cout << "\t\tMuon sach" << endl;
    cout << endl;
    cin.ignore();
    cout << "- Nhap ten sinh vien muon: ";
    cin.getline(ten,10);
    cout << "- Nhap ma sinh vien: ";
    cin.getline(mssv, 20);
    cout << "- Nhap ma sach: ";
    cin.getline(ms, 10);
    cout << "- Nhap ngay thang nam muon: ";
    cin.getline(ntn, 20);
    BOOK* z;
    ifstream eIn;
    eIn.open("Books.txt", ios_base::in);
    fstream save;
    save.open("PhieuMuon.txt", ios::out | ios::app);
    while (!eIn.eof()) {
        z = new BOOK();
        z->ReadFile(eIn);
        if (z->getmasach() == ms && z->gettinhtrangsach() != 1) {
            save << endl;
            save << ten << endl;
            save << mssv << endl;
            save << ms << endl;
            save << ntn << endl;
            save << sophieu ;
            cout << "Da them phieu muon !!!" << endl;
            //chinh lai tinh trang sach
            Suatinhtrangsach(ms, n);
            backQuanlyphieumuon();
        }
        else if (z->getmasach() == ms && z->gettinhtrangsach() == 1) {
            textColor(4);
            cout << "Sach da co nguoi muon" << endl;
            textColor(15);
            backQuanlyphieumuon();
        }
    }
    eIn.close();
    save.close();
    cout << endl;
    backQuanlyphieumuon();
}

void traSach() {
    char ten[10], mssv[20], ms[10], ntn[20];
    int sophieu = 1;
    int n = 0; 
    cout << "\t\tTra sach" << endl;
    cout << endl;
    cin.ignore();
    cout << "- Nhap ten sinh vien muon: ";
    cin.getline(ten, 10);
    cout << "- Nhap ma sinh vien: ";
    cin.getline(mssv, 20);
    cout << "- Nhap ma sach: ";
    cin.getline(ms, 10);
    
    CARD* x;
    ifstream FileIn;
    FileIn.open("PhieuMuon.txt", ios_base::in);
    ofstream FileOut;
    FileOut.open("cPhieuMuon.txt", ios_base::out);
    while (!FileIn.eof()) {
        x = new CARD();
        x->ReadFile(FileIn);
        if (x->getmasach() != ms) {
            FileOut << x->getHoTen() << endl << x->getMSSV() << endl << x->getmasach() << endl << x->getntn() << endl << x->gettinhtrangsach();
            Suatinhtrangsach(ms, n);
        }
    }
    FileIn.close();
    FileOut.close();

    CARD* y;
    ifstream In;
    In.open("cPhieuMuon.txt", ios_base::in);
    ofstream Out;
    Out.open("PhieuMuon.txt", ios_base::out);
    while (!In.eof()) {
        y = new CARD();
        y->ReadFile(In);
        if (y->getHoTen() != "") {
            Out << y->getHoTen() << endl << y->getMSSV() << endl << y->getmasach() << endl << y->getntn() << endl << y->gettinhtrangsach();
        }
    }
    In.close();
    Out.close();
    cout << "Tra sach thanh cong !!!" << endl;
    backQuanlyphieumuon();
}

void Suatinhtrangsach(string ms, int n) {
    BOOK* x;
    ifstream leIn;
    leIn.open("Books.txt", ios_base::in);
    ofstream leOut;
    leOut.open("ChangeBooks.txt", ios_base::out);
    while (!leIn.eof()) {
        x = new BOOK();
        x->ReadFile(leIn);
        if (x->getmasach() != ms) {
            leOut << x->getmasach() << endl << x->gettensach() << endl << x->gettacgia() << endl << x->getnhaxuatban() << endl << x->getgiaban() << endl << x->getnamphathanh() << endl << x->getsotrang() << endl << x->getngaynhapkho() << endl << x->gettinhtrangsach();
        }
        else if (x->getmasach() == ms) {
            x->settinhtrangsach(n);
            leOut << x->getmasach() << endl << x->gettensach() << endl << x->gettacgia() << endl << x->getnhaxuatban() << endl << x->getgiaban() << endl << x->getnamphathanh() << endl << x->getsotrang() << endl << x->getngaynhapkho() << endl << x->gettinhtrangsach();
        }
    }
    leIn.close();
    leOut.close();

    BOOK* y;
    ifstream In;
    In.open("ChangeBooks.txt", ios_base::in);
    ofstream Out;
    Out.open("Books.txt", ios_base::out);
    while (!In.eof()) {
        y = new BOOK();
        y->ReadFile(In);
        if (y->getmasach() != "") {
            Out << y->getmasach() << endl << y->gettensach() << endl << y->gettacgia() << endl << y->getnhaxuatban() << endl << y->getgiaban() << endl << y->getnamphathanh() << endl << y->getsotrang() << endl << y->getngaynhapkho() << endl << y->gettinhtrangsach();
        }
    }
    In.close();
    Out.close();
}