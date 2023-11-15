#pragma once
//#include "../lib/Validator.h"


template <typename T>
Triangle<T>::Triangle() {
    this->point = std::shared_ptr<Point<T>[]>(::new Point<T>[3]);
    for (int i = 0; i < 3; ++i) {
        ::new (this->point.get() + i) Point<T>();
    }
}


template <typename T>
Triangle<T>::Triangle(const Point<T> &point1, const Point<T> &point2, const Point<T> &point3) {
    this->point = std::shared_ptr<Point<T>[]>(::new Point<T>[3]);
    Point<T> * temp_point = this->point.get();
    temp_point[0] = point1;
    temp_point[1] = point2;
    temp_point[2] = point3;
    Validator<T> validator;
    validator.validate_figure(*this);
}


template <typename T>
std::ostream& Triangle<T>::print(std::ostream &out) const {
    for (int i = 0; i < 3; ++i) {
        out << this->point[i] << std::endl;
    }
    return out;
}


template <typename T>
std::istream& Triangle<T>::scan(std::istream &in) {
    int cnt = 1;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Введите координаты точки " << cnt++ << ": ";
        in >> this->point[i];
    }
    return in;
}

template <typename T>
Point<T> Triangle<T>::center() const {
    Point<T> * temp_point = this->point.get();
    double x = (temp_point[0].x + temp_point[1].x + temp_point[2].x);
    double y = (temp_point[0].y + temp_point[1].y + temp_point[2].y);
    return Point<T>(x / 3, y / 3);
}


template <typename T>
double Triangle<T>::square() const {
    Point<T> * temp_point = this->point.get();
    double side = len(temp_point[0], temp_point[1]);
    return side * side * sqrt(3) / 4;
}


template <typename T>
Triangle<T> & Triangle<T>::operator=(const Triangle<T> & triangle) {
    for (int i = 0; i < 3; ++i) {
        ::new (this->point.get() + i) Point<T>(triangle.point[i]);
    }
    return *this;
}


template <typename T>
Triangle<T> & Triangle<T>::operator=(const Triangle<T> && triangle) noexcept{
    if (this != &triangle) {
        this->point = std::move(triangle.point);
    }
    return *this;
}

template <typename T>
Triangle<T>::Triangle(const Triangle<T> & other) : Triangle<T>() {
    for (int i = 0; i < 3; ++i) {
        ::new (this->point.get() + i) Point<T>(other.point[i]);
    }
}


template <typename T>
bool Triangle<T>::equal(const Figure<T> &figure) const {
    Point<T> * temp_point = this->point.get();
    Point<T> * figure_point = figure.getPoint().get();
    for (int i = 0; i < 3; ++i) {
        if (temp_point[i] != figure_point[i]) {
            return false;
        }
    }
    return true;
}


template <typename T>
std::shared_ptr<Point<T>[]> Triangle<T>::getPoint() const { return this->point; }

