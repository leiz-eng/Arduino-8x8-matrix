#include "Matrix.h"
Matrix myMatrix(A4, A5);
uint8_t LedArray1[4][8] = { 0x00, 0x18, 0x24, 0x42, 0x81, 0x99, 0x66, 0x00, // heart shape
                           0x00, 0x09, 0x1E, 0x3E, 0x2D, 0x00, 0x00, 0x00, // Cai
                           0x00, 0x01, 0x1E, 0x3E, 0x7B, 0x40, 0x00, 0x00, // Xu
                           0x00, 0x01, 0x0F, 0x0F, 0x1F, 0x10, 0x00, 0x00, // Kun
                           }; 
uint8_t LedArray2[8] = { 0x00, 0x00, 0x18, 0x30, 0x78, 0x38, 0x30, 0x48};// heart shape
uint8_t LEDArray[8];
uint8_t t = 0;
void setup() {
  myMatrix.begin(0x70);
}

void loop(){
  
  for (int p = 1; p < 4; p++){
    for(int i=0; i<8; i++)
    {
      LEDArray[i]=LedArray1[p][i];
      for(int j=7; j>=0; j--)
      {
        if((LEDArray[i]&0x01)>0)
        myMatrix.drawPixel(j, i,1);
        LEDArray[i] = LEDArray[i]>>1;
      }
    }
    myMatrix.writeDisplay();
    delay(300);
    myMatrix.clear();
  }
  
}

