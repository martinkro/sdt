/*
 * Copyright(C) 2014 Tencent All Rights Reserved.
 */

#ifndef __TSSSDK_SDT__
#define __TSSSDK_SDT__

#define USE_SDT // comment this line if disable sdt

#include <time.h>
#include <stdlib.h>

namespace tsssdk
{
    unsigned int gen_random();

    const int SDT_BACKUP_LEN = 8;
    template<typename T>
    class sdt
    {
    public:
        sdt()
        {
            T val = 0;
            this->assign(val);
        }

        sdt(const T& val)
        {   
            this->assign(val);
        }

        sdt(const sdt<T>& rhs)
        {
            this->assign(rhs.value());
        }

        sdt<T>& operator=(const T& val)
        {
            this->assign(val);
            return *this;
        }

        sdt<T>& operator=(sdt<T>& rhs)
        {
            if (this != &rhs)
            {
                this->assign(rhs.value());
            }
            return *this;
        }

        ~sdt()
        {
        }

        operator const T()const
        {
            return this->value();
        }
        
        const T value() const
        {
            return this->encrypt(m_vals[m_idx]);
        }

        // +=
        sdt<T>& operator+=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val += rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator+=(const char rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const unsigned char rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const short rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const unsigned short rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const int rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const unsigned int rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const long rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const unsigned long rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const float rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator+=(const double rhs)
        {
            T val = this->value();
            val += rhs;
            this->assign(val);
            return *this;
        }

        // -=
        sdt<T>& operator-=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val -= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator-=(const char rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const unsigned char rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const short rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const unsigned short rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const int rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const unsigned int rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const long rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const unsigned long rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const float rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator-=(const double rhs)
        {
            T val = this->value();
            val -= rhs;
            this->assign(val);
            return *this;
        }

        // *=
        sdt<T>& operator*=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val *= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator*=(const char rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const unsigned char rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const short rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const unsigned short rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const int rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const unsigned int rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const long rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const unsigned long rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const float rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator*=(const double rhs)
        {
            T val = this->value();
            val *= rhs;
            this->assign(val);
            return *this;
        }

        // /=
        sdt<T>& operator/=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val /= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator/=(const char rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const unsigned char rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const short rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const unsigned short rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const int rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const unsigned int rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const long rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const unsigned long rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const float rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator/=(const double rhs)
        {
            T val = this->value();
            val /= rhs;
            this->assign(val);
            return *this;
        }

        // %=
        sdt<T>& operator%=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val %= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator%=(const char rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const unsigned char rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const short rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const unsigned short rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const int rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const unsigned int rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const long rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const unsigned long rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const float rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator%=(const double rhs)
        {
            T val = this->value();
            val %= rhs;
            this->assign(val);
            return *this;
        }

        // &=
        sdt<T>& operator&=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val &= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator&=(const char rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const unsigned char rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const short rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const unsigned short rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const int rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const unsigned int rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const long rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const unsigned long rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const float rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator&=(const double rhs)
        {
            T val = this->value();
            val &= rhs;
            this->assign(val);
            return *this;
        }

        // |=
        sdt<T>& operator|=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val |= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator|=(const char rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const unsigned char rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const short rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const unsigned short rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const int rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const unsigned int rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const long rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const unsigned long rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const float rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator|=(const double rhs)
        {
            T val = this->value();
            val |= rhs;
            this->assign(val);
            return *this;
        }

        // ^=
        sdt<T>& operator^=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val ^= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator^=(const char rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const unsigned char rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const short rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const unsigned short rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const int rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const unsigned int rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const long rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const unsigned long rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const float rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator^=(const double rhs)
        {
            T val = this->value();
            val ^= rhs;
            this->assign(val);
            return *this;
        }

        // >>=
        sdt<T>& operator>>=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val >>= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator>>=(const char rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const unsigned char rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const short rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const unsigned short rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const int rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const unsigned int rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const long rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const unsigned long rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const float rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator>>=(const double rhs)
        {
            T val = this->value();
            val >>= rhs;
            this->assign(val);
            return *this;
        }

        // <<=
        sdt<T>& operator<<=(const sdt<T>& rhs)
        {
            T val = this->value();
            T rval = rhs.value();
            val <<= rval;
            this->assign(val);
            return *this;
        }

        
        sdt<T>& operator<<=(const char rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const unsigned char rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const short rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const unsigned short rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const int rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const unsigned int rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const long rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const unsigned long rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const float rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        sdt<T>& operator<<=(const double rhs)
        {
            T val = this->value();
            val <<= rhs;
            this->assign(val);
            return *this;
        }

        // ++
        const sdt<T> operator++()
        {
            T temp = this->value();
            ++temp;
            this->assign(temp);
            return *this;
        }

        const sdt<T> operator++(int)
        {
            T temp = this->value();
            sdt<T> t(*this);
            ++temp;
            this->assign(temp);
            return t;
        }
        // --
    
        const sdt<T> operator--()
        {
            T temp = this->value();
            --temp;
            this->assign(temp);
            return *this;
        }

        const sdt<T> operator--(int)
        {
            T temp = this->value();
            sdt<T> t(*this);
            --temp;
            this->assign(temp);
            return t;
        }
    private:
        inline T encrypt(const T& val) const
        {
            T result = 0;
            const unsigned char* src = (const unsigned char*)&val;
            unsigned char* dst = (unsigned char*)&result;
            for (unsigned int i = 0; i < sizeof(T); i++)
            {
                *(dst + i) = *(src + i) ^ m_key;
            }
            return result;
        }
        
        inline void assign(const T& val)
        {
            m_idx = get_idx();
            m_key = get_key();
            for (unsigned char i = 0; i < SDT_BACKUP_LEN; i++)
            {
                m_vals[i] = i + get_random();
            }
            m_vals[m_idx] = this->encrypt(val);
        }

        unsigned char get_random()
        {
            return gen_random() % 256;
        }

        unsigned char get_key()
        {
            unsigned char t = gen_random() % 256;
            if (t == m_key)
            {
                m_key = (gen_random() + t) % 256;
            }
            else
            {
                m_key = t;
            }
            return m_key;
        }

        unsigned char get_idx()
        {
            unsigned char t = gen_random() % SDT_BACKUP_LEN;
            if (t == m_idx)
            {
                m_idx = (gen_random() + t) % SDT_BACKUP_LEN;
            }
            else
            {
                m_idx = t;
            }

            return m_idx;
        }



    private:
        T m_vals[SDT_BACKUP_LEN];
        unsigned char m_idx;
        unsigned char m_key;
    };
} // end of namespace tsssdt

#ifdef USE_SDT
typedef tsssdk::sdt<char>           sdt_char;
typedef tsssdk::sdt<unsigned char>  sdt_uchar;
typedef tsssdk::sdt<short>          sdt_short;
typedef tsssdk::sdt<unsigned short> sdt_ushort;
typedef tsssdk::sdt<int>            sdt_int;
typedef tsssdk::sdt<unsigned int>   sdt_uint;
typedef tsssdk::sdt<long>           sdt_long;
typedef tsssdk::sdt<unsigned long>  sdt_ulong;
typedef tsssdk::sdt<float>          sdt_float;
typedef tsssdk::sdt<double>         sdt_double;
#else
typedef char            sdt_char;
typedef unsigned char   sdt_uchar;
typedef short           sdt_short;
typedef unsigned short  sdt_ushort;
typedef int             sdt_int;
typedef unsigned int    sdt_uint;
typedef long            sdt_long;
typedef unsigned long   sdt_ulong;
typedef float           sdt_float;
typedef double          sdt_double;
#endif

#endif // end of __TSSSDK_SDT__
