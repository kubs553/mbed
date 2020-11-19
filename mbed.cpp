#include "mbed.h"
#include "C12832.h"

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
DigitalOut led(LED1), led2(LED2), led3(LED3), led4(LED4);

int main() {
    uint8_t byte= 0b00001010;
    uint8_t l1, l2, l3, l4;
    
    l1 = byte & 0b00000001;
    l2 = byte & 0b00000010;
    l3 = byte & 0b00000100;
    l4 = byte & 0b00001000;
    
    if(l1 == 0){
        led = !led;
    }
    if(l2 == 0){
        led2 = !led2;
    }
    if(l3 == 0){
        led3 = !led3;
    }
    if(l4 == 0){
        led4 = !led4;
    }
    
    while (1) {
        led = !led;
        led2 = !led2;
        led3 = !led3;
        led4 = !led4;
        lcd.printf("Blink! LED is now %d\n", led.read());
        wait_ms(1500);
    }
}
