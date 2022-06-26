//Nhom 15 - Quan Ly kinh doanh khach san
/*
Vuong Sy Tuan - 2010C01
Do Minh Cuong - 2010A05
Nguyen Trung Kien - 2010A03
Nguyen Xuan Hien - 2010A04 
*/
#include<bits/stdc++.h>

using namespace std;

//SECTION khai báo đối tượng
//SECTION nhân viên
struct NhanVien{
	string maNV; 
	string tenNV;
	string ngaySinh;
	string gioiTinh;
	string sdt;
};

struct NodeNV {
	NhanVien info;
	struct NodeNV *next;
};

struct ListNV{
	NodeNV *Head;
	NodeNV *Tail;
};
//!SECTION

//SECTION khách
struct KhachHang{
	string maKH; 
	string tenKH;
	string ngaySinh;
	string gioiTinh;
	int sdt;
};

struct NodeKH {
	KhachHang info;
	struct NodeKH *next;
};

struct ListKH{
	NodeKH *Head;
	NodeKH *Tail;
};
//!SECTION

//SECTION Phong 
struct Phong{
	string maP;
	string loaiP;
	float donGia; 
}; 

struct NodeP {
	Phong info;
	struct NodeP *next;
};

struct ListP{
	NodeP *Head;
	NodeP *Tail;
};
//!SECTION

//SECTION Hóa đơn
struct HoaDon{ 
	string maHD;
	string thoiGianLap;
	int thoiGianThue; 
	NhanVien nv;
	int soPhong;
	ListP DSP;
	KhachHang kh;
	double tongTien; 
}; 

struct NodeHD{
	HoaDon info;
	struct NodeHD *next; 
};

struct ListHD{
	NodeHD *Head;
	NodeHD *Tail; 
};
//!SECTION

ListNV listNV;
ListKH listKH;
ListHD listHD;
//!SECTION 

//các thao tác với nhân viên
void nhapNV(NhanVien &x);//LINK BTL.cpp#nhapNV

void hienNV(NhanVien x);

NodeNV *getNodeNV(NhanVien x);

void initDSNV(ListNV &Q);

void insertFirstNV(ListNV &Q, NodeNV *p);

void nhapDSNV(ListNV &Q);

void hienDSNV(ListNV Q);

NodeNV *timKiemNVTheoMa(ListNV Q, string k);


//Các thao tác với khách hàng
void nhapKhachHang(KhachHang &x);//LINK BTL.cpp#nhapKhachHang

void hienKhachHang(KhachHang x);

NodeKH *getNodeKH(KhachHang x);

void initDSKH(ListKH &Q);

void insertFirstKH(ListKH &Q, NodeKH *p);

void nhapDSKH(ListKH &Q);

void hienDSKH(ListKH Q);


//Các thao tác với phòng
void nhapPhong(Phong &x);//LINK BTL.cpp#nhapPhong

void hienPhong(Phong x);

void initDSPhong(ListP &Q);

NodeP *getNodePhong(Phong x);

void insertFirstP(ListP &Q, NodeP *p);

void nhapDSP(ListP &Q);

void hienDSP(ListP Q);



//Các thao tác với hóa đơn
void nhapHoaDon(HoaDon &x); //LINK BTL.cpp#nhapHD

void hienHoaDon(HoaDon x);

void initHoaDon(ListHD &Q);

NodeHD *getNodeHD(HoaDon x);

void insertFirstHoaDon(ListHD &Q, NodeHD *p);

void nhapDSHD(ListHD &Q);

void hienDSHD(ListHD Q);

double tinhTienPhong(ListP ds,int gioThue);

//ANCHOR hàm main
int main(){
	string n;
    initHoaDon(listHD);
	int chon;
	do{
		cout<<"QUAN LI HOA DON KHACH SAN ";
		cout<<"\n1.Nhap danh sach hoa don";
		cout<<"\n2.Hien danh sach hoa don";
		cout<<"\n3.Sap xep hoa don";
		cout<<"\n0.Thoat chuong trinh";
		cout<<"\nMoi ban chon: ";
		cin>>chon;
		switch(chon)
		{
			case 1:
				nhapDSHD(listHD);
				break;
			case 2:
				hienDSHD(listHD);
				break;
			case 0:
				exit(1);
				break;
			default: 
				cout<<"Khong co lua chon nay!";
				break;
				
		}
	}while(chon!=0);
}

//ANCHOR[id=nhapNV] nhân viên
void nhapNV(NhanVien &x){
	fflush(stdin); 
	cout<<"\nMa nhan vien: ";
	getline(cin,x.maNV);
	cout<<"Ten nhan vien: ";
	getline(cin,x.tenNV);
	cout<<"Ngay sinh: ";
	getline(cin,x.ngaySinh);
	cout<<"Gioi tinh :";
	getline(cin,x.gioiTinh);
	cout<<"SDT: ";
	getline(cin,x.sdt);
}

void hienNV(NhanVien x){
	cout<<setw(12)<<x.maNV<<setw(12)<<x.tenNV<<setw(12)<<x.ngaySinh<<setw(12)<<x.gioiTinh<<setw(12)<<x.sdt
	<<setw(12)<<endl;
}

NodeNV *getNodeNV(NhanVien x){ 
	NodeNV *p;
	p = new NodeNV();
	if(p==NULL)
	{
		cout<<"Khong thanh cong";
		exit(0);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void insertFirstNV(ListNV &Q, NodeNV *p){
	if(Q.Head == NULL){
		Q.Head = p;
		Q.Tail = Q.Head;
	}
	else{
		p->next = Q.Head;
		Q.Head = p;
	}
}

void initDSNV(ListNV &Q){
	Q.Head = NULL;
	Q.Tail = NULL; 
}

void nhapDSNV(ListNV &Q){
	int i, n; 
	NodeNV *p;
	NhanVien x;
	cout<<"Nhap so nhan vien: ";
	cin>>n;
	for( i = 0 ; i < n ; i++)
	{
		cout<<"Moi ban nhap thong tin nhan vien thu "<<i + 1<<": "<<endl;
		nhapNV(x);
		p = getNodeNV(x);
		insertFirstNV(Q, p);
	}
}

void hienDSNV(ListNV Q){
	NodeNV *p;
	cout<<"Danh sach nhan vien: \n";
	
	cout<<setw(12)<<"Ma Nhan Vien"<<setw(12)<<"Ten Nhan Vien"<<setw(12)<<"Ngay Sinh"<<setw(12)<<"Gioi Tinh"
	<<setw(12)<<"So Dien Thoai"<<setw(12)<<"He So Luong"<<setw(12)<<"Phu Cap"<<setw(12)<<"Luong";
	
	for(p = Q.Head; p != NULL; p = p->next)
	{
		hienNV(p->info);
	}
}


//ANCHOR[id=nhapKhachHang] khách hàng
void nhapKhachHang(KhachHang &x){
	fflush(stdin); 
	cout<<"\nMa khach hang: ";
	getline(cin,x.maKH);
	cout<<"Ten khach hang: ";
	getline(cin,x.tenKH);
	cout<<"Ngay sinh: ";
	getline(cin,x.ngaySinh);
	cout<<"Gioi tinh :";
	getline(cin,x.gioiTinh);
	cout<<"SDT: ";
	cin>>x.sdt;
}

void hienKhachHang(KhachHang x){
		
	cout<<setw(12)<<x.maKH<<setw(12)<<x.tenKH<<setw(12)
	<<x.ngaySinh<<setw(12)<<x.gioiTinh<<setw(12)<<x.sdt<<endl;
}

NodeKH *getNodeKH(KhachHang x){ 
	NodeKH *p;
	p = new NodeKH();
	if(p==NULL)
	{
		cout<<"Khong thanh cong";
		exit(0);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void initDSKH(ListKH &Q){
	Q.Head = NULL;
	Q.Tail = NULL; 
}

void insertFirstKH(ListKH &Q, NodeKH *p){
	if(Q.Head == NULL){
		Q.Head = p;
		Q.Tail = Q.Head;
	}
	else{
		p->next = Q.Head;
		Q.Head = p;
	}
}

void nhapDSKH(ListKH &Q){
	int i, n; 
	NodeKH *p;
	KhachHang x;
	cout<<"Nhap so khach hang: ";
	cin>>n;
	for( i = 0 ; i < n ; i++)
	{
		cout<<"Moi ban nhap thong tin khach hang thu "<< i+1 <<": "<<endl;
		nhapKhachHang(x);
		p = getNodeKH(x);
		insertFirstKH(Q, p);
	}
}

void hienDSKH(ListKH Q){
	NodeKH *p;
	cout<<"Thong tin cua khach hang: \n";
	cout<<setw(12)<<"Ma Khach Hang"<<setw(12)<<"Ten Khach Hang"<<setw(12)<<"Ngay Sinh"<<setw(12)<<"Gioi Tinh"
	<<setw(12)<<"So Dien Thoai"<<endl;
	for(p = Q.Head; p != NULL; p = p->next)
	{
		hienKhachHang(p->info);
	}
}

//ANCHOR[id=nhapPhong] phòng
void nhapPhong(Phong &x){
	fflush(stdin); 
	cout<<"Ma phong: ";
	getline(cin,x.maP);
	cout<<"Loai phong: ";
	getline(cin,x.loaiP);
	cout<<"Don gia: ";
	cin>>x.donGia;
} 

void hienPhong(Phong x){
	cout<<setw(12)<<x.maP;
	cout<<setw(12)<<x.loaiP;
	cout<<setw(12)<<x.donGia;
	cout<<endl;
}

void initDSPhong(ListP &Q){
	Q.Head = NULL;
	Q.Tail = NULL; 
}

NodeP *getNodePhong(Phong x){ 
	NodeP *p;
	p = new NodeP();
	if(p==NULL)
	{
		cout<<"Khong thanh cong";
		exit(0);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void insertFirstP(ListP &Q, NodeP *p){
	if(Q.Head == NULL){
		Q.Head = p;
		Q.Tail = Q.Head;
	}
	else{
		p->next = Q.Head;
		Q.Head = p;
	}
}

void nhapDSP(ListP &Q, int n){
	int i; 
    initDSPhong(Q);
    for(int i=0;i<n;i++){
        NodeP *p;
        Phong x;
        cout<<"Moi ban nhap thong tin phong: "<<endl;
        nhapPhong(x);
        p = getNodePhong(x);
        insertFirstP(Q, p);
    }

}

void hienDSP(ListP Q){
	cout<<"Thong tin phong duoc thue: \n";
	cout<<setw(12)<<"Ma Phong"<<setw(12)<<"Loai Phong"<<setw(12)<<"Don Gia"<<endl;
	for (NodeP *i = Q.Head; i !=NULL; i=i->next)
	{
		hienPhong(i->info);/* code */
	}
}

double tinhTienPhong(ListP ds,int gioThue){
    double sum=0;
    for (NodeP *i = ds.Head; i!=NULL; i=i->next)
    {
        sum+=i->info.donGia*gioThue;
        /* code */
    }
    return sum;
}
//ANCHOR[id=nhapHD] hóa đơn
void nhapHoaDon(HoaDon &x){
	fflush(stdin);
    cout<<"\nNhan vien lap";
    nhapNV(x.nv); 
	cout<<"\nNhap ma hoa don: ";
	getline(cin,x.maHD);
	cout<<"\nNhap thoi gian lap hoa don: ";
	getline(cin,x.thoiGianLap);
	cout<<"\nNhap thoi gian thue phong(so ngay): ";
	cin>>x.thoiGianThue;
    cout<<"\nNhap khach hang ";
    nhapKhachHang(x.kh);
    cout<<"\nNhap so phong khach thue: ";
    cin>>x.soPhong;
    nhapDSP(x.DSP,x.soPhong);
    x.tongTien=tinhTienPhong(x.DSP,x.thoiGianThue);
}

void hienHoaDon(HoaDon x){
	cout<<setw(30)<<"\nMa hoa don: "<<x.maHD<<"||";
	cout<<setw(20)<<"Thoi gian lap: "<<x.thoiGianLap;
	cout<<setw(30)<<"\nTen nhan vien lap: "<<x.nv.tenNV<<"||";
	cout<<setw(20)<<"Ma nhan vien: "<<x.nv.maNV;
	cout<<setw(30)<<"\nTen khach hang: "<<x.kh.tenKH<<"||";
	cout<<setw(20)<<"SDT: "<<x.kh.sdt;
	cout<<setw(10)<<"\nSo phong thue: "<<x.soPhong<<endl;
	hienDSP(x.DSP);
	cout<<setw(10)<<"\nTong tien thanh toan: "<<x.tongTien<<endl;
	
}

void initHoaDon(ListHD &Q){
	Q.Head = NULL;
	Q.Tail = NULL; 
}

NodeHD *getNodeHD(HoaDon x){
	NodeHD *p; 
	p = new NodeHD();
	if(p == NULL){
		cout<<"\n Khong thanh cong ";
		exit(0); 
	}
	p->info = x;
	p->next = NULL;
	return p; 
} 

void insertFirstHoaDon(ListHD &Q, NodeHD *p){
	if(Q.Head == NULL){
		Q.Head = p;
		Q.Tail = p;
	}
	else{
		p->next = Q.Head;
		Q.Head = p;
	}
}

void nhapDSHD(ListHD &Q){
	int i, n; 
	NodeHD *p;
	HoaDon x;
	cout<<"Nhap so hoa don: ";
	cin>>n;
	for( i = 0 ; i < n ; i++)
	{
		cout<<"Moi ban nhap thong tin hoa don thu"<< i+1 <<endl;
		nhapHoaDon(x);
		p = getNodeHD(x);
		insertFirstHoaDon(Q, p);
	}
}

void hienDSHD(ListHD Q){
	NodeHD *p;
	cout<<"Danh sach hoa don"<<endl;
	for(p = Q.Head; p != NULL; p = p->next)
	{
		hienHoaDon(p->info);
	}
}