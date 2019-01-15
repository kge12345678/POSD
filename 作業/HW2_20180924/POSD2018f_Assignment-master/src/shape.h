#ifndef SHAPE_H
#define SHAPE_H
#include <math.h>

class Shape{
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        double compactness() 
        {
            if(area() == 0)
                throw std::string("Division by zero");
            return perimeter() * perimeter() / area();
        }
};


#endif
