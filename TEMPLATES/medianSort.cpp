#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case(int N) {
    auto query = [&](int a, int b, int c) -> int {
        cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int ans;
        cin >> ans;
        assert(ans != -1);
        ans--;
        return ans;
    };

    vector<int> sorted = {0, 1};

    for (int i = 2; i < N; i++) {
        int low = 0, high = i;

        while (high - low > 1) {
            int mid1 = (2 * low + high) / 3;
            int mid2 = (low + 2 * high) / 3;
            int median = query(sorted[mid1], sorted[mid2], i);

            if (median == sorted[mid1]) {
                high = mid1;
            } else if (median == sorted[mid2]) {
                low = mid2 + 1;
            } else {
                low = mid1 + 1;
                high = mid2;
            }
        }

        if (high - low == 1) {
            int a = low, b = high;

            if (high == i) {
                a--;
                b--;
            }

            int median = query(sorted[a], sorted[b], i);

            if (high == i) {
                if (median == i)
                    high = low;
                else
                    low = high;
            } else {
                if (median == i)
                    low = high;
                else
                    high = low;
            }
        }

        sorted.insert(sorted.begin() + low, i);
    }

    output_vector(sorted, true);
    cout << flush;
    int ans;
    cin >> ans;
    assert(ans != -1);
}

int main() {
    int T, N, Q;
    cin >> T >> N >> Q;

    for (int tc = 1; tc <= T; tc++) {
        run_case(N);
        cout << flush;
    }
}
