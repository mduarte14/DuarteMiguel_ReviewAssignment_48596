/*
						Miguel Duarte
						Review Assignment 1 
						CIS-17B 
						09/10/14
*/


//Libraries
#include <QApplication>
#include <iostream>
#include <ctime>
#include <QLabel>
#include <cstdlib>
#include <sstream>          //For String Stream function
using namespace std;

//For Grading Purposes I wont include a header file. All code will be here.
//Initialize class
class array2d
{

private:

    int nRows;
    int nCols;
    int **array;

public:
    //Constructor
    array2d(int, int);
    //Destrcutor
    ~array2d();
    //Accessor/Mutators
    char *toString();
    int getNum();
    int *getArray(int);
};

//Main
int main(int argc, char *argv[])
{
    //Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Initialize Variables
    int rows = 10;
    int cols = 10;
    array2d myArray = array2d(rows, cols);

    //Print On QT
    QCoreApplication a(argc, argv);
    QLabel *label = new QLabel(myArray.toString());
    (*label).show();
    return a.exec();
}

//Constructor Initialization
array2d::array2d(int rows, int cols)
{
    //Set
    nRows = rows;
    nCols = cols;

    int** newArray = new int*[nRows];
    //Create seperated arrays
    for (int i = 0; i < nCols; i++)
    {
        newArray[i] = getArray(nCols);
    }

    //Now Set the newArray equal to the Perm Array
    array = newArray;
}

//Destructor Initialization
array2d::~array2d()
{
    for (int i = 0; i < nCols; i++)
    {
        //Free Memory in Array
        delete[] array;
    }
}

char *array2d::toString()
{
    std::stringstream  temp;	//sstream
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; i < nCols; j++){
            temp << array[i][i] << "   " << endl;
        }
        temp << endl;
    }
    int size = temp.str().length() + 1;
    char* output = new char[size];
    for (int i = 0; i < size; i++)
    {
        output[i] = temp.str()[i];
    }
	//Return the string
    return output;
}

int array2d::getNum(){
    //Random Number Generator
    return rand() % 90 + 10;
}

int *array2d::getArray(int c)
{
    //Initialize new vars
    int *temp = new int[c];
    //set array
    for (int i = 0; i < c; i++){
        temp[i] = getNum();
    }
    //Return Temp array
    return temp;
}
