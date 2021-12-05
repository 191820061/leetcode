#include <iostream>

using namespace std;

#define maxn 1000001
long long Sum[maxn << 2], Add[maxn << 2];
long long A[maxn];


long long n;
long long m;

void pushUp(long long rt) {
    Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1];
}

void Build(long long left, long long right, long long rt) {
    if (left == right) {
        Sum[rt] = A[left];
        return;
    }
    long long mid = (left + right) / 2;
    Build(left, mid, rt << 1);
    Build(mid + 1, right, rt << 1 | 1);
    pushUp(rt);
}

void Update(long long L, long long E, long long left, long long right, long long rt) {
    if (left == right) {
        Sum[rt] += E;
        return;
    }
    long long mid = (left + right) / 2;
    if (L <= mid) {
        Update(L, E, left, mid, rt << 1);
    } else {
        Update(L, E, mid + 1, right, rt << 1 | 1);
    }
    pushUp(rt);
}


void PushDown(long long rt, long long ln, long long rn) {
    //ln,rn为左子树，右子树的数字数量。
    if (Add[rt]) {
        //下推标记
        Add[rt << 1] += Add[rt];
        Add[rt << 1 | 1] += Add[rt];
        //修改子节点的Sum使之与对应的Add相对应
        Sum[rt << 1] += Add[rt] * ln;
        Sum[rt << 1 | 1] += Add[rt] * rn;
        //清除本节点标记
        Add[rt] = 0;
    }
}


void UpdateAll(long long L, long long R, long long C, long long left, long long right, long long rt) {
    if (L <= left && right <= R) {
        Sum[rt] += C * (right - left + 1);
        Add[rt] += C;
        return;
    }
    long long mid = (left + right) / 2;
    PushDown(rt, mid - left + 1, right - mid);
    if (L <= mid) {
        UpdateAll(L, R, C, left, mid, rt << 1);
    }
    if (R >= mid + 1) {
        UpdateAll(L, R, C, mid + 1, right, rt << 1 | 1);
    }
    pushUp(rt);
}

long long Query(long long L, long long R, long long left, long long right, long long rt) {
    if (L <= left && right <= R) {
        return Sum[rt];
    }
    long long mid = (left + right) / 2;
    PushDown(rt, mid - left + 1, right - mid);
    long long all = 0;
    if (L <= mid) {
        all += Query(L, R, left, mid, rt << 1);
    }
    if (R >= mid + 1) {
        all += Query(L, R, mid + 1, right, rt << 1 | 1);
    }
    return all;
}

struct instruct {
    long long order;
    long long x;
    long long y;
    long long k;
};

instruct name[maxn];

int main() {
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> A[i];
    }
    Build(1, n, 1);
    long long order;
    for (long long i = 1; i <= m; i++) {
        cin >> order;
        if (order == 1) {
            name[i].order = 1;
            cin >> name[i].x >> name[i].y >> name[i].k;
        } else {
            name[i].order = 2;
            cin >> name[i].x >> name[i].y;
        }
    }

    for (long long i = 1; i <= m; i++) {
        if (name[i].order == 1) {
            UpdateAll(name[i].x, name[i].y, name[i].k, 1, n, 1);
        } else {
            cout << Query(name[i].x, name[i].y, 1, n, 1) << endl;
        }
    }
}