#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
float x, y;
int c;
string str;
double sum(double x);

int main()

{

    ofstream doc("text2.txt");	//открываем ффйл для записи

    c = 1;				// начальное условие
    for (x=-9; x <=9; x++)
    {
        doc << c << " dot ";	//записываем порядковый номер точки
        c++;					//увеличиваем счетчик 
        y = sum(x);				//присваиваем значение
        doc << y << "\n";		//записываем соответствующую точку функции
    }
    doc.close();				//закрываем документ
    
    ifstream print("text2.txt");	//открываем для чтения
    
    while (getline(print, str))
    {
        cout << str << "\n";		//захватываем строку		
    }
    print.close();				//закрываем
}

double sum(double x)	//сама функция обработки

{
	double y;
	
	if (x>=-9 && x<-6)
			{
				y = -sqrt(9-pow((x+6),2));
			}
		if (x>=-6 && x<-3)
		{
			y = x+3;
		}
			if (x>=-3 && x<0)
			{
				y = sqrt(9-pow((x),2));
			}
		if (x>=0 && x<3)
		{
			y=3-x;
		}
			if (x>=3 && x<=9)	//определение диапазона
			{
				y =0.5*(x-3);
			}					//	вычисление значения У
		if (x>9 || x<-9)		// попадаем в определенность?
		{
			cout << " ERROR, not included in the function " << endl;	// не попали
		}
		
	return y;
}