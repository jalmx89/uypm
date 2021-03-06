#include <lcd_cargando.h>

#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

#define LCD_ENABLE_PIN  PIN_B0                                    
#define LCD_RS_PIN      PIN_B1                                    
#define LCD_RW_PIN      PIN_B2                                   
#define LCD_DATA4       PIN_B4                                   
#define LCD_DATA5       PIN_B5                                    
#define LCD_DATA6       PIN_B6                                    
#define LCD_DATA7       PIN_B7  

void main()
{

   lcd_init();
   delay_ms(10);   
  
   while(TRUE)
   {
     lcd_putc("\fCargando"); //Limpio toda la lcd y se vizualiza "cargando" en posicion (1,1)
     delay_ms(10);
        
      int8 i=1;
      
      for(; i <= 16; i++){
         lcd_gotoxy(i,2);
         lcd_putc("*");
         delay_ms(500);
      }
     
      i = 1; //reset    
      
      for(; i <= 16; i++){
         lcd_gotoxy(i,2);
         lcd_putc("+");
         delay_ms(500);
      }
      
   }//termina el while

}
