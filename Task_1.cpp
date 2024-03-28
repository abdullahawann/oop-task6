#include <iostream>
using namespace std;

class Complex 
{
    int real;
    int imaginary;

public:

    Complex ()
    {
        real=0;
        imaginary=0;
    }

    Complex(int r ,int i)
    {
        real =r;
        imaginary =i;   
    }

    Complex(const Complex& obj)
    {
        real=obj.real;
        imaginary = obj.imaginary; 
    }

    ~Complex()
    {
    
    }
 
	Complex operator ++(int)
    {
        Complex temp;
        temp.real = real;
		real++;
		temp.imaginary = imaginary;
		imaginary++;

        return temp;
    }

	Complex operator --(int)
    {
		Complex temp;
        temp.real = real;
		real--;
		temp.imaginary = imaginary;
		imaginary--;

        return temp;
    }


    Complex operator =(Complex obj)
    {
        real = obj.real;
        imaginary = obj.imaginary;

        return obj;
    }

    bool operator ==(Complex obj)
    {
        if(obj.real==real && obj.imaginary==imaginary)
        {
            return 1;
        }
        else 
		{
            return 0;
		}
    }

    bool operator !=(Complex obj)
    {
        if(obj.real!=real||obj.imaginary!=imaginary)
        {
			real = obj.real;
            imaginary = obj.imaginary;

            return 1;
        }
        else
		{
            return 0;
		}
    }

    friend ostream &operator <<(ostream &strm,const Complex &obj)
    {
        strm << obj.real << "+" << obj.imaginary << "i" << endl;

        return strm;
    }

    friend istream &operator >>(istream &strm,Complex &obj)
    {
        cout << "Enter the real part : ";
        strm >> obj.real;
        cout << "Enter the imaginary part : ";
        strm >> obj.imaginary;

        return strm;
    }
};

int main()
{
	Complex C1;
	Complex C2(5,6);
	Complex C3;

	cout << "Enter a Complex number" << endl;
	cin >> C3;

	cout << C1 << C2 << C3;

	if(C1 == C2)
	{
		cout << "C1 == C2" << endl;
        C1++;
        cout << "C1 Incremented" << endl;
	}

	else
	{
		cout << "C1 != C2" << endl;
        C2--;
        cout << "C2 decremented" << endl;
	}


	if(C1 != C3)
	{
		cout << "C1 != C3" << endl;
        C1--;
	    cout << "C1 decremented" << endl;
	}

    else
	{
		cout << "C1 != C3" << endl;
	}
	cout << C1;
    cout << C2;

	system("pause");
	return 0;
}