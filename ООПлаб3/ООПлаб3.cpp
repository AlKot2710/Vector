#include <iostream>
#include <string>

using namespace std;

template<typename T>
class TVector
{
public:
    T& operator[](int index) // оператор индексации
    {
        return arr[index];
    }
    TVector() 
    {

    }

    TVector(int size_)  //конструктор вектора заданной длинны
    {
        this->size_ = size_;
        arr = new T[size_];
        for (int i = 0; i < size_; i++)
        {
            cin >> arr[i];
            cout << arr[i];
        }
    }
    ~TVector()      //деструктор
    {
        delete[] arr;
    }
    int size() const
    {
        return size_;
    }
public:
    T* arr;
    int size_ = 0;
};

template<typename T>
class TMatrix
{
    TVector<T>* vrows;
    int rows, cols;
public:
    TVector<T>& operator[]( int index) 
    { 
        return vrows[index]; 
    }

    TMatrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        vrows = new TVector<T>[rows];
        for (int i = 0; i < rows; i++) {
            vrows[i] = new TVector<T>(cols);
        }
    }
    int Getrows()
    {
        return rows;
    }
    int Getcols()
    {
        return cols;
    }
    
};

template<typename T>
ostream& operator<<(ostream& os, TVector<T>& vector)
{
    for (int i = 0; i < vector.size(); ++i)
    {
        os << vector[i] << " ";
    }
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, TMatrix<T>& matrix)
{
    for (int i = 0; i < matrix.Getrows(); i++)
    {
        for (int j = 0; j < matrix.Getcols(); j++)
        {
            os << matrix[i][j];
        }
    }
    return os;
}


int main()
{
    //TVector<string> amogus(5);
    //cout << amogus;
    TMatrix<int> a(2, 2);
    cout << a;

}