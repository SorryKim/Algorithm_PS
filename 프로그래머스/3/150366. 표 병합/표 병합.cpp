#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> board(51, vector<string>(51, "EMPTY"));
vector<vector<pair<int, int>>> parent(51, vector<pair<int, int>>(51));

pair<int, int> find(pair<int, int> p) {
    int r = p.first;
    int c = p.second;
    if (parent[r][c] == p) {
        return p;
    }
    return parent[r][c] = find(parent[r][c]);
}

// 두 셀을 병합하는 함수
void merge(pair<int, int> p1, pair<int, int> p2) {
    pair<int, int> root1 = find(p1);
    pair<int, int> root2 = find(p2);

    if (root1 == root2) return;

    // (r1, c1) 위치의 셀이 값을 가지고 있을 경우 그 값을 유지
    if (board[root1.first][root1.second] != "EMPTY") {
        parent[root2.first][root2.second] = root1;
    } else {
        parent[root1.first][root1.second] = root2;
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    // parent 배열 초기화
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            parent[i][j] = {i, j};
        }
    }

    for (string& s : commands) {
        stringstream ss(s);
        vector<string> tokens;
        string token;
        while (ss >> token) tokens.push_back(token);

        string cmd = tokens[0];

        if (cmd == "UPDATE") {
            if (tokens.size() == 4) { // "UPDATE r c value"
                int r = stoi(tokens[1]);
                int c = stoi(tokens[2]);
                string value = tokens[3];
                
                // 핵심: 그룹의 값은 루트 노드에만 저장합니다.
                pair<int, int> root = find({r, c});
                board[root.first][root.second] = value;
            } else { // "UPDATE value1 value2"
                string value1 = tokens[1];
                string value2 = tokens[2];
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        // 루트의 값만 확인하면 됩니다.
                        if (parent[i][j] == make_pair(i,j) && board[i][j] == value1) {
                            board[i][j] = value2;
                        }
                    }
                }
            }
        } else if (cmd == "MERGE") {
            int r1 = stoi(tokens[1]), c1 = stoi(tokens[2]);
            int r2 = stoi(tokens[3]), c2 = stoi(tokens[4]);
            
            if (r1 == r2 && c1 == c2) continue;
            merge({r1, c1}, {r2, c2});

        } else if (cmd == "UNMERGE") {
            int r = stoi(tokens[1]), c = stoi(tokens[2]);
            pair<int, int> root = find({r, c});
            string rootValue = board[root.first][root.second];

            vector<pair<int, int>> to_unmerge;
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (find({i, j}) == root) {
                        to_unmerge.push_back({i, j});
                    }
                }
            }
            
            // 그룹에 속했던 모든 셀들의 연결을 끊고 값을 초기화
            for (auto& p : to_unmerge) {
                parent[p.first][p.second] = p;
                board[p.first][p.second] = "EMPTY";
            }
            // 원래 (r,c) 셀에만 값을 다시 부여
            board[r][c] = rootValue;

        } else if (cmd == "PRINT") {
            int r = stoi(tokens[1]), c = stoi(tokens[2]);
            pair<int, int> root = find({r, c});
            answer.push_back(board[root.first][root.second]);
        }
    }

    return answer;
}