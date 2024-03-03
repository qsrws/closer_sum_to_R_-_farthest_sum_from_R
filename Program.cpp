#include <iostream>
#include <cmath>

class Numbers
{

    public:
    int ind_i;
    int ind_j;
    double res;
    double arg;

    Numbers Get_Numbers(int ind_i, int ind_j, double arg, double r)
    {
        this->ind_i = ind_i;
        this->ind_j = ind_j;
        this->res = abs(r - arg);
        this->arg = arg;

        return *this;
    }
};


int Factorial(int N)
{
    if (N == 1) return 1;
    return N *= Factorial(N - 1);
}


int main(int argc, char *argv[])
{
    int N1, k=0, min_i = -1, min_j = -1, max_i = -1, max_j = -1, i_min = -1, i_max = -1;
    double R, min = 99999.99, max = -9999.99;

    std::cout<<"input R: ";
    std::cin>>R;
    std::cout<<"Input Length of array: ";
    std::cin>>N1;

    int N2 = Factorial(N1) / (Factorial(2) * Factorial(N1 - 2));

    double *array_1 = new double [N1];

    Numbers *array_2 = new Numbers[N2];

    for (int i = 0; i < N1; i++)
    {
        std::cout<<"Enter " <<i<<" element: ";
        std::cin>> array_1[i];
    }  

    std::cout;

    for (int i = 0; i < N1; i++)
    {
        for (int j = i + 1; j < N1; j++)
        {
            array_2[k].Get_Numbers(i, j, array_1[i] + array_1[j], R);

            k++;
        }
    }

    for (int i = 0; i < N2; i++)
    {
        if (min > array_2[i].res)
        {
            min = array_2[i].res;
            min_i = array_2[i].ind_i;
            min_j = array_2[i].ind_j;
            i_min = i;
        }

        if (max < array_2[i].res)
        {
            max = array_2[i].res;
            max_i = array_2[i].ind_i;
            max_j = array_2[i].ind_j;
            i_max = i;
        }
    }

    std::cout<<"% arg i j\n";

    for (int i = 0; i < N2; i++)
    {
        std::cout<<array_2[i].res<<", "<<array_2[i].arg<<", "<<array_2[i].ind_i<<", "<<array_2[i].ind_j<<"\n";
    } 

    std::cout;
    
    std::cout<<"farthest sum = "<<array_2[i_max].arg<<", i is "<<max_i<<", j is "<<max_j<<"\n";
    std::cout<<"closer sum = "<<array_2[i_min].arg<<", i is "<<min_i<<", j is "<<min_j<<"\n";

    return 0;
}