#ifndef _SD_H_
#define _SD_H_	 
#include "stm32f10x.h"
#include "spi.h"
/******************************************************************* 				
������ʹ�õ�Ӳ���ӿڣ�
SD������SPI�ӿ�ͨѶ

DATA1--PC9

PG6
DATA2----------SD_DT2
CD/DATA3-------SD_DT3
CMD------------SD_CMD
//SPI�ӿ�
CS--------------PD2(Ƭѡ��)
CLK----SD_SCK---PB13(ʱ����)
DATA0--SD_DT0---PB14(���)
DATA1--SD_DT1---PB15(����)
********************************************************************/
				
// SD�����Ͷ���  
#define SD_TYPE_ERR     0X00
#define SD_TYPE_MMC     0X01
#define SD_TYPE_V1      0X02
#define SD_TYPE_V2      0X04
#define SD_TYPE_V2HC    0X06	   

// SD��ָ���  	   
#define CMD0    0       //����λ
#define CMD1    1
#define CMD8    8       //����8 ��SEND_IF_COND
#define CMD9    9       //����9 ����CSD����
#define CMD10   10      //����10����CID����
#define CMD12   12      //����12��ֹͣ���ݴ���
#define CMD16   16      //����16������������С Ӧ����0x00
#define CMD17   17      //����17��������
#define CMD18   18      //����18����Multi ����
#define CMD23   23      //����23�����ö�����д��ǰԤ�Ȳ���N��block
#define CMD24   24      //����24��д����
#define CMD25   25      //����25��д�������
#define CMD41   41      //����41��Ӧ����0x00
#define CMD55   55      //����55��Ӧ����0x01
#define CMD58   58      //����58����OCR��Ϣ
#define CMD59   59      //����59��ʹ��/��ֹCRC��Ӧ����0x00��

/*����д���Ӧ������*/
#define SD_DATA_OK                0x05
#define SD_DATA_CRC_ERROR         0x0B
#define SD_DATA_WRITE_ERROR       0x0D
#define SD_DATA_OTHER_ERROR       0xFF

/*SD����Ӧ�����*/
#define SD_RESPONSE_NO_ERROR      0x00   //��Ӧ����
#define SD_IN_IDLE_STATE          0x01   //����״̬
#define SD_ERASE_RESET            0x02   //������λ
#define SD_ILLEGAL_COMMAND        0x04
#define SD_COM_CRC_ERROR          0x08
#define SD_ERASE_SEQUENCE_ERROR   0x10
#define SD_ADDRESS_ERROR          0x20
#define SD_PARAMETER_ERROR        0x40
#define SD_RESPONSE_FAILURE       0xFF
 							   						 					    	  
#define SD_CS_H()	GPIOB->BSRR |=GPIO_Pin_12
#define SD_CS_L()	GPIOB->BRR  |=GPIO_Pin_12

extern u8  SD_Type; //SD��������

//���������� 
u8 SD_SPI_Read_Write_Byte(u8 data);               //�ײ�ӿڣ�SPI��д�ֽں���
u8 SD_Wait_Ready(void);							           		//�ȴ�SD��׼��
u8 SD_Get_Ack(u8 Response);					       				//���Ӧ��
u8 SD_Init(void);							            				//��ʼ��
u8 SD_Read_Data(u8*buf,u32 sector,u32 cnt);		    //����
u8 SD_Write_Data(u8*buf,u32 sector,u32 cnt);		  //д��
u32 SD_Get_Sector_Count(void);   					        //��������
u8 SD_GetCID(u8 *cid_data);                       //��SD��CID
u8 SD_GetCSD(u8 *csd_data);                       //��SD��CSD
void SD_SPI_Init(void);		//��ʼ��IO
#endif

