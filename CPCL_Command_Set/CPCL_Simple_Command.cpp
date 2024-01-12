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




//���������滻�����пո�
INSTANT_COMMAND_OUTPUT_DEFINITION(Print,PRINT)
//�·���ӡ����
//ʹ��ӡ������״̬����������ӡ�����Ʋ��ֵ����ݡ�
//[ע��]
//1.PRINT�������Ӹ��س���
//2.�����<!>Commands���


SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(PageWidth,PW,width)
//���ô�ӡҳ����
//width��ҳ���ȵ�����8��/mm��
//[ע��]
//����Դ�ӡ��о���Ϊԭ������ġ�
//������ӡ��ȵ����ݽ������ԡ�

INSTANT_COMMAND_OUTPUT_DEFINITION(Locate,FORM)
//���ô�ӡ�����󣬲���ֽ����λ�㡣
//[ע��]�����<BAR-SENSE>/<GAP-SENSE>ָ�����












DOUBLE_PARAM_COMMAND_OUTPUT_DEFINITION(SETMAG,SETMAG,w,h)
//���ַ�������зŴ�
//w�����ַ��Ŀ�Ƚ��зŴ���Ч����ֵΪ1-16��
//h�����ַ��ĸ߶Ƚ��зŴ���Ч����ֵΪ1-16��
//[ע��]
//��ʹ��SETMAGָ�������SIZE��ʶ����Ч�����������������зŴ�
//��w����h=0ʱ������Ŀ�Ȼ��߸߶Ȼ�ԭ�����������С��


INSTANT_COMMAND_OUTPUT_DEFINITION(BarSense_Right,BAR-SENSE)
/*[����]
���ü��ģʽΪ�Һڱ꣬����FORM���ʹ�ú󣬴�ӡ�����ֽ���Һڱ괦ֹͣ��
[ע��]
��
�����FORM���ʹ��*/










INSTANT_COMMAND_OUTPUT_DEFINITION(GapSense,GAP-SENSE)
/*[����]
���ü��ģʽΪ��ǩ������FORM���ʹ�ú󣬴�ӡ�����ֽ����ǩ��ֹͣ��
[ע��]
��
�����FORM���ʹ��*/


INSTANT_COMMAND_OUTPUT_DEFINITION(Left_align,LEFT)
/*[����]
���ô�ӡ���뷽ʽΪ�����
[ע��]
��
���귽���Ǵ����ҡ���X������Ч��*/
INSTANT_COMMAND_OUTPUT_DEFINITION(Center_align,CENTER)
/*[����]
���ô�ӡ���뷽ʽΪ���Ķ���
[ע��]
��
ֻ���ַ���������Ч�����߶�BOXָ����Ч
��
��X����Ϊ0ʱ���ַ�������������ԭ��Գƴ�ӡ��*/
INSTANT_COMMAND_OUTPUT_DEFINITION(Right_align,RIGHT)
/*[����]
���ô�ӡ���뷽ʽΪ�Ҷ���
[ע��]
��
�ַ������X����ʧЧ�����������ұ�Ϊ��׼�����ұߴ�ӡ*/

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(setPrintSpeed,SPEED,speed_level)
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






SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(PREFEED,PREFEED,length)
/*{length}:��ֽ���������8��=1mm
[����]
���ô�ӡ֮ǰ��ֽ���롣*/
SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(POSTFEED,POSTFEED,length)
/*{length}:��ֽ���������8��=1mm
[����]
���ô�ӡ֮����ֽ���롣*/
SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(SETBOLD,SETBOLD,val)
/*{level}0ȡ������ģʽ
{level}>1���ô�ӡ����Ϊ����
[����]
���ô�ӡ���ַ�Ϊ����,*/

INSTANT_COMMAND_OUTPUT_DEFINITION(PaceControl,PACE)
//������ӡʱ����һ�Ŵ�ӡ����Ҫ����ֽ�����ܼ�����ӡ�ڶ���

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(WAIT,WAIT,time)
/*{delay-time}:��ʱ1/8��ʱ��
[����]
��ӡһ�ź���Ҫ�ȴ����õ�ʱ�����Ŵ�ӡ�ڶ��š�*/

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(aetSpace,SETSP,val)
/*{spacing}:�ַ����ַ�֮��ļ����С��n*0.125mm
[����]
�����ַ����*/

SINGLE_PARAM_COMMAND_OUTPUT_DEFINITION(BACKGROUND,BACKGROUND,val)
/*{backgroundlevel}:�Ҷȵȼ���0-255
[����]
����ˮӡ���ֵĻҶ�*/

INSTANT_COMMAND_OUTPUT_DEFINITION(Reprint,REPRINT)
//����ҳ���ӡ�������ȱֽ�ȹ��Ͻ��Զ�����[ע��]ֻ���XT423����







void CPCL_cmd::Count(uint16_t long_param)const {
	output_interface_callback("UNDERLINE");
	output_interface_callback(" ");
	output_interface_callback(to_string(long_param));
	output_interface_callback("\n");
}
//num����65535�ڵ������������Դ�ӡ���ֽ����Զ�������
// [ע��]
// 1.ֻ�ܶ����ֲ��ֽ�������
// 2.�н�λ���λʱ�������λ���߽�λ��������ʱ���ý�λ���߽�λ���ԡ�



void CPCL_cmd::BarSense_Left()const {
	output_interface_callback("BAR-SENSE");
	output_interface_callback(" ");
	output_interface_callback("LEFT");
	output_interface_callback("\n");
}
/*[����]
���ü��ģʽΪ��ڱ꣬����FORM���ʹ�ú󣬴�ӡ�����ֽ����ڱ괦ֹͣ��
[ע��]
��
�����FORM���ʹ��*/


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
/*��ON�������»��ߴ�ӡģʽ
��OFF�����ر��»��ߴ�ӡģʽ
[����]
�����Ƿ��ӡ�»���*/