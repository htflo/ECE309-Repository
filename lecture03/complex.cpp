#include <iostream>

using namespace std;

class Complex { // description of an object  (type, class)
private:
  double re; // real part
  double im; // imaginary
public:
  Complex() { // default constructor
    re = 0;
    im = 0;
  }
  // constructor with a single argument => type converter  
  Complex(int i){
    re = i;
    im = 0;
  }	        
  Complex(double r, double i) { // parameterized constructor
    re = r;
    im = i;
  }
  Complex(const Complex &other) {
    re = other.re;
    im = other.im;
  }
  ~Complex() {
    std::cout << "I got destroyed!" << endl;
  }
  
  Complex& operator = (const Complex &other)
  {
    cout << "We are assigning one complex to another!" << endl;
    re = other.re;
    im = other.im;    
    return *this;
  }
  
  // Add this object to the other object and return the sum
  Complex add(Complex other) const
  {
    Complex sum;
    sum.re = re + other.re;
    sum.im = im + other.im;
    return sum;
  }

  // Add this object to the other object and return the sum
  Complex multiply(Complex other) const
  {
    Complex prod;
    prod.re = re*other.re - im*other.im;
    prod.im = im*other.re + other.im*re;
    return prod;
  }  

  void print(std::ostream &out)
  {
    out << re << " + " << im << "j" ;
  }
};

Complex operator + (Complex a, Complex b)
{
  return a.add(b);
}

Complex operator * (Complex a, Complex b)
{
  return a.multiply(b);
}

ostream& operator << (ostream &out, Complex c)
{
  c.print(out);
  return out;
}

Complex make_copy(Complex c)
{
  std::cout << "this is a copy: " << c << std::endl;
  return c;
}

int main()
{
  Complex one(1,0); // declare a Complex number (instance)
  Complex imag(0,1);

  Complex sum = one; // COPY
  // sum and one are identical
  std::cout << "here: " << sum << endl;
  
  sum = imag + one;

  make_copy(sum);

  Complex prod;
  prod = (one + one) * sum + 1;
  
  std::cout << " " << one << std::endl;
  std::cout << "+" << imag << std::endl;
  std::cout << "-----------------------" << std::endl;
  std::cout << sum << std::endl;
  std::cout << prod << std::endl;
  
  //std::cout << one.re << " + " << one.im << "j" << std::endl;
  //std::cout << imag.re << " + " << imag.im << "j" << std::endl;
  
  return 0;
}
