/*
 *
 */

#ifndef __TSSSDK_SDT__
#define __TSSSDK_SDT__

#define USE_SDT // comment this line if disable sdt

namespace tsssdk
{
    template<typename T>
    class sdt
    {

    };
} // end of namespace tsssdt

#ifdef USE_SDT
typedef sdt_char    tsssdk::sdt<char>;
typedef sdt_uchar   tsssdk::sdt<unsigned char>;
typedef sdt_short   tsssdk::sdt<short>;
typedef sdt_ushort  tsssdk::sdt<unsigned short>;
typedef sdt_int     tsssdk::sdt<int>;
typedef sdt_uint    tsssdk::sdt<unsigned int>;
typedef sdt_long    tsssdk::sdt<long>;
typedef sdt_ulong   tsssdk::sdt<unsigned long>;
typedef sdt_float   tsssdk::sdt<float>;
typedef sdt_double  tsssdk::sdt<double>;
#else
#endif

#endif // end of __TSSSDK_SDT__
