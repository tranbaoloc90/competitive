#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_container(vector<T>& x)
{
    for_each(x.begin(), x.end(), [](auto& el)
    {
        cout << el << "\t";
    });
    cout << endl;
}

int max_candy_consume(vector<int>& bags, int k)
{
    make_heap(bags.begin(), bags.end());
    int num_candy = 0;
    while(k--)
    {
        //print_container(bags);
        int max_ = bags[0];
        num_candy += max_;
        pop_heap(bags.begin(), bags.end());
        bags.pop_back();
        bags.push_back(max_/2);
        push_heap(bags.begin(), bags.end());
    }
    return num_candy;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N,K;
        cin >> N >> K;
        vector<int> bags(N,-1);
        for_each(bags.begin(), bags.end(), [](auto& el)
        {
            cin >> el;
        });
        cout << max_candy_consume(bags, K) << endl;
    }
}
