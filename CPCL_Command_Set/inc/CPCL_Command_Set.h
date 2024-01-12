#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CPCL_COMMAND_SET
#define __CPCL_COMMAND_SET

typedef uint8_t HorizonalOffset_t;
typedef uint16_t Resolution_DotPerInch_t;
typedef uint16_t Dot_t;
typedef uint16_t Length_mm_t;
typedef uint16_t Quantity_t; // Maximum 1024
typedef uint8_t CharSize_t;//1~7
typedef string CPCL_Command_t;
typedef string Content_t;

typedef void (*Output_Interface_Callback_Handler)(CPCL_Command_t);

enum CharFont_t { FONT0 = 0, FONT1, FONT2, FONT3, FONT4, FONT5, FONT6, FONT7, FONT8 };
enum CharRotation_t { ROTATION0 = 0, ROTATION90, ROTATION180, ROTATION270 };


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
	void (*output_interface_callback)(CPCL_Command_t);

public:
	void Init();
	void add(CPCL_Basic_Object& object)const;
	void Print()const;

	void Left_align()const;
	void Center_align()const;
	void Right_align()const;
};





#endif

#ifdef __cplusplus
}
#endif
