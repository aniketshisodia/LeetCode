// jai shree ram
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(1e6 + 1, 1);
        prime[0] = prime[1] = 0; // 0 and 1 are not prime
        
        // Corrected Sieve of Eratosthenes
        for (int i = 2; i * i <= 1e6; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= 1e6; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // Store primes in the given range [left, right]
        vector<int> primesInRange;
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                primesInRange.push_back(i);
            }
        }

        // If no pair exists, return {-1, -1}
        if (primesInRange.size() < 2) return {-1, -1};

        // Find closest primes
        int minDiff = INT_MAX;
        vector<int> res(2, -1);
        for (int i = 1; i < primesInRange.size(); i++) {
            if (primesInRange[i] - primesInRange[i - 1] < minDiff) {
                minDiff = primesInRange[i] - primesInRange[i - 1];
                res = {primesInRange[i - 1], primesInRange[i]};
            }
        }

        return res;
    }
};
