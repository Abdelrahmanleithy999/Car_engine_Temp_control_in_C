/*
 * project.c
 *first project c
 *  Created on: Dec 19, 2021
 *   Author:Abdelrahman Leithy
 */
/**********************************************************************************************************************************/
#include <stdio.h>
#include <math.h>
#include<string.h>
enum speed { speed_G=100 , speed_o=30 , speed_R=0} ;
enum room_temperature { temp_less_10=20 , temp_greater_30=20 };
char car_engine[3];
void set_temp_and_AC(float*temperature_input);
void display_car_statusG(char* car_engine_pointer);\
void main_input_from_user(char*main_input_pointer );
void sensors_menu();
void print_menu();
void sensors_action(char* pointer_sensor);
void display_car_statusO(char*car_engine_pointer);
void set_colors(char* pointer_color);
void set_engine_temprature(float*engine_temperature_pointer);
void case_30Km (float* temperature_30,float* engine_temperature_30);
char AC_ON[3]="ON";
char AC_OFF[3]="OFF";
char EN_controller_ON[5]="ON";
char EN_controller_off[5]="OFF";
int speed = 40 ;
float temperature_room=45.0;
float engine_temperature=155.0;
char AC_var[10]="ON";
char engine_Var[10]="ON";
char main_input , sensor_input ;
int main(){
	fflush(stdout);
	setvbuf(stdout, NULL, _IONBF, 0);
	print_menu();
	scanf("%c" , &main_input);
	main_input_from_user(&main_input );
	return 0 ;}
void main_input_from_user(char*main_input_pointer ){
	switch (*main_input_pointer){
		case 'a':
			strcpy(car_engine,EN_controller_ON);
			printf("a-Turn on the vehicle engine \n");
			printf("\n");
			sensors_menu();
			fflush(stdin);
			scanf("%c" , &sensor_input);
			sensors_action(&sensor_input);
			break;
		case'b':
			strcpy(car_engine,AC_OFF);
			printf("b-Turn off the vehicle engine \n");
			printf("\n");
			print_menu();
			fflush(stdin);
			scanf("%c" , &main_input);
			main_input_from_user(&main_input);
			break;
		case'c':
			printf("Quit program\n");
			break;
		}
}
void print_menu(){
	printf("a-Turn on the vehicle engine \n");
	printf("b-Turn off the vehicle engine \n");
	printf("c-Quit the system \n");
	printf("\n");
}
void sensors_menu(){
	printf("a-Turn off the engine \n");
	printf("b-set the traffic light color\n");
	printf("c-set the room temperature\n");
	printf("d-set the engine temperature\n");
}
void sensors_action(char* pointer_sensor){
	switch (*pointer_sensor){
	case'a':
		printf("\n");
		print_menu();
		fflush(stdin);
		scanf("%c" , &main_input);
			main_input_from_user(&main_input );
		break;
	case'b':
		printf("enter the required color : \n");
		char color ;
		fflush(stdin);
		scanf("%c" , &color);
		set_colors(&color);
		sensors_menu();
		fflush(stdin);
					scanf("%c" , &sensor_input);
					sensors_action(&sensor_input);
		break;
	case 'c' :
		printf("enter the required room temperature : \n");
		float temperature_input ;
				fflush(stdin);
				scanf("%f" , &temperature_input);
				if(temperature_input>=10 && temperature_input<=30){
					strcpy(engine_Var,EN_controller_off);
					display_car_statusG(car_engine);
					sensors_menu();
					fflush(stdin);
				 scanf("%c" , &sensor_input);
		         sensors_action(&sensor_input);
				}
				set_temp_and_AC(&temperature_input);
				display_car_statusO(car_engine);
						sensors_menu();
								fflush(stdin);
								scanf("%c" , &sensor_input);
						        sensors_action(&sensor_input);
		break ;
	case 'd':
		printf("enter the required Engine temperature : \n");
		fflush(stdin);
		float engine_temperature_input;
		scanf("%f" , &engine_temperature_input);
		if(engine_temperature_input>=125 &&engine_temperature_input<=150 ){
			strcpy(engine_Var,EN_controller_off);
			display_car_statusO(car_engine);
		}
		set_engine_temprature( &engine_temperature_input);
		display_car_statusO(car_engine);
		sensors_menu();
		fflush(stdin);
		scanf("%c" , &sensor_input);
		sensors_action(&sensor_input);
				break ;
	}
}
void set_colors(char* pointer_color ){
	if(*pointer_color=='g'){
		speed = speed_G;
		display_car_statusG(car_engine);
	}
	else if(*pointer_color=='o'){
		speed = speed_o;
	    case_30Km (&temperature_room, &engine_temperature);
	   display_car_statusO(car_engine);
		}
	else if (*pointer_color=='R'){
		speed = speed_R;
		display_car_statusG(car_engine);
	}
}
void set_temp_and_AC(float*temperature_input_pointer){
	if(*temperature_input_pointer<10 ||*temperature_input_pointer>30){
		temperature_room= 20.0;
		strcpy(engine_Var,EN_controller_off);
	}
}
void set_engine_temprature(float*engine_temperature_pointer){
	if(*engine_temperature_pointer<100 || *engine_temperature_pointer>150){
		 engine_temperature=125;
	}
}
void case_30Km (float* temperature_30,float* engine_temperature_30){
	if (speed== speed_o){
		* temperature_30 = (* temperature_30) * ((5/4)+1);
		* engine_temperature_30 = (* engine_temperature_30)*((5/4)+1);
		strcpy(AC_var,AC_ON);
		strcpy(engine_Var,EN_controller_ON);
	}
}
void display_car_statusG(char*car_engine_pointer){
    printf("Enigne statue : %s : " ,car_engine_pointer);
	printf("\n");
	printf("AC : OFF"	);
	printf("\n");
	printf("Vechicle speed : %d  km/hr" , speed);
	printf("\n");
	printf("Room temperature %f : " ,temperature_room );
	printf("\n");
	printf("Engine controller Status : %s" , EN_controller_off);
	printf("\n");
	printf("Engine Temperature %f C " , engine_temperature);
	printf("\n");
	printf("\n");
}
void display_car_statusO(char*car_engine_pointer){
    printf("Enigne statue : %s : " ,car_engine_pointer);
	printf("\n");
	printf("AC : %s" ,AC_var );
	printf("\n");
	printf("Vechicle speed : %d  km/hr" , speed);
	printf("\n");
	printf("Room temperature %f : " ,temperature_room );
	printf("\n");
	printf("Engine controller Status : %s" , engine_Var);
	printf("\n");
	printf("Engine Temperature %f " , engine_temperature);
	printf("\n");
	printf("\n");
}

