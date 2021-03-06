/*
*********************************************************************************************************
*
*	模块名称 : I2C总线驱动模块
*	文件名称 : sim_i2c.c
*	版    本 : V2.0
*	说    明 : 用gpio模拟i2c总线, 适用于STM32F4|F1系列CPU。
*
*	修改记录 :
*		版本号  日期          作者      说明
*		V1.0    2015-05-21    armfly    正式发布
* 	 	V2.0 	2019-011-15   dsg       修改，增加功能函数
*	Copyright (C), 2015-2019, 小鲨鱼电子 2720199045@qq.com
*********************************************************************************************************
*/
#include "sim_i2c.h"
#include "delay.h"



/*
*********************************************************************************************************
*	函 数 名: i2c_Speed
*	功能说明: I2C总线位延迟，最快400KHz
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
static void i2c_Speed(void)
{
	uint8_t i;

	/*　
		CPU主频168MHz时，在内部Flash运行, MDK工程不优化。用台式示波器观测波形。
		循环次数为5时，SCL频率 = 1.78MHz (读耗时: 92ms, 读写正常，但是用示波器探头碰上就读写失败。时序接近临界)
		循环次数为10时，SCL频率 = 1.1MHz (读耗时: 138ms, 读速度: 118724B/s)
		循环次数为28时，SCL频率 = 400KHz

		上拉电阻选择2.2K欧时，SCL上升沿时间约0.5us，如果选4.7K欧，则上升沿约1us

		实际应用选择400KHz左右的速率即可
	*/
	for (i = 0; i < 28; i++);
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Start
*	功能说明: CPU发起I2C总线启动信号
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_Start(void)
{
	/* 当SCL高电平时，SDA出现一个下跳沿表示I2C总线启动信号 */
	I2C_SDA_1(); 	//sda线输出
	I2C_SCL_1();
	i2c_Speed();
	I2C_SDA_0();
	i2c_Speed();
	I2C_SCL_0(); 	//钳住I2C总线，准备发送或接收数据 
	i2c_Speed();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Start
*	功能说明: CPU发起I2C总线停止信号
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_Stop(void)
{
	/* 当SCL高电平时，SDA出现一个上跳沿表示I2C总线停止信号 */
	I2C_SDA_0();
	I2C_SCL_1();
	i2c_Speed();
	I2C_SDA_1();
	i2c_Speed();
}

/*
*********************************************************************************************************
*	函 数 名: bsp_InitI2C
*	功能说明: 配置I2C总线的GPIO，采用模拟IO的方式实现
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void SIM_I2C_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_I2C_PORT, ENABLE);	/* 打开GPIO时钟 */

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;	/* 开漏输出模式 */
	
	GPIO_InitStructure.GPIO_Pin = PIN_I2C_SCL;
	GPIO_Init(PORT_I2C_SCL, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = PIN_I2C_SDA;
	GPIO_Init(PORT_I2C_SDA, &GPIO_InitStructure);

	/* 给一个停止信号, 复位I2C总线上的所有设备到待机模式 */
	i2c_Stop();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_SendByte
*	功能说明: CPU向I2C总线设备发送8bit数据
*	形    参:  _ucByte ： 等待发送的字节
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_SendByte(uint8_t _ucByte)
{
	u8 i;

	/* 先发送字节的高位bit7 */
	for (i = 0; i < 8; i++)
	{
		if (_ucByte & 0x80)
		{
			I2C_SDA_1();
		}
		else
		{
			I2C_SDA_0();
		}
		i2c_Speed();
		I2C_SCL_1();
		i2c_Speed();
		I2C_SCL_0();
		if (i == 7)
		{
			 I2C_SDA_1(); // 释放总线
		}
		_ucByte <<= 1;	/* 左移一个bit */
		i2c_Speed();
	}
}

/*
*********************************************************************************************************
*	函 数 名: i2c_ReceiveByte
*	功能说明: CPU从I2C总线设备接收8bit数据
*	形    参:  无
*	返 回 值: 读到的数据
*********************************************************************************************************
*/
u8 i2c_ReceiveByte(void)
{
	u8 i;
	u8 value;

	/* 读到第1个bit为数据的bit7 */
	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		I2C_SCL_1();
		i2c_Speed();
		if (I2C_SDA_READ())
		{
			value++;
		}
		I2C_SCL_0();
		i2c_Speed();
	}
	return value;
}

/*
*********************************************************************************************************
*	函 数 名: Slave_ACK
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参: 无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
u8 Slave_ACK(void)
{
	u8 ucErrTime=0;
	I2C_SDA_1();
	i2c_Speed(); 	   
	I2C_SCL_1();  
	i2c_Speed(); 	 
	while( I2C_SDA_READ() ) 	/*等待应答*/
	{
		ucErrTime++;
		if(ucErrTime>250) 	
		{
			i2c_Stop();
			return 1;
		}
	}
	I2C_SCL_0();  	   
	return 0;   
}
/*
*********************************************************************************************************
*	函 数 名: Mster_ACK
*	功能说明: CPU产生一个ACK信号
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void Mster_ACK(void)
{
	I2C_SCL_0();  
    i2c_Speed();  
	I2C_SDA_0();	/* CPU驱动SDA = 0 */
	i2c_Speed();
	I2C_SCL_1();	/* CPU产生1个时钟 */
	i2c_Speed();
	I2C_SCL_0();
	i2c_Speed();
	I2C_SDA_1();	/* CPU释放SDA总线 */
}

/*
*********************************************************************************************************
*	函 数 名: Mster_NOACK
*	功能说明: CPU产生1个NACK信号
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void Mster_NOACK(void)
{
	I2C_SCL_0();  
    i2c_Speed(); 
	I2C_SDA_1();	/* CPU驱动SDA = 1 */
	i2c_Speed();
	I2C_SCL_1();	/* CPU产生1个时钟 */
	i2c_Speed();
	I2C_SCL_0();
	i2c_Speed();
	I2C_SDA_1(); 	/* CPU释放SDA总线 */
}
/*
*********************************************************************************************************
*	函 数 名: i2c_CheckDevice
*	功能说明: 检测I2C总线设备，CPU向发送设备地址，然后读取设备应答来判断该设备是否存在
*	形    参:  _Address：设备的I2C总线地址
*	返 回 值: 返回值 0 表示正确， 返回1表示未探测到
*********************************************************************************************************
*/
u8 i2c_CheckDevice(u8 _Address)
{
	u8 ucAck;

	if (I2C_SDA_READ() && I2C_SCL_READ())
	{
		i2c_Start();		/* 发送启动信号 */

		/* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
		i2c_SendByte(_Address | I2C_WR);
		ucAck = Slave_ACK();	/* 检测设备的ACK应答 */

		i2c_Stop();			/* 发送停止信号 */

		return ucAck;
	}
	return 1;	/* I2C总线异常 */
}
/*
*********************************************************************************************************
*	函 数 名: I2C_WriteByte
*	功能说明: 指定地址写一个字节
*	形    参:  address 地址	 	data_value 写入字节
*	返 回 值: 无
*********************************************************************************************************
*/
void I2C_WriteByte(u8 address,u8 data_value)
{
	i2c_Start();
	i2c_SendByte(0xa0);
	Slave_ACK();
	i2c_SendByte(address);
	Slave_ACK();
	i2c_SendByte(data_value);
	Slave_ACK();
	i2c_Stop();
}
/*
*********************************************************************************************************
*	函 数 名: I2C_ReadByte
*	功能说明: 指定地址读一个字节
*	形    参:  address 地址	 	
*	返 回 值: data_value 读取到的字节
*********************************************************************************************************
*/
u8 I2C_ReadByte(u8 address)  
{  
	u8 data_value;
	i2c_Start();
	i2c_SendByte(0xa0);
	Slave_ACK();
	i2c_SendByte(address);
	Slave_ACK();

	i2c_Start();
	i2c_SendByte(0xa1);
	Slave_ACK();
	data_value=i2c_ReceiveByte(); 
	Mster_NOACK();
	i2c_Stop();
	
	return data_value;
}

/**************************实现函数********************************************
*函数原型:	u8 I2C_WriteBytes(u8 dev, u8 reg, u8 length, u8* data)
*功　　能:	将多个字节写入指定设备 指定寄存器
输入	 	dev  目标设备地址
			reg	  寄存器地址
			length 要写的字节数
			*data  将要写的数据的首地址
返回    	返回是否成功
*******************************************************************************/ 
u8 I2C_WriteBytes(u8 dev, u8 reg, u8 length, u8  *data)
{
  
 	u8 count = 0;
	i2c_Start();
	i2c_SendByte(dev);	   //发送设备地址
	Slave_ACK();
	i2c_SendByte(reg);   //发送地址
    Slave_ACK();
	
	for(count=0;count<length;count++)
	{
		i2c_SendByte(data[count]); 
		Slave_ACK(); 
	 }
	i2c_Stop();//产生一个停止条件
	 
    return 1; //status == 0;
}
/**************************实现函数********************************************
*函数原型:	u8 I2C_ReadBytes(u8 dev, u8 reg, u8 length, u8 *data)
*功　　能:	读取指定设备 指定寄存器的 length个值
输入	 	dev  目标设备地址
			reg	  寄存器地址
			length 要读的字节数
			*data  读出的数据将要存放的指针
返回    	读出来的字节数量
*******************************************************************************/ 
u8 I2C_ReadBytes(u8 dev, u8 reg, u8 length, u8 *data)
{
    u8 count = 0;
	i2c_Start();
	i2c_SendByte(dev);	   //发送设备地址
	Slave_ACK();
	i2c_SendByte(reg);   //发送地址
    Slave_ACK();	
	
	i2c_Start();
	i2c_SendByte(dev+1);  //进入接收模式	
	Slave_ACK();
	
    for(count=0;count<length;count++)
	{
		if(count!=length-1)
		{
			data[count]=i2c_ReceiveByte();
			Mster_ACK();  //带ACK的读数据
			
		}
		else  
		{
			data[count]=i2c_ReceiveByte();
			Mster_NOACK();//最后一个字节NACK
		}	 
	}
    i2c_Stop();//产生一个停止条件
    return count;
}

/****************************************** (END OF FILE) **********************************************/


