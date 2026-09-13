//2025 카카오 하반기 1차 노란불 신호등
//사고체계: 2차 배열을 int main에서 받고, 그러니까 함수에서 매개변수를 2차 배열로 받고
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long gcd(long long a, long long b)//최대공약수
{
    while(b>0)
    {long long temp=a%b;
    a=b;
    b=temp;}
    return a;
    }
long long lcm(long long a, long long b)//최소공배수
{
    if(a==0 || b==0) return 0;
    return (a*b)/gcd(a,b); //return 2개 쓸 수 있음. 상황에 따라서 어짜피 하나만 해서
}


//이게 메인으로 해결하는 함수. 매개변수를 2차 배열로 두고
int solution(vector<vector<int>> signals)
{
    long long maxTime=1;
    for(const auto& signal : signals)//for (int i = 0; i < signals.size(); i++) signals이 2차 배열이므로 그 안에 있는 signal은 1차 배열
    {
        long long cycle=signal[0]+signal[1]+signal[2];
        maxTime=lcm(maxTime, cycle);//배열들의 최소공배수 구함. maxTime을 다시 설정하는 것이 어떠니
    }
    for(long long t=0;t<maxTime;t++)//이제 제대로 시작하자
    {
        bool allYellow=true;//형식적으로 원래 이래야 하는 것. 뭔가 다 됐다!하면 bool쓰는 것
        for(const auto& signal : signals)
        {
            int g=signal[0], y=signal[1], r=signal[2];
            int cycle=g+y+r;

            int mod=t%cycle;
            if(mod<g||mod>=g+y) {allYellow=false;break;}

        }
        if(allYellow) return t;
    }
    return -1;
}

int main()
{
    int N;
    cout<<"신호등 개수를 입력하세요: ";
    cin>>N;
    //main함수에서 2차 배열을 생성
    vector<vector<int>> signals(N, vector<int>(3));
    cout<<"각 신호등의 G,Y,R값을 입력하세요:\n";
    for(int i=0;i<N;i++)
    {
        for(int i=0;i<N;++i)
        {
            cin>>signals[i][0]>>signals[i][1]>>signals[i][2];
        }}
    int result=solution(signals);
    cout<<"모든 신호등이 처음으로 노란불이 되는 시각: "<<result<<endl;}
    return 0;
}
