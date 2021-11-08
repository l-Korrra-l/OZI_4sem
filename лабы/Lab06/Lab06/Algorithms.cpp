#include "Algorithms.h"
#include "Math.h"
using namespace std;

void DH(int pri_1, int pub_1,int pri_2,int pub_2)
{
	try {
		std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
		std::cout << "\n|               �������� �����-��������               |";
		std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

		std::cout << "\nUser 1: \t\tUser 2:\nPublic key:" << pub_1 << " \t\tPublic key:" << pub_2;
		std::cout << "\nPrivate Key:" << pri_1 << " \tPrivate Key:" << pri_2;

		int part_1 = (int)pow(pub_1, pri_1) % pub_2;
		int part_2 = (int)pow(pub_2, pri_2) % (pub_1);
		std::cout << "\nPartial Key:" << part_1 << " \tPartial Key:" << part_2;

		int full_2 = (int)pow(part_1, pri_2) % (pub_1);
		int full_1 = (int)pow(part_2, pri_1) % (pub_2);
		std::cout << "\nFull Key:" << full_1 << " \tFull Key:" << full_2<<std::endl;

		//return 0;
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}


template <typename T>
T modpow(T base, T exp, T modulus) {
	base %= modulus;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

void RSA(int text)
{
	int e = 17, n = 391, d = 145; // �������� ����������,  {�������� ����}

	std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	std::cout << "\n|                     �������� RSA                    |";
	std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	std::cout << "\n�������� �����:\t" << text;
	std::cout << "\n�������� ����������:\t" << e;
	std::cout << "\n�������� ���� {e,n}:\t{" << e << ", " << n << "} ";
	std::cout << "\n�������� ���� {d,n}:\t{" <<d<<", "<<n<<"} " ;

	int newtext = modpow(text, e, n);
	std::cout << "\n������������� �����:\t" << newtext;
	std::cout << "\n�������������� �����:\t" << modpow(newtext, d, n)<<std::endl;


	
};

/*****************************************************
	p - ������� �����
	0 < g < p-1
	0 < x < p-1
	m - ��������� ��������� m < p
*****************************************************/
void crypt(int p, int g, int x, string inFileName, string outFileName) {
	ifstream inf(inFileName.c_str());
	ofstream outf(outFileName.c_str());

	int y = power(g, x, p);

	wcout << "Open key (p,g,y)=" << "(" << p << "," << g << "," << y << ")" << endl;
	wcout << "Close key x=" << x << endl;

	wcout << "\nEncrypted text:" << endl;

	while (inf.good()) {
		int m = inf.get();
		if (m > 0) {
			wcout << (char)m;

			int k = rand() % (p - 2) + 1; // 1 < k < (p-1) 
			int a = power(g, k, p);
			int b = mul(power(y, k, p), m, p);
			outf << a << " " << b << " ";
		}
	}

	wcout << endl;

	inf.close();
	outf.close();
}

void decrypt(int p, int x, string inFileName, string outFileName) {
	ifstream inf(inFileName.c_str());
	ofstream outf(outFileName.c_str());

	wcout << "\nDecrypted text:" << endl;

	while (inf.good()) {
		int a = 0;
		int b = 0;
		inf >> a;
		inf >> b;

		if (a != 0 && b != 0) {
			//wcout<<a<<" "<<b<<endl; 

			int deM = mul(b, power(a, p - 1 - x, p), p);// m=b*(a^x)^(-1)mod p =b*a^(p-1-x)mod p - ������ ����  ����� ���������� �������, � ��� ��� ��������� 
			char m = static_cast<char>(deM);
			outf << m;
			wcout << m;
		}
	}

	wcout << endl;

	inf.close();
	outf.close();
}
void LG()
{
	std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	std::cout << "\n|                  �������� ���-������                |";
	std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	srand(time(NULL));
	int p =1+3* rand() % 10;
	int n = bitNum(p);
	std::cout << "\n��������� �����: "<<p <<" ������ "<<n<<" ���";

	int g=1+rand() % 9;
	std::cout << "\n��������� ����������� �������: " << g ;

	int x = 2*rand() % 10;
	std::cout << "\n��������� ����� ����� x:{1<x<p-1}: " << x;
	//

	crypt(p, g, x, "in.txt", "out_crypt.txt");
	decrypt(p, x, "out_crypt.txt", "out_decrypt.txt");



}

void CP(int text)
{
	int e = 17, n = 391, d = 145; // �������� ����������,  {�������� ����}

	std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	std::cout << "\n|                     �������� RSA                    |";
	std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	std::cout << "\n�������� �����:\t" << text;
	std::cout << "\n�������� ����������:\t" << e;
	std::cout << "\n�������� ���� {e,n}:\t{" << e << ", " << n << "} ";
	std::cout << "\n�������� ���� {d,n}:\t{" << d << ", " << n << "} ";

	int temp = text % 10;
	std::cout << "\n��� ��������:\t" << temp;

	int newtext = modpow(temp, d, n);
	std::cout << "\n������������� �����:\t" << newtext;


	std::cout << "\n��������:\t" << modpow(newtext, e, n) << std::endl;
	std::cout << "\nH=H'->true\t";


};