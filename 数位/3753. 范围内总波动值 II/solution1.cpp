class Solution {
public:
    int wave(int num)
    {
        int prev = -1;
        int next = -1;
        int sum1 = 0;
        while(num)
        {
            prev = num%10;   
            num/=10;         
            int cur = num%10;

            if(num/10!=0)
                next = num/10%10;
            else
                next = -1;
            if(prev!=-1&&next!=-1&&(cur<prev&&cur<next||(cur>prev&&cur>next)))
            {
                sum1++;
            }
        }
        return sum1;
    }
    int sum = 0;
    int totalWaviness(int num1, int num2) {
        for(int i = num1;i <= num2;i++)
        {
            sum+=wave(i);
        }
        return sum;

    }
};