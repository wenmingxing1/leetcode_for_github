#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    //��ָoffer49�������ǵ��������
    int myAtoi(string str) {
        int size = str.size();
        if (size == 0){
            return 0;
        }

        string::iterator iter = str.begin();

        while (*iter == ' ')    //���ڿո�Ĵ���
            iter++;

        bool isPositive = true;

        if (*iter == '-'){      //���������ŵĴ���
            isPositive = false;
            iter++;
        }
        else if(*iter == '+'){
            iter++;
        }

        double number = 0;      //double��Ϊ�˷���Խ�紦��
        while (iter != str.end()){      //�������
            if (*iter >= '0' && *iter <= '9'){
                number = number * 10 + *iter - '0';
                iter++;
            }
            else
                break;
        }

        if (number > INT_MAX){      //Խ�紦�����������ж�
            if (isPositive)
                return INT_MAX;
            else
                return INT_MIN;
        }
        else{
            if (isPositive)
                return number;
            else
                return 0-number;
        }
    }
};

int main()
{
    string str = "-123a5";
    Solution solu;
    cout << solu.myAtoi(str) << endl;

    return 0;
}
