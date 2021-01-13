#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vll fentree;

void printFentree(vll arr)
{
    cout << "Fentree is :";
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

ll getTwoComplement(ll ele)
{
    return ele & (-1 * ele);
}

ll getNext(ll index)
{
    ll twoComplement = getTwoComplement(index);
    ll andIndex = index & twoComplement;
    return index + andIndex;
}

ll getParent(ll index)
{
    ll twoComplement = getTwoComplement(index);
    ll andIndex = index & twoComplement;
    return index - andIndex;
}

ll getSum(ll index)
{

    ll fentreeIndex = index + 1;
    ll sum = 0;

    while (fentreeIndex > 0)
    {
        sum += fentree[fentreeIndex];
        fentreeIndex = getParent(fentreeIndex);
    }

    return sum;
}

void initFenTree(ll n, ll ele, ll index)
{

    ll fentreeIndex = index + 1;

    while (fentreeIndex < n + 1)
    {
        fentree[fentreeIndex] += ele;

        fentreeIndex = getNext(fentreeIndex);
    }
}

int main()
{
    fastIO

        ll n;
    cin >> n;

    ll i;
    vll arr;

    REP(i, 0, n)
    {
        ll ele;
        cin >> ele;
        arr.push_back(ele);
        fentree.push_back(0);
    }

    REP(i, 0, n)
    {
        initFenTree(n, arr[i], i);
        //printFentree(fentree);
    }

    ll q;
    cin >> q;

    while (q--)
    {

        char op;
        cin >> op;

        if (op == 'q')
        {

            ll l, r;
            cin >> l >> r;
            l--;
            r--;

            ll rSum = getSum(r);
            ll lSum = getSum(l - 1);

            cout << rSum - lSum << endl;
        }
        else
        {

            ll i, x;
            cin >> i >> x;
            i--;
            initFenTree(n, x, i);
        }
    }

    return 0;
}