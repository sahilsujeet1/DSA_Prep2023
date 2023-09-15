#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;

    q.push({beginWord, 1});
    words.erase(beginWord);

    while(!q.empty()) {
        pair<string, int> front = q.front();
        string word = front.first;
        int count = front.second;
        q.pop();

        if(word == endWord) return count;

        for(int i=0; i<word.size(); i++) {
            char prev = word[i];
            for(char c='a'; c<='z'; c++) {
                word[i] = c;
                if(words.find(word) != words.end()) {
                    q.push({word, count + 1});
                    // cout << word << ", ";
                    words.erase(word);
                }
            }
            word[i] = prev;
        }
    }

    return 0;


    // int count = 0;
    // string temp;

    // while(beginWord != endWord) {
    //     // temp = beginWord;
    //     for(int i=0; i<beginWord.size(); i++) {
    //         temp = beginWord;
    //         for(char c='a'; c<='z'; c++) {
    //             temp[i] = c;
    //             if(words.find(temp) != words.end()) {
    //                 words.erase(temp);
    //                 beginWord = temp;
    //                 i=0;
    //                 count++;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // return count++;
}

int main() {
    string start = "hit";
    string end = "cog";
    vector<string> words({"hot","dot","dog","lot","log","cog"});

    cout << ladderLength(start, end, words);
}