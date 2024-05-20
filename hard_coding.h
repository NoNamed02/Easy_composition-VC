#ifndef HARD_CODING_H
#define HARD_CODING_H

#include <QRandomGenerator>

#endif // HARD_CODING_H

int code_rule(int code);
int extra_rule(int code);
char make_chord(int code);
int s_move_for_first(char code);
void f_voice(char melody);


int code_rule(int code){
    if(code == 1) // 1
        return rand() % 6 + 1;
    else if(code == 2){ // 2
        int sub = rand() % 2;
        if(sub == 0)
            return 4;
        else
            return 5;
    }
    else if(code == 3) // 3
        return 2;
    else if(code == 4){ // 4
        int sub = rand() % 2;
        if(sub == 0)
            return 2;
        else
            return 5;
    }
    else if(code == 5){
        int sub = rand() % 2;
        if(sub == 0)
            return 1;
        else
            return 2;
    }
    else if(code == 6){
        int sub = rand() % 3;
        if(sub == 0)
            return 2;
        else if(sub == 1)
            return 4;
        else if(sub == 2)
            return 5;
    }
    return 0;
}

int extra_rule(int code){ // 3번 마디 특수 코드
    if(code == 1){
        int sub = rand() % 3;
        if(sub == 0)
            return 2;
        else if(sub == 1)
            return 4;
        else if(sub == 2)
            return 6;
    }
    else if(code == 2)
        return 4;
    else if(code == 3)
        return 2;
    else if(code == 4)
        return 2;
    else if(code == 5){
        int sub = rand() % 2;
        if(sub == 0)
            return 1;
        else
            return 2;
    }
    else if(code == 6){
        int sub = rand() % 2;
        if(sub == 0)
            return 2;
        else
            return 4;
    }
    return 0;
}

char make_chord(int code){
    if(code == 0){ // 1도 도미솔
        int sub = rand() % 6;
        if(sub == 0)
            return 'C';
        else if(sub == 1)
            return 'E';
        else if(sub == 2)
            return 'G';
        else if(sub == 3)
            return 'c';
        else if(sub == 4)
            return 'e';
        else
            return 'g';
    }
    if(code == 1){ // 2도 레파라
        int sub = rand() % 5;
        if(sub == 0)
            return 'D';
        else if(sub == 1)
            return 'F';
        else if(sub == 2)
            return 'A';
        else if(sub == 3)
            return 'd';
        else
            return 'f';
    }
    if(code == 2){ // 3도 미솔시
        int sub = rand() % 5;
        if(sub == 0)
            return 'E';
        else if(sub == 1)
            return 'G';
        else if(sub == 2)
            return 'B';
        else if(sub == 3)
            return 'e';
        else if(sub == 4)
            return 'g';
    }
    if(code == 3){ // 4도 파라도
        int sub = rand() % 5;
        if(sub == 0)
            return 'F';
        else if(sub == 1)
            return 'A';
        else if(sub == 2)
            return 'C';
        else if(sub == 3)
            return 'f';
        else if(sub == 4)
            return 'c';
    }
    if(code == 4){ // 5도 솔시레
        int sub = rand() % 5;
        if(sub == 0)
            return 'G';
        else if(sub == 1)
            return 'B';
        else if(sub == 2)
            return 'D';
        else if(sub == 3)
            return 'g';
        else if(sub == 4)
            return 'd';
    }
    if(code == 5){ // 6도 라도미
        int sub = rand() % 5;
        if(sub == 0)
            return 'A';
        else if(sub == 1)
            return 'C';
        else if(sub == 2)
            return 'E';
        else if(sub == 3)
            return 'c';
        else if(sub == 4)
            return 'e';
    }
    if(code == 6){ // 7도 시레파
        int sub = rand() % 5;
        if(sub == 0)
            return 'B';
        else if(sub == 1)
            return 'D';
        else if(sub == 2)
            return 'F';
        else if(sub == 3)
            return 'd';
        else if(sub == 4)
            return 'f';
    }

    return 'a'; // 의미없는 반환임 무시할것
}

int s_move_for_first(char code){
    int A = 0; // 보정값
    if(code == 'C')
        return 236 + A; // A는 보정값(악보에 정확한 표시를 하기 위한)
    if(code == 'c')
        return 180 + A;

    if(code == 'D')
        return 228 + A;
    if(code == 'd')
        return 172 + A;

    if(code == 'E')
        return 220 + A;
    if(code == 'e')
        return 164 + A;

    if(code == 'F')
        return 212 + A;
    if(code == 'f')
        return 156 + A;

    if(code == 'G')
        return 204 + A;
    if(code == 'g')
        return 148 + A;

    if(code == 'A')
        return 196 + A;
    if(code == 'B')
        return 188 + A;

    return 0;
}
