// Bignum.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Nhóm 1: Họ tên - Mã số SV
- Đặng Minh Nhật - 21110842
- Phạm Quỳnh Như - 21110843
- Triệu Thị Tâm Anh - 21110128
- Bùi Đặng Thùy Thương - 21110316
Ngày cập nhật cuối: 12/03/2022
Công dụng: cài đặt hoàn chỉnh các thao tác +,-,*,/,% trên số lớn, đổi số nguyên thành số lớn
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// hang so
#define PLUS 1
#define MINUS -1
#define MAXDIGITS 100

struct bignum
{
	int signbit;
	char digits[MAXDIGITS];
	int lastdigit; // so mu cao nhat VD: 234 -> lastdigit = 2
};

void initialize_bignum(bignum& n);
void zero_justify(bignum& n);
int kiemtra(char s[]);
void scan_bignum(bignum& n);
void print_bignum(bignum n);
int compare_bignum(bignum a, bignum b);
void subtract_bignum(bignum a, bignum b, bignum& c);
void add_bignum(bignum a, bignum b, bignum& c);
void digit_shift(bignum& n, int d);
void multiply_bignum(bignum a, bignum b, bignum& c);
void divide_bignum(bignum a, bignum b, bignum& c);
long long mod_bignum(bignum n, long long m);
void int_to_bignum(int s, bignum& n);
long long sum_bignum(bignum n);
int isPrime_bignum(bignum n);

int main()
{
	bignum a, b, c, d, e, f;
	cout << "Nhap bignum a: ";
	scan_bignum(a);
	cout << "Nhap bignum b: ";
	scan_bignum(b);
	add_bignum(a, b, c);
	cout << "a + b = ";
	print_bignum(c);
	subtract_bignum(a, b, f);
	cout << "a - b = ";
	print_bignum(f);
	multiply_bignum(a, b, d);
	cout << "a * b = ";
	print_bignum(d);
	divide_bignum(a, b, e);
	cout << "a / b = ";
	print_bignum(e);
	bignum k;
	long long m;
	cout << "Bignum can chia lay du va kiem tra xem co phai la so nguyen to hay khong: ";
	scan_bignum(k);
	cout << "So bi chia: ";
	cin >> m;
	long long result = mod_bignum(k, m);
	cout << "a % b = " << result << endl;
	cout << "Bignum can kiem tra xem co phai la so nguyen to hay khong: " << endl;
	int result1 = isPrime_bignum(k);
	cout << "1 la so nguyen to, 0 khong phai la so nguyen to:  " << result1;
}

void initialize_bignum(bignum& n)
{
	for (int i = 0; i <= MAXDIGITS; i++)
		n.digits[i] = 0;
	n.signbit = PLUS;
	n.lastdigit = 0;
}

void zero_justify(bignum& n)
{
	while (n.lastdigit > 0 && n.digits[n.lastdigit] == 0)
		n.lastdigit--;
	if (n.lastdigit == 0 && n.digits[0] == 0)
		n.signbit = PLUS;       // tranh tinh trang bignum = -0
}

int kiemtra(char s[])
{
	if (s[0] != '-' && !(s[0] >= '0' && s[0] <= '9')) return 0; //kiem tra ki tu dau la dau tru hoac so
	for (int i = 1; i < strlen(s); i++)
		if (!(s[i] >= '0' && s[i] <= '9'))         // kiem tra coi co phai so hay khong
			return 0;
	return 1;
}

void scan_bignum(bignum& n)
{
	//B1: nhap chuoi
	char temp[256];
	cin.getline(temp, 256);
	//B2: kiem tra
	if (!kiemtra(temp))
	{
		n.signbit = PLUS;
		n.lastdigit = 0;
		n.digits[0] = 0;
	}
	else
	{
		//B3: chuyen thanh bignum
		if (temp[0] != '-')
		{
			n.signbit = PLUS;
			n.lastdigit = strlen(temp) - 1;
			for (int i = 0; i <= n.lastdigit; i++)
				n.digits[i] = temp[n.lastdigit - i] - 48;
		}
		else
		{
			n.signbit = MINUS;
			n.lastdigit = strlen(temp) - 2;
			for (int i = 0; i <= n.lastdigit; i++)
				n.digits[i] = temp[n.lastdigit - i + 1] - 48;
		}
	}
}

void print_bignum(bignum n)
{
	if (n.signbit == MINUS) cout << '-';
	for (int i = n.lastdigit; i >= 0; i--)
		cout << int(n.digits[i]);
	cout << endl;
}

int compare_bignum(bignum a, bignum b)
{
	// xet cung dau hay trai dau
	if (a.signbit != b.signbit)
	{
		if (a.signbit == PLUS && b.signbit == MINUS) return PLUS;
		else return MINUS;
	}
	else
	{
		if (a.lastdigit > b.lastdigit) return MINUS * a.signbit;
		if (a.lastdigit < b.lastdigit) return PLUS * a.signbit;
		// xet lastdigit bang nhau
		for (int i = a.lastdigit; i >= 0; i--)
		{
			if (a.digits[i] > b.digits[i])
				return MINUS * a.signbit;
			if (a.digits[i] < b.digits[i])
				return PLUS * a.signbit;
		}
	}
	return 0;
}

void subtract_bignum(bignum a, bignum b, bignum& c)
{
	int borrow = 0; // cho muon
	int digit_tam; // giu gia tri
	if (a.signbit == MINUS || b.signbit == MINUS)
	{
		b.signbit = -1 * b.signbit;
		add_bignum(a, b, c);
		b.signbit = -1 * b.signbit;
		return;
	}
	if (compare_bignum(a, b) == PLUS)
	{	
		subtract_bignum(b, a, c);
		c.signbit = MINUS;
		return;
	}

	c.lastdigit = max(a.lastdigit, b.lastdigit);
	// them so 0 vao ben phai cua 2 so a va b
	for (int i = a.lastdigit + 1; i <= c.lastdigit; i++)
		a.digits[i] = 0;
	for (int i = b.lastdigit + 1; i <= c.lastdigit; i++)
		b.digits[i] = 0;

	for (int i = 0; i <= c.lastdigit; i++)
	{
		digit_tam = (a.digits[i] - borrow - b.digits[i]);
		if (a.digits[i] > 0)
			borrow = 0;
		if (digit_tam < 0)
		{
			digit_tam = digit_tam + 10;
			borrow = 1;
		}
		c.digits[i] = digit_tam;
	}
	zero_justify(c);
}

void add_bignum(bignum a, bignum b, bignum& c)
{
	// khoi tao bignum c bang 0
	initialize_bignum(c);
	// bien nho
	int carry = 0;
	// xet dau
	if (a.signbit == b.signbit) c.signbit = a.signbit;
	else
	{
		if (a.signbit == MINUS)       // neu a la so am
		{
			a.signbit = -1 * a.signbit; // chuyen dau cua a tu am sang duong
			subtract_bignum(b, a, c); // xet neu so a be hon so b thi c mang dau am
		}
		else
		{
			b.signbit = -1 * b.signbit;
			subtract_bignum(a, b, c);
		}
		return;
	}
	c.lastdigit = max(a.lastdigit, b.lastdigit) + 1;
	// them so 0 vao ben phai cua 2 so a va b
	for (int i = a.lastdigit + 1; i <= c.lastdigit; i++)
		a.digits[i] = 0;
	for (int i = b.lastdigit + 1; i <= c.lastdigit; i++)
		b.digits[i] = 0;

	for (int i = 0; i <= c.lastdigit; i++)
	{
		c.digits[i] = (carry + (a.digits[i]) + (b.digits[i])) % 10;
		carry = (carry + (a.digits[i]) + (b.digits[i])) / 10;
	}

	zero_justify(c);
}

void multiply_bignum(bignum a, bignum b, bignum& c)
{
	bignum row;
	bignum tmp;
	initialize_bignum(c);
	row = a;
	for (int i = 0; i <= b.lastdigit; i++)
	{
		for (int j = 1; j <= b.digits[i]; j++)
		{
			add_bignum(c, row, tmp);
			c = tmp;
		}
		digit_shift(row, 1);
	}
	c.signbit = a.signbit * b.signbit;
	zero_justify(c);
}

void digit_shift(bignum& n, int d) 
{
	if ((n.lastdigit == 0) && (n.digits[0] == 0)) return;
	for (int i = n.lastdigit; i >= 0; i--)
		n.digits[i + d] = n.digits[i];
	for (int i = 0; i < d; i++) n.digits[i] = 0;
		n.lastdigit = n.lastdigit + d;
}

void divide_bignum(bignum a, bignum b, bignum &c)
{
	bignum row; 
	bignum tmp; 
	int asign, bsign;
	int i, j; 
	initialize_bignum(c);
	c.signbit = a.signbit * b.signbit;
	asign = a.signbit;
	bsign = b.signbit;
	a.signbit = PLUS;
	b.signbit = PLUS;
	initialize_bignum(row);
	initialize_bignum(tmp);
	c.lastdigit = a.lastdigit;
	for (i = a.lastdigit; i >= 0; i--) {
		digit_shift(row, 1);
		row.digits[0] = a.digits[i];
		c.digits[i] = 0;
		while (compare_bignum(row, b) != PLUS) {
			c.digits[i] ++;
			subtract_bignum(row, b, tmp);
			row = tmp;
		}
	}
	zero_justify(c);
	a.signbit = asign;
		b.signbit = bsign;
}

long long mod_bignum(bignum n, long long m)
{
	long long res = 0;
	for (int i = n.lastdigit; i >= 0; i--)
	{
		res = (res * 10 + n.digits[i]) % m;
	}
	return res;
}

void int_to_bignum(int s, bignum& n)
{
	int i; /* counter */
	int t; /* int to work with */
	if (s >= 0) n.signbit = PLUS;
	else n.signbit = MINUS;
	for (i = 0; i < MAXDIGITS; i++) n.digits[i] = (char)0;
	n.lastdigit = -1;
	t = abs(s);
	while (t > 0) {
		n.lastdigit++;
		n.digits[n.lastdigit] = (t % 10);
		t = t / 10;
	}
	if (s == 0) n.lastdigit = 0;
}

long long sum_bignum(bignum n)
{
	long long sum_digits=0;
	for (int i = n.lastdigit; i >= 0; i--)
	{
		sum_digits = sum_digits + (n.digits[i]);
	}
	return sum_digits;
}

int isPrime_bignum(bignum n)
{
	if (n.lastdigit == 0 && n.digits[0] == 2)
		return 1;
	if (n.lastdigit == 0 && n.digits[0] == 5)
		return 1;
	if (n.digits[0] % 2 == 0)
		return 0;
	if (sum_bignum(n) % 3 == 0)
		return 0;
	if (n.digits[0] == 0 || n.digits[0] == 5)
		return 0;
	return 1;
}