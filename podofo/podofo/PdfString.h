//
//  PdfString.h
//  podofo
//
//  Created by Caland on 14-10-13.
//  Copyright (c) 2014年 Caland. All rights reserved.
//

#ifndef __podofo__PdfString__
#define __podofo__PdfString__

//#include <stdio.h>
#include <cstdio>
#include "PdfDataType.h"
#include "PDFDefines.h"

namespace PoDoFo {
    
//pdf的string缓存区大小为24字节
#define PDF_STRING_BUFFER_SIZE 24
    
    class PdfEncoding;
    class PdfOutputDevice;
    class PdfEncrypt;
    
    enum EPdfStringConversion {
        ePdfStringConversion_Strict,//严格模式
        ePdfStringConversion_Lenient//宽大模式
        
    };
    
//    using namespace std;
    
    class PdfString : public PdfDataType {
        
    public:
        /**
         *  创建一个空的非法的string
         */
        PdfString();
        
        /**
         *  从指定string中创建，是一个copy
         *  \param sString 原始的string串
         *  \param pEncoding 字符串的编码
         */
        PdfString(const std::string & sString, const PdfEncoding * const pEncoding = NULL);
        
        /**
         *  从指定char*中创建，是一个copy
         *  \param sString 原始的string串
         *  \param pEncoding 字符串的编码
         */
        PdfString(const char * pszString, const PdfEncoding * pEncoding = NULL);
        
        /**
         *
         *
         *
         */
//        void setFromWchar_t(const wchar_t *pszString, pdf_long = -1);
        
        /**
         *  从char字符串中构造
         *  是原有字符的拷贝
         *  若字符串以0xFE和0xFF开头，这个字符串将会被当做成Unicode16编码进行处理。
         *
         *  \param pszString 字符串
         *  \param lLen 字符串的长度
         *  \param bHex 字符串是否是以16进制显示的
         *  \param pEncoding 字符串的编码
         */
        PdfString(const char* pszString, pdf_long lLen, bool bHex = false, const PdfEncoding *pEncoding = NULL);
        
        /**
         *  从指定pdf_utf8*中创建，是一个copy
         *  \param pszStringUtf8 原始的string串，pdf_utf8 是 unsigned char 类型的
         */
        PdfString(const pdf_utf8* pszStringUtf8);
        
        /**
         *  从指定pdf_utf8*中创建，是一个copy
         *  \param pszStringUtf16 原始的string串，pdf_utf8 是 pdf_uint16 类型的，pdf_uint16是uint16_t的转定义
         */
        PdfString(const pdf_utf16be* pszStringUtf16);
        
        /**
         *  从指定pdf_utf8*中创建，是一个copy
         *  \param pszStringUtf8 原始的string串，pdf_utf8 是 unsigned char 类型的
         *  \param lLen 字符串的长度
         */
        PdfString(const pdf_utf8* pszStringUtf8, pdf_long lLen);
        
        /**
         *  从指定pdf_utf8*中创建，是一个copy
         *  \param pszStringUtf16 原始的string串，pdf_utf8 是 pdf_uint16 类型的，pdf_uint16是uint16_t的转定义
         *  \param lLen 字符串的长度
         */
        PdfString(const pdf_utf16be* pszStringUtf16, pdf_long lLen);
        
        /**
         *  拷贝构造函数
         */
        PdfString(const PdfString & rhs);
        
        /**
         *  析构函数
         */
        ~PdfString();
        
        
        /**
         *  将16进制的转换为字符数据
         *  \param pszHex 16进制的原始数据
         *  \param lLen 原始数据的长度
         *  \param pEncrypt 如果非空，就表示需要进行解码才能正常使用
         */
        void SetHexData(const char* pszHex, pdf_long lLen = -1, const PdfEncrypt* pEncrypt = NULL);
        
        /**
         *  这个对象在构造过程中如果没有发生错误，就表明这个对象是一个合法对象
         *  \return true 如果这个对象被正常初始化
         */
        inline bool IsValid() const;
        
        /**
         *  检查这个对象是否是一个hex构造的对象
         *  如果是的话，在写入pdf文件中时会以hex写回。
         *  \return true 如果本对象是从16进制中获得的
         */
        inline bool IsHex() const;
        
        /**
         *  本对象的字符编码为Latin1或者Unicode。
         *  本函数返回true表明这个对象的编码方式为Unicode
         *
         *  \return true 如果本对象的从unicode编码中获得的
         */
        inline bool IsUnicode() const;
        
        /**
         *  字符串的内容可以通过本方法读取
         *  若是16进制的数据，则其返回的编码不包含0.
         *  如果IsUnicode函数返回true，最好使用GetUnicode方法读取，因为在计算length的时候可能会出错
         *  \return 由0结束的字符串，不过中间可能包含0
         *  \see IsHex
         *  \see IsUnicode
         *  \see Length
         */
        inline char* GetString() const;
        
        /**
         *  字符串的内容可以通过本方法读取
         *  若是16进制的数据，则其返回的编码不包含0.
         *  如果IsUnicode函数返回true，最好使用GetUnicode方法读取，因为在计算length的时候可能会出错
         *  \return 由0结束的字符串，不过中间可能包含0
         *  \see IsHex
         *  \see IsUnicode
         *  \see Length
         */
        inline pdf_utf16be* GetUnicode() const;
        
        /**
         *  字符串的内容用utf8编码方式读取
         *  \return 字符串的编码方式为utf8
         */
        inline const std::string& GetStringUtf8() const;
        
        
        /**
         *  由GetString方法获得的字符集（不包含终止字符0）的长度
         *
         *  \returns the length of the string.
         *
         *  \see GetCharacterLength 决定字符串中有多少个字符
         */
        inline pdf_long GetLength() const;
        
        /**
         *  由GetUnicode方法获得的字符集（不包含终止字符0）的长度
         *
         *  \returns the length of the string.
         *
         *  \see GetCharacterLength 决定字符串中有多少个字符
         */
        inline pdf_long GetUnicodeLength() const;
        
        /**
         *  字符串中字符的个数
         *
         *  \returns 字符串中有多少个字符
         */
        inline pdf_long GetCharacterLength() const;
        
        /**
         *  继承下来的方法，重写
         *  用来在pDevice中写入本对象
         */
        void Write(PdfOutputDevice *pDevice, EPdfWriteMode eWriteMode, const PdfEncrypt *pEncrypt = NULL) const;
        
        /**
         *  拷贝一个已经存在的PdfString对象
         *  \param rhs 已经存在的对象
         *  \return 本对象
         */
        const PdfString & operator=(const PdfString & rhs);
        
        /** 
         *  对比两个对象
         *  \param rhs 另外一个对象
         *  \returns 本对象
         */
        bool operator>(const PdfString & rhs) const;
        
        /**
         *  对比两个对象
         *  \param rhs 另外一个对象
         *  \returns 本对象
         */
        bool operator<(const PdfString & rhs) const;
        
        /**
         *  比较运算符
         *  utf8和utf16编码的内容一致，就会返回true
         *  \param rhs 另外一个对象
         *  \returns true 如果两个对象的内容一致
         */
        bool operator==(const PdfString & rhs) const;
        
        /**
         *  比较运算符
         *  utf8和utf16编码的内容一致，就会返回false
         *  \param rhs 另外一个对象
         *  \returns true 如果两个对象的内容不一致
         */
        bool operator!=(const PdfString & rhs) const {return !operator==(rhs);}
        
        /**
         *  返回一个本对象内容的Unicode副本
         *
         *  如果IsUnicode返回true，则是本对象的一个副本，否则将本对象内容转化为Unicode的新对象返回
         *  \return 一个Unicode的版本。
         */
        PdfString ToUnicode() const;
        
#warning 记得这里被注释掉了，因为不完全
        /**
         *  返回内部的缓存对象，不能释放它，它属于PdfString对象的
         */
//        PdfRefCountedBuffer &GetBuffer(void);
        
        
        static const PdfString StringNull;
        
        static const pdf_long ConvertUTF8ToUTF16(pdf_utf8 *pszUtf8, pdf_utf16be * pszUtf16, pdf_long lLenUtf16);
        
        static const pdf_long ConvertUTF8ToUTF16(pdf_utf8 *pszUtf8, pdf_long lenUtf8,
                                                 pdf_utf16be * pszUtf16, pdf_long lLenUtf16, EPdfStringConversion = ePdfStringConversion_Strict);

        static const pdf_long ConvertUTF16ToUTF8(pdf_utf16be *pszUtf16, pdf_utf8 * pszUtf8, pdf_long lLenUtf8);

        static const pdf_long ConvertUTF16ToUTF8(pdf_utf16be *pszUtf16, pdf_long lLenUtf16,
                                                 pdf_utf8 * pszUtf8, pdf_long lLenUtf8, EPdfStringConversion = ePdfStringConversion_Strict);
        
        
    private:
        /** Allocate m_lLen data for m_pszData if data
         *  does not fit into m_pBuffer.
         *  Otherwise m_pszData is set to point to
         *  m_pBuffer.
         *  在数据不符合m_pBuffer的时候为m_pszData开辟足够的空间
         *  否则m_pszData是指向m_pBuffer的指针。
         */
        void Allocate();
        
        /** Frees the internal buffer
         *  if it was allocated using malloc
         *  释放使用malloc申请的内存空间
         */
        void FreeBuffer();
        
        /** Construct a new PdfString from a 0 terminated
         *  string.
         *  从以0为结束标识的char字符串中构造PdfString对象
         *
         *  The input string will be copied. 内容是被拷贝的
         *  if m_bhex is true the copied data will be hex encoded. 如果m_bhex属性设置为真，则拷贝的内容是十六进制数
         *
         *  \param pszString 用来进行拷贝的字符串，不能为NULL
         *  \param lLen 需要拷贝的长度
         *  
         */
        void Init(const char * pszString, pdf_long lLen);
        
        /** Construct a new PdfString from a UTF8
         *  string.
         *  从以utf8编码方式的字符中构造PdfString对象
         *  The input string will be copied and converted to UTF-16be.
         *  字符将以utf16编码方式保存
         *  \param pszStringUtf8 the string to copy, ust not be NULL 用来进行拷贝的字符串，不能为NULL
         *  \param lLen number of bytes of the string data to copy 需要拷贝的字节长度
         *  
         */
        void InitFromUtf8(const pdf_utf8 * pszString, pdf_long lLen);
        
        /** Swap the bytes in the buffer (UTF16be -> UTF16le)  将utf16be转化为utf16le
         *  \param pBuf buffer  缓存
         *  \param lLen length of buffer 缓存大小
         */
        static void SwipBytes(char *buf, pdf_long lLen);
        
        /** Initialise the data member containing a
         *  UTF8 version of this string.
         *  初始化一个utf8编码格式的PdfString
         *
         *  This is only done once and only if necessary. 本方法仅会调用一次
         */
        void InitUtf8();
        
    private:
        static const char s_pszUnicodeMarker[];             ///<unicode标识，表示在pdf中得string得编码方式
        static const char* s_pszUnicodeMarkerHex;           ///<unicode标识，标识着HEX
        static const pdf_utf16be s_cPdfDocEncoding[256];    ///<转换表，用来将PDFDocEncoding转化为utf16
        static const char * const m_escMap;                 ///<逃避数组的映射
        
    private:
#warning 去掉注释
//        PdfRefCountedBuffer m_buffer;
        
        bool m_bHex;
        bool m_bUnicode;
        
        std::string m_sUtf8;
        const PdfEncoding* m_pEncoding;
        
    };
    
}

#endif /* defined(__podofo__PdfString__) */
