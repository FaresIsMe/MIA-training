#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle(int length, int width) :length(length), width(width)
        {
            Rectangle::count++;
        }
        static int count;

        void setLength(int length) 
        {
            if (length  < 0)
            {
                cout << "Error: Length cannot be negative" << endl; 
                return;
            }
            this->length = length; 
        }
        void setWidth(int width)
        {
            if (width < 0)
            {
                cout << "Error: Width cannot be negative" << endl;
                return;
            }
            this->width = width;
        }

        int getLength() { return length; }

        int getWidth() { return width; }

        int Area() { return length * width; }
        int premiter(){ return length + width;}

        ~Rectangle()
        {
            cout << "Destruction was done" << endl;
            Rectangle::count--;
        }
        
};

int Rectangle :: count = 0;

int main()
{
    Rectangle r1 = Rectangle(10, 5);
    r1.setLength(-12);

    cout <<"area of Rectangle 1: " << r1.Area() << endl;
    cout << "premiter of Rectangle 1: " << r1.premiter() << endl;


    cout << Rectangle :: count << endl;
    return 0;
}