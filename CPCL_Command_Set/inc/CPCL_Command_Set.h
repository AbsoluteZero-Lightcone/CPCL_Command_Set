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

	public:
		Dot_t position_left = 0;
		Dot_t position_top = 0;
		CharRotation_t char_rotation = ROTATION0;
		CharFont_t char_font = FONT0;
		CharSize_t char_size = 1;

	public:
		void updateCmd();
	};

	class AdvancedText :public CPCL_Basic_Object {
	public:
		OVERLOAD_CONSTRUCTOR_DECLARATION(AdvancedText)

	public:
		Dot_t position_left = 0;
		Dot_t position_top = 0;
		Dot_t block_width = 100;
		Dot_t block_height = 100;
		CharFont_t char_font = FONT1;
		CharSize_t char_size = 3;

	public:
		void updateCmd();
	};

	class CPCL_cmd
	{
	public:
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
		void Init();
		void add(CPCL_Basic_Object& object)const;
		void Print()const;

		void Left_align()const;
		void Center_align()const;
		void Right_align()const;
	};


}


#endif


