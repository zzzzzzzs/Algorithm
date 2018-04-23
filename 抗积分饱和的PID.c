//抗积分饱和的PID
/*************************************************
* 输入量rin(t)为电机转速预定值
* 输出量rout(t)为电机转速实际值
* 执行器为直流电机
* 传感器为编码器
* 直流电机采用PWM调速
**************************************************/
#include <stdio.h>
#include <math.h>

typedef struct _pid
{
	float SetSpeed;		//设定速度
	float ActualSpeed;	//实际速度
	float err;			//误差
	float err_last;		//上一次误差
	float Kp, Ki, Kd;  	//比例、积分、微分系数
	float voltage;		//执行器变量（直流电机）
	float integral;  	//积分值
	float umin, umax;	//阈值（最小值、最大值）
} Pid;
Pid pid;
void PID_Init(void)
{
	printf("PID_Init begin!\n");
	pid.SetSpeed 	= 0.0;
	pid.ActualSpeed = 0.0;
	pid.err 		= 0.0;
	pid.err_last   	= 0.0;
	pid.voltage		= 0.0;
	pid.integral 	= 0.0;
	pid.Kp			= 0.2;//比例
	pid.Ki			= 0.1;//积分
	pid.Kd			= 0.2;//微分
	pid.umin		= -200;
	pid.umax		= 400;
	printf("PID_Init end!\n");
}
float PID_Realize(float speed)
{
	int index;
	pid.SetSpeed = speed;//将需要的速度传给设定速度
	pid.err = pid.SetSpeed - pid.ActualSpeed;//误差 = 设定速度 - 实际速度
	if(pid.ActualSpeed > pid.umax)			//实际速度 > 最大值
	{
		if(abs(pid.err) > 200)				//误差绝对值 > 200
		{
			index = 0;
		}
		else
		{
			index = 1;
			if(pid.err < 0)					//	误差 < 0
			{
				pid.integral += pid.err;	//积分值累加误差
			}
		}	
	}
	else if(pid.ActualSpeed < pid.umin)		//实际速度 < 最小值
	{
		if(abs(pid.err) > 200)				//误差绝对值 > 200	
		{
			index = 0;
		}
		else
		{
			index = 1;
			if(pid.err > 0)
			{
				pid.integral += pid.err;	//积分值累加误差
			}
		}
	}
	else
	{
		if(abs(pid.err) > 200)				//误差绝对值 > 200
		{
			index = 0;
		}
		else
		{
			index = 1;
			pid.integral += pid.err;		//积分值累加误差
		}
	}
	pid.voltage = pid.Kp * pid.err + index * pid.Ki * pid.integral \
				  + pid.Kd * (pid.err - pid.err_last);			//执行器变量(直流电机变量) = 比例 * 误差 + 
	pid.err_last = pid.err;
	pid.ActualSpeed = pid.voltage * 1.0;
	return pid.ActualSpeed;
}
int main()
{
	PID_Init();
	int count = 0;
	//while(count < 1)
	//{
		float speed = PID_Realize(200.0);
		printf("%f\n", speed);
	//	count++;
	//}
	getchar();
	return 0;
}