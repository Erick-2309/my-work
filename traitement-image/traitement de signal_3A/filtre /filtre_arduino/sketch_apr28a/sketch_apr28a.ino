
/*
#include "stdint.h"
void setup() {
   Serial.begin(9600);
 }

void loop() {
 int8_t val1 = -64;
 int8_t val2 = -64;
 int8_t val3;
 int8_t rest12;
 int8_t res;
   
if(Serial.available() > 0) {
   val3 = Serial.parseInt();
   rest12 = val1 + val2;
   res = rest12 + val3;
   Serial.print("val1= ");
   Serial.println(val1);
   Serial.print("val2=");
   Serial.println(val2);
   Serial.print("val1+ val2 = ");
   Serial.println(rest12);
   Serial.print("val3= ");
   Serial.println(val3);
   Serial.print("val1 + val2 + val3 = ");
   Serial.println(res);
   Serial.println(".........");  
   }
  }
*/

/*
int16_t xn;//Q(16,0)
int16_t xn1=0;//Q(16,0)
int16_t xn2=0;//0(16,0)
int16_t yn;//Q(16,0)
int16_t yn1=0;//Q(16,0)
int16_t yn2=0;//Q(16,0)
int8_t b0=6; //Q(8,6)
int8_t b1=-7; //Q(8,6)
int8_t b2=6; //0(8,6)
int8_t a1=-104; //Q(8,6)
int8_t a2=46; //0(8,6)
int n ;
int16_t mult; //Q(16,6)
void setup() {
Serial.begin(9600);
n=0;
}

void loop()
{
  xn=round (511*sin (2*3.1415*n*0.03)) ; // cos wave at frequency 0.03, Q(16,0)
  //xn = (n > 0) ? 0: 511;// impulse 0(16,0)
  mult=(xn*b0)+(xn1*b1)+(xn2*b2)-(yn1*a1)-(yn2*a2);//Q(16,6)
  yn=mult>>6; //back to Q(16,0)
  Serial.print("xn:");
  Serial.print(xn);
  Serial.print(',') ;
  Serial.print("yn:");
  Serial.println(yn);
  xn2=xn1;
  xn1=xn;
  yn2=yn1;
  yn1=yn;
  n++;
  delay(200);
}


int16_t xn;//Q(16,0)
int16_t xn1=0;//Q(16,0)
int16_t xn2=0;//0(16,0)
int16_t yn;//Q(16,0)
int16_t yn1=0;//Q(16,0)
int16_t yn2=0;//Q(16,0)
int16_t b0= 1729; //Q(16,14)
int16_t b1=-2040; //Q(16,14)
int16_t b2= 1729.; //0(16,14)
int16_t a1=-26695; //Q(16,14)
int16_t a2= 11901; //0(16,14)
int n ;
int32_t mult; //Q(32,20)
void setup() {
Serial.begin(9600);
n=0;
}

void loop()
{
  xn=round (511*sin (2*3.1415*n*0.03)) ; // cos wave at frequency 0.03, Q(16,0)
  //xn = (n > 0) ? 0: 511;// impulse 0(16,0)
  xn0=xn<<6 // INPUT DATA  Q(16,6)
  mult=((int32_t)xn*b0)+((int32_t)xn1*b1)+((int32_t)xn2*b2)-((int32_t)yn1*a1)-((int32_t)yn2*a2);//Q(16,6)
  yn=mult>>14; //back to Q(16,0)
  Serial.print("xn:");
  Serial.print(xn);
  Serial.print(',') ;
  Serial.print("yn:");
  Serial.println(yn);
  xn2=xn1;
  xn1=xn;
  yn2=yn1;
  yn1=yn;
  n++;
  delay(200);
}
*/


int16_t xn;//Q(16,0)
int16_t xn1=0;//Q(16,0)
int16_t xn2=0;//0(16,0)
int16_t yn;//Q(16,0)
int16_t yn1=0;//Q(16,0)
int16_t yn2=0;//Q(16,0)
int16_t b0= 1729; //Q(16,14)
int16_t b1=-2040; //Q(16,14)
int16_t b2= 1729.; //0(16,14)
int16_t a1=-26695; //Q(16,14)
int16_t a2= 11901; //0(16,14)
int n ;
int32_t mult; //Q(32,20)

int16_t* tab;
tab= new int16_t[100]


void setup() {
Serial.begin(9600);
n=0;

}

void loop()
{
  xn=round (511*sin (2*3.1415*n*0.03)) ; // cos wave at frequency 0.03, Q(16,0)

  //xn = (n > 0) ? 0: 511;// impulse 0(16,0)
  xn0=xn<<6 // INPUT DATA  Q(16,6)
  mult=((int32_t)xn*b0)+((int32_t)xn1*b1)+((int32_t)xn2*b2)-((int32_t)yn1*a1)-((int32_t)yn2*a2);//Q(16,6)
  yn=mult>>14; //back to Q(16,0)
  Serial.print("xn:");
  Serial.print(xn);
  Serial.print(',') ;
  Serial.print("yn:");
  Serial.println(yn);
  xn2=xn1;
  xn1=xn;
  yn2=yn1;
  yn1=yn;
  n++;
  delay(200);

}