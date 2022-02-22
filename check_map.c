#include "my_lib.h"


int check_char(t_opt *c)
{
    if (!(c->empty_c >= 32 && c->empty_c <= 126))
        return (0);    
    if (!(c->fill_c >= 32 && c->fill_c <= 126))
        return (0);  
    if (!(c->hurdle_c >= 32 && c->hurdle_c <= 126))
        return (0);  
    if (c->fill_c == c->empty_c)
        return (0);
    if (c->fill_c == c->hurdle_c)
        return (0);
    if (c->empty_c == c->hurdle_c)
        return (0);
    return (1);
}

int check_row_size(char *num)               // 행 개수가 유효하지 않으면 0반환
{                                           // 유효하면 행 개수 반환
    int i;

    i = 0;
    while (num[i])
    {
        if (i == 0 && !(num[i] >= '1' && num[i] <= '9'))
            return (0);
        if (!(num[i] >= '0' && num[i] <= '9'))
            return (0);
        i++;
    }
    return (ft_atoi(num));
}

int check_firstline(char *buf, t_opt *c)
{
    int i;
    int j;
    char num[100];

    i = 0;
    while(buf[i] && buf[i] != '\n')
        i++;
    if (i < 3)                              // 문자가 4개 미만이면
        return (0);                         // 유효하지 않음
    c->fill_c = buf[--i];
    c->hurdle_c = buf[--i];
    c->empty_c = buf[--i];
    if (!check_char(c))                     // 중복된 문자가 있거나 출력되지 않는 문자가 있으면
        return (0);                         // 유효하지 않음
    j = -1;
    while(++j < i)
        num[j] = buf[j];
    num[++j] = '\0';
    c->row_size = check_row_size(num);
    if (c->row_size <= 0)                   // 행의 개수가 0이하이면
        return (0);                         // 유효하지 않음
    return (1);
}                                                       

int check_col_size(char *buf, t_opt *c)
{
    int i;
    int col_size;

    i = 0;
    col_size = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    while (buf[++i] && buf[i] != '\n')
        col_size++;
    if (col_size <= 0)                      // 열의 길이가 0이하이면
        return (0);                         // 유효하지 않음
    c->col_size = col_size;
    return (1);
}

int check_map_char(t_opt *c, char target)   // 지도의 문자가 첫행의 규칙을 따르면 1반환
{                                           // 따르지 않으면 0반환
    if (target == c->empty_c)
        return (1);
    if (target == c->hurdle_c)
        return (1);
    return (0);
}

int check_map(char *buf, t_opt *c)          // 지도의 행 개수가 첫 행의 규칙을 따르지 않거나
{                                           // 지도의 모든 열 길이가 같지 않으면 0반환
    int i;
    int row_size;
    int col_size;

    i = 0;
    row_size = 0;
    col_size = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    while (buf[++i])
    {
        if (buf[i] == '\n')
        {
            row_size++;
            if (col_size != c->col_size)
                return (0);
            col_size = 0;
        }
        else
        {
            if (!check_map_char(c, buf[i]))
                return (0);
            col_size++;
        }
    }
    if (row_size != c->row_size)
        return (0);
    return (1);
}

int check_all(char *buf)                        // 지도 파일이 유효한지 확인
{
    t_opt c;
    int i;

    i = 0;
    while (i < 10)                              // 이거 안해주면 제대로 실행이 안됨
        i++;                                    // 이유를 잘 모르겠음
    if (!check_firstline(buf, &c))
        return (0);
    if (!check_col_size(buf, &c))
        return (0);
    if (!check_map(buf, &c))
        return (0);
    return (1);
}