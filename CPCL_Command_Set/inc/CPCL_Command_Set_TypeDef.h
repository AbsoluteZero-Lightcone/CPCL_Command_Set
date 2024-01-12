#ifndef __CPCL_COMMAND_SET_TYPEDEF
#define __CPCL_COMMAND_SET_TYPEDEF


#include <stdint.h>
#include <string>
using namespace std;


typedef uint8_t HorizonalOffset_t;
typedef uint16_t Resolution_DotPerInch_t;
typedef uint16_t Dot_t;
typedef uint16_t Length_mm_t;
typedef uint16_t Quantity_t; // Maximum 1024
typedef uint8_t CharSize_t;//1~7
typedef string CPCL_Command_t;
typedef string Content_t;

typedef void (*Output_Interface_Callback_Handler)(CPCL_Command_t);


// Format:
enum CharFont_t { FONT0 = 0, FONT1, FONT2, FONT3, FONT4, FONT5, FONT6, FONT7, FONT8 };
enum CharRotation_t { ROTATION0 = 0, ROTATION90, ROTATION180, ROTATION270 };
enum Align_t {LEFT_ALIGN = 0,CENTER_ALIGN,RIGHT_ALIGN};
enum CharBold_t {UNBOLD=0,BOLD};

// DeviceCmd:
enum SensorMode_t { NORMAL_MODE = 0, BAR_SENSE_LEFT, BAR_SENSE_RIGHT, GAP_SENSE };
#endif

