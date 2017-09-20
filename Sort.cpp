#include "include/Sort.h"
#include <algorithm>
using namespace std;


void Sort::sortByDecreasingPerimeter(vector<Shape *> & shapes){
    int left = 0;
    int right = shapes.size()-1;
    int shift = 0;
    Shape *temp;

    while(left < right){
        for(int i = left; i < right; i++) {
            if(shapes[i]->perimeter() < shapes[i+1]->perimeter()){
                temp = shapes[i];
                shapes[i] = shapes[i+1];
                shapes[i+1] = temp;
                shift = i;
            }
        }
        right = shift;
        for(int i = right; i > left; i--){
            if(shapes[i]->perimeter() > shapes[i-1]->perimeter()){
                temp = shapes[i];
                shapes[i] = shapes[i-1];
                shapes[i-1] = temp;
                shift = i;
            }
        }
        left = shift;
    }
};

void Sort::sortByIncreasingPerimeter(vector<Shape *> & shapes){
    int left = 0;
    int right = shapes.size()-1;
    int shift = 0;
    Shape *temp;

    while(left < right){
        for(int i = left; i < right; i++) {
            if(shapes[i]->perimeter() > shapes[i+1]->perimeter()){
                temp = shapes[i];
                shapes[i] = shapes[i+1];
                shapes[i+1] = temp;
                shift = i;
            }
        }
        right = shift;
        for(int i = right; i > left; i--){
            if(shapes[i]->perimeter() < shapes[i-1]->perimeter()){
                temp = shapes[i];
                shapes[i] = shapes[i-1];
                shapes[i-1] = temp;
                shift = i;
            }
        }
        left = shift;
    }
};
void Sort::sortByDecreasingArea(vector<Shape *> & shapes){
    int left = 0;
    int right = shapes.size()-1;
    int shift = 0;
    Shape *temp;

    while(left < right){
        for(int i = left; i < right; i++) {
            if(shapes[i]->area() < shapes[i+1]->area()){
                temp = shapes[i];
                shapes[i] = shapes[i+1];
                shapes[i+1] = temp;
                shift = i;
            }
        }
        right = shift;
        for(int i = right; i > left; i--){
            if(shapes[i]->area() > shapes[i-1]->area()){
                temp = shapes[i];
                shapes[i] = shapes[i-1];
                shapes[i-1] = temp;
                shift = i;
            }
        }
        left = shift;
    }
};

void Sort::sortByIncreasingArea(vector<Shape *> & shapes){
    int left = 0;
    int right = shapes.size()-1;
    int shift = 0;
    Shape *temp;

    while(left < right){
        for(int i = left; i < right; i++) {
            if(shapes[i]->area() > shapes[i+1]->area()){
                temp = shapes[i];
                shapes[i] = shapes[i+1];
                shapes[i+1] = temp;
                shift = i;
            }
        }
        right = shift;
        for(int i = right; i > left; i--){
            if(shapes[i]->area() < shapes[i-1]->area()){
                temp = shapes[i];
                shapes[i] = shapes[i-1];
                shapes[i-1] = temp;
                shift = i;
            }
        }
        left = shift;
    }
};


void Sort::sortByIncreasingCompactness(vector<double> & result){
    sort(result.begin(),result.end());
};