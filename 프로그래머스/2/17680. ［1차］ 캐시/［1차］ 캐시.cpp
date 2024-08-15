#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) {
        return 5 * cities.size();
    }

    for (int i = 0; i < cities.size(); i++) {
        string now = cities[i];

        for(auto &ch : now)
            ch = tolower(ch);
        
        // 캐시에 있는지 확인
        auto it = find(cache.begin(), cache.end(), now);

        // 캐시에 존재하면
        if (it != cache.end()) {
            answer += 1;
            
            // 해당 항목을 맨 앞으로 이동
            cache.erase(it);
            cache.insert(cache.begin(), now);
        } else {
            // 캐시 미스
            answer += 5;
            
            if (cache.size() >= cacheSize)
                cache.pop_back();
            
            
            // 새 항목을 맨 앞으로 추가
            cache.insert(cache.begin(), now);
        }
    }

    return answer;
}
