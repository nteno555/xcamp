#include <bits/stdc++.h>
using namespace std;

int main() {
    int floors, start, end, curCount, curFloor, curStep, arr[201], vis[201];
    bool foundAns;
    queue<pair<int, int>> q;

    while (true) {
        cin >> floors;

        if (floors == 0) {
            return 0;
        }
        
        foundAns = false;
        while(!q.empty()) {
            q.pop();
        }
        
        cin >> start >> end;
        end--;

        for (int i=0; i<floors; i++) {
            cin >> arr[i];
            vis[i] = 0;
        }
        
        q.push({start-1, 0});

        while(!q.empty()) {
            curFloor = q.front().first;
            curCount = q.front().second;
            q.pop();
            curStep = arr[curFloor];
            vis[curFloor] = 1; 

            if (curFloor == end) {
                cout << curCount << endl;
                foundAns = true;
                break;            
            }

            if (curFloor - curStep > -1 && vis[curFloor-curStep] != 1) {
                q.push({curFloor - curStep, curCount+1});
                vis[curFloor-curStep] = 1;
            }

            if (curFloor + curStep < floors && vis[curFloor+curStep] != 1) {
                q.push({curFloor + curStep, curCount+1});
                vis[curFloor+curStep] = 1;
            }
        }
        if (!foundAns) cout << -1 << endl;
    }
}