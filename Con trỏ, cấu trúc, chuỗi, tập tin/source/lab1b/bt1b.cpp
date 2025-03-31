#include<iostream>
#include<cmath>
using namespace std;
void gptb2(double* a, double* b, double* c) //Khai báo chương trình con với biến con trỏ
{
	double delta = ((*b) * (*b)) - 4 * (*a) * (*c); // Tính delta
	double x1, x2; //Khai báo biến kết quả
	if (delta > 0) {	
		x1 = (-(*b) - sqrt(delta)) / (2 * (*a));
		x2 = ((*b) - sqrt(delta)) / (2 * (*a));
		cout << "Phuong trinh co 2 nghiem phan biet: x1= " << x1 << " x2= " << x2 << endl;
	}
	else if (delta == 0) {
		x1 = (-(*b)) / (2 * (*a));
		cout << "Phuong trinh co 1 nghiem kep: x= " << x1 << endl;
	}
	else {
		cout << "Phuong trinh vo nghiem" << endl;
	}
}
int main()
{
	double a, b, c;
	cout << "Nhap a, b, c: ";
		cin >> a >> b >> c;
		if (a == 0) { 
			if (b == 0) {
				if (c == 0) {
					cout << "Phuong trinh vo so nghiem";  // Nếu c=0 -> phương trình vô số nghiệm 0+0+0=0
				}
				else
				{
					cout << "Phuong trinh vo nghiem";	//Nếu c khác 0 -> phương trình vô nghiệm 0+0+c=0
				}
			}
			else
			{
				cout << "Phuong trinh co 1 nghiem: x= " << -c / b << endl; //Phương trình 0+bx+c=0 -> x=-c/b
			}
		}
		else
		{
			gptb2(&a, &b, &c); //Phương trình ax2+bx+c=0 -> giải bằng chương trình con ở trên
		}

			return 0;
		}