// Change the width and height if required (defined in portrait mode)
// or use the constructor to over-ride defaults
//#define TFT_WIDTH  240
//#define TFT_HEIGHT 400

// Generic commands used by TFT_eSPI.cpp
#define TFT_NOP     0x00
#define TFT_SWRST   0x01

#define TFT_CASET   0x2A
#define TFT_PASET   0x2B
#define TFT_RAMWR   0x2C
#define TFT_RAMRD   0x2E

#define TFT_MADCTL  0x36
#define TFT_MAD_MY  0x80
#define TFT_MAD_MX  0x40
#define TFT_MAD_MV  0x20
#define TFT_MAD_ML  0x10
#define TFT_MAD_BGR 0x08
#define TFT_MAD_MH  0x04
#define TFT_MAD_RGB 0x00

#if 0
#ifdef TFT_RGB_ORDER
  #if (TFT_RGB_ORDER == 1)
    #define TFT_MAD_COLOR_ORDER TFT_MAD_RGB
  #else
    #define TFT_MAD_COLOR_ORDER TFT_MAD_BGR
  #endif
#else
  #define TFT_MAD_COLOR_ORDER TFT_MAD_BGR
#endif
#endif

#define TFT_INVOFF  0x20
#define TFT_INVON   0x21


// S6D04D1 specific commands
#define S6D04D1_NOP     0x00
#define S6D04D1_SWRESET 0x01
#define S6D04D1_RDDID   0x04
#define S6D04D1_RDDST   0x09

#define S6D04D1_SLPIN   0x10
#define S6D04D1_SLPOUT  0x11
#define S6D04D1_PTLON   0x12
#define S6D04D1_NORON   0x13

#define S6D04D1_RDMODE  0x0A
#define S6D04D1_RDMADCTL  0x0B
#define S6D04D1_RDPIXFMT  0x0C
#define S6D04D1_RDIMGFMT  0x0E
#define S6D04D1_RDSELFDIAG  0x0F

//#define S6D04D1_INVOFF  0x20
//#define S6D04D1_INVON   0x21

#define S6D04D1_DISPOFF 0x28
#define S6D04D1_DISPON  0x29

#define S6D04D1_CASET   0x2A
#define S6D04D1_PASET   0x2B
#define S6D04D1_RAMWR   0x2C
#define S6D04D1_RAMRD   0x2E

#define S6D04D1_PTLAR   0x30
//#define S6D04D1_VSCRDEF 0x33
#define S6D04D1_TEOOFF	0x34
#define S6D04D1_TEOON	0x35
#define S6D04D1_MADCTL  0x36
//#define S6D04D1_VSCRSADD 0x37
#define S6D04D1_IDMOFF	0x38
#define S6D04D1_IDMON	0x39
#define S6D04D1_PIXFMT  0x3A

#define S6D04D1_WRDISBV  0x51
#define S6D04D1_RDDISBV  0x52
#define S6D04D1_WRCTRLD  0x53
#define S6D04D1_RDCTRLD  0x54
#define S6D04D1_WRCABC  0x55
#define S6D04D1_RDCABC  0x56
#define S6D04D1_WRCABCMB  0x5E
#define S6D04D1_RDCABCMB  0x5F

#define S6D04D1_FRMCTR1 0xB1
#define S6D04D1_FRMCTR2 0xB2
#define S6D04D1_FRMCTR3 0xB3
#define S6D04D1_INVCTR  0xB4
#define S6D04D1_DFUNCTR 0xB6

#define S6D04D1_PWCTR1  0xC0
#define S6D04D1_PWCTR2  0xC1
#define S6D04D1_PWCTR3  0xC2

#define S6D04D1_VMCTR1  0xC5
#define S6D04D1_VMCOFF  0xC6

#define S6D04D1_RDID4   0xD3

#define S6D04D1_GMCTRP1 0xE0
#define S6D04D1_GMCTRN1 0xE1

#define S6D04D1_MADCTL_MY  0x80
#define S6D04D1_MADCTL_MX  0x40
#define S6D04D1_MADCTL_MV  0x20
#define S6D04D1_MADCTL_ML  0x10
#define S6D04D1_MADCTL_RGB 0x00
#define S6D04D1_MADCTL_BGR 0x08
#define S6D04D1_MADCTL_MH  0x04
