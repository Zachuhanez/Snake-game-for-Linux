#include <iostream>

using namespace std;
 
class Point
{
public:
    int x, y;
    //construtors
    Point (int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }
    Point (Point & other)
    {
        this -> x = other.x;
        this -> y = other.y;
    }
    Point ()
    {
        x = y = 0;
    }

    void Draw(int arr[][2], int L, int width = 0, int height = 0)
    {
        for(int y2 = 0; y2 <= height; y2++)
        {
            if (y2 == 0 || y2 == height)
            {
                for(int i = 0; i <= width; i++)
                {
                    cout << "#";
                }
                cout << '#' << endl;
            }
            else
            {
                cout << "#";
                if(y2 == y)
                {
                    for(int x2 = 1; x2 <= x; x2++)
                    {
                        for(int i = 1; i < L; i++)
                        {
                            if(arr[i][0] == x2 && arr[i][1] == y2)
                            {
                                cout << '@';
                                break;
                            }
                            if(arr[0][0] == x2 && arr[0][1] == y2)
                            {
                                cout << "•";
                                break;
                            }
                            if(i == L - 1)
                            {
                                cout << " ";
                            }
                        }
                    }
                    for(int n = 1; n < width - x + 1; n++)
                    {
                        for(int i = 1; i < L; i++)
                        {
                            if(arr[i][0] == n + x && arr[i][1] == y2)
                            {
                                cout << '@';
                                break;
                            }
                            if(arr[0][0] == n + x && arr[0][1] == y2)
                            {
                                cout << "•";
                                break;
                            }
                            if(i == L - 1)
                            {
                                cout << " ";
                            }
                        }
                    }
                }
                else if(y2 != y)
                {
                    for(int x2 = 1; x2 <= width; x2++)
                    {
                        for(int i = 1; i < L; i++)
                        {
                            if(arr[i][0] == x2 && arr[i][1] == y2)
                            {
                                cout << '@';
                                break;
                            }
                            if(arr[0][0] == x2 && arr[0][1] == y2)
                            {
                                cout << "•";
                                break;
                            }
                            if(i == L - 1)
                            {
                                cout << " ";
                            }
                        }
                    }
                }
                cout << '#' << endl;
            }
        }
    }
};
