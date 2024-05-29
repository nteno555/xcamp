#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sx, sy, ex, ey, xCount=0, yCount=0;

  cin >> n >> sx >> sy >> ex >> ey;

  xCount = (sx-ex)/2;
  if (xCount < 0) xCount = -xCount;
  if ((sx-ex) % 2 == 1 || (-(sx-ex) % 2) == 1) xCount++;

  yCount = (sy-ey)/2;
  if (yCount < 0) yCount = -yCount;
  if ((sy-ey)%2 == 1 || (-(sy-ey)) % 2 == 1) yCount++;

  cout << xCount+yCount;
}