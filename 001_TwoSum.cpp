/*===============暴力======================*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> temp;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                }
            }
        }
        return temp;
        }
};

/*=================利用map=====================*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
            int n = numbers.size();
            vector<int> result;
            map<int, int> index;
            for (int i = 0; i < n; i++)
            {
                if (index.count(numbers[i]) != 0)
                {
                    // if exists
                    result.push_back(index[numbers[i]] + 1);
                    result.push_back(i + 1);
                    break;
                }
                index[target - numbers[i]] = i;
            }
            return result;
    }
};

/*=====================hash===========================*/
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}

/*==================先排序再夹逼======================*/
class Solution
{
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            int sz = numbers.size();
            int left = 0, right = sz - 1, sum = 0;

            vector<int> sorted (numbers);
            std::sort(sorted.begin(), sorted.end());

            vector<int> index;
            while (left < right)
            {
                sum = sorted[left] + sorted[right];
                if (sum == target)
                {
                    // find the answer
                    for (int i = 0; i < sz; i++)
                    {
                        if (numbers[i] == sorted[left])
                            index.push_back(i + 1);
                        else if (numbers[i] == sorted[right])
                            index.push_back(i + 1);
                        if (index.size() == 2)
                            return index;
                    }
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            // Program never go here, because
            // "each input would have exactly one solution"
        }
};

