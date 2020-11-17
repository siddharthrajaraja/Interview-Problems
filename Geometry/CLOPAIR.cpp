#include <bits/stdc++.h>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
unsigned long long int MOD = 1e9 + 7;
unsigned long long int MAX = 1e5;
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vi>

#define pushb push_back
#define popf pop_front
#define popb pop_back
#define pushf push_front

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i >= b; i--)

typedef long long ll;
typedef unsigned long long ull;

void printPoints(vvi arr);
void printMapofAllPoints();

#define mdvi map<double, vector<vi>>

mdvi mapOfAllPoints;

double distance(int x1, int y1, int x2, int y2)
{
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    vector<vi> arr;
    // cout << "X1,Y1 :" << x1 << " " << y1 << endl;
    // cout << "X2,Y2 :" << x2 << " " << y2 << endl;
    // cout << "DIST IS :" << dist << endl;

    arr.push_back({x1, y1});
    arr.push_back({x2, y2});
    mapOfAllPoints[dist] = arr;

    return dist;
}

bool compareY(vi a, vi b)
{
    return a[1] > b[1];
}

double stripClosest(vvi strip, double d)
{

    double mini = d;

    sort(strip.begin(), strip.end(), compareY);

    int size = strip.size();

    int i;
    REP(i, 0, size)
    {
        for (int j = i + 1; j < size && abs(strip[i][1] - strip[j][1]) < mini; j++)
        {
            mini = min(mini, distance(strip[i][0], strip[i][1], strip[j][0], strip[j][1]));
        }
    }
    return mini;
}

double divideArr(vvi &arr, int l, int h)
{
    //cout << "LOW IS :" << l << " HIGH IS :" << h << endl;
    if (abs(l - h) <= 3)
    {
        double mini = INT_MAX;
        int i;
        REP(i, l, h)
        {
            int j;
            REP(j, i + 1, h)
            {
                mini = min(mini, distance(arr[i][0], arr[i][1], arr[j][0], arr[j][1]));
            }
        }
        return mini;
    }

    int mid = (l + h) / 2;
    double dl = divideArr(arr, l, mid);
    double dr = divideArr(arr, mid + 1, h);

    //cout << "dl is :" << dl << " dr is :" << dr << endl;
    double d = min(dl, dr);

    //cout << "d is :" << d << endl;

    // strip of d is created and find distance across strip d
    vvi strip;

    int i;
    REP(i, l, h)
    {
        if (abs(arr[i][0] - arr[mid][0]) < d)
        {
            strip.push_back({arr[i][0], arr[i][1]});
        }
    }

    return min(d, stripClosest(strip, d));
}

int main()
{
    fastIO;
    int n;
    cin >> n;

    vvi arr;

    map<vi, int> allPoints;
    int index = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
        allPoints[{x, y}] = index;
        index++;
    }

    sort(arr.begin(), arr.end());

    //printPoints(arr);

    double distance = divideArr(arr, 0, arr.size());

    vvi points = mapOfAllPoints[distance];

    int firstIndex = allPoints[points[0]];
    int secondIndex = allPoints[points[1]];

    cout << min(firstIndex, secondIndex) << " " << max(firstIndex, secondIndex)
         << " "; //<< distance << endl;

    printf("%0.06f", distance);
    //printMapofAllPoints();

    return 0;
}

void printPoints(vvi arr)
{
    for (auto ele : arr)
    {
        cout << ele[0] << " " << ele[1] << endl;
    }
}

void printMapofAllPoints()
{

    for (auto ele : mapOfAllPoints)
    {
        cout << ele.first << " : ";
        for (auto every : ele.second)
        {
            cout << every[0] << " " << every[1] << " ------  ";
        }
        cout << endl;
    }
}