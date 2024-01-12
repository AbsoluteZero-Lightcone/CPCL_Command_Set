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
			//下发打印命令
			//使打印机控制状态结束，并打印出控制部分的内容。
			//[注意]
			//1.PRINT后面必须加个回车。
			//2.必须和<!>Commands配合


			SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(PageWidth, PW, width)
			//设置打印页面宽度
			//width：页面宽度点数（8点/mm）
			//[注意]
			//宽度以打印机芯左边为原点算起的。
			//超出打印宽度的数据将被忽略。

			INSTANT_COMMAND_OUTPUT_DECLARATION(Locate, FORM)
			//设置打印结束后，并走纸到定位点。
			//[注意]必须和<BAR-SENSE>/<GAP-SENSE>指令配合












			DOUBLE_PARAM_COMMAND_OUTPUT_DECLARATION(SETMAG, SETMAG, w, h)
			//对字符字体进行放大
			//w：对字符的宽度进行放大，有效的数值为1-16。
			//h：对字符的高度进行放大，有效的数值为1-16。
			//[注意]
			//当使用SETMAG指令后，字体SIZE标识将无效。仅对其基本字体进行放大
			//当w或者h=0时，字体的宽度或者高度还原到基本字体大小。


			INSTANT_COMMAND_OUTPUT_DECLARATION(BarSense_Right, BAR - SENSE)
			/*[描述]
			设置检测模式为右黑标，当和FORM配合使用后，打印完后走纸到右黑标处停止。
			[注意]
			●
			必须和FORM配合使用*/










INSTANT_COMMAND_OUTPUT_DECLARATION(GapSense, GAP - SENSE)
/*[描述]
设置检测模式为标签，当和FORM配合使用后，打印完后走纸到标签处停止。
[注意]
●
必须和FORM配合使用*/


INSTANT_COMMAND_OUTPUT_DECLARATION(Left_align, LEFT)
/*[描述]
设置打印对齐方式为左对齐
[注意]
●
坐标方向是从左到右。且X坐标有效。*/
INSTANT_COMMAND_OUTPUT_DECLARATION(Center_align, CENTER)
/*[描述]
设置打印对齐方式为中心对齐
[注意]
●
只对字符，条码有效，对线段BOX指令无效
●
当X坐标为0时，字符和条码沿坐标原点对称打印。*/
INSTANT_COMMAND_OUTPUT_DECLARATION(Right_align, RIGHT)
/*[描述]
设置打印对齐方式为右对齐
[注意]
●
字符条码的X坐标失效，总是以最右边为基准，靠右边打印*/

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(setPrintSpeed, SPEED, speed_level)
/*{speedlevel}:0-5的数值，0是最慢的速度。
[描述]
设置打印速度
[注意]
●
打印速度越慢，打印质量越高。
●
必须每一个标签指定一个打印速度，当指定后，该标签内的其他速度指令无效。
●
该指令不改变打印机通过屏幕设置的速度。*/






SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(PREFEED, PREFEED, length)
/*{length}:走纸距离点数。8点=1mm
[描述]
设置打印之前走纸距离。*/
SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(POSTFEED, POSTFEED, length)
/*{length}:走纸距离点数。8点=1mm
[描述]
设置打印之后走纸距离。*/
SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(SETBOLD, SETBOLD, val)
/*{level}0取消粗体模式
{level}>1设置打印字体为粗体
[描述]
设置打印的字符为粗体,*/

INSTANT_COMMAND_OUTPUT_DECLARATION(PaceControl, PACE)
//批量打印时，第一张打印后，需要按走纸键才能继续打印第二张

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(WAIT, WAIT, time)
/*{delay-time}:延时1/8的时间
[描述]
打印一张后，需要等待设置的时间过后才打印第二张。*/

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(aetSpace, SETSP, val)
/*{spacing}:字符与字符之间的间隔大小，n*0.125mm
[描述]
设置字符间距*/

SINGLE_PARAM_COMMAND_OUTPUT_DECLARATION(BACKGROUND, BACKGROUND, val)
/*{backgroundlevel}:灰度等级，0-255
[描述]
设置水印文字的灰度*/

INSTANT_COMMAND_OUTPUT_DECLARATION(Reprint, REPRINT)
//将此页面打印如果遇到缺纸等故障将自动补打。[注意]只针对XT423机型







void Count(uint16_t long_param)const;
		//num：±65535内的任意整数，对打印数字进行自动增减。
		// [注意]
		// 1.只能对数字部分进行增减
		// 2.有进位或借位时，如果进位或者借位不是数字时，该进位或者借位忽略。



void BarSense_Left()const;
		/*[描述]
		设置检测模式为左黑标，当和FORM配合使用后，打印完后走纸到左黑标处停止。
		[注意]
		●
		必须和FORM配合使用*/


void UnderlineCmd(Switch_t SWITCH)const;
		/*“ON”：打开下划线打印模式
		“OFF”：关闭下划线打印模式
		[描述]
		设置是否打印下划线*/

	};


}


#endif


