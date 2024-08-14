using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    answer = (long long)price * ((count *(count + 1)) / 2) - money;
    
    if(answer <= 0)
        return 0;
    return answer;
}