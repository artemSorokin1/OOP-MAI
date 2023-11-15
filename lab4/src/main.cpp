#include "../lib/includes.h"
//#include <vector>

int main() {
    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(2, 2);
    Point<double> p4(2, 0);
//    Box<int> b(p1, p2, p3, p4);
//    std::cout << b;
//    Box<double> b = Box(p1 ,p2 ,p3, p4);
//    Box<double> b2(b);
//
//    std::cout << b;

    Triangle<double> t(p1, p2, p3);

//    std::cout << t;

    FabricTriangle<double> fabric;
    auto p = create_array_of_points<double>(3, p1, p2, p3);
    Figure<double> * fig = fabric.create_figure(p);


    std::cout << *fig;



    return 0;
}
