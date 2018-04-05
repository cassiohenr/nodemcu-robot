int m1_F = 8, m1_T = 9, m2_T = 10, m2_F =11; 
int NODE_K1=2; //ligado gpio_16 = D0
int NODE_K2=3;   //gpio_5 = D1
int VALOR_K1=0;
int VALOR_K2=0;
int VALOR_K1_SPEED=0;
int VALOR_K2_SPEED=0;

void setup() 
{
 Serial.begin(9600);
 pinMode(m1_F, OUTPUT);
 pinMode(m1_T, OUTPUT);
 pinMode(m2_F, OUTPUT);
 pinMode(m2_T, OUTPUT);
 pinMode(m2_T, OUTPUT);
 pinMode(NODE_K1, INPUT);
 pinMode(NODE_K2, INPUT);
}

void loop()
{
  VALOR_K1 = pulseIn(NODE_K1, HIGH, 20000);
  VALOR_K2 = pulseIn(NODE_K2, HIGH, 20000);
  VALOR_K1 = map(VALOR_K1, 0, 1023, 0, 255);
  VALOR_K2 = map(VALOR_K2, 0, 1023, 0, 255);
  
  analogWrite(m1_F, VALOR_K1 );   
  analogWrite(m2_F, VALOR_K2);
   
  if(VALOR_K1 > 550)
  { 
  analogWrite(m1_F, 150);   //FRENTE
  analogWrite(m1_T, 0);
  analogWrite(m2_T, 0);
  }
  
  if(VALOR_K1 < 450)
  { 
  analogWrite(m1_F, 0);    //TRAZ
  analogWrite(m2_F, 00);
  analogWrite(m1_T, 150);
  analogWrite(m2_T, 150);
  }

  if(VALOR_K2 > 700)
  {
  analogWrite(m1_F, 150);   //GIRA
  analogWrite(m2_F, 0);
  analogWrite(m1_T, 0);
  analogWrite(m2_T, 150);
  }  
  
  if(VALOR_K2 < 300)
  { 
  analogWrite(m1_F, 0);    //GIRA
  analogWrite(m2_F, 150);
  analogWrite(m1_T, 150);
  analogWrite(m2_T, 0);
  }
   
  if((VALOR_K1 <= 550)&&(VALOR_K1>=450))
  { 
  analogWrite(m1_F, 0);
  analogWrite(m2_F, 0);
  analogWrite(m1_T, 0);
  analogWrite(m2_T, 0);
  }
}
