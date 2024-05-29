#include <bits/stdc++.h>
using namespace std;

// optimization: keep track of # of kfs and stop when it reaches

struct QInfo {
    int x;
    int y;
    int count;
};

map<pair<int, int>, pair<int, int>> kfcs;
int n, m, arr[201][201], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void meBFS(int sx, int sy) {
    int cmx, cmy, cmc, tmx, tmy, visme[201][201];
    queue<QInfo> qme;
    qme.push({sx, sy, 0});
    visme[sx][sy] = 1;

    while (!qme.empty()) {
        cmx = qme.front().x;
        cmy = qme.front().y;
        cmc = qme.front().count;
        qme.pop();

        for (int i=0; i<4; i++) {
            tmx = cmx + dx[i];
            tmy = cmy + dy[i];
            if (tmx>-1 && tmy>-1 && tmx<n && tmy<m) {
                if (visme[tmx][tmy] != 1 && arr[tmx][tmy] != 1) {
                    visme[tmx][tmy] = 1;
                    if (arr[tmx][tmy]==2) {
                        kfcs[{tmx, tmy}] = {cmc+1, -1};
                    }
                    qme.push({tmx, tmy, cmc+1});
                }
            }
        }
    }
}

void friendBFS(int sx, int sy) {
    int cfx, cfy, cfc, tfx, tfy, visf[201][201];
    
    for (int i=0; i<201; i++) {
        for (int j=0; j<201; j++) {
            visf[i][j] = 0;
        }
    }
    
    queue<QInfo> qfriend;
    qfriend.push({sx, sy, 0});
    visf[sx][sy] = 1;

    while (!qfriend.empty()) {
        cfx = qfriend.front().x;
        cfy = qfriend.front().y;
        cfc = qfriend.front().count;
        qfriend.pop();
        

        for (int i=0; i<4; i++) {
            tfx = cfx + dx[i];
            tfy = cfy + dy[i];
            if (tfx>-1 && tfy>-1 && tfx<n && tfy<m) {
                if (visf[tfx][tfy] != 1 && arr[tfx][tfy] != 1) {
                    visf[tfx][tfy] = 1;
                    if (arr[tfx][tfy] == 2) {
                        kfcs[{tfx, tfy}] = {kfcs[{tfx, tfy}].first, cfc+1};
                    }
                    qfriend.push({tfx, tfy, cfc+1});
                }
            }
        }
    }
}

int main() {
    int friendsx, friendsy, mesx, mesy;
    pair<int, int> loopTemp;
    string temp;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<m; j++) {
            if (temp[j] == '.') {
                arr[i][j] = 0;
            }
            else if (temp[j] == '#') {
                arr[i][j] = 1;
            }
            else if (temp[j] == 'F') {
                kfcs.insert({{i, j}, {-1, -1}});
                arr[i][j] = 2;
            }
            else if (temp[j] == '&') {
                friendsx = i;
                friendsy = j;
                arr[i][j] = 0;
            }
            else {
                mesx = i;
                mesy = j;
                arr[i][j] = 0;
            }
        }
    }

    meBFS(mesx, mesy);
    friendBFS(friendsx, friendsy);

    bool ansExists = false;
    int minAns = INT_MAX;

    for (auto i=kfcs.begin(); i!=kfcs.end(); i++) {
        loopTemp = i->second;
        if (loopTemp.first==-1 || loopTemp.second==-1) {
            continue;
        }
        else {
            ansExists = true;
            minAns = min(loopTemp.first+loopTemp.second, minAns);
        }
    }

    if (ansExists) cout << minAns;
    else cout << "Meeting cancelled";

    return 0;
}