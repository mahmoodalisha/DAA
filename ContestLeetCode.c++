/*Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.

Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, return the sum of all available primes. If no prime numbers can be formed, return 0.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.

A substring is a contiguous sequence of characters within a string.

Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, when converting a substring to an integer, any leading zeros are ignored.

 

Example 1:

Input: s = "12234"

Output: 1469

Explanation:

The unique prime numbers formed from the substrings of "12234" are 2, 3, 23, 223, and 1223.
The 3 largest primes are 1223, 223, and 23. Their sum is 1469.
Example 2:

Input: s = "111"

Output: 11

Explanation:

The unique prime number formed from the substrings of "111" is 11.
Since there is only one prime number, the sum is 11.
 

Constraints:

1 <= s.length <= 10
s consists of only digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<int> primes;
        int n = s.length();

        
        for (int i = 0; i < n; ++i) {
            string numStr = "";
            for (int j = i; j < n; ++j) {
                numStr += s[j];
                int num = stoi(numStr);
                if (isPrime(num)) {
                    primes.insert(num);
                }
            }
        }

        
        vector<int> primelist(primes.begin(), primes.end());
        sort(primelist.rbegin(), primelist.rend());

        
        long long sum = 0;
        for (int k = 0; k < min(3, (int)primelist.size()); k++) {
            sum += primelist[k];
        }

        return sum;
    }
};


//another soluther for a very large input
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if number is prime
    bool isPrime(long long n) {
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> primes;
        int n = s.length();

        // Generate all substrings
        for (int i = 0; i < n; ++i) {
            string numStr = "";
            for (int j = i; j < n; ++j) {
                numStr += s[j];
                try {
                    long long num = stoll(numStr);  // Use stoll instead of stoi
                    if (isPrime(num)) {
                        primes.insert(num);
                    }
                } catch (out_of_range& e) {
                    // skip numbers too big to convert
                    continue;
                }
            }
        }

        // Sort in descending order
        vector<long long> primeList(primes.begin(), primes.end());
        sort(primeList.rbegin(), primeList.rend());

        // Sum top 3
        long long sum = 0;
        for (int i = 0; i < min(3, (int)primeList.size()); ++i) {
            sum += primeList[i];
        }

        return sum;
    }
};
