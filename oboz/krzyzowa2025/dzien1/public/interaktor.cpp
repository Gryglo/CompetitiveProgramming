#include <bits/stdc++.h>
#include "solve_dlazaw.hpp"

#define pb push_back
#define st first
#define nd second

using namespace std;
using namespace Solve;

const int MN = 567;

int test, test_nr, n, goal;
vector <pair <int, int> > kr;
vector <int> vv[MN];

int final_score(int max_q) { 
    if(test == 0 || test == 1) {
        if(max_q <= 4)
            return 100;
        if(max_q <= 6)
            return 80;
        if(max_q <= 10)
            return 66;
        if(max_q <= 14)
            return 40;
        if(max_q <= 15)
            return 25;
        if(max_q <= 16)
            return 15;
    }
    else if(test == 2) {
        if(max_q <= 9)
            return 100;
        if(max_q <= 11)
            return 85;
        if(max_q <= 45)
            return 66;
    }
    else if(test == 3) {
        if(max_q <= 9)
            return 100;
        if(max_q <= 11)
            return 75;
        if(max_q <= 45)
            return 66;
    }
    return 0;
}

void prep() {
    for(int i = 1; i <= n; i++) {
        vv[i].clear(); 
    }
    for(auto i : kr) {
        vv[i.st].pb(i.nd);
        vv[i.nd].pb(i.st);
    }
}

bool git[MN];
int ile; 

void dfs(int x, int y) {
    ile++;
    for(auto i : vv[x]) {
        if(i != y && git[i] == 1) {
            dfs(i, x);
        }
    }
}

bool czy_s(vector <int> zap) {
    ile = 0;
    for(int i = 1; i <= n; i++) {
        git[i] = 0; 
    }
    for(auto i : zap) {
        git[i] = 1;
    }
    dfs(zap[0], zap[0]);
    return ((int)zap.size() == ile);
}

int main(int argc, char** argv) {
	auto& I = Interactor::create(argc, argv);
	auto& input = I.test_reader();
	
	auto end = [&] (int score, const std::string& msg) {
		I.end(score, msg);
	};
	
	input >> test >> test_nr;
    I.writer(0) << test << ' ' << test_nr << endl; 
    int max_query_cnt = 0; 
    for(int i = 0; i < test_nr; i++) {
        //read 
        input >> n >> goal; 
        I.writer(0) << n << endl; 
        kr.clear(); 
        for(int ii = 0; ii < n - 1; ii++) {
            int a, b;
            input >> a >> b;
            I.writer(0) << a << ' ' << b << endl; 
            kr.pb({a, b});
        }
        // prep 
        prep();
        //#test
        int query_cnt = 0;
        bool czy = 0;
        for(int q = 0; q < 46; q++) {
            char co; 
            I.reader(0) >> co; 
            if(co == '?') {
                query_cnt++; 
                int k;
                I.reader(0) >> k;
                if(k < 1 || k > n) {
                    end(0, "Zapytanie powinno zawierać pomiędzy 1 a n wierzchołków");
                }
                vector <int> v = {};
                set<int> S;
                int czy_cel = 0;
                for(int ii = 0; ii < k; ii++) {
                    int a;
                    I.reader(0) >> a;
                    S.insert(a);
                    if(a == goal) {
                        czy_cel = 1;
                    }
                    if(a < 1 || a > n) {
                        end(0, "Numer wierzchołek poza przedziałem [1,n]");
                    }
                    v.pb(a);
                }
                if(S.size() != v.size()){
                    end(0, "Podane numery wierzchołków powtarzają się");
                }
                bool czy_sp = czy_s(v);
                if(!czy_sp) {
                    end(0, "Wierzchołki nie są spójne");
                }
                I.writer(0) << czy_cel << endl; 
            }
            else if(co == '!') {
                int ans; 
                I.reader(0) >> ans;
                if(ans != goal) {
                    end(0, "WA");
                }
                czy = 1; 
                break; 
            }
            else {
                end(0, "Niepoprawny format zapytania. Oczekiwano '?' lub '!'"); 
            }
        }
        if(czy == 0) {
            end(0, "Nie zgadnięto w 45 zapytań typu '?'");
        }
        max_query_cnt = max(max_query_cnt, query_cnt);
    }

    end(final_score(max_query_cnt), "AC: " + to_string(max_query_cnt) + " zapytań");
	return 0;
}
