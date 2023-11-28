// Project15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Triangle.h"

int main()
{
    TriangleByVertices* triangle1 = new TriangleByVertices(0, 0, 0, 1, 1, 0);
    TriangleBySides* triangle2 = new TriangleBySides(3, 4, 5);
    MedianTriangle* medianTriangle = new MedianTriangle(0, 0, 0, 1, 1, 0);
    ParallelMedianTriangle* parallelMedianTriangle = new ParallelMedianTriangle(0, 0, 0, 1, 1, 0);
    RightTriangle* rightTriangle = new RightTriangle(3, 4, 5);

    triangle1->printInfo();
    std::cout << "Area: " << triangle1->calculateArea() << "\n\n";

    triangle2->printInfo();
    std::cout << "Area: " << triangle2->calculateArea() << "\n\n";

    medianTriangle->printInfo();
    std::cout << "Area: " << medianTriangle->calculateArea() << "\n\n";

    parallelMedianTriangle->printInfo();
    std::cout << "Area: " << parallelMedianTriangle->calculateArea() << "\n\n";

    rightTriangle->printInfo();
    std::cout << "Inscribed Radius: " << rightTriangle->calculateInscribedRadius() << "\n";
    std::cout << "Circumscribed Radius: " << rightTriangle->calculateCircumscribedRadius() << "\n";

    delete triangle1;
    delete triangle2;
    delete medianTriangle;
    delete parallelMedianTriangle;
    delete rightTriangle;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
