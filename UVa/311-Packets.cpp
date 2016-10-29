// UVa 311 - Packets
#include <iostream>
using namespace std;
int main() {
  int p1, p2, p3, p4, p5, p6, result, left;
  while (cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6) {
    if ((p1 == 0) && (p2 == 0) && (p3 == 0) && (p4 == 0) && (p5 == 0) &&
        (p6 == 0)) {
      break;
    }
    // 處理6x6
    result = p6;

    // 處理5x5
    result += p5;
    left = p5 * 11; // 剩餘的給1x1
    if (p1 <= left) {
      p1 = 0;
    } else {
      p1 -= left;
    }

    // 處理4x4
    result += p4;
    left = p4 * 20;
    // 處理4x4後，剩餘的給2x2
    // if p2所有面積小於空位
    if (p2 * 4 <= left) {
      left -= p2 * 4;
      p2 = 0;
    } else {
      p2 -= left / 4;
      left = 0;
    }
    // 處理4x4後，給2x2後給1x1
    // if p1所有面積小於空位
    if (p1 <= left) {
      left -= p1;
      p1 = 0;
    } else {
      p1 -= left;
      left = 0;
    }

    // 處理3x3
    result += p3 / 4;
    p3 = p3 % 4; //處理3x3後不足1個給2x2
    if (p3 > 0) {
      result++;
    }
    if (p3 == 1) {
      if (p2 >= 5) {
        p2 -= 5;
        left = 7;
      } else {
        left = 27 - p2 * 4;
        p2 = 0;
      }
    }
    if (p3 == 2) {
      if (p2 >= 3) {
        p2 -= 3;
        left = 6;
      } else {
        left = 18 - p2 * 4;
        p2 = 0;
      }
    }
    if (p3 == 3) {
      if (p2 >= 1) {
        p2 -= 1;
        left = 5;
      } else {
        left = 27;
      }
    }
    if (p1 <= left) { // 處理3x3後不足1個給2x2，還有剩給1x1
      left -= p1;
      p1 = 0;
    } else {
      p1 -= left;
      left = 0;
    }

    // 處理2x2
    result += p2 / 9;
    p2 = p2 % 9;
    if (p2 > 0) { //處理2x2後，不足1個給1x1
      result++;
      left = 36 - p2 * 4;
    }
    if (p1 <= left) {
      p1 = 0;
    } else {
      p1 -= left;
      left = 0;
    }

    // 處理1x1
    result += p1 / 36;
    if ((p1 % 36) > 0) {
      result++;
    }
    cout << result << endl;
  }
  // system("pause");
}

/*
ref:
https://sites.google.com/site/zsgititit/home/c-cheng-shi-she-ji/c110-packets

sample input

0 0 4 0 0 1
7 5 1 0 0 0
0 0 0 0 0 3
79 96 94 30 18 14
53 17 12 98 76 54
83 44 47 42 80 3
15 26 13 29 42 40
41 61 36 90 54 66
0 0 0 0 0 0

sample output

2
1
3
86
231
137
115
219
*/
