#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin>>n;
    for(int i = 0; i < n; i++)
    {
        int size;
        cin >> size;

        int *arr = new int[size];

        for(int j = 0; j < size; j++)
            cin >> arr[j];
        
        qsort(arr, size, sizeof(int), compare);
        // for(int j = 0; j < size; j++)
        //     cout << arr[j] << " ";
        // cout << endl;
        int temp;
        for(int j = size - 2; j >= 1; j-= 4)
        {
            //cout << "j - " << j;
            if(arr[j] == 0 || arr[j - 1] == 0 || arr[j + 1] == 0)
            {
                j += 3;
                continue;
            }
            if(arr[j] < 0)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                continue;
            }
            temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;

            temp = arr[j + 1];
            arr[j + 1] = arr[j - 1];
            arr[j - 1] = temp;
        }

        // for(int j = 0; j < size; j++)
        //     cout << arr[j] << " ";
        // cout << endl;

        long long sum = 0;
        for(int j = 0; j < size - 1; j++)
            sum += long(arr[j]) * long(arr[j + 1]);
        sum += long(arr[size -1]) * long(arr[0]);
        delete[] arr;
        cout << sum << endl;
    }
}
