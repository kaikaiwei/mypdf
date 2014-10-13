//
//  PdfDataType.cpp
//  podofo
//
//  Created by Caland on 14-10-13.
//  Copyright (c) 2014年 Caland. All rights reserved.
//

#include "PdfDataType.h"

namespace PoDoFo {
    
    
    PdfDataType::PdfDataType():m_bImmutable(false)
    {
        
    }
    
    PdfDataType::~PdfDataType()
    {
        
    }
    
    bool PdfDataType::IsDirty() const
    {
        return false;
    }
    
    void PdfDataType::SetDirty(bool )
    {
        //这里被忽略了
    }
    
}