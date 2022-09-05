#include <iostream>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
int main(){
    Circle c1(1,1,5);
    Shape* f1;
    f1 = &c1;
    cout << f1->draw() << endl;
    Shape* arr[5];
    arr[0] = new Circle(2,3,6);
    arr[1] = new Rectangle(4,4,8,5);
    arr[2] = new Circle(2,3,6);
    arr[3] = new Rectangle(4,5,5,5);
    arr[4] = new Circle(8,2,5);
    for(int i=0 ;i<5;i++){
        cout << arr[i]->draw() << " - ";
        cout << arr[i] << endl;
        cout << arr[i]->area() << endl;
        if(Circle* c=dynamic_cast <Circle*>(arr[i])){
            cout << "Circumference " << c->circumference() << endl;
        }
    }
    vector <Shape*> vectorS;
    vectorS.push_back(new Circle(2,3,6));
    vectorS.push_back(new Rectangle(4,4,8,5));
    vectorS.push_back(new Circle(2,3,6));
    vectorS.push_back(new Rectangle(4,5,5,5));
    vectorS.push_back(new Circle(8,2,5));
    for(int i=0 ;i<vectorS.size();i++){
        cout << vectorS[i]->draw() << " - ";
        cout << vectorS[i] << endl;
        cout << vectorS[i]->area() << endl;
        if(Circle* c=dynamic_cast <Circle*>(vectorS[i])){
            cout << "Circumference " << c->circumference() << endl;
        }
    }
    cout << "WITH FOR EACH" <<endl;
    for (auto &ptrShape:vectorS){
        cout << ptrShape->draw() << endl;
    }
    return 0;
}