#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct File {
    string head, number, tail;

    bool operator<(const File &other) const {
        string h1 = this->head;
        string h2 = other.head;

        for(int i = 0; i < h1.size(); i++){
            if(h1[i] >= 'A' && h1[i] <= 'Z'){
                h1[i] += ('a' - 'A');
            }
        }

        for(int i = 0; i < h2.size(); i++){
            if(h2[i] >= 'A' && h2[i] <= 'Z'){
                h2[i] += ('a' - 'A');
            }
        }

        if(h1 != h2) return h1 < h2;

        int n1 = stoi(this->number);
        int n2 = stoi(other.number);

        if(n1 != n2) return n1 < n2;

        return false;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> v;

    for(auto file : files){
        string head = "";
        string number = "";
        string tail = "";

        int i = 0;

        // HEAD 추출
        while(i < file.size() &&
              !(file[i] >= '0' && file[i] <= '9')){
            head += file[i++];
        }

        // NUMBER 추출 (최대 5자리)
        while(i < file.size() &&
              file[i] >= '0' && file[i] <= '9' &&
              number.size() < 5){
            number += file[i++];
        }

        // TAIL 추출
        while(i < file.size()){
            tail += file[i++];
        }

        v.push_back({head, number, tail});
    }

    // 동일한 정렬 기준이면 입력 순서 유지
    stable_sort(v.begin(), v.end());

    for(auto a : v){
        answer.push_back(a.head + a.number + a.tail);
    }

    return answer;
}