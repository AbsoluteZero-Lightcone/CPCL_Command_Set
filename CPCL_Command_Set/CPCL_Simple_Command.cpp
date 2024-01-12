#include ".\inc\CPCL_Command_Set.h"

#define INSTANT_COMMAND_OUTPUT_DEFINITION(				\
	func_name,											\
	instruction)										\
	void CPCL_cmd::func_name()const {					\
		output_interface_callback(#instruction);		\
		output_interface_callback("\n");				\
	}

#define SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(			\
	func_name,											\
	instruction,										\
	param)												\
	void CPCL_cmd::func_name(Param_t param)const {		\
		output_interface_callback(#instruction);		\
		output_interface_callback(" ");					\
		output_interface_callback(to_string(param));				\
		output_interface_callback("\n");				\
	}

#define DOUBLE_PARAM_COMMAND_OUTPUT_DEFINITION(			\
	func_name,											\
	instruction,										\
	param1,												\
	param2)												\
	void CPCL_cmd::func_name(Param_t param1,Param_t param2)const {		\
		output_interface_callback(#instruction);		\
		output_interface_callback(" ");					\
		output_interface_callback(to_string(param1));				\
		output_interface_callback(" ");					\
		output_interface_callback(to_string(param2));				\
		output_interface_callback("\n");				\
	}




//以下内容替换掉所有空格
INSTANT_COMMAND_OUTPUT_DEFINITION(Print,PRINT)
//下发打印命令
//使打印机控制状态结束，并打印出控制部分的内容。
//[注意]
//1.PRINT后面必须加个回车。
//2.必须和<!>Commands配合


SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(PageWidth,PW,width)
//设置打印页面宽度
//width：页面宽度点数（8点/mm）
//[注意]
//宽度以打印机芯左边为原点算起的。
//超出打印宽度的数据将被忽略。

INSTANT_COMMAND_OUTPUT_DEFINITION(Locate,FORM)
//设置打印结束后，并走纸到定位点。
//[注意]必须和<BAR-SENSE>/<GAP-SENSE>指令配合












DOUBLE_PARAM_COMMAND_OUTPUT_DEFINITION(SETMAG,SETMAG,w,h)
//对字符字体进行放大
//w：对字符的宽度进行放大，有效的数值为1-16。
//h：对字符的高度进行放大，有效的数值为1-16。
//[注意]
//当使用SETMAG指令后，字体SIZE标识将无效。仅对其基本字体进行放大
//当w或者h=0时，字体的宽度或者高度还原到基本字体大小。


INSTANT_COMMAND_OUTPUT_DEFINITION(BarSense_Right,BAR-SENSE)
/*[描述]
设置检测模式为右黑标，当和FORM配合使用后，打印完后走纸到右黑标处停止。
[注意]
●
必须和FORM配合使用*/










INSTANT_COMMAND_OUTPUT_DEFINITION(GapSense,GAP-SENSE)
/*[描述]
设置检测模式为标签，当和FORM配合使用后，打印完后走纸到标签处停止。
[注意]
●
必须和FORM配合使用*/


INSTANT_COMMAND_OUTPUT_DEFINITION(Left_align,LEFT)
/*[描述]
设置打印对齐方式为左对齐
[注意]
●
坐标方向是从左到右。且X坐标有效。*/
INSTANT_COMMAND_OUTPUT_DEFINITION(Center_align,CENTER)
/*[描述]
设置打印对齐方式为中心对齐
[注意]
●
只对字符，条码有效，对线段BOX指令无效
●
当X坐标为0时，字符和条码沿坐标原点对称打印。*/
INSTANT_COMMAND_OUTPUT_DEFINITION(Right_align,RIGHT)
/*[描述]
设置打印对齐方式为右对齐
[注意]
●
字符条码的X坐标失效，总是以最右边为基准，靠右边打印*/

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(setPrintSpeed,SPEED,speed_level)
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






SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(PREFEED,PREFEED,length)
/*{length}:走纸距离点数。8点=1mm
[描述]
设置打印之前走纸距离。*/
SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(POSTFEED,POSTFEED,length)
/*{length}:走纸距离点数。8点=1mm
[描述]
设置打印之后走纸距离。*/
SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(SETBOLD,SETBOLD,val)
/*{level}0取消粗体模式
{level}>1设置打印字体为粗体
[描述]
设置打印的字符为粗体,*/

INSTANT_COMMAND_OUTPUT_DEFINITION(PaceControl,PACE)
//批量打印时，第一张打印后，需要按走纸键才能继续打印第二张

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(WAIT,WAIT,time)
/*{delay-time}:延时1/8的时间
[描述]
打印一张后，需要等待设置的时间过后才打印第二张。*/

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(aetSpace,SETSP,val)
/*{spacing}:字符与字符之间的间隔大小，n*0.125mm
[描述]
设置字符间距*/

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(BACKGROUND,BACKGROUND,val)
/*{backgroundlevel}:灰度等级，0-255
[描述]
设置水印文字的灰度*/

INSTANT_COMMAND_OUTPUT_DEFINITION(Reprint,REPRINT)
//将此页面打印如果遇到缺纸等故障将自动补打。[注意]只针对XT423机型







void CPCL_cmd::Count(uint16_t long_param)const {
	output_interface_callback("UNDERLINE");
	output_interface_callback(" ");
	output_interface_callback(to_string(long_param));
	output_interface_callback("\n");
}
//num：±65535内的任意整数，对打印数字进行自动增减。
// [注意]
// 1.只能对数字部分进行增减
// 2.有进位或借位时，如果进位或者借位不是数字时，该进位或者借位忽略。



void CPCL_cmd::BarSense_Left()const {
	output_interface_callback("BAR-SENSE");
	output_interface_callback(" ");
	output_interface_callback("LEFT");
	output_interface_callback("\n");
}
/*[描述]
设置检测模式为左黑标，当和FORM配合使用后，打印完后走纸到左黑标处停止。
[注意]
●
必须和FORM配合使用*/


void CPCL_cmd::UnderlineCmd(Switch_t SWITCH)const {
	output_interface_callback("UNDERLINE");
	output_interface_callback(" ");
	if (SWITCH) {
		output_interface_callback("ON");
	}
	else {
		output_interface_callback("OFF");
	}
	output_interface_callback("\n");
}
/*“ON”：打开下划线打印模式
“OFF”：关闭下划线打印模式
[描述]
设置是否打印下划线*/