#include <iostream>
using namespace std;
int* MergeSort(int* up, int* down, unsigned int left, unsigned int right, long& counter);
int main()

{
    int n;
    int* mass, * mass2;
    long counter = 0;
    cin >> n;
    mass = new int[n];
    mass2 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> mass[i];

    MergeSort(mass, mass2, 0, n - 1, counter);
    cout << counter;
}
int* MergeSort(int* up, int* down, unsigned int l, unsigned int r, long& counter)
{
    if (l == r)
    {
        down[l] = up[l];
        return down;
    }

    unsigned int m = (l + r) / 2;


    int* l_buff = MergeSort(up, down, l, m, counter);
    int* r_buff = MergeSort(up, down, m + 1, r, counter);


    int* target = l_buff == up ? down : up;

    unsigned int l_cur = l, r_cur = m + 1;
    for (unsigned int i = l; i <= r; i++)
    {
        if (l_cur <= m && r_cur <= r)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
                counter += m - l + 1 - (l_cur - l);
            }
        }
        else if (l_cur <= m)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}