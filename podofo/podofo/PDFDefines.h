//
//  PDFDefines.h
//  podofo
//
//  Created by Caland on 14-10-13.
//  Copyright (c) 2014年 Caland. All rights reserved.
//

//这里是一些常用的pdf定义所在的位置

#ifndef podofo_PDFDefines_h
#define podofo_PDFDefines_h

#include "Podofo_config.h"

/**
 * PODOFO_VERSION_PATCH .
 * PoDoFo 版本信息，一个24位的二进制码流。
 * 版本信息的格式为： 0xMMmmpp M是大版本号，m是镜像号，p是补丁号
 * 如： 0.7.0 版本号表示为0x000700， 0.7.99版本号表示为0x000763
 * 注意，pdf的版本号可以使用PDFOFO_VERSION_MAJOR, PODOFO_VERSION_MINOR,PODOFO_VERSION_PATCH组成
 */
#define PODOFO_MAKE_VERSION_REAL(M,m,p) ( (M<<16)+(m<<8)+(p) )
#define PODOFO_MAKE_VERSION(M,m,p) PODOFO_MAKE_VERSION_REAL(M,m,p)
#define PODOFO_VERSION PODOFO_MAKE_VERSION(PODOFO_VERSION_MAJOR, PODOFO_VERSION_MINOR, PODOFO_VERSION_PATCH)

/**
 * PoDoFo 版本信息的字符呈现方式，如0.7.99
 */
#define PODOFO_MAKE_VERSION_STR_REAL(M,m,p) ("\"" #M "." #m "." #p "\"")
#define PODOFO_MAKE_VERSION_STR(M,m,p) PODOFO_MAKE_VERSION_STR_REAL(M,m,p)
#define PODOFO_VERSION_STR PODOFO_MAKE_VERSION_STR(PODOFO_VERSION_MAJOR, PODOFO_VERSION_MINOR, PODOFO_VERSION_PATCH)



#ifdef PODOFO_HAVE_BOOST
#include <boost/config.hpp>
#endif // PODOFO_HAVE_BOOST


#ifndef PODOFO_VERBOSE_DEBUG
//#define PODOFO_VERBOSE_DEBUG
#endif //PODOFO_VERBOSE_DEBUG

#ifdef DEBUG
#include <assert.h>
#define PODOFO_ASSERT( x ) assert( x );
#else
#define PODOFO_ASSERT( x )
#endif // DEBUG

#ifndef PODOFO_EXTRA_CHECKS
//#define PODOFO_EXTRA_CHECKS
#endif //PODOFO_EXTRA_CHECKS



namespace PoDoFo {
    typedef PDF_INT8_TYPENAME  pdf_int8;
    typedef PDF_INT16_TYPENAME  pdf_int16;
    typedef PDF_INT32_TYPENAME  pdf_int32;
    typedef PDF_INT64_TYPENAME  pdf_int64;
    typedef PDF_UINT8_TYPENAME pdf_uint8;
    typedef PDF_UINT16_TYPENAME pdf_uint16;
    typedef PDF_UINT32_TYPENAME pdf_uint32;
    typedef PDF_UINT64_TYPENAME pdf_uint64;
};

namespace PoDoFo {
    
    /* Explicitly big-endian short, suitable for unicode text */
    typedef pdf_uint16     pdf_utf16be;
    /* Typedef to indicate utf-8 encoded data */
    typedef unsigned char  pdf_utf8;
    
    // Enums
    
    /**
     * Enum to identify diferent versions of the PDF file format
     */
    enum EPdfVersion {
        ePdfVersion_1_0 = 0,       /**< PDF 1.0 */
        ePdfVersion_1_1,           /**< PDF 1.1 */
        ePdfVersion_1_2,           /**< PDF 1.2 */
        ePdfVersion_1_3,           /**< PDF 1.3 */
        ePdfVersion_1_4,           /**< PDF 1.4 */
        ePdfVersion_1_5,           /**< PDF 1.5 */
        ePdfVersion_1_6,           /**< PDF 1.6 */
        ePdfVersion_1_7            /**< PDF 1.7 */
    };
    
    /** The default PDF Version used by new PDF documents
     *  in PoDoFo.
     */
    const EPdfVersion ePdfVersion_Default = ePdfVersion_1_3;
    
    /**
     * Specify additional options for writing the PDF.
     */
    enum EPdfWriteMode {
        ePdfWriteMode_Compact = 0x01, ///< Try to write the PDF as compact as possible (Default)  尽可能的紧凑的书写
        ePdfWriteMode_Clean = 0x02,   ///< Create a PDF that is readable in a text editor, i.e. insert spaces and linebreaks between tokens 格式良好的书写，方便查看
    };
    
    const EPdfWriteMode ePdfWriteMode_Default = ePdfWriteMode_Compact;
    
    /**
     * Every PDF datatype that can occur in a PDF file
     * is referenced by an own enum (e.g. Bool or String).
     *
     * \see PdfVariant
     *
     * Remember to update PdfVariant::GetDataTypeString() when adding members here.
     */
    enum EPdfDataType {
        ePdfDataType_Bool,                  /**< Boolean datatype: Accepts the values "true" and "false" */
        ePdfDataType_Number,                /**< Number datatype for integer values */
        ePdfDataType_Real,                  /**< Real datatype for floating point numbers */
        ePdfDataType_String,                /**< String datatype in PDF file. Strings have the form (Hallo World!) in PDF files. \see PdfString */
        ePdfDataType_HexString,             /**< HexString datatype in PDF file. Hex encoded strings have the form &lt;AF00BE&gt; in PDF files. \see PdfString */
        ePdfDataType_Name,                  /**< Name datatype. Names are used as keys in dictionary to reference values. \see PdfName */
        ePdfDataType_Array,                 /**< An array of other PDF data types. */
        ePdfDataType_Dictionary,            /**< A dictionary associates keys with values. A key can have another dictionary as value. */
        //ePdfDataType_Stream,                /**< A stream can be attached to a dictionary and contain additional data. \see PdfStream */
        ePdfDataType_Null,                  /**< The null datatype is always null. */
        ePdfDataType_Reference,             /**< The reference datatype contains references to PDF objects in the PDF file of the form 4 0 R. \see PdfObject */
        ePdfDataType_RawData,               /**< Raw PDF data */
        
        ePdfDataType_Unknown                /**< The Datatype is unknown */
    };
    
    /**
     * Every filter that can be used to encode a stream
     * in a PDF file is referenced by an own enum value.
     * Common filters are ePdfFilter_FlateDecode (i.e. Zip) or
     * ePdfFilter_ASCIIHexDecode
     */
    enum EPdfFilter {
        ePdfFilter_ASCIIHexDecode,            /**< Converts data from and to hexadecimal. Increases size of the data by a factor of 2! \see PdfHexFilter */
        ePdfFilter_ASCII85Decode,             /**< Converts to and from Ascii85 encoding. \see PdfAscii85Filter */
        ePdfFilter_LZWDecode,
        ePdfFilter_FlateDecode,               /**< Compress data using the Flate algorithm of ZLib. This filter is recommended to be used always. \see PdfFlateFilter */
        ePdfFilter_RunLengthDecode,           /**< Run length decode data. \see PdfRLEFilter */
        ePdfFilter_CCITTFaxDecode,
        ePdfFilter_JBIG2Decode,
        ePdfFilter_DCTDecode,
        ePdfFilter_JPXDecode,
        ePdfFilter_Crypt
    };
    
    
    /**
     * Enum for the different font formats supported by PoDoFo
     */
    enum EPdfFontType {
        ePdfFontType_TrueType,
        ePdfFontType_Type1Pfa,
        ePdfFontType_Type1Pfb,
        ePdfFontType_Type1Base14,
        ePdfFontType_Type3,
        ePdfFontType_Unknown = 0xff
    };
    
    /**
     * Enum for the colorspaces supported
     * by PDF.
     */
    enum EPdfColorSpace {
        ePdfColorSpace_DeviceGray,        /**< Gray */
        ePdfColorSpace_DeviceRGB,         /**< RGB  */
        ePdfColorSpace_DeviceCMYK,        /**< CMYK */
        ePdfColorSpace_Separation,        /**< Separation */
        ePdfColorSpace_CieLab,            /**< CIE-Lab */
        ePdfColorSpace_Indexed,           /**< Indexed */
        ePdfColorSpace_Unknown = 0xff
    };
    
    /**
     * Enum for text rendering mode (Tr)
     */
    enum EPdfTextRenderingMode {
        ePdfTextRenderingMode_Fill = 0,                 /**< Default mode, fill text */
        ePdfTextRenderingMode_Stroke,                   /**< Stroke text */
        ePdfTextRenderingMode_FillAndStroke,            /**< Fill, then stroke text */
        ePdfTextRenderingMode_Invisible,                /**< Neither fill nor stroke text (invisible) */
        ePdfTextRenderingMode_FillToClipPath,           /**< Fill text and add to path for clipping */
        ePdfTextRenderingMode_StrokeToClipPath,         /**< Stroke text and add to path for clipping */
        ePdfTextRenderingMode_FillAndStrokeToClipPath,  /**< Fill, then stroke text and add to path for clipping */
        ePdfTextRenderingMode_ToClipPath,               /**< Add text to path for clipping */
        ePdfTextRenderingMode_Unknown = 0xff
    };
    
    /**
     * Enum for the different stroke styles that can be set
     * when drawing to a PDF file (mostly for line drawing).
     */
    enum EPdfStrokeStyle {
        ePdfStrokeStyle_Solid,
        ePdfStrokeStyle_Dash,
        ePdfStrokeStyle_Dot,
        ePdfStrokeStyle_DashDot,
        ePdfStrokeStyle_DashDotDot,
        ePdfStrokeStyle_Custom
    };
    
    /**
     * Enum for predefined tiling patterns.
     */
    enum EPdfTilingPatternType {
        ePdfTilingPatternType_BDiagonal = 1,
        ePdfTilingPatternType_Cross,
        ePdfTilingPatternType_DiagCross,
        ePdfTilingPatternType_FDiagonal,
        ePdfTilingPatternType_Horizontal,
        ePdfTilingPatternType_Vertical,
        ePdfTilingPatternType_Image
    };
    
    /**
     * Enum for line cap styles when drawing.
     */
    enum EPdfLineCapStyle {
        ePdfLineCapStyle_Butt    = 0,
        ePdfLineCapStyle_Round   = 1,
        ePdfLineCapStyle_Square  = 2
    };
    
    /**
     * Enum for line join styles when drawing.
     */
    enum EPdfLineJoinStyle {
        ePdfLineJoinStyle_Miter   = 0,
        ePdfLineJoinStyle_Round   = 1,
        ePdfLineJoinStyle_Bevel   = 2
    };
    
    /**
     * Enum for vertical text alignment
     */
    enum EPdfVerticalAlignment {
        ePdfVerticalAlignment_Top    = 0,
        ePdfVerticalAlignment_Center = 1,
        ePdfVerticalAlignment_Bottom  = 2
    };
    
    /**
     * Enum for text alignment
     */
    enum EPdfAlignment {
        ePdfAlignment_Left    = 0,
        ePdfAlignment_Center  = 1,
        ePdfAlignment_Right   = 2
    };
}



//导入头文件
#if PODOFO_HAVE_STRINGS_H
#include <strings.h>
#endif

#if PODOFO_HAVE_ARPA_INET_H
#  include <arpa/inet.h>
#endif

#if PODOFO_HAVE_CTYPE_H
#include <ctype.h>
#endif


#if PODOFO_HAVE_STDINT_H
#include <stdint.h>
#endif


#if PODOFO_HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif








#endif
