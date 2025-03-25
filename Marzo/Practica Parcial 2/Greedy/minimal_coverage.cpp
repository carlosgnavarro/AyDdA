#include <iostream>
#include <algorithm>
#include <vector>


// Este problema implica seleccionar el menor número de segmentos de línea que cubran un intervalo 
// dado. Es un buen ejemplo de cómo los algoritmos voraces pueden usarse para resolver problemas de 
// optimización que involucran intervalos
using namespace std;

struct Segment {
    int left, right;
};

bool compareSegments(const Segment& a, const Segment& b) {
    return a.left < b.left;
}

int main() {
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int M;
        cin >> M;

        vector<Segment> segments;
        int left, right;
        while (cin >> left >> right && (left != 0 || right != 0)) {
            segments.push_back({left, right});
        }

        sort(segments.begin(), segments.end(), compareSegments);

        vector<Segment> result;
        int covered = 0;
        int i = 0;
        while (covered < M) {
            int bestRight = covered;
            int bestSegmentIndex = -1;

            while (i < segments.size() && segments[i].left <= covered) {
                if (segments[i].right > bestRight) {
                    bestRight = segments[i].right;
                    bestSegmentIndex = i;
                }
                i++;
            }

            if (bestSegmentIndex == -1) {
                break;
            }

            result.push_back(segments[bestSegmentIndex]);
            covered = bestRight;
        }

        if (covered < M) {
            cout << "0" << endl;
        } else {
            cout << result.size() << endl;
            for (const auto& segment : result) {
                cout << segment.left << " " << segment.right << endl;
            }
        }

        if (caseNum) {
            cout << endl;
        }
    }

    return 0;
}