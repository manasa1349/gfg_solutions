class Solution:
    def computeValue(self, n):
        # code here
        # no.of 1's in 1st half == no.of 1's in 2nd half ->assume k
        # then nck ways for each half
        # ans= (nck)^2
        MOD = 10**9 + 7
        fact_2n = 1
        fact_n = 1
        
        for i in range(1, 2 * n + 1):
            fact_2n = (fact_2n * i) % MOD
            if i == n:
                fact_n = fact_2n
                
        # Denominator is (n! * n!) % MOD
        denom = (fact_n * fact_n) % MOD
        
        # Use Fermat's Little Theorem for division: 
        # a / b % MOD is (a * pow(b, MOD - 2, MOD)) % MOD
        return (fact_2n * pow(denom, MOD - 2, MOD)) % MOD