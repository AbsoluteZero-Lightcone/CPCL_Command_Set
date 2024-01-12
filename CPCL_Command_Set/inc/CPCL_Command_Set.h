#ifndef __CPCL_COMMAND_SET
#define __CPCL_COMMAND_SET

#include ".\inc\CPCL_Command_Set_TypeDef.h"


extern "C" {

	class CPCL_Basic_Object {
	protected:
		CPCL_Command_t cmd;
	public:
		Content_t Data = "Basic_Object";
		virtual void updateCmd();
		CPCL_Command_t getFormCmd();
	};

#define OVERLOAD_CONSTRUCTOR_DECLARATION(class_name)\
		class_name();\
		class_name(Content_t t_Data);\
		class_name& operator=(Content_t t_Data);

	class Text :public CPCL_Basic_Object {
	public:
		OVERLOAD_CONSTRUCTOR_DECLARATION(Text)
			Dot_t position_left = 0;
		Dot_t position_top = 0;
		CharRotation_t char_rotation = ROTATION0;
		CharFont_t char_font = FONT0;
		CharSize_t char_size = 1;
		Align_t align = LEFT_ALIGN;
		void updateCmd();
	};

	class AdvancedText :public CPCL_Basic_Object {
	public:
		OVERLOAD_CONSTRUCTOR_DECLARATION(AdvancedText)
			Dot_t position_left = 0;
		Dot_t position_top = 0;
		Dot_t block_width = 100;
		Dot_t block_height = 100;
		CharFont_t char_font = FONT1;
		CharSize_t char_size = 3;
		void updateCmd();
	};

	class CPCL_Core_Object {
	protected:
		CPCL_Command_t cmd;
	public:
		virtual void updateCmd();
		CPCL_Command_t getFormCmd();
	};

	class Page :public CPCL_Core_Object {
	public:
		HorizonalOffset_t offset = 0;
		Resolution_DotPerInch_t horizonalResolution = 200;
		Resolution_DotPerInch_t verticalResolution = 200;
		Length_mm_t height_mm = 30;
		Dot_t height_dot = 240;
		Length_mm_t width_mm = 50;
		Dot_t width_dot = 400;
		Quantity_t quantity = 1;
		void updateCmd();
	};
	class Printer :public CPCL_Core_Object {
	public:
		void updateCmd();
	};

	#define INSTANT_COMMAND_OUTPUT_DECLARATION(				\
		func_name,											\
		instruction)										\
		void func_name()const;

	#define SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(		\
		func_name,											\
		instruction,										\
		param)												\
		void func_name(Param_t param)const;

	#define DOUBLE_PARAM_COMMAND_OUTPUT_DECLARATION(		\
		func_name,											\
		instruction,										\
		param1,												\
		param2)												\
		void func_name(Param_t param1,Param_t param2)const;


	class CPCL_cmd
	{
	public:
		Output_Interface_Callback_Handler output_interface_callback;

		//void Init(Printer& t_printer,Page& t_page);

		void add(CPCL_Basic_Object& object)const;
		void set(CPCL_Core_Object& object)const;

	public:
		INSTANT_COMMAND_OUTPUT_DECLARATION(Print, PRINT)
			//�·���ӡ����
			//ʹ��ӡ������״̬����������ӡ�����Ʋ��ֵ����ݡ�
			//[ע��]
			//1.PRINT�������Ӹ��س���
			//2.�����<!>Commands���


			SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(PageWidth, PW, width)
			//���ô�ӡҳ����
			//width��ҳ���ȵ�����8��/mm��
			//[ע��]
			//����Դ�ӡ��о���Ϊԭ������ġ�
			//������ӡ��ȵ����ݽ������ԡ�

			INSTANT_COMMAND_OUTPUT_DECLARATION(Locate, FORM)
			//���ô�ӡ�����󣬲���ֽ����λ�㡣
			//[ע��]�����<BAR-SENSE>/<GAP-SENSE>ָ�����












			DOUBLE_PARAM_COMMAND_OUTPUT_DECLARATION(SETMAG, SETMAG, w, h)
			//���ַ�������зŴ�
			//w�����ַ��Ŀ�Ƚ��зŴ���Ч����ֵΪ1-16��
			//h�����ַ��ĸ߶Ƚ��зŴ���Ч����ֵΪ1-16��
			//[ע��]
			//��ʹ��SETMAGָ�������SIZE��ʶ����Ч�����������������зŴ�
			//��w����h=0ʱ������Ŀ�Ȼ��߸߶Ȼ�ԭ�����������С��


			INSTANT_COMMAND_OUTPUT_DECLARATION(BarSense_Right, BAR - SENSE)
			/*[����]
			���ü��ģʽΪ�Һڱ꣬����FORM���ʹ�ú󣬴�ӡ�����ֽ���Һڱ괦ֹͣ��
			[ע��]
			��
			�����FORM���ʹ��*/










INSTANT_COMMAND_OUTPUT_DECLARATION(GapSense, GAP - SENSE)
/*[����]
���ü��ģʽΪ��ǩ������FORM���ʹ�ú󣬴�ӡ�����ֽ����ǩ��ֹͣ��
[ע��]
��
�����FORM���ʹ��*/


INSTANT_COMMAND_OUTPUT_DECLARATION(Left_align, LEFT)
/*[����]
���ô�ӡ���뷽ʽΪ�����
[ע��]
��
���귽���Ǵ����ҡ���X������Ч��*/
INSTANT_COMMAND_OUTPUT_DECLARATION(Center_align, CENTER)
/*[����]
���ô�ӡ���뷽ʽΪ���Ķ���
[ע��]
��
ֻ���ַ���������Ч�����߶�BOXָ����Ч
��
��X����Ϊ0ʱ���ַ�������������ԭ��Գƴ�ӡ��*/
INSTANT_COMMAND_OUTPUT_DECLARATION(Right_align, RIGHT)
/*[����]
���ô�ӡ���뷽ʽΪ�Ҷ���
[ע��]
��
�ַ������X����ʧЧ�����������ұ�Ϊ��׼�����ұߴ�ӡ*/

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(setPrintSpeed, SPEED, speed_level)
/*{speedlevel}:0-5����ֵ��0���������ٶȡ�
[����]
���ô�ӡ�ٶ�
[ע��]
��
��ӡ�ٶ�Խ������ӡ����Խ�ߡ�
��
����ÿһ����ǩָ��һ����ӡ�ٶȣ���ָ���󣬸ñ�ǩ�ڵ������ٶ�ָ����Ч��
��
��ָ��ı��ӡ��ͨ����Ļ���õ��ٶȡ�*/






SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(PREFEED, PREFEED, length)
/*{length}:��ֽ���������8��=1mm
[����]
���ô�ӡ֮ǰ��ֽ���롣*/
SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(POSTFEED, POSTFEED, length)
/*{length}:��ֽ���������8��=1mm
[����]
���ô�ӡ֮����ֽ���롣*/
SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(SETBOLD, SETBOLD, val)
/*{level}0ȡ������ģʽ
{level}>1���ô�ӡ����Ϊ����
[����]
���ô�ӡ���ַ�Ϊ����,*/

INSTANT_COMMAND_OUTPUT_DECLARATION(PaceControl, PACE)
//������ӡʱ����һ�Ŵ�ӡ����Ҫ����ֽ�����ܼ�����ӡ�ڶ���

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(WAIT, WAIT, time)
/*{delay-time}:��ʱ1/8��ʱ��
[����]
��ӡһ�ź���Ҫ�ȴ����õ�ʱ�����Ŵ�ӡ�ڶ��š�*/

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(aetSpace, SETSP, val)
/*{spacing}:�ַ����ַ�֮��ļ����С��n*0.125mm
[����]
�����ַ����*/

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(BACKGROUND, BACKGROUND, val)
/*{backgroundlevel}:�Ҷȵȼ���0-255
[����]
����ˮӡ���ֵĻҶ�*/

INSTANT_COMMAND_OUTPUT_DECLARATION(Reprint, REPRINT)
//����ҳ���ӡ�������ȱֽ�ȹ��Ͻ��Զ�����[ע��]ֻ���XT423����







void Count(uint16_t long_param)const;
		//num����65535�ڵ������������Դ�ӡ���ֽ����Զ�������
		// [ע��]
		// 1.ֻ�ܶ����ֲ��ֽ�������
		// 2.�н�λ���λʱ�������λ���߽�λ��������ʱ���ý�λ���߽�λ���ԡ�



void BarSense_Left()const;
		/*[����]
		���ü��ģʽΪ��ڱ꣬����FORM���ʹ�ú󣬴�ӡ�����ֽ����ڱ괦ֹͣ��
		[ע��]
		��
		�����FORM���ʹ��*/


void UnderlineCmd(Switch_t SWITCH)const;
		/*��ON�������»��ߴ�ӡģʽ
		��OFF�����ر��»��ߴ�ӡģʽ
		[����]
		�����Ƿ��ӡ�»���*/

	};


}


#endif


