#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


vector<int> solution(vector<int> arr)
{
    sort(arr.begin(),arr.end(), greater<int>());
    
    auto new_end=unique(arr.begin(),arr.end());

    arr.erase(new_end,arr.end());

    return arr;

}

bool compare(int a, int b)
{
    return a>b;
}

vector<int> solution(vector<int> arr)
{
    sort(arr.begin(),arr.end(), compare);

    arr.erase(unique(arr.begin(),arr.end()),arr.end());

    return arr;
}