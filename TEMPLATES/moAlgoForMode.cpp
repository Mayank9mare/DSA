#include <bits/stdc++.h>
using namespace std;

int N, Q;

// Variables, that hold current "state" of computation
long long current_answer;
long long cnt[100];

// Array to store answers (because the order we achieve them is messed up)
long long answers[100500];
int BLOCK_SIZE;
int arr[100500];

// We will represent each query as three numbers: L, R, idx. Idx is 
// the position (in original order) of this query.
pair< pair<int, int>, int> queries[100500];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// When adding a number, we first nullify it's effect on current
// answer, then update cnt array, then account for it's effect again.
inline void add(int x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_answer += cnt[x] * cnt[x] * x;
}

// Removing is much like adding.
inline void remove(int x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += cnt[x] * cnt[x] * x;
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N >> Q;
    BLOCK_SIZE = static_cast<int>(sqrt(N));

    // Read input array
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    // Read input queries, which are 0-indexed. Store each query's 
    // original position. We will use it when printing answer.
    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    // Sort queries using Mo's special comparator we defined.
    sort(queries, queries + Q, mo_cmp);

    // Set up current segment [mo_left, mo_right].
    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < Q; i++) {
        // [left, right] is what query we must answer now.
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right > right) {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(arr[mo_left]);
        }

        // Store the answer into required position.
        answers[queries[i].second] = current_answer;
    }

    // We output answers *after* we process all queries.
    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}
// Same solution without global variables (the way I like to implement it):

// #include <bits/stdc++.h>
// using std::vector;
// using std::tuple;

// /*
//  * Take out adding\removing logic into separate class.
//  * It provides functions to add and remove numbers from
//  * our structure, while maintaining cnt[] and current_answer.
//  * 
//  */
// struct Mo
// {
//     static constexpr int MAX_VALUE = 1005000;
//     vector<long long> cnt;
//     long long current_answer;

//     void process(int number, int delta)
//     {
//         current_answer -= cnt[number] * cnt[number] * number;
//         cnt[number] += delta;
//         current_answer += cnt[number] * cnt[number] * number;
//     }
// public:
//     Mo()
//     {
//         cnt = vector<long long>(MAX_VALUE, 0);
//         current_answer = 0;
//     }

//     long long get_answer() const
//     {
//         return current_answer;
//     }

//     void add(int number)
//     {
//         process(number, 1);
//     }

//     void remove(int number)
//     {
//         process(number, -1);
//     }
// };

// int main()
// {
//     int N, Q, BLOCK_SIZE;
//     std::cin.sync_with_stdio(false);
//     std::cin >> N >> Q;
//     BLOCK_SIZE = static_cast<int>(sqrt(N));

//     // No global variables, everything inside.
//     vector<int> arr(N);
//     vector<long long> answers(Q);
//     vector< tuple<int, int, int> > queries;
//     queries.reserve(Q);

//     for(int i = 0; i < N; i++)
//         std::cin >> arr[i];

//     for(int i = 0; i < Q; i++) {
//         int le, rg;
//         std::cin >> le >> rg;
//         queries.emplace_back(le, rg, i);
//     }

//     // Comparator as a lambda-function, which catches BLOCK_SIZE
//     // from the above definition.
//     auto mo_cmp = [BLOCK_SIZE](const tuple<int, int, int> &x,
//             const tuple<int, int, int> &y) -> bool {
//         int block_x = std::get<0>(x) / BLOCK_SIZE;
//         int block_y = std::get<0>(y) / BLOCK_SIZE;
//         if(block_x != block_y)
//             return block_x < block_y;
//         return std::get<1>(x) < std::get<1>(y);
//     };

//     std::sort(queries.begin(), queries.end(), mo_cmp);

//     Mo solver;
//     int mo_left = 0, mo_right = -1;

//     // Usual Mo's algorithm stuff.
//     for(const auto &q: queries) {
//         int left, right, answer_idx;
//         std::tie(left, right, answer_idx) = q;

//         while(mo_right < right) {
//             mo_right++;
//             solver.add(arr[mo_right]);
//         }
//         while(mo_right > right) {
//             solver.remove(arr[mo_right]);
//             mo_right--;
//         }

//         while(mo_left < left) {
//             solver.remove(arr[mo_left]);
//             mo_left++;
//         }
//         while(mo_left > left) {
//             mo_left--;
//             solver.add(arr[mo_left]);
//         }

//         answers[answer_idx] = solver.get_answer();
//     }

//     for(int i = 0; i < Q; i++)
//         std::cout << answers[i] << "\n";
//     return 0;
// }