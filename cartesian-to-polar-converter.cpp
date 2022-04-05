#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


const double PI{3.14159265359};
std::string cartesian_polar_converter(const double &real, const double &imaginary);


int main(){
    double real{0}, imaginary{0};
    std::cout << "z = x + iy" << std::endl;
    std::cout << "Enter the real part(x) and imaginary part(y) of complex number separated by space, (x,y ∈ R): ";
    std::cin >> real >> imaginary;

    std::cout << std::endl << cartesian_polar_converter(real,imaginary);
    return 0;
}


std::string cartesian_polar_converter(const double &real, const double &imaginary){
    std::stringstream out_stream{};
    double radius{}, radius_squared{0}, argument_arcsin{}, argument_arccos{}, argument_arctan{}, argument{0};

    radius_squared = pow(real,2) + pow(imaginary,2);
    radius = sqrt(radius_squared);                      //Value of |z|
    argument_arcsin = asin(imaginary/radius);           //possible value of arg(z) 
    argument_arccos = acos(real/radius);                //possible value of arg(z)
    argument_arctan = atan(imaginary/real);             //possible value of arg(z)

    //We use this inequality because cmath only take the closest value to arg(z) = 0, so:
    if (real > 0){
        argument = argument_arcsin;                     //if real part of complex number is greater than zero this means that the arguments depends on the arcsin of sin(arg(z))
    }else if (real < 0 && imaginary < 0){           
        argument = -PI + argument_arctan;               //if real part and imaginary part is less than zero, it means that the value of arg(z) is in the range -pi < arg(z) <= -pi/2
    }else{
        argument = argument_arccos;                     //if the real part of complex number is less than zero and imaginary part of complex number is greater than zero, it means that the arg(z) only depends on the arcos of cos(arg(z))
    }

    out_stream << "√" << "(" << radius_squared << ")" << "×" << "e^(i(" << argument * 180/PI<< "°))";
    return out_stream.str();
}