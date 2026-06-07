#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string s) {
    if (s.empty()) return false;

    int start = 0;

    if (s[0] == '-') {
        if (s.length() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }

    return true;
}

vector<unsigned long> groups(string str) {
    vector<unsigned long> res;

    if (str[0] == '-')
        str = str.substr(1);

    int iters = (str.length() + 8) / 9;
    int len = str.length();

    for (int i = 1; i <= iters; i++) {
        unsigned long sub;

        if (len - i * 9 >= 0)
            sub = stoul(str.substr(len - i * 9, 9));
        else
            sub = stoul(str.substr(0, len % 9));

        res.push_back(sub);
    }

    return res;
}

vector<unsigned long> summa(vector<unsigned long> a, vector<unsigned long> b, char op, bool &negative) {
    vector<unsigned long> res;
    negative = false;

    if (op == '+') {
        unsigned long flag = 0;
        size_t len = max(a.size(), b.size());

        for (size_t i = 0; i < len; i++) {
            unsigned long x = 0, y = 0;

            if (i < a.size()) x = a[i];
            if (i < b.size()) y = b[i];

            unsigned long sum = x + y + flag;

            if (sum >= 1000000000) {
                flag = 1;
                sum -= 1000000000;
            } else {
                flag = 0;
            }

            res.push_back(sum);
        }

        if (flag)
            res.push_back(flag);
    }

    else if (op == '-') {

        if (a.size() < b.size()) {
            swap(a, b);
            negative = true;
        }

        else if (a.size() == b.size()) {
            for (int i = a.size() - 1; i >= 0; i--) {
                if (a[i] < b[i]) {
                    swap(a, b);
                    negative = true;
                    break;
                }

                else if (a[i] > b[i]) {
                    break;
                }
            }
        }

        long long flag = 0;
        size_t len = max(a.size(), b.size());

        for (size_t i = 0; i < len; i++) {
            long long x = 0, y = 0;

            if (i < a.size()) x = a[i];
            if (i < b.size()) y = b[i];

            long long sub = x - y - flag;

            if (sub < 0) {
                flag = 1;
                sub += 1000000000;
            } else {
                flag = 0;
            }

            res.push_back(sub);
        }

        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
    }

    return res;
}

int main() {
    string a, b;
    char op;
    cout << "Введите два числа через пробел: " << endl;
    cin >> a >> b;
    cout << "Введите операцию (+ или -): " << endl;
    cin >> op;

    if (!check(a) || !check(b)) {
        cout << "Error";
        return 0;
    }

    bool negA = false;
    bool negB = false;

    if (a[0] == '-') negA = true;
    if (b[0] == '-') negB = true;

    bool negative = false;

    vector<unsigned long> res = summa(groups(a), groups(b), op, negative);

    if (negative)
        cout << "-";

    if (negA && negB)
        cout << "-";

    for (int i = res.size() - 1; i >= 0; i--) {
        if (i == res.size() - 1) {
            cout << res[i];
        } else {
            string part = to_string(res[i]);
            int zeros = 9 - part.length();

            for (int j = 0; j < zeros; j++)
                cout << "0";

            cout << part;
        }
    }
}