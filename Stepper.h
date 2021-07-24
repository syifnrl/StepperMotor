#ifndef MBED_STEPPER_H
#define MBED_STEPPER_H

#include "mbed.h"

/* This library is used to control stepper using driver motor TB6560
    with common cathode configuration
    
    Library ini digunakan untuk mengontrol stepper dengan driver TB6560
    dan wiring secara common cathode configuration
*/

/*Example:
    #include "mbed.h"
#include "Stepper.h"
#define steps_per_rev 200 //steps the stepper takes per one rotation

Serial pc(USBTX, USBRX);
Stepper myStepper(PC_8, PC_6);
long posisi;
             

int main()
{
    // Initialise the digital pin LED1 as an output
    myStepper.speed(1500); //set stepper speed in microseconds. The default speed is 1000 microseconds
    while (1) {
        myStepper.step(1350); //stepper rotating clockwise
        posisi = myStepper.readPosition(); //save position
        pc.printf("Posisi: %d\n", posisi);
        wait(1);
        myStepper.step(-1350); //stepper rotating counter clockwise
        posisi = myStepper.readPosition();
        pc.printf("Posisi: %d\n", posisi);
        wait(1);
    }
}
*/

class Stepper{
    public:
    /*common cathode configuration used 2 digital pins, CLK+ and CW+
    you can ground CLK- pin and CW-. EN pins are NC
    
    konfigurasi common cathode menggunakan 2 pin digital, CLK+ dan CW+
    untuk pin CLK- dan CW- bisa dihubungkan ke ground. Pin EN tidak perlu
    dihubungkan (NC)
    */
    Stepper(PinName pin_dir, PinName pin_clk);
    
    /* Stepper moves continuously with determined interval value of your choice
    
    Stepper bergerak secara terus menerus dengan interval pos yang ditentukan
    */
    void step(int pos_relative);
    
    /*Stepper moves to absolute position, means if u choose 200 as yor target position
    and your stepper is already at 200 steps from 0, the stepper won't move
    
    Stepper bergerak ke posisi absolut dengan, dimana bila anda memilih 200 sebagai
    target posisi anda dan stepper telah berjalan 200 step, stepper tidak akan
    bergerak*/
    void stepTo(int pos_);
    
    /* Set speed between each step that the stepper takes
    
    atur kecepatan diantara setiap langkah yang stepper ambil
    */   
    void speed(float delay_);
    
    /*return current position of stepper
    
    Posisi terkini stepper
    */
    long readPosition();

    long lastpos;
    
    protected:
    int direction;
    long position;
    float delay_, delay;
    
    private:
    DigitalOut dir_;
    DigitalOut clk_;
    long pos_, pos_relative, target, steps_left;
    int i;
    void init();
};

#endif