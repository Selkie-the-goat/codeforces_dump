<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solve_agent() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    string s = "";
    char colors[] = {'r', 'g', 'b'};
    for (int i = 1; i <= n; ++i) {
        s += colors[dist[i] % 3];
    }
    cout << s << endl;
}
void solve_blackslex() {
    int q_count;
    cin >> q_count;
    while (q_count--) {
        int d;
        cin >> d;
        string colors;
        cin >> colors;

        bool has_r = false, has_g = false, has_b = false;
        for (char c : colors) {
            if (c == 'r') has_r = true;
            if (c == 'g') has_g = true;
            if (c == 'b') has_b = true;
        }

        char target;
        if (has_r && has_g) target = 'r';
        else if (has_g && has_b) target = 'g';
        else if (has_b && has_r) target = 'b';
        else target = colors[0]; // Only one color present

        for (int i = 0; i < d; ++i) {
            if (colors[i] == target) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string problem_type;
        cin >> problem_type;
        if(problem_type=="first")
        solve_blackslex();
        else
        solve_agent();
    }

    return 0;
=======
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solve_agent() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    string s = "";
    char colors[] = {'r', 'g', 'b'};
    for (int i = 1; i <= n; ++i) {
        s += colors[dist[i] % 3];
    }
    cout << s << endl;
}
void solve_blackslex() {
    int q_count;
    cin >> q_count;
    while (q_count--) {
        int d;
        cin >> d;
        string colors;
        cin >> colors;

        bool has_r = false, has_g = false, has_b = false;
        for (char c : colors) {
            if (c == 'r') has_r = true;
            if (c == 'g') has_g = true;
            if (c == 'b') has_b = true;
        }

        char target;
        if (has_r && has_g) target = 'r';
        else if (has_g && has_b) target = 'g';
        else if (has_b && has_r) target = 'b';
        else target = colors[0]; // Only one color present

        for (int i = 0; i < d; ++i) {
            if (colors[i] == target) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string problem_type;
        cin >> problem_type;
        if(problem_type=="first")
        solve_blackslex();
        else
        solve_agent();
    }

    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}