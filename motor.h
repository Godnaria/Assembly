//this file contain the pin of motors' definition
#define MIDDLE_ECHO 2
#define MIDDLE_TRIG 4
#define LEFT_ECHO 7
#define LEFT_TRIG 8
#define RIGHT_ECHO 10
#define RIGHT_TRIG 11
#define MOTOR_A1 3      //HIGH:forward LOW:backward
#define MOTOR_B1 5      //speed 0~255
#define MOTOR_A2 6
#define MOTOR_B2 9
typedef int Motor;
void turn_left(Motor ax = MOTOR_A1,Motor bx = MOTOR_B1 , int speed)
{
    digitalWrite(MOTOR_B1,speed);
}

void turn_right(Motor ax = MOTOR_A2,Motor bx = MOTOR_B2 , int speed)
{
    digitalWrite(MOTOR_B2,speed);
}