#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    int temp, n=arr.size()-1, i=0, j=n, t1, t2;
    while(i<n && arr[i]<arr[i+1]) i++;
    if(i==n)
    {
        cout<<"yes";
        return;
    }
    while(j>0 && arr[j]>arr[j-1]) j--;
    t1=i;
    t2=j;

    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i=0;
    while(i<n && arr[i]<arr[i+1]) i++;
    if(i==n)
    {
        cout<<"yes\nswap "<<t1+1<<" "<<t2+1;
        return;
    }
    i=t1;
    j=t2;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    while(i<j)
    {
        temp=arr[i];
        arr[i++]=arr[j];
        arr[j--]=temp;
    }
    i=0;
    while(i<n && arr[i]<arr[i+1]) i++;
    if(i<n)
    {
        cout<<"no";
        return;
    }
    cout<<"yes\n";
    if(t1+1==t2)
        cout<<"swap "<<t1+1<<" "<<t2+1;
    else
        cout<<"reverse "<<t1+1<<" "<<t2+1;
    return;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
