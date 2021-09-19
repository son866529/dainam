#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

const int MAX = 10;

struct SV //Tao kieu du lieu cho sinh vien
{
	char HT[20];
	int NS;
	int DT;
	int DL;
	int DH;
	int SUM;
};

struct LIST //Tao kieu du lieu cho danh sach tuyen tinh
{
	int n;
	SV dainam[MAX];
};

void Create(LIST &L) //Khoi tao danh sach tuyen tinh
{
	L.n = 0;	
}

int empty(LIST L) //Kiem tra rong
{
	return L.n==0;	
}

int full(LIST L) //Kiem tra day
{
	return L.n==MAX;
}

void insert(LIST &L, SV x, int k) //Them phan tu vao danh sach
{
	if(full(L)!=MAX&&k>=0&&k<=L.n)
	{
		for(int i=L.n;i>k;i--)
		{
			L.dainam[i] = L.dainam[i-1];
		}
		L.dainam[k] = x;
		L.n++;
	}
}

void del(LIST &L, int k) //Xoa phan tu vi tri k trong danh sach
{
	if(empty(L)==0&&k>=0&&k<L.n)
	{
		for(int i=k;i<L.n;i++)
		{
			L.dainam[i]=L.dainam[i+1];
		}
		L.n--;
	}
}

SV CreateSV() //Tao mot sinh vien
{
	SV sv;
	cout<<"Nhap hoten: ";
	fflush(stdin);
	gets(sv.HT);
	cout<<"Nhap namsinh: ";
	cin>>sv.NS;
	cout<<"Nhap diemtoan: ";
	cin>>sv.DT;
	cout<<"Nhap diemly: ";
	cin>>sv.DL;
	cout<<"Nhap diemhoa: ";
	cin>>sv.DH;
	sv.SUM = sv.DT+sv.DL+sv.DH;
	return sv;
}

void nhap(LIST &L, int &n) //Nhap danh sach 
{
	do
	{
		cout<<"Nhap so luong sv: ";
		cin>>n;
	}while(n>MAX);
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap sinh vien thu "<<i+1<<endl;
		insert(L,CreateSV(),i);
	}
}

void SinhVienTongDiemTren18(LIST L) //in ra nhung sinh vien co tong diem >= 18
{
	if(L.n==0)
	{
		cout<<"danh sach k co j ca"<<endl;
		return;
	}
	cout<<endl<<"DANH SACH SINH VIEN CO TONG DIEM >= 18"<<endl<<endl;
	cout<<"|      HOTEN      |NAMSINH|DIEMTOAN|DIEMLY|DIEMHOA|TONGDIEM|"<<endl;
	for(int i=0;i<L.n;i++)
	{
		if(L.dainam[i].SUM>=18)
		printf("|%17s|%7d|%8d|%6d|%7d|%8d|\n",L.dainam[i].HT,L.dainam[i].NS,L.dainam[i].DT,L.dainam[i].DL,L.dainam[i].DH,L.dainam[i].SUM);
	}
}
int main()
{
	LIST L;
	int n;
	Create(L);
	nhap(L,n);
	SinhVienTongDiemTren18(L);
	return 0;
}
