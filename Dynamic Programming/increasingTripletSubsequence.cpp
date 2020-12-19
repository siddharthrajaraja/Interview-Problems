#define REP(i, a, b) for (int i = a; i < b; i++)
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int oneMin = INT_MAX;
        int twoMin = INT_MAX;

        int i;
        int size = nums.size();

        REP(i, 0, size)
        {

            if (nums[i] < oneMin)
            {
                oneMin = nums[i];
            }
            else if (nums[i] > oneMin)
            {
                if (twoMin < nums[i])
                    return true;
                twoMin = nums[i];
            }
        }
        return false;
    }
};