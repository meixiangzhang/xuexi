#include <stdio.h>
// 151.双手石头剪刀布
// 

int win(char a, char b) {
    if ((a == 'O') && (b == 'Y')) return 0; //赢
    else if ((a == 'Y') && (b == 'H')) return 0;
    else if ((a == 'H') && (b == 'O')) return 0;
    else if (a == b) return 1; // 平局
    else return 2; // 输
}

int main() {
    char m_l, m_r, l_l, l_r;
    scanf("%s%s%s%s", &m_l, &m_r, &l_l, &l_r);
    switch (win(m_l, l_l)) {
        case 0: {
            if (win(m_l, l_r) < 2) printf("MING\n");
            else {
                if (win(m_r, l_r) == 0) printf("MING\n");
                if (win(m_r, l_r) > 0) printf("LIHUA\n");
            }
        } break;
        case 1: {
            if (win(m_r, l_r) == 0) printf("MING\n");
            if (win(m_r, l_r) == 2) printf("LIHUA\n");
            if (win(m_r, l_r) == 1) printf("TIE\n"); 
        } break;
        case 2: {
            if (win(m_r, l_l) > 0) printf("LIHUA\n");
            else {
                if (win(m_r, l_r) < 2) printf("MING\n");
                if (win(m_r, l_r) == 2) printf("LIHUA\n");
            }
        } break;
    }

    return 0;
}