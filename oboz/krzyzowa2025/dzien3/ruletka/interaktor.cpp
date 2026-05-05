#include <bits/stdc++.h>
#include "solve_dlazaw.hpp"

#define pb push_back

using ld = long double;

using namespace Solve;
using namespace std;

int goal; 
int used_chips;
int N = 256;

int odl(int x) {
    return min(abs(goal - x), N - abs(goal - x));
}

// n/k
int ceili(int n, int k) {
    return (n + k - 1) / k;
}

int query(vector <int> v) {
    used_chips += ceili(256, (int)v.size());
    int cur_ans = INT_MAX;
    for(int i : v) {
        cur_ans = min(cur_ans, odl(i));
    }
    return cur_ans;
}

int final_score() {
    if(used_chips <= 6) {
        return 100; 
    }
    if(used_chips > 512) {
        return 0;
    }
    return min(100, max(0, (int)ceil(100. - (5. * log2((ld)(used_chips - 5))))));
}

int main(int argc, char** argv) {
	auto& I = Interactor::create(argc, argv);
	auto& input = I.test_reader();
	
	auto end = [&] (int score, const std::string& msg) {
		I.end(score, msg);
	};
	
	input >> goal;

	int query_cnt = 0;
    while(query_cnt < 513) {
        char co; 
        I.reader(0) >> co; 
        if(co == '?') {
            int k;
            I.reader(0) >> k;
            if(k < 1 || k > 256) {
                end(0, "Wczytano niepoprawna liczbe");
            }
            vector <int> v = {};
            set<int> S;
            for(int i = 0; i < k; i++) {
                int a;
                I.reader(0) >> a;
                S.insert(a);
                if(a < 1 || a > 256) {
                    end(0, "Wczytano niepoprawne pole");
                }
                v.pb(a);
            }
            if(S.size() != v.size()){
                end(0, "Pola z zapytania nie są parami różne");
            }
            I.writer(0) << query(v) << endl; 
        }
        else if(co == '!') {
            int ans;
            I.reader(0) >> ans;
            if(ans == goal) {
                //OK
                end(final_score(), "AC: "+ to_string(used_chips) + " wydanych bajtcointów");
            }
            else {
                end(0, "WA");
            }
        }
        else {
            end(0, "Niepoprawny format zapytania");
        }
        query_cnt++; 
    }
	end(0, "Krzysio nie ma juz wiecej zetonow");
	return 0;
}
