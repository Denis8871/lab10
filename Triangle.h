#pragma once
#include<iostream>
#include<cmath>
class Triangle
{
public:
    virtual double calculateArea() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Triangle() {}
};

class TriangleByVertices : public Triangle {
protected:
    double x1, y1, x2, y2, x3, y3;

public:
    TriangleByVertices(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    double calculateArea() const override {
        return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }

    void printInfo() const override {
        std::cout << "Triangle by vertices: (" << x1 << "," << y1 << "), ("
            << x2 << "," << y2 << "), (" << x3 << "," << y3 << ")\n";
    }
};

class TriangleBySides : public Triangle {
protected:
    double side1, side2, side3;

public:
    TriangleBySides(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3) {}

    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void printInfo() const override {
        std::cout << "Triangle by sides: " << side1 << ", " << side2 << ", " << side3 << "\n";
    }
};

class MedianTriangle : public TriangleByVertices {
public:
    MedianTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : TriangleByVertices(x1, y1, x2, y2, x3, y3) {}

    double calculateMedianLength(double x1, double y1, double x2, double y2) const {
       
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2.0;
    }

    double calculateArea() const override {
        double median1 = calculateMedianLength(x1, y1, x2, y2);
        double median2 = calculateMedianLength(x1, y1, x3, y3);
        double median3 = calculateMedianLength(x2, y2, x3, y3);
        double s = (median1 + median2 + median3) / 2.0;
        return std::sqrt(s * (s - median1) * (s - median2) * (s - median3));
    }

    void printInfo() const override {
        std::cout << "Median Triangle by vertices: (" << x1 << "," << y1 << "), ("
            << x2 << "," << y2 << "), (" << x3 << "," << y3 << ")\n";
    }
};

class ParallelMedianTriangle : public MedianTriangle {
public:
    ParallelMedianTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : MedianTriangle(x1, y1, x2, y2, x3, y3) {}

    void printInfo() const override {
        std::cout << "Parallel Median Triangle by vertices: (" << x1 << "," << y1 << "), ("
            << x2 << "," << y2 << "), (" << x3 << "," << y3 << ")\n";
    }
};

class RightTriangle : public TriangleBySides {
public:
    RightTriangle(double s1, double s2, double s3)
        : TriangleBySides(s1, s2, s3) {}

    double calculateInscribedRadius() const {
    
        return calculateArea() / (0.5 * (side1 + side2 + side3));
    }

    double calculateCircumscribedRadius() const {

        return (side1 * side2 * side3) / (4 * calculateArea());
    }

    void printInfo() const override {
        std::cout << "Right Triangle by sides: " << side1 << ", " << side2 << ", " << side3 << "\n";
    }
};
