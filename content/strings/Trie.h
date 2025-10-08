#pragma once

struct Trie {
    struct TrieNode {
        array<int,26> nxt = {};
        int stop = 0;
    };

    int node_count = 0;
    vector<TrieNode> info;

    Trie(): info(1) {}
    Trie(int N): info(N) {}
    
    void insert(const string& word) {
        int node = 0;
        for(const char& c : word) {
            // If a node with the current char doesn't exist create one.
            if(info[node].nxt[c - 'a'] == 0) { 
                info[node].nxt[c - 'a'] = ++node_count; 
                if(node_count >= sz(info)) {
                    info.emplace_back();
                }
            }
            // Move down the path in the trie.
            node = info[node].nxt[c - 'a'];
        }
        info[node].stop++;
    }

    int find(const string& word) {
        int node = 0;
        for(const char& c : word) {
            if(info[node].nxt[c - 'a'] == 0) {return 0;}
            node = info[node].nxt[c - 'a'];
        }
        return info[node].stop;
    }
};