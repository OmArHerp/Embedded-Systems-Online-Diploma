/*
 * Simple_Security_System.c
 *
 * Created: 10/23/2023 10:36:20 AM
 * Author : Herp
 */
 
#include "Include.h"
void Push_button_init();
void LED_init();
void Sev_Seg_init();
void Sev_Seg_display_Num(uint8_t num);

int main(void)
{
	Push_button_init();
	LED_init();
	Sev_Seg_init();
	uint8_t Num = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		//Tens_button pressed
		if( ((Push_Button_PIN >> TENS_button) & 1) == PRESSED)
		{
			//Debounce effect
			_delay_ms(20);
			if(((Push_Button_PIN >> TENS_button) & 1) == PRESSED)
			{
				while(((Push_Button_PIN >> TENS_button) & 1) == PRESSED); //Single Pressing
				Num = Num + 10; //Increase the tense
			}
		}
		//Units_button pressed
		else if(((Push_Button_PIN >> UNITS_button) & 1) == PRESSED)
		{
			//Debounce effect
			_delay_ms(20);
			if(((Push_Button_PIN >> UNITS_button) & 1) == PRESSED)
			{
				while(((Push_Button_PIN >> UNITS_button) & 1) == PRESSED); //Single Pressing
				Num++; //Increase the Units
			}
		}
		//Enter_button pressed
		else if(((Push_Button_PIN >> ENTER_buttton) & 1) == PRESSED)
		{
			//Debounce effect
			_delay_ms(20);
			if(((Push_Button_PIN >> ENTER_buttton) & 1) == PRESSED)
			{
				while(((Push_Button_PIN >> ENTER_buttton) & 1) == PRESSED); //Single Pressing
				if(Num == PASSWORD)
				{
					//LED GREEN ON for 5 sec
					LED_BUZZER_PORT ^= (1<<LED_GREEN);
					
					while(1)
					{
						Sev_Seg_display_Num(Num);
					}
					
				}
				else
				{
					//LED RED,YELLOW AND BUZZER ON for 5 sec
					LED_BUZZER_PORT ^= (1<<LED_YELLOW);
					LED_BUZZER_PORT ^= (1<<LED_RED);
					LED_BUZZER_PORT ^= (1<<BUZZER);
					_delay_ms(5000);
					LED_BUZZER_PORT ^= (1<<BUZZER);
					while(1)
					{
						Sev_Seg_display_Num(Num);
					}
				}
			}
		}
		else if (((Push_Button_PIN >> RESET_buttton) & 1) == PRESSED )
		{
			//Debounce effect
			_delay_ms(20);
			if(((Push_Button_PIN >> RESET_buttton) & 1) == PRESSED)
			{
				while(((Push_Button_PIN >> UNITS_button) & 1) == PRESSED); //Single Pressing
				Num = 0; //Reset the count
			}
		}
		
		Sev_Seg_display_Num(Num);
    }
}

void Push_button_init()
{
	//Set the 3 PushButtons as input (With External PUR)
	Push_Button_Direction &= ~((1<<TENS_button) | (1<<UNITS_button) | (1<<ENTER_buttton));
	
}
void LED_init()
{
	//Set LED & Buzzer as output 
	LED_BUZZER_Direction |= ((1<<LED_GREEN) | (1<<LED_YELLOW) | (1<<LED_RED) | (1<<BUZZER));
	LED_BUZZER_PORT |=((1<<LED_GREEN) | (1<<LED_YELLOW) | (1<<LED_RED) | (1<<BUZZER));
	
}
void Sev_Seg_init()
{
	//Make Sev_Seg pins output
	Seven_Seg_Direction = 0b00111111 ;
	//Initialize it with Zero value
	//Seven_Seg_PORT = 0xF0;
	
}
void Sev_Seg_display_Num(uint8_t num)
{
	if(num > 99)
		num = 99;
	uint8_t tens = num/10;
	uint8_t units = num%10;	
	
	//Write tens
	
	//Enable 7Seg1 & Disable 7Seg2
	Seven_Seg_PORT &= ~(1<<SEG1_EN);
	Seven_Seg_PORT |= (1<<SEG2_EN);
	Seven_Seg_PORT = (Seven_Seg_PORT & 0xF0) | tens ;
	_delay_ms(30);
	
	
	//Enable 7Seg2 & Disable 7Seg1
	Seven_Seg_PORT |= (1<<SEG1_EN);
	Seven_Seg_PORT &= ~(1<<SEG2_EN);
	//Write Units
	Seven_Seg_PORT = (Seven_Seg_PORT & 0xF0) | units ;
	_delay_ms(30);
	
}
