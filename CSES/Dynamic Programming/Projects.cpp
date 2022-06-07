/*

dp[i] represents all options where the ith project was last project attended
value will be max

dp[i] = max( {dp[i-1],dp[i-2],...,dp[1]} ) + p[i];

but with N<=2e5, O(N^2) takes too long


*/
