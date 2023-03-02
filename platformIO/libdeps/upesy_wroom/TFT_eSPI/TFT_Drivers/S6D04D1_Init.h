
// This is the command sequence that initialises the ST7796 driver
//
// This setup information uses simple 8 bit SPI writecommand() and writedata() functions
//
// See ST7735_Setup.h file for an alternative format

#define TFT_INIT_DELAY 0

#if 1
	writecommand(0xf4);
	writedata(0x59);
	writedata(0x59);
	writedata(0x52);
	writedata(0x52);
	writedata(0x11);

	writecommand(0xf5);
	writedata(0x12);
	writedata(0x00);
	writedata(0x0b);
	writedata(0xf0);
	writedata(0x00);

	delay(10);

	writecommand(0xf3);
	writedata(0xff);
	writedata(0x2a);
	writedata(0x2a);
	writedata(0x0a);
	writedata(0x22);
	writedata(0x72);
	writedata(0x72);
	writedata(0x20);

	writecommand(0x3a);
	writedata(0x05);

	writecommand(0xf2);
	writedata(0x10);
	writedata(0x10);
	writedata(0x01);
	writedata(0x08);
	writedata(0x08);
	writedata(0x08);
	writedata(0x08);
	writedata(0x00);
	writedata(0x00);//04
	writedata(0x1a);
	writedata(0x1a);

	writecommand(0xf6);
	writedata(0x00);
	writedata(0x80);//88
	writedata(0x10);

	writecommand(0xf7);
	writedata(0x0d);
	writedata(0x00);
	writedata(0x03);
	writedata(0x0e);
	writedata(0x1c);
	writedata(0x29);
	writedata(0x2d);
	writedata(0x34);
	writedata(0x0e);
	writedata(0x12);
	writedata(0x24);
	writedata(0x1e);
	writedata(0x07);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xf8);
	writedata(0x0d);
	writedata(0x00);
	writedata(0x03);
	writedata(0x0e);
	writedata(0x1c);
	writedata(0x29);
	writedata(0x2d);
	writedata(0x34);
	writedata(0x0e);
	writedata(0x12);
	writedata(0x24);
	writedata(0x1e);
	writedata(0x07);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xf9);
	writedata(0x1e);
	writedata(0x00);
	writedata(0x0a);
	writedata(0x19);
	writedata(0x23);
	writedata(0x31);
	writedata(0x37);
	writedata(0x3f);
	writedata(0x01);
	writedata(0x03);
	writedata(0x16);
	writedata(0x19);
	writedata(0x07);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xfA);
	writedata(0x0D);
	writedata(0x11);
	writedata(0x0A);
	writedata(0x19);
	writedata(0x23);
	writedata(0x31);
	writedata(0x37);
	writedata(0x3f);
	writedata(0x01);
	writedata(0x03);
	writedata(0x16);
	writedata(0x19);
	writedata(0x07);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xfB);
	writedata(0x0D);
	writedata(0x00);
	writedata(0x03);
	writedata(0x0E);
	writedata(0x1C);
	writedata(0x29);
	writedata(0x2D);
	writedata(0x34);
	writedata(0x0E);
	writedata(0x12);
	writedata(0x24);
	writedata(0x1E);
	writedata(0x07);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xfC);
	writedata(0x0D);
	writedata(0x00);
	writedata(0x03);
	writedata(0x0E);
	writedata(0x1C);
	writedata(0x29);
	writedata(0x2D);
	writedata(0x34);
	writedata(0x0E);
	writedata(0x12);
	writedata(0x24);
	writedata(0x1E);
	writedata(0x07);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xFD);
	writedata(0x11);
	writedata(0x01);

	writecommand(0x36);
	writedata(0x48);

	writecommand(0x35);
	writedata(0x00);

	writecommand(0x2A);
	writedata(0x00);
	writedata(0x00);
	writedata(0x00);
	writedata(0xEF);

	writecommand(0x2B);
	writedata(0x00);
	writedata(0x00);
	writedata(0x01);
	writedata(0x8F);

	writecommand(0xF1);
	writedata(0x5A);

	writecommand(0xFF);
	writedata(0x00);
	writedata(0x00);
	writedata(0x00);
	writedata(0x40);

	writecommand(0x11);

	delay(120);

	writecommand(0xF1);
	writedata(0x00);

	writecommand(0x29);
	delay(40);
#else
{
	writecommand(0xE0);//MDDI Control 1 (E0h)
	writedata(0x01);//VWAKE_EN=1, When VWAKE_EN is 1, client initiated wake-up is enabled

	writecommand(0x11);//Sleep Out (11h)
	delay(150);

	writecommand(0xF3);//Power Control Register (F3h)
	writedata(0x01);//VCI1_EN
	writedata(0x00);//
	writedata(0x00);//
	writedata(0x0C);//Do not set any higher VCI1 level than VCI -0.15V. 0C 0A
	writedata(0x03);//VGH和VGL 01 02VGH=6VCI1,VGL=-4VCI1.
	writedata(0x75);//
	writedata(0x75);//
	writedata(0x30);//

	writecommand(0xF4);//VCOM Control Register (F4h)
	writedata(0x4C);//
	writedata(0x4C);//
	writedata(0x44);//
	writedata(0x44);//
	writedata(0x22);//

	writecommand(0xF5);//Source Output Control Register (F5h)
	writedata(0x10);//
	writedata(0x22);//
	writedata(0x05);//
	writedata(0xF0);//
	writedata(0x70);//
	writedata(0x1F);//
	delay(30);//

	writecommand(0xF3);//Power Control Register (F3h)
	writedata(0x03);//

	delay(30);

	writecommand(0xF3);//Power Control Register (F3h)
	writedata(0x07);//

	delay(30);

	writecommand(0xF3);//Power Control Register (F3h)
	writedata(0x0F);//

	delay(30);

	writecommand(0xF3);//Power Control Register (F3h)
	writedata(0x1F);//

	delay(30);

	writecommand(0xF3);//Power Control Register (F3h)
	writedata(0x7F);//

	delay(30);

	writecommand(0xF7);//Positive Gamma Control Register for Red (F7h)
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	writedata(0x05);
	writedata(0x0D);
	writedata(0x1F);
	writedata(0x26);
	writedata(0x2D);
	writedata(0x14);
	writedata(0x15);
	writedata(0x26);
	writedata(0x20);
	writedata(0x01);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xF8);//Negative Gamma Control Register for Red
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	writedata(0x00);
	writedata(0x07);
	writedata(0x1E);
	writedata(0x2A);
	writedata(0x32);
	writedata(0x10);
	writedata(0x16);
	writedata(0x36);
	writedata(0x3C);
	writedata(0x3B);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xF9);//Positive Gamma Control Register for Green
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	writedata(0x05);
	writedata(0x0D);
	writedata(0x1F);
	writedata(0x26);
	writedata(0x2D);
	writedata(0x14);
	writedata(0x15);
	writedata(0x26);
	writedata(0x20);
	writedata(0x01);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xFA);//Negative Gamma Control Register for Green
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	writedata(0x00);
	writedata(0x07);
	writedata(0x1E);
	writedata(0x2A);
	writedata(0x32);
	writedata(0x10);
	writedata(0x16);
	writedata(0x36);
	writedata(0x3C);
	writedata(0x3B);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xFB);//Positive Gamma Control Register for Blue
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	writedata(0x05);
	writedata(0x0D);
	writedata(0x1F);
	writedata(0x26);
	writedata(0x2D);
	writedata(0x14);
	writedata(0x15);
	writedata(0x26);
	writedata(0x20);
	writedata(0x01);
	writedata(0x22);
	writedata(0x22);

	writecommand(0xFC);//Negative Gamma Control Register for Blue
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	writedata(0x00);
	writedata(0x07);
	writedata(0x1E);
	writedata(0x2A);
	writedata(0x32);
	writedata(0x10);
	writedata(0x16);
	writedata(0x36);
	writedata(0x3C);
	writedata(0x3B);
	writedata(0x22);
	writedata(0x22);

	//writecommand(0x35);
	writecommand(0x34); //Tearing Effect Line OFF (34h)

	writecommand(0x36);//Memory Data Access Control (36h)
	writedata(0x80);//48);//08

	writecommand(0x3A);//Interface Pixel Format (3Ah)
	writedata(0x05);//101-16bit/pixel
	//ReadReg(0x0C, array, 1);//

	writecommand(0xF2);//Display Control Register (F2h)
	writedata(0x17);
	writedata(0x17);
	writedata(0x0F);
	writedata(0x08);
	writedata(0x08);
	writedata(0x00);
	writedata(0x00);
	writedata(0x00);
	writedata(0x06);
	writedata(0x13);
	writedata(0x00);

	writecommand(0xF6);//Interface Control Register (F6h)
	writedata(0x00);
	writedata(0x80);
	writedata(0x00);
	writedata(0x00);
	//ReadReg(0xF6, array, 4);//

	writecommand(0xFD);//Gate Control Register (FDh)
	writedata(0x02);
	writedata(0x01); //240*400

	delay(20);

	writecommand(0x29);//Display On (29h)
	//ReadReg(0x0B, array, 1);//read MADCTL
	delay(20);                                      	
}
#endif