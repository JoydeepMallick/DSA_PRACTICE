class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // xor all numbers to get xor of singles / the number actually stored bit information of which bits are different in the singles
        int mismatches = 0;
        for (auto val : nums)
        {
            mismatches ^= val;
        }

        // lets pick the right most set bit as its easiest to find
        // edge case : if mismatches = -2^31 and (mismatches-1) will be out of bounds for integer, so long long is preferred
        long misminus1 = (long)mismatches - 1L;
        int rightmostbit = mismatches ^ (mismatches & misminus1); // assume xth bit of mismatch

        // now we compare with rightmost set bit and sort into buckets accordingly, also we xor elements to delete the duplicates
        int b1 = 0; // stores all numbers with xth bit = 1
        int b0 = 0; // stores all numbers with xth bit = 0
        for (auto val : nums)
        {
            if ((val & rightmostbit) != 0)
                b1 ^= val;
            else
                b0 ^= val;
        }
        return {b1, b0};
    }
};