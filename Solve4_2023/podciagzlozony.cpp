#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 4000000;
const int BUCKET_SIZE = 2000;

vector<bool> is_prime(MAX_N + 1, true);
vector<int> is_composite(MAX_N + 1, 0);
vector<int> longest_in_bucket, prefix_in_bucket, suffix_in_bucket;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_N; ++i) {
        if (!is_prime[i]) {
            is_composite[i] = 1;
        }
    }
}

void preprocess_buckets() {
    int n_buckets = (MAX_N + BUCKET_SIZE - 1) / BUCKET_SIZE;
    longest_in_bucket.assign(n_buckets, 0);
    prefix_in_bucket.assign(n_buckets, 0);
    suffix_in_bucket.assign(n_buckets, 0);

    for (int i = 0; i < n_buckets; ++i) {
        int start = i * BUCKET_SIZE;
        int end = min(MAX_N, start + BUCKET_SIZE - 1);
        int current_length = 0, max_length = 0;

        for (int j = start; j <= end; ++j) {
            if (is_composite[j]) {
                current_length++;
                max_length = max(max_length, current_length);
            } else {
                current_length = 0;
            }
        }
        longest_in_bucket[i] = max_length;

        current_length = 0;
        for (int j = start; j <= end; ++j) {
            if (is_composite[j]) {
                current_length++;
            } else {
                break;
            }
        }
        prefix_in_bucket[i] = current_length;

        current_length = 0;
        for (int j = end; j >= start; --j) {
            if (is_composite[j]) {
                current_length++;
            } else {
                break;
            }
        }
        suffix_in_bucket[i] = current_length;
    }
}

int longest_composite_in_range(int A, int B) {
    int max_len = 0, current_len = 0;
    for (int i = A; i <= B; ++i) {
        if (is_composite[i]) {
            current_len++;
            max_len = max(max_len, current_len);
        } else {
            current_len = 0;
        }
    }
    return max_len;
}

int solve_query(int A, int B) {
    int start_bucket = A / BUCKET_SIZE;
    int end_bucket = B / BUCKET_SIZE;

    if (start_bucket == end_bucket) {
        return longest_composite_in_range(A, B);
    }


    int max_len = longest_composite_in_range(A, (start_bucket + 1) * BUCKET_SIZE - 1);

    max_len = max(max_len, longest_composite_in_range(end_bucket * BUCKET_SIZE, B));

    max_len = max(max_len, suffix_in_bucket[start_bucket] + prefix_in_bucket[end_bucket]);

    for (int bucket = start_bucket + 1; bucket < end_bucket; ++bucket) {
        max_len = max(max_len, longest_in_bucket[bucket]);
    }

    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    preprocess_buckets();

    int Q;
    cin >> Q;

    while (Q--) {
        int A, B;
        cin >> A >> B;
        cout << solve_query(A, B) << '\n';
    }

    return 0;
}
