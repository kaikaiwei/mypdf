//
//  PdfDataType.h
//  podofo
//
//  Created by Caland on 14-10-13.
//  Copyright (c) 2014年 Caland. All rights reserved.
//

#ifndef __podofo__PdfDataType__
#define __podofo__PdfDataType__

#include "PDFDefines.h"
#include "PdfError.h"

#include <stdio.h>


namespace PoDoFo {
    class PdfEncrypt;
    class PdfOutputDevice;
    
    class PdfDataType {
        
    protected:
        PdfDataType();//只允许子类进行构造，不允许其他类进行构造
        
    public:
        virtual ~PdfDataType();//虚析构函数，会调用子类的析构函数
        
        /**
         *  将完整的datatype写入文件
         *
         *  \param pDevice 将datatype写入到该device中
         *  \param eWriteMode 写入模式，分为两类，紧凑和格式良好
         *  \param pEncrypt 一个用来对本datatype对象进行编码的对象，默认为空
         */
        virtual void Write(PdfOutputDevice *pDevice, EPdfWriteMode eWriteMode, const PdfEncrypt * pEncrypt = NULL ) const = 0;//常函数，纯虚函数（=0）
        
        /**
         *  dirty 标志着该对象在通过构造函数创建之后，其成员时候被修改过。
         *  通常情况下，只要调用非常函数的成员函数，都会造成该值被设置为真。
         *  \return true 如果对象的成员中在构造之后被修改
         */
        virtual bool IsDirty() const;
        
        /**
         *  设置PdfVariant的dirty标记
         *  \see IsDirty
         */
        virtual void SetDirty(bool bDirty);
        
        /**
         *  设置本实例的immutable对象，若设置为真，则本对象就无法被修改
         *
         *  \param bImmutable 若bImmutable为真，则会这只本对象无法被修改
         *  该数据通常用在PdfImmediateWrite和PDFStreamedDocument,这样只要设置了该值，就不能在写入之后再修改该值
         */
        inline void SetImmutable(bool bImmutable);
        
        /**
         *  取回本实例的immutable属性
         *
         *  @return true 若本属性为真，则返回true。
         */
        inline bool GetImmutable() const;
        
    protected:
        /**
         *  如果该实例的immutable属性为真，则会抛出一个异常
         *  在真正开始修改文件的时候需要调用此方法
         *
         */
        inline void AssertMutable() const;
        
    private:
        bool m_bImmutable;
        
    };
    
    inline void PdfDataType::SetImmutable(bool bImmutable)
    {
        m_bImmutable = bImmutable;
    }
    
    inline bool PdfDataType::GetImmutable() const
    {
        return m_bImmutable;
    }
    
    inline void PdfDataType::AssertMutable() const
    {
        if (m_bImmutable) {
#warning 带完成error信息后，修改此处。将此处的注释去掉
//            throw PdfError(ePdfError_ChangeOnImmutable);
        }
    }
    
}

#endif /* defined(__podofo__PdfDataType__) */
