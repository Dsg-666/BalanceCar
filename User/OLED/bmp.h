#ifndef __BMP_H
#define __BMP_H
#include "sys.h"

u8 BMP_SHARK[] = 	 	 	/*--  ����x�߶�=125x48  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xE0,0xF0,0xF0,0x78,0x38,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0x78,
0x7C,0x3E,0x1E,0x0F,0x07,0x07,0xC3,0xFF,0xFF,0x7F,0x07,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0xC0,0xC0,0xE0,0xE0,0x70,0x70,0x38,
0x38,0x98,0x9C,0xCC,0xEE,0x7E,0x3C,0x00,0x0F,0xFF,0xFE,0x8E,0x3C,0xF8,0xF0,0xC0,
0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0xFF,0x07,0x03,0x79,0x7C,0x6E,0x67,0x7F,0x7F,
0x78,0x00,0xFC,0xFF,0xFF,0x07,0x00,0xF0,0xF0,0xF0,0xF0,0x70,0x70,0x70,0x60,0xE0,
0xE0,0xC0,0x80,0x80,0x00,0x00,0xF0,0xF0,0x70,0x70,0xE0,0xE0,0xC0,0x80,0x80,0x80,
0xC0,0xC0,0xE0,0xE0,0x70,0x70,0x30,0x38,0x38,0x38,0x18,0x9C,0xCC,0xCE,0xEE,0xEE,
0x76,0x76,0x37,0x3F,0x3F,0x1B,0x1F,0x0F,0x0F,0x0F,0x0F,0x07,0x07,0x07,0x07,0x07,
0x03,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x38,0x7C,0x7C,0x7E,
0x7E,0x7F,0x77,0x73,0x73,0x31,0x31,0x38,0x18,0x1C,0x8C,0xFC,0xFC,0xC1,0x63,0x77,
0x3E,0xBC,0x98,0xC0,0xE0,0x70,0x39,0x9F,0xCF,0xE0,0x6F,0x67,0xE7,0xE6,0x8E,0x3E,
0xFC,0xF8,0xC7,0x1F,0x3F,0x38,0x30,0x3F,0x3F,0x07,0x03,0xFF,0xFF,0xFF,0x00,0xFF,
0xFF,0xFF,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0xE0,0xE0,0xE0,0xE0,0xF0,0x71,0x7B,0x3F,
0x3F,0x1F,0x00,0xFF,0xFF,0x80,0xC0,0xF0,0xFB,0x3F,0x1F,0x1F,0x3B,0x79,0x71,0x70,
0xE0,0xE0,0xC0,0xDC,0xBE,0xFE,0xF7,0xE7,0xC3,0x83,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x03,0x03,
0x03,0x03,0x03,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x03,0x1F,0xFF,0xF8,0x83,0xFF,
0xFE,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x0F,0x1F,0x3F,0x00,
0x00,0x0F,0x0F,0x07,0x00,0x01,0x01,0x01,0x03,0x03,0x07,0x07,0x06,0x06,0x00,0x00,
0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x01,0x03,0x03,0x03,0x07,0x07,0x07,0x0F,0x0E,0x1C,0x1C,0x18,0x38,0x38,0x30,0x30,
0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x07,0x07,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
u8 BMP__[]=
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
}; 	// �ո�

u8 BMP_Blue[] =
{/*--  ������־ ����x�߶�=16x16  --*/
0x00,0x00,0x00,0x08,0x10,0x20,0x40,0x80,0xFF,0x82,0x44,0x28,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x10,0x08,0x04,0x02,0x01,0xFF,0x41,0x22,0x14,0x08,0x00,0x00,0x00,
};
u8 BMP_Blue_1[] =
{/*--  ������־ ����x�߶�=16x16  --*/
0x00,0x40,0x80,0x08,0x30,0xC0,0x02,0x0C,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x02,0x01,0x10,0x0C,0x03,0x40,0x30,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

u8 BMP_Battary[] =
{/*--  δ���ر�־ ����x�߶�=16x16  --*/
0x00,0x00,0x00,0xFC,0x04,0x44,0x26,0x16,0x16,0xA6,0x44,0x04,0xFC,0x00,0x00,0x00,
0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x40,0x57,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,
};
u8 BMP_T[] =
{/*--  �¶��쳣��־ ����x�߶�=16x16  --*/
0x00,0x0E,0x0A,0x0E,0x00,0xF0,0x08,0x04,0x02,0xFA,0xFA,0x02,0x04,0x08,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0F,0x10,0x20,0x40,0x4C,0x4D,0x40,0x20,0x10,0x00,0x00,
};

u8 BMP1[] =
{
/*--  ����ѧԺ  --*/
/*--  ����_GB231212;  �������¶�Ӧ�ĵ���Ϊ����x��=64x16   --*/
0x00,0x00,0xE4,0xAA,0xB1,0xA0,0xA4,0xEA,0xB1,0xA0,0xA4,0xAA,0xF1,0x00,0x00,0x00,
0x10,0x60,0x02,0x8C,0x00,0x88,0x88,0xFF,0x88,0x88,0x00,0xFE,0x22,0x22,0xFE,0x00,
0x40,0x30,0x11,0x96,0x90,0x90,0x91,0x96,0x90,0x90,0x98,0x14,0x13,0x50,0x30,0x00,
0x00,0xFE,0x22,0x5A,0x86,0x10,0x0C,0x24,0x24,0x25,0x26,0x24,0x24,0x14,0x0C,0x00,
0x88,0x88,0x4B,0x4A,0x2A,0x1A,0x0A,0xFF,0x0A,0x1A,0x2A,0x4A,0x4B,0x88,0x88,0x00,
0x04,0x04,0x7E,0x01,0x00,0x1F,0x08,0x08,0x08,0x9F,0x60,0x1F,0x42,0x82,0x7F,0x00,
0x04,0x04,0x04,0x04,0x04,0x44,0x84,0x7E,0x06,0x05,0x04,0x04,0x04,0x04,0x04,0x00,
0x00,0xFF,0x04,0x08,0x07,0x80,0x41,0x31,0x0F,0x01,0x01,0x3F,0x41,0x41,0x71,0x00,
}; 	

u8 BMP2[] =
{/*--  �� ΰ  --*/
/*--  ����_GB231212;  �������¶�Ӧ�ĵ���Ϊ����x��=32x16   --*/
0x00,0x12,0x22,0x42,0x82,0x62,0x1E,0x00,0x00,0xFE,0x02,0x22,0xDA,0x06,0x00,0x00,
0x00,0x80,0x60,0xF8,0x07,0x08,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0x08,0x00,
0x20,0x10,0x08,0x06,0x01,0x06,0x18,0x00,0x00,0xFF,0x08,0x10,0x08,0x07,0x00,0x00,
0x01,0x00,0x00,0xFF,0x00,0x02,0x02,0x02,0x02,0xFF,0x02,0x02,0x12,0x22,0x1E,0x00,
}; 	
u8 BMP3[] =
{
/*--  16  --*/
/*--  ����_GB231212;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,
0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,	
0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,
0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00,
};

u8 BMP4[] =
{
/*--  ��������  --*/
/*--  ����_GB231212;  �������¶�Ӧ�ĵ���Ϊ����x��=64x16   --*/
0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x88,0xF8,0x00,0x00,0x00,
0x20,0x10,0x4C,0x47,0x54,0x54,0x54,0x54,0x54,0x54,0x54,0xD4,0x04,0x04,0x00,0x00,	
0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x00,	
0x84,0x84,0xFC,0x84,0x84,0x00,0xF8,0x00,0xFF,0x00,0x84,0x84,0xFC,0x84,0x84,0x00,	
0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x7F,0x88,0x88,0x88,0x88,0x9F,0x80,0xF0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x30,0x40,0xF0,0x00,
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,
0x10,0x30,0x1F,0x08,0x88,0x42,0x21,0x18,0x07,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,
};

u8 BMP5[] =
{
/*--  ѧ��  --*/
/*--  ����_GB231212;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x40,0x30,0x11,0x96,0x90,0x90,0x91,0x96,0x90,0x90,0x98,0x14,0x13,0x50,0x30,0x00,
0x80,0x80,0x80,0xBE,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xBE,0x80,0x80,0x80,0x00,	
0x04,0x04,0x04,0x04,0x04,0x44,0x84,0x7E,0x06,0x05,0x04,0x04,0x04,0x04,0x04,0x00,
0x00,0x00,0x00,0x06,0x05,0x04,0x04,0x04,0x44,0x84,0x44,0x3C,0x00,0x00,0x00,0x00,
};
u8 BMP6[] =
{
/*--  16011055  --*/
/*--  ����_GB231212;  �������¶�Ӧ�ĵ���Ϊ����x��=64x16   --*/
0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,	
0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,	
0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,	
0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,	
0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00,
0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,
0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,
0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00,0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00,
}; 		


#endif

