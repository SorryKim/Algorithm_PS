#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Song {
    int id;
    int plays;

    Song(int id, int plays) : id(id), plays(plays) {}

    bool operator<(const Song& other) const {
        if (plays == other.plays) {
            return id < other.id;
        }
        return plays > other.plays;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<Song>> genreToSongs;
    unordered_map<string, int> genreToTotalPlays;

    // 장르별로 노래와 재생 횟수 저장
    for (int i = 0; i < genres.size(); ++i) {
        genreToSongs[genres[i]].emplace_back(i, plays[i]);
        genreToTotalPlays[genres[i]] += plays[i];
    }

    // 재생 횟수 내림차순으로 정렬
    vector<pair<string, int>> totalPlays;
    for (const auto& a : genreToTotalPlays)
        totalPlays.emplace_back(a.first, a.second);
    

    sort(totalPlays.begin(), totalPlays.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    vector<int> answer;

    // 각 장르에 대해 베스트 노래 선택
    for (const auto& a : totalPlays) {
        const string& genre = a.first;
        auto& songs = genreToSongs[genre];

        sort(songs.begin(), songs.end());

        // 최대 2곡 선택
        for (int i = 0; i < min(2, static_cast<int>(songs.size())); ++i) {
            answer.push_back(songs[i].id);
        }
    }

    return answer;
}