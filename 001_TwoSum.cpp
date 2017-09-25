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
//map为关联容器，其中是一个key-value的pair。key为索引。

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
            int n = numbers.size();
            vector<int> result;
            map<int, int> index;
            for (int i = 0; i < n; i++)
            {
                if (index.count(numbers[i]) != 0)   //index中numbers[i]出现的次数
                {
                    // if exists
                    result.push_back(index[numbers[i]]);
                    result.push_back(i);
                    break;
                }
                index[target - numbers[i]] = i;     //不存在的话就向index中赋值
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

            vector<int> sorted (numbers);   //将numbers赋值到sorted中。用于排序数组
            std::sort(sorted.begin(), sorted.end());    //对sorted进行排序

            vector<int> index;      //存储结果
            while (left < right)
            {
                sum = sorted[left] + sorted[right];
                if (sum == target)
                {
                    // find the answer
                    for (int i = 0; i < sz; i++)
                    {
                        if (numbers[i] == sorted[left])
                            index.push_back(i);     //将left的索引添加到index中
                        else if (numbers[i] == sorted[right])
                            index.push_back(i);         //将right的索引到index中。
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

        }
};

