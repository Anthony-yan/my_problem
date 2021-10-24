#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>

using namespace std;

int a[18][18];
char b[18][18];
int i, j, k;
int n, m;
int s = 0, bj = 1;
int x, y;
int mark;

int numofboom(int x, int y)
{
    int s = 0;
    for (i = x - 1; i <= x + 1; ++i)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            s += a[i][j];
        }
    }
    return s;
}

int main()
{
    system("cls");
    cout << "Please enter the side length and the number of landmines" << endl;
    cin >> n >> m;
    system("cls");
    int i;
    while (n * n < m)
    {
        cout << "Do you want to play?" << endl;
        cout << "Then enter the right side length and the number of landmines!!!" << endl;
        cin >> n >> m;
        system("cls");
        ++i;
        if (i > 3)
        {
            break;
        }
    }
    if (i == 4)
    {
        for (i = 0; i < 200; ++i)
        {
            cout << "Don't play after this!" << endl;
            system("cls");
        }
        for (i = 200; i >= 0; --i)
        {
            cout << i << endl;
            system("cls");
        }
        return 0;
    }
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            a[i][j] = rand() % 2;
            if (a[i][j] == 1)
                ++s;
            if (s == m)
            {
                bj = 0;
                break;
            }
        }
        if (bj == 0)
            break;
    }
    if (bj == 1)
    {
        for (i = n; i >= 1; --i)
        {
            for (j = n; j >= 1; --j)
            {
                if (!a[i][j])
                {
                    ++a[i][j];
                    ++s;
                }
                if (s == m)
                {
                    bj = 0;
                    break;
                }
            }
            if (bj == 0)
                break;
        }
    }
    bj = 1;
    s = 0;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            b[i][j] = 'o';
        }
    }
    time_t first, second;
    first = time(NULL);
    while (bj)
    {
        cout << "The number of landmines:" << m - s << endl;
        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                cout << b[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "Please enter the coordinates you want to operate, the format is 'x y'" << endl;
        cin >> x >> y;
        cout << "Please enter operation:1 to open, 2 to mark or unmark" << endl;
        cin >> mark;
        if (mark == 1)
        {
            if (a[x][y] == 1)
            {
                system("cls");
                cout << "You failed!" << endl;
                for (int i = 1; i <= n; ++i)
                {
                    for (j = 1; j <= n; ++j)
                    {
                        if (a[i][j] == 1)
                            cout << '*';
                        else
                            cout << 'o';
                        cout << ' ';
                    }
                    cout << endl;
                }
                char www;
                cout << "TAP ANY TO ENTER. . ." << endl;
                cin >> www;
                return 0;
            }
            else
            {
                b[x][y] = (char)numofboom(x, y) + '0';
            }
        }
        else
        {
            if (b[x][y] == 'f')
            {
                b[x][y] = 'o';
                --s;
            }
            else
            {
                b[x][y] = 'f';
                ++s;
            }
        }
        if (m - s == 0)
        {
            int mm = 0;
            for (i = 1; i <= n; ++i)
            {
                for (j = 1; j <= n; ++j)
                {
                    if (a[i][j] == 1 && b[i][j] == 'f')
                        ++mm;
                }
            }
            if (mm == m)
                bj = 0;
        }
        system("cls");
    }
    cout << "You win!" << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (a[i][j] == 1)
                cout << '*';
            else
                cout << 'o';
            cout << ' ';
        }
        cout << endl;
    }
    second = time(NULL);
    cout << "You use just " << difftime(second, first) << " seconds!" << endl;
    cout << "TAP ANY TO ENTER. . ." << endl;
    char qqq;
    cin >> qqq;
    system("cls");
    return 0;
}
