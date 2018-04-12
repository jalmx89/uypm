#include <display_doble.h>
#use fast_io(D)
#use fast_io(B)

void main()
{
   set_tris_d(0); //configuración del PORT D, como salida
   set_tris_b(0);
   output_b(0);
   output_d(0);
   
   const int8 numbers[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0xfd, 0x07, 0xff, 0x67};
   
   while(TRUE){//inicia while
      
      for(int x=0; x < 10; x++){    
      
         for(int i=0; i < 0x0A; i++){ //inicia for
         
            for(int d=0; d<5; d++){ 
            
               output_b(0x01); //activo display de unidades
               output_d(numbers[i]); //se ve en el display la unidad
               delay_ms(100);
               
               output_b(0x02);
               output_d(numbers[x]);
               delay_ms(100);
            }//ultimo for
         }// fin del segundo for
      }//fin del primer for
   }//termina while

}

