#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findConnectedComponents' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY d as parameter.
 */

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int findConnectedComponents(vector<long> d) {
    int n = d.size();
    vector<int> nodes;
    int sum_connected = 0;
    
    for(int i=0; i<n; i++){
        int count = 0;
        while(d[i]){
            count += d[i]&1;
            d[i]>>=1;
        }
        int node = count/2;
        nodes.push_back(node);
    }
    cout<<endl;
    for (int i=1; i<=n; i++){
        int combination = nCr(n,i); 
        int per_element = combination*i/n;
        int sum_node = 0;
        for (int j=0; j<n; j++){
            sum_node += per_element*nodes[j];
        }
        sum_connected += (64*combination-sum_node);
    }
    sum_connected += 64;
    return sum_connected;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string d_count_temp;
    getline(cin, d_count_temp);

    int d_count = stoi(ltrim(rtrim(d_count_temp)));

    string d_temp_temp;
    getline(cin, d_temp_temp);

    vector<string> d_temp = split(rtrim(d_temp_temp));

    vector<long> d(d_count);

    for (int i = 0; i < d_count; i++) {
        long d_item = stol(d_temp[i]);

        d[i] = d_item;
    }

    int components = findConnectedComponents(d);

    fout << components << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
