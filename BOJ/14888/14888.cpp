#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> operands;
vector<int> operators;
int oper[11];
bool visited[11];

int maxVal = 1 << 31;
int minVal = ~(1 << 31);

void solve(int count) {
    if(count == N - 1) {
        int result = operands[0];
        for(int i = 0; i < N - 1; i++) {
            switch (oper[i]) { // 1 : plus, 2 : minus, 3 : mult, 4 : div
                case 1:
                    result += operands[i + 1];
                    break;
                case 2:
                    result -= operands[i + 1];
                    break;
                case 3:
                    result *= operands[i + 1];
                    break;
                case 4:
                    result /= operands[i + 1];
                    break;
            }
        }
        if(result > maxVal) {
            maxVal = result;
        }
        if(result < minVal) {
            minVal = result;
        }
        return;
    }

    for(int i = 0; i < N - 1; i++) {
        if(visited[i]) {
            continue;
        }

        oper[count] = operators[i];
        visited[i] = true;
        solve(count + 1);
        visited[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int number;
        cin >> number;
        operands.push_back(number);
    }

    int plus, minus, mult, divide;
    cin >> plus >> minus >> mult >> divide;

    while(plus--) {
        operators.push_back(1);
    }

    while(minus--) {
        operators.push_back(2);
    }

    while(mult--) {
        operators.push_back(3);
    }

    while(divide--) {
        operators.push_back(4);
    }

    solve(0);

    cout << maxVal << "\n";
    cout << minVal << "\n";
    return 0;
}