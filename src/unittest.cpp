/*
 * Copyright(C) 2014 Tencent All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>

#include "sdt.h"

void __assert(bool flag, const char* filename, int line)
{
    if (flag)
    {
        printf("!!!assert fail :%s:%d\n",filename, line);
    }
}

#define TASSERT(exp) __assert(!(exp),__FILE__,__LINE__)

template<typename T1,typename T2>
void __assert_equ(T1& val1, T2 val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail general %s:%d\n", filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<char>& val1, char val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail char [%d,%d]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<unsigned char>& val1, unsigned char val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail uchar [%d,%d]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<short>& val1, short val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail short [%x,%x]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<unsigned short>& val1, unsigned short val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail ushort [%x,%x]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<int>& val1, int val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail int [%x,%x]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<unsigned int>& val1, unsigned int val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail uint [%x,%x]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<long>& val1, long val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail long [%zx,%zx]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<unsigned long>& val1, unsigned long val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail ulong [%zx,%zx]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<float>& val1, float val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail float [%f,%f]%s:%d\n", val1.value(), val2, filename,line);
    }
}

template<>
void __assert_equ(tsssdk::sdt<double>& val1, double val2, const char* filename, int line)
{
    if (val1 != val2)
    {
        printf("!equ fail double [%f,%f]%s:%d\n", val1.value(), val2, filename,line);
    }
}

#define TASSERT_EQU(a,b) __assert_equ(a,b,__FILE__,__LINE__)

int t_random()
{
    unsigned char flag = 0;
    if (!flag)
    {
        flag = 1;
        srand((unsigned int)time(NULL));
    } 

    int r = rand();
    return ++r;
}

float t_random_float()
{
    float r = 1234.01234f;
    int a = t_random();
    return a / r;
}

double t_random_double()
{
    double r = 456.0456;
    int a = t_random();
    return a/r;
}

const int TEST_TIMES = 10000;
template<typename T1, typename T2>
void test_sdt_1()
{
    // += -= *= /= ++ --
    T1 a = 0;
    T1 b = 0;
    T2 raw_a,raw_b;

    a = b = 0;
    raw_a = raw_b = 0;

    TASSERT_EQU(a,raw_a);
    TASSERT_EQU(b,raw_b);

    for (int i = 0; i < TEST_TIMES; i++)
    {
        int a_int = t_random();
        int b_int = t_random();
        b_int = b_int==0?b_int+1:b_int;

        raw_a = a_int;
        raw_b = b_int;
        a = a_int;
        b = b_int;
        
        // printf("a = %d,raw_a = %d\n", a, b);        
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);

        // +=
        a += b;
        raw_a += raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a += raw_b;
        raw_a += b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // -=
        a -= b;
        raw_a -= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a -= raw_b;
        raw_a -= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);

        // *=
        a *= b;
        raw_a *= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a *= raw_b;
        raw_a *= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // /=
        
        a /= b;
        raw_a /= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a /= raw_b;
        raw_a /= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);

        // ++
        TASSERT_EQU(a++,raw_a++);
        TASSERT_EQU(++a,++raw_a);

        // --
        TASSERT_EQU(a--,raw_a--);
        TASSERT_EQU(--a,--raw_a);
        
        // float
        float a_float = t_random_float();
        float b_float = t_random_float();
        b_float = b_float==0?b_float+1:b_float;
        
        raw_a = a_float;
        raw_b = b_float;
        a = a_float;
        b = b_float;
        
        // printf("a = %d,raw_a = %d\n", a, b);
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // +=
        a += b;
        raw_a += raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a += raw_b;
        raw_a += b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // -=
        a -= b;
        raw_a -= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a -= raw_b;
        raw_a -= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // *=
        a *= b;
        raw_a *= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a *= raw_b;
        raw_a *= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // /=
        
        a /= b;
        raw_a /= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a /= raw_b;
        raw_a /= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // ++
        TASSERT_EQU(a++,raw_a++);
        TASSERT_EQU(++a,++raw_a);
        
        // --
        TASSERT_EQU(a--,raw_a--);
        TASSERT_EQU(--a,--raw_a);

        // double
        double a_double = t_random_double();
        double b_double = t_random_double();
        b_double = b_double==0?b_double+1:b_double;
        
        raw_a = a_double;
        raw_b = b_double;
        a = a_double;
        b = b_double;
        
        // printf("a = %d,raw_a = %d\n", a, b);
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // +=
        a += b;
        raw_a += raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a += raw_b;
        raw_a += b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // -=
        a -= b;
        raw_a -= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a -= raw_b;
        raw_a -= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // *=
        a *= b;
        raw_a *= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a *= raw_b;
        raw_a *= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // /=
        
        a /= b;
        raw_a /= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a /= raw_b;
        raw_a /= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // ++
        TASSERT_EQU(a++,raw_a++);
        TASSERT_EQU(++a,++raw_a);
        
        // --
        TASSERT_EQU(a--,raw_a--);
        TASSERT_EQU(--a,--raw_a);
    }
    
}

// no float double
template<typename T1, typename T2>
void test_sdt_2()
{
    // %= &= |= ^= <<= >>=
    T1 a = 0;
    T1 b = 0;
    T2 raw_a,raw_b;
    
    a = b = 0;
    raw_a = raw_b = 0;
    
    TASSERT_EQU(a,raw_a);
    TASSERT_EQU(b,raw_b);
    
    for (int i = 0; i < TEST_TIMES; i++)
    {
        int a_int = t_random();
        int b_int = t_random();
        b_int = b_int==0?b_int+1:b_int;
        
        raw_a = a_int;
        raw_b = b_int;
        a = a_int;
        b = b_int;
        
        // printf("a = %d,raw_a = %d\n", a, b);
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // %=
        a %= b;
        raw_a %= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a %= raw_b;
        raw_a %= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // &=
        a &= b;
        raw_a &= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a &= raw_b;
        raw_a &= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // |=
        a |= b;
        raw_a |= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a |= raw_b;
        raw_a |= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // ^=
        
        a ^= b;
        raw_a ^= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a ^= raw_b;
        raw_a ^= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // <<=
        
        a <<= b;
        raw_a <<= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a <<= raw_b;
        raw_a <<= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        // >>=
        
        a >>= b;
        raw_a >>= raw_b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
        a >>= raw_b;
        raw_a >>= b;
        TASSERT_EQU(a,raw_a);
        TASSERT_EQU(b,raw_b);
        
    }
}

void do_test()
{
    // TASSERT(1==3);
    int a_int = t_random();
    int b_int = t_random();
    sdt_char a = 0;
    sdt_char b = 0;
    char raw_a,raw_b;
    
    b_int = b_int==0?b_int+1:b_int;
    a = a_int;
    raw_a = a_int;
    b = b_int;
    raw_b = b;
    
    TASSERT_EQU(a , raw_a);
    TASSERT_EQU(b , raw_b);
    
    a += b;
    raw_a += raw_b;
    TASSERT_EQU(a , raw_a);
    TASSERT_EQU(b , raw_b);
    
    test_sdt_1<sdt_char,char>();
    test_sdt_1<sdt_uchar,unsigned char>();
    test_sdt_1<sdt_short,short>();
    test_sdt_1<sdt_ushort,unsigned short>();
    test_sdt_1<sdt_int,int>();
    test_sdt_1<sdt_uint,unsigned int>();
    test_sdt_1<sdt_long,long>();
    test_sdt_1<sdt_ulong,unsigned long>();
    test_sdt_1<sdt_float,float>();
    test_sdt_1<sdt_double,double>();

    test_sdt_2<sdt_char,char>();
    test_sdt_2<sdt_uchar,unsigned char>();
    test_sdt_2<sdt_short,short>();
    test_sdt_2<sdt_ushort,unsigned short>();
    test_sdt_2<sdt_int,int>();
    test_sdt_2<sdt_uint,unsigned int>();
    test_sdt_2<sdt_long,long>();
    test_sdt_2<sdt_ulong,unsigned long>();
    // test_sdt_2<sdt_float,float>();
    // test_sdt_2<sdt_double,double>();
}

int main(int argc, const char* argv[])
{
    printf("=== sdt unittest [===\n");
    
    sdt_char a = 0;
    char raw_a = 0;
    __assert_equ(a, raw_a, __FILE__, __LINE__);
    
    do_test();
    
    printf("=== sdt unittest ]===\n");
    return 0;
}
