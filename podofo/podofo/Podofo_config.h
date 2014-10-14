//
//  Podofo_config.h
//  podofo
//
//  Created by Caland on 14-10-13.
//  Copyright (c) 2014年 Caland. All rights reserved.
//

#ifndef podofo_Podofo_config_h
#define podofo_Podofo_config_h

//podofo的版本信息
#define PODOFO_VERSION_MAJOR 0
#define PODOFO_VERSION_MINOR 9
#define PODOFO_VERSION_PATCH 4

/* PoDoFo configuration options */
#define PODOFO_MULTI_THREAD

/* <string.h> */
#define PODOFO_HAVE_STRINGS_H 1
/* <arap/inet> */
#define PODOFO_HAVE_ARPA_INET_H 1
/* <ctype.h> */
#define PODOFO_HAVE_CTYPE_H 1

/* <stdint.h>  - headers */
#define PODOFO_HAVE_STDINT_H 1
/* <sys/type.h>*/
#define PODOFO_HAVE_SYS_TYPES_H 1

/* <stdint.h> 中定义的*/
#define PDF_INT8_TYPENAME   int8_t
#define PDF_INT16_TYPENAME  int16_t
#define PDF_INT32_TYPENAME  int32_t
#define PDF_INT64_TYPENAME  int64_t
#define PDF_UINT8_TYPENAME  uint8_t
#define PDF_UINT16_TYPENAME uint16_t
#define PDF_UINT32_TYPENAME uint32_t
#define PDF_UINT64_TYPENAME uint64_t

/* Sizes of int64 and long, to pick proper printf format 
 * int64和long数据类型的size，为了进行更准确的打印输出。
 */
#define SZ_INT64 8
#define SZ_LONG 8

/* 字节顺序 */
/* #undef TEST_BIG */

/* 特性 */
/* #undef PODOFO_NO_FONTMANAGER */

/* 定义需要的依赖库 */
/* jpeg lib*/
#define PODOFO_HAVE_JPEG_LIB
/* png lib, 需要zlib库*/
#define PODOFO_HAVE_PNG_LIB
/* tiff lib*/
#define PODOFO_HAVE_TIFF_LIB
/* fontconfig lib */
#define PODOFO_HAVE_FONTCONFIG
/* #undef PODOFO_HAVE_LUA */
/* #undef PODOFO_HAVE_BOOST */
/* #undef PODOFO_HAVE_CPPUNIT */
/* openssl lib */
#define PODOFO_HAVE_OPENSSL
/* #undef PODOFO_HAVE_LIBIDN */

/* 平台怪癖 */
#define PODOFO_JPEG_RUNTIME_COMPATIBLE

#endif
