//
//  PdfString.h
//  podofo
//
//  Created by Caland on 14-10-13.
//  Copyright (c) 2014年 Caland. All rights reserved.
//

#ifndef __podofo__PdfString__
#define __podofo__PdfString__

#include <stdio.h>

namespace PoDoFo {
    
//pdf的string缓存区大小为24字节
#define PDF_STRING_BUFFER_SIZE 24
    
    class PdfEncoding;
    class PdfOutputDevice;
    
    enum EPdfStringConversion {
        ePdfStringConversion_Strict,
        ePdfStringConversion_Lenient
    };
    
    
}

#endif /* defined(__podofo__PdfString__) */
