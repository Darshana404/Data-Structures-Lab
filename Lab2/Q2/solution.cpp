// Code for Lab2 - Q2
//Program to find the area of square,cube,rect,cuboid using classes
#include<iostream>
#include<stdlib.h>
using namespace std;
//Class for finding area of square and cube
class area1{
    private:
        int len;
    public:
        area1()
            {len=1;}
            void setside(int);
            int square()
            {
                return len*len;
            }
            int cube(){
                return 6*len*len;
            }
}obj1;
//Class for finding area of rectangle and cuboid
class area2{
    private:
        int len,bre,hei;
    public:
        area2()
            {len=1,bre=1,hei=1;}
            void setlen(int);
            void setbre(int);
            void sethei(int);
            int rect(){
                return len*bre;
            }
            int cuboid(){
                return 2*((len*bre)+(bre*hei)+(len*hei));
            }
}obj2;
int main()
{
    int len,bre,hei,ch;
    while(1)
    {
        cout <<"\n1-square\n2-Cube\n3-Rectangle\n4-Cuboid\n5-Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "Enter the side of the square: ";
                cin >> len;
                obj1.setside(len);
                cout << "The area of the square is " << obj1.square();
                break;
            case 2:
                cout << "Enter the side of the cube: ";
                cin >> len;
                obj1.setside(len);
                cout << "The area of the cube is " << obj1.cube();
                break;
            case 3:
                cout << "Enter the length of the rectangle: ";
                cin >> len;
                cout << "Enter the breadth of the rectangle: ";
                cin >> bre;
                obj2.setlen(len);
                obj2.setbre(bre);
                cout << "The area of the rectangle is " << obj2.rect();
                break;
            case 4:
                cout << "Enter the length of the cuboid: ";
                cin >> len;
                cout << "Enter the breadth of the cuboid: ";
                cin >> bre;
                cout << "Enter the height of the cuboid: ";
                cin >> hei;
                obj2.setlen(len);
                obj2.setbre(bre);
                obj2.sethei(hei);
                cout << "The area of the cuboid is " << obj2.cuboid();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;    
}
void area1::setside(int temp)
{
    len=temp;
}
void area2::setlen(int temp)
{
    len=temp;
}
void area2::setbre(int temp)
{
    bre=temp;
}
void area2::sethei(int temp)
{
    hei=temp;
}
