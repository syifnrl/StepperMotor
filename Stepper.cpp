#include "Stepper.h"
#include "mbed.h"

Stepper::Stepper(PinName pin_dir, PinName pin_clk) : dir_(pin_dir), clk_(pin_clk){
    init();
    }

void Stepper::init(){
    delay = 1000;
    lastpos = 0;
    float delay_;
    }
    
void Stepper::step(int pos_relative){
    target = abs(pos_relative);
    
    if(target != 0){
        if(pos_relative > 0){
            direction = 1;
            dir_.write(1);
            
            for(i = 0; i <= target; i++){
                clk_.write(1);
                wait_us(delay);
                clk_.write(0);
                wait_us(delay);
                }
            }
        if(pos_relative < 0){
            direction = -1;
            dir_.write(0);
            
            for(i = 0; i <= target; i++){
                clk_.write(1);
                wait_us(delay);
                clk_.write(0);
                wait_us(delay);
                }
            }
        }
    else{
        //do nothing
        }
    
    position = target * direction;
    lastpos = lastpos + position;
}

void Stepper::stepTo(int pos_){
     steps_left = pos_ - lastpos;
     
     if(steps_left != 0){
         target = abs(steps_left);
         
        if(steps_left > 0){
            direction = 1;
            dir_.write(1);
            
            for(i = 0; i <= target; i++){
                clk_.write(1);
                wait_us(delay);
                clk_.write(0);
                wait_us(delay);
                }
            }
        if(steps_left < 0){
            direction = -1;
            dir_.write(0);
            
            for(i = 0; i <= target; i++){
                clk_.write(1);
                wait_us(delay);
                clk_.write(0);
                wait_us(delay);
                }
            }
    }
    else{
        //do nothing
        }
    
    lastpos = pos_;
}

long Stepper::readPosition(){
    return lastpos;
    }

void Stepper::speed(float delay_){
    delay = delay_;
}

