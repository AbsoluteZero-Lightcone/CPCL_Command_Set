#include ".\inc\CPCL_Command_Set.h"

Dot_t toDot(Length_mm_t len) {
	return 8 * (Dot_t)len;
}


void CPCL_Basic_Object::updateCmd() {}// 子类实现虚函数
CPCL_Command_t CPCL_Basic_Object::getFormCmd() {// 生成对象控制指令统一调用接口
	//cout << "CPCL_Basic_Object::getFormCmd()" << endl;
	updateCmd();
	return cmd;
}

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

OVERLOAD_CONSTRUCTOR(AdvancedText)
void AdvancedText::updateCmd() {}


void CPCL_cmd::Init() {
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
void CPCL_cmd::add(CPCL_Basic_Object& object)const {
	output_interface_callback(object.getFormCmd());
	// todo：模板实现调用任意对象的输出指令
}
void CPCL_cmd::Print()const {
	output_interface_callback("PRINT\n");
}


//对齐方式
void CPCL_cmd::Left_align()const {
	output_interface_callback("LEFT\n");
}
void CPCL_cmd::Center_align()const {
	output_interface_callback("CENTER\n");
}
void CPCL_cmd::Right_align()const {
	output_interface_callback("RIGHT\n");
}
