//Ram Ghimire
//200133902
// myComplex.cpp 


#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
using namespace std; 
class Complex {                  // complex number class
	float re;                // real part            
	float im;                // imagination part 
    
public: 
	Complex(float r = 0.0,
        float i = 0.0){
        re = r;
        im = i;
    }
    
    Complex (const Complex & c){
        re =c.re; im = c.im;
    }
    
    void operator =(const Complex & c){
        re= c.re;
        im = c.im;
    }
    Complex operator -()const{
        return Complex(-re, -im);
    }
    
    Complex operator -(const Complex & c){
        Complex c2; 
        c2.re = re -c.re;
        c2.im = im -c.im;
        return c2;
    }  
    
    Complex operator +(const Complex & c){
        Complex c2;
        c2.re = re +c.re;
        c2.im = im +c.im;
        return c2;
    }    
    
    Complex operator *(const Complex & c){
    Complex c2;
        c2.re = (re*c.re) - (im*c.im);
        c2.im = (re*c.im) + (im*c.re);
        return c2;
    }
    
    Complex operator /(const Complex & c){
        Complex c2;
        
        c2.re = (re*c.re + im*c.im) /((c.re * c.re) + (c.im * c.im));
        c2.im =  (c.re*im - c.im*re)/((c.re * c.re) + (c.im * c.im));
        
        return c2;
    }
    
    friend ostream & operator <<(ostream& os, const Complex & c){
        os << c.re;
        if (c.im < 0)
            os  << "i" <<c.im;
        else if (c.im >0 )
           os << " +i"<< c.im;
        return os;
    }

};

int main(){ 
	Complex x[8], y[8], s[8], d[8], p[8], q[8]; 
	for(int i=0; i<8; i++){ 
	x[i] = Complex(i+1,i+1); 
	y[i] = Complex(i+2, i+2); 
	s[i] = x[i]+y[i]; 
	d[i] = x[i]-y[i]; 
	p[i] = x[i]*y[i]; 
	q[i] = x[i]/y[i];
	 
	cout<<"i="<<i<<endl; 
	cout << "x=" <<x[i] <<"\t" <<"y="<<y[i]<<endl; 
	cout << "x+y="<<s[i]<<endl; 
	cout << "x-y="<<d[i]<<endl; 
	cout << "x*y="<<p[i]<<endl; 
	cout << "x/y="<<q[i]<<endl;
}
return 0;
}

