// the solution using state machines is shown here, detailed derivation and logic is in notebook. PDF attached here with same file name also.

// Solution 1 : Using old ones and old twos to compute new ones and new twos
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;

        for (const int num : nums)
        {
            int oldones = ones;
            int oldtwos = twos;
            // nums means all 32 ith bits together work in one pass, thats where the boost in speed lies
            ones = ~oldtwos & (num ^ oldones);
            twos = (num & oldones & (~oldtwos)) | ((~num) & (~oldones) & oldtwos);
            cout << ones << " " << twos << endl; // dry run for clarity
        }

        return ones;
    }
};

// Solution 2 : Using new ones to computer new twos, rest same
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;

        for (const int num : nums)
        {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
            cout << ones << " " << twos << endl;
        }

        return ones;
    }
};

/*
Example 1
=========
Input
nums = [0,1,0,1,0,1,99]

Stdout
0 0
1 0
1 0
0 1
0 1
0 0
99 0

Output
99


Example 2
=========
Input
nums =[2,2,3,2]

Stdout
2 0
0 2
1 0
3 0

Output
3

*/
