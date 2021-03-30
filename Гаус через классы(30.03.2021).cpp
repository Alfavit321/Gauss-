#include <iostream>
using namespace std;
class Gauss{
    float m;
    float** matr;
    void Create() {
        matr = new float* [m];
        for (int i = 0; i < m; i++)
            matr[i] = new float[m];
    }
public:
    Gauss();
    Gauss(int m);
    ~Gauss();
    void AddMatr();
    void Print();
    void Transformer();
    void Del();
};
Gauss::Gauss()
{
    this->m = 3;
    this->Create();
}
Gauss::Gauss(int row)
{
    this->m = row;
    this->Create();
}
Gauss::~Gauss()
{
    for (int i = 0; i < this->m; i++)
        delete[] matr[i];
    delete[] matr;
}
void Gauss::AddMatr()
{
    for (int i = 0; i < this->m; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            this->matr[i][j] = rand() % 21 - 10;
        }
    }
}
void Gauss::Transformer()
{
    for (int i = 0; i < m; i++)
    {
        int c = i;
        while (abs(matr[c][i]) < 1e-15 && c < m) c++;
        swap(matr[c], matr[i]);
        for (int j = i + 1; j < m + 1; j++)
            matr[i][j] /= matr[i][i];
        matr[i][i] = 1;
        for (int k = i + 1; k < m; k++)
        {
            double y = matr[k][i];
            for (int j = 0; j < m + 1; j++)
            {
                matr[k][j] -= matr[i][j] * y;
            }
        }
    }
}
void Gauss::Print()
{
    for (int i = 0; i < this->m; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
           cout<<this->matr[i][j] <<" \t";
        }
        cout << endl;
    }
    cout << endl;
}
void Gauss::Del()sdsd
{
    for (int i = 0; i <this->m; i++)
    {
        delete matr[i];
    }
    delete[]matr;
}
int main()
{
    Gauss a;
    a.AddMatr();
    a.Print();
    a.Transformer();
    a.Print();
    a.Del();
}
