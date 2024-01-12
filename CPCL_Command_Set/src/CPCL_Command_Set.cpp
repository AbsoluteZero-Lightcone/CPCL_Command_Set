//#include "stm32f10x.h"                  // Device header

//#include <iostream>
using namespace std;

#include <stdint.h>

#include <string>
#include ".\inc\CPCL_Command_Set.h"

Dot_t toDot(Length_mm_t len) {
	return 8 * (Dot_t)len;
}

class CPCL_Basic_Object {
protected:
	CPCL_Command_t cmd;
public:
	Content_t Data = "Basic_Object";
	virtual void updateCmd() {}// 子类实现虚函数
	CPCL_Command_t getFormCmd() {// 生成对象控制指令统一调用接口
		//cout << "CPCL_Basic_Object::getFormCmd()" << endl;
		updateCmd();
		return cmd;
	}
};

#define OVERLOAD_CONSTRUCTOR(class_name)\
	class_name() { Data = #class_name; }\
	class_name(Content_t t_Data) { Data = t_Data; }\
	class_name& operator=(Content_t t_Data) {\
		this->Data = t_Data;\
		return *this;\
	}


class Text :public CPCL_Basic_Object {
public:
	OVERLOAD_CONSTRUCTOR(Text)

public:
	// 基本文字参数列表
	Dot_t position_left = 0;
	Dot_t position_top = 0;
	CharRotation_t char_rotation = ROTATION0;
	CharFont_t char_font = FONT0;
	CharSize_t char_size = 1;

public:
	void updateCmd() {
		switch (char_rotation) {
		case 0:cmd.append("T ");break;
		case 1:cmd.append("VT ");break;
		case 2:cmd.append("T180 ");break;
		case 3:cmd.append("T270 ");break;
		}
		cmd.append(to_string(char_font));
		cmd.push_back(' ');
		cmd.append(to_string(char_size));
		cmd.push_back(' ');
		cmd.append(to_string(position_left));
		cmd.push_back(' ');
		cmd.append(to_string(position_top));
		cmd.push_back(' ');
		cmd.append(Data);
		cmd.push_back('\n');
	}
};


class AdvancedText :public CPCL_Basic_Object {
public:
	OVERLOAD_CONSTRUCTOR(AdvancedText)

public:
	Dot_t position_left = 0;
	Dot_t position_top = 0;
	Dot_t block_width = 100;
	Dot_t block_height = 100;
	CharFont_t char_font = FONT1;
	CharSize_t char_size = 3;

public:
	void updateCmd() {

	}
};

class CPCL_cmd
{
public:
	//打印页面设置
	HorizonalOffset_t offset = 0;
	Resolution_DotPerInch_t horizonalResolution = 200;
	Resolution_DotPerInch_t verticalResolution = 200;
	Length_mm_t height_mm = 30;
	Dot_t height_dot = 240;
	Length_mm_t width_mm = 50;
	Dot_t width_dot = 400;
	Quantity_t quantity = 1;

public:
	Output_Interface_Callback_Handler output_interface_callback;

public:
	void Init() {
		output_interface_callback(
			"! "
			+ to_string(offset) + " "
			+ to_string(horizonalResolution) + " "
			+ to_string(verticalResolution) + " "
			+ to_string(height_dot) + " "
			+ to_string(quantity)
			+ " \nPAGE-WIDTH " + to_string(width_dot)
			+ "\n"
		);
	}
	void add(CPCL_Basic_Object& object)const {
		output_interface_callback(object.getFormCmd());
		// todo：模板实现调用任意对象的输出指令
	}
	void Print()const {
		output_interface_callback("PRINT\n");
	}


	//对齐方式
	void Left_align()const {
		output_interface_callback("LEFT\n");
	}
	void Center_align()const {
		output_interface_callback("CENTER\n");
	}
	void Right_align()const {
		output_interface_callback("RIGHT\n");
	}
};

