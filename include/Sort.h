#include <list>
#include "Shapes.h"

using namespace std;

class Sort {

  public :static void sortByIncreasingPerimeter(vector<Shape *> & shapeList);

  public :static void sortByDecreasingPerimeter(vector<Shape *> & shapeList);

  public :static void sortByIncreasingArea(vector<Shape *> & shapes);

  public :static void sortByDecreasingArea(vector<Shape *> & shapes);
  
  public :static void sortByIncreasingCompactness(vector<double> & result);
  
};
