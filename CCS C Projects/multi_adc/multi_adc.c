#include <multi_adc.h>

#use fast_io(B)
#use fast_io(C)
#use fast_io(D)

//configuraci�n de multiples entradas anal�gicas
void main(){
    
    set_tris_b(0);
    set_tris_c(0);
    set_tris_d(0);
    output_b(0);
    output_c(0);
    output_d(0);
    
    //configuraci�n de ADCs
    setup_adc(ADC_CLOCK_INTERNAL); //se ajusta el oscilador del ADC
    setup_adc_ports(AN0_TO_AN2_ANALOG);//aciva desde el AN0 hasta el AN3
    delay_ms(10);

    while(TRUE){
        set_adc_channel(0);
        delay_ms(10);//tiempo para configurar el canal
        int16 adc0 = read_adc();
        output_b(adc0);
        delay_ms(50);
        
        set_adc_channel(1);
        delay_ms(10);//tiempo para configurar el canal 
        int16 adc1 = read_adc();
        output_c(adc1);
        delay_ms(50);
        
        set_adc_channel(2);
        delay_ms(10);//tiempo para configurar el canal 
        int16 adc2 = read_adc();
        output_d(adc2);
        delay_ms(50);
    }

}