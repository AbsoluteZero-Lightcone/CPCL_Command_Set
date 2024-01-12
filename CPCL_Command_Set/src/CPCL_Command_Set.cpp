#include ".\inc\CPCL_Command_Set.h"

Dot_t toDot(Length_mm_t len) {
	return 8 * (Dot_t)len;
}

// 通用对象基类：
void CPCL_Basic_Object::updateCmd() {/*空实现*/}
CPCL_Command_t CPCL_Basic_Object::getFormCmd() {// 生成对象控制指令统一调用接口
	updateCmd();
	return cmd;
}

// 打印机控制对象基类：
void CPCL_Core_Object::updateCmd() {/*空实现*/ }
CPCL_Command_t CPCL_Core_Object::getFormCmd() {// 生成对象控制指令统一调用接口
	updateCmd();
	return cmd;
}

// 通用对象类：
#define OVERLOAD_CONSTRUCTOR(class_name)\
	class_name::class_name() { Data = #class_name; }\
	class_name::class_name(Content_t t_Data) { Data = t_Data; }\
	class_name& class_name::operator=(Content_t t_Data) {\
		this->Data = t_Data;\
		return *this;\
	}

OVERLOAD_CONSTRUCTOR(Text)
void Text::updateCmd() {
	switch (char_rotation) {
	case ROTATION0:cmd.append("T");break;
	case ROTATION90:cmd.append("VT");break;
	case ROTATION180:cmd.append("T180");break;
	case ROTATION270:cmd.append("T270");break;
	}
	cmd.push_back(' ');
	switch (align){
	case LEFT:cmd.append("LEFT");break;
	case CENTER:cmd.append("CENTER");break;
	case RIGHT:cmd.append("RIGHT");break;
	}
	cmd.push_back(' ');
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

OVERLOAD_CONSTRUCTOR(AdvancedText)
void AdvancedText::updateCmd() {}

/**
* @brief 打印页面参数设置。设置打印页面高度和张数，设置打印页面宽度
*/
void Page::updateCmd() {
	cmd = "! "
		+ to_string(offset) + " "
		+ to_string(horizonalResolution) + " "
		+ to_string(verticalResolution) + " "
		+ to_string(height_dot) + " "
		+ to_string(quantity)
		+ " \nPAGE-WIDTH " + to_string(width_dot)
		+ "\n";
}





// Cmd类：输出模块 即时调用的配置命令 和 通用对象的统一调用接口
/**
* @brief 在页面上添加通用对象
* @param object: 传入CPCL_Basic_Object实例的引用
*/
void CPCL_cmd::add(CPCL_Basic_Object& object)const {
	output_interface_callback(object.getFormCmd());
	// todo：模板实现调用任意对象的输出指令
}


#define INSTANT_COMMAND_OUTPUT_DEFINITION(				\
	func_name,											\
	instruction)										\
	void CPCL_cmd::func_name()const {					\
		output_interface_callback(#instruction);		\
		output_interface_callback("\n");				\
	}

INSTANT_COMMAND_OUTPUT_DEFINITION(Print, PRINT)
INSTANT_COMMAND_OUTPUT_DEFINITION(Left_align, LEFT)
INSTANT_COMMAND_OUTPUT_DEFINITION(Center_align, CENTER)
INSTANT_COMMAND_OUTPUT_DEFINITION(Right_align, RIGHT)
