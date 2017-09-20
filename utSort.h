#ifndef EXP_H
#define EXP_H

#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <algorithm>
#include <vector>
#include <typeinfo>

using namespace std;

const double epsilon = 0.01;


TEST (Sort, sortByDecreasingPerimeter) {
    
    Rectangle rect(0, 0, 8, 9);
    Circle cir(0, 0, 12);
    Triangle tri({1, 1}, {3, 1}, {3, 4});
    
    vector<Shape *> Shapelist;
    Shapelist.push_back(&rect);
    //75.3982
    Shapelist.push_back(&tri);
    //8.6055
    Shapelist.push_back(&cir);
    //34

    Sort::sortByDecreasingPerimeter(Shapelist);

    int i =0;
    int j=Shapelist.size();
    /*
        while(i<j)
        {
           
           cout<<Shapelist[i]->perimeter()<<endl;
           ++i;
        }*/
    
   
    double array[3];
    array[2] = 8.60555;
    array[1] = 34;
    array[0] = 75.3982;
    
    //for(int i =0;i<3;++i)
    //cout<<array[i]<<endl;
   ASSERT_NEAR(Shapelist[j-1]->perimeter(),array[2],epsilon);
   
}

TEST (Sort, sortByIncreasingPerimeter) {

    Rectangle rect(0, 0, 8, 9);
    Circle cir(0, 0, 12);
    Triangle tri({1, 1}, {3, 1}, {3, 4});
    
    vector<Shape *> Shapelist;
    Shapelist.push_back(&rect);
    //75.3982
    Shapelist.push_back(&tri);
    //8.6055
    Shapelist.push_back(&cir);
    //34

    Sort::sortByIncreasingPerimeter(Shapelist);

    int i =0;
    int j=Shapelist.size();
   /* 
        while(i<j)
        {
           
           cout<<Shapelist[i]->perimeter()<<endl;
           ++i;
        }
    
   cout<<endl;
   cout<<Shapelist[j-1]->perimeter()<<endl;*/


    double array[3];
    array[2] = 75.3982;
    array[1] = 34;
    array[0] = 8.60555;
   // cout<<array[2]<<endl;

   ASSERT_NEAR(Shapelist[j-1]->perimeter(),array[2],epsilon);
}



TEST (Sort, sortByDecreasingArea) {
    Rectangle rect(0, 0, 8, 9);
    Circle cir(0, 0, 12);
    Triangle tri({1, 1}, {3, 1}, {3, 4});
    
    vector<Shape *> Shapelist;
    Shapelist.push_back(&rect);
    //72
    Shapelist.push_back(&tri);
    //3
    Shapelist.push_back(&cir);
    //452.389

    Sort::sortByDecreasingPerimeter(Shapelist);

    int i =0;
    int j=Shapelist.size();
    /*
        while(i<j)
        {

           cout<<Shapelist[i]->area()<<endl;
           ++i;
        }
    cout<<endl;*/
   
    double array[3];
    array[2] = 3;
    array[1] = 72;
    array[0] = 452.389;
    
   // for(int i =0;i<3;++i)
    //cout<<array[i]<<endl;
   ASSERT_NEAR(Shapelist[j-1]->area(),array[2],epsilon);
}

TEST (Sort, sortByIncreasingArea) {
    Rectangle rect(0, 0, 8, 9);
    Circle cir(0, 0, 12);
    Triangle tri({1, 1}, {3, 1}, {3, 4});
    
    vector<Shape *> Shapelist;
    Shapelist.push_back(&rect);
    //72
    Shapelist.push_back(&tri);
    //3
    Shapelist.push_back(&cir);
    //452.389

    Sort::sortByIncreasingPerimeter(Shapelist);

    int i =0;
    int j=Shapelist.size();
    /*
        while(i<j)
        {

           cout<<Shapelist[i]->area()<<endl;
           ++i;
        }
    cout<<endl;*/
   
    double array[3];
    array[2] = 452.389;
    array[1] = 72;
    array[0] = 3;
    
    //for(int i =0;i<3;++i)
   // cout<<array[i]<<endl;
   ASSERT_NEAR(Shapelist[j-1]->area(),array[2],epsilon);
}


TEST (Sort, sortByIncreasingCompactness) {
    Rectangle rect(0, 0, 8, 9);
    //72 34
    Circle cir(0, 0, 12);
    //
    Triangle tri({1, 1}, {3, 1}, {3, 4});
    //
    vector<Shape *> Shapelist;
    vector<double> result;
    Shapelist.push_back(&rect);
    //72 34   2.11765
    Shapelist.push_back(&tri);
    //3  8.60555   0.348612
    Shapelist.push_back(&cir);
    //452.389 75.3982  6
    
   
    int i =0;
    int j=Shapelist.size();
    double temp = 0;
        while(i<j)
        {
            temp = Shapelist[i]->area()/Shapelist[i]->perimeter();
       //    cout<<Shapelist[i]->area()<<" "<<Shapelist[i]->perimeter()<<endl;
           cout<<temp<<endl;
           result.push_back(temp);
           ++i;
        }
    cout<<endl<<endl;

    Sort::sortByIncreasingCompactness(result);

     i =0;
     
    while(i<j)
    {
      cout<<result[i]<<endl;
      ++i;
    }
    double array[1];
    array[0] = 6;
    ASSERT_NEAR(result[j-1],array[0],epsilon);
}

#endif
