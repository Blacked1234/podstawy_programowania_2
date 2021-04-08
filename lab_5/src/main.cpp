#include <iostream>
#include <cmath>
#include <vector>
#include<sstream>

class TwoDimensionMatrix {
private:
    int matrix[2][2];
    static const int size = 2;
public:
    TwoDimensionMatrix() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    TwoDimensionMatrix(const int matrix[][2])
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this->matrix[i][j] = matrix[i][j];
            }
        }
    }
    int getElement(int row, int col)const
    {
        if(row < size && col < size)
        {
            return matrix[row][col];
        }
        else
        {
            return NULL;
        }
    }
    void setElement(int row, int col, int wart)
    {
        if(row < size && col < size)
        {
            this->matrix[row][col] = wart;
        }
    }
    static constexpr int getSize()
    {
        return size;
    }

    TwoDimensionMatrix operator =(const TwoDimensionMatrix & T)
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this->matrix[i][j] = T.matrix[i][j];
            }
        }
        return *this;
    }

    TwoDimensionMatrix& operator *=(int number)
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] *= number;
            }
        }
        return *this;
    }

    bool operator &&(const TwoDimensionMatrix& matrix1)const
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(matrix[i][j] != matrix1.matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

std::ostream operator <<(std::ostream & os, const TwoDimensionMatrix & V)
{
    for (int i = 0; i < V.getSize(); i++) {
        for (int j = 0; j < V.getSize(); j++) {
            os << V.getElement(i, j);
        }
    }
}

TwoDimensionMatrix operator +(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2)
{
    TwoDimensionMatrix matrix3;
    for (int i = 0; i < matrix1.getSize(); i++) {
        for (int j = 0; j < matrix1.getSize(); j++) {
           matrix3.setElement(i, j, matrix1.getElement(i, j) + matrix2.getElement(i, j));
        }
    }
    return matrix3;
}


int main(int argc, char *argv[])
{

    return 0;
}