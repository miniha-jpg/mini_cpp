/*[PCCP 기출문제 동영상 재생기-10초 전으로 이동, 10초 후로 이동, 오프닝 건너뛰기
문자열은 계산이 안 된다, vector는 문자열이기에 문자열에 있는 거 하나씩 꺼내서 검사해봐야한다,
오프닝 건너뛰기는 계속해서 해야 한다. (함수는 호출까지가 완성!)그래서 한 번만 쓰면 안 되고 반복문*/
//문자열을 int로 바꾸고, int를 문자열로 다시 바꾸어야 한다.
#include <string>
#include <vector>
using namespace std;
int timeToSeconds(string time_str)
{
    int mm=stoi(time_str.substr(0,2)); //time_str.substr(위치, 길이)
    int ss=stoi(time_str.substr(3,2));
    return mm*60+ss;
}
string secondsToTime(int total_seconds)
{
    int mm=total_seconds/60;
    int ss=total_seconds%60;
    string mm_str=(mm<10?"0":"")+to_string(mm);
    string ss_str=(ss<10?"0":"")+to_string(ss);
    return mm_str+":"+ss_str;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    int video_sec=timeToSeconds(video_len);
    int pos_sec=timeToSeconds(pos);
    int op_start_sec=timeToSeconds(op_start);
    int op_end_sec=timeToSeconds(op_end);
    //시작 지점: 오프닝 구간에 있다면 오프닝 끝으로 즉시 이동
    if(pos_sec>=op_start_sec && pos_sec<=op_end_sec) pos_sec=op_end_sec;
    //그리고 문자열에 있는 거 하나하나 읽으면서 반복문 시작
    for(string cmd: commands)
    {
        if(cmd=="prev") //괄호 범위 조심하세요. 선후관계 생각!
            {pos_sec-=10;
            if(pos_sec<0) pos_sec=0;}
        else if(cmd=="next") 
            {pos_sec+=10;
            if(pos_sec>video_sec) pos_sec=video_sec;}
    }
    return secondsToTime(pos_sec);
}
int main()
{
    string result=solution("10:00","01:00","00:30","02:00",{"prev","next","next"};
    cout<<"최종 재생 위치: "<<result<<endl;
    return 0;
}
