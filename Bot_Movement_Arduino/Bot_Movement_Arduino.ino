int mot1=9;
int mot2=6;
int mot3=5;
int mot4=3;

int left=13;
int right=12;

int Left=0;
int Right=0;

void LEFT (void);
void RIGHT (void);
void STOP (void);

void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
  Serial.begin(115200);
  pinMode(left,INPUT);
  pinMode(right,INPUT);

  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
  char x= Serial.read();
  while(x!='a')
  {
    Serial.println("Not connected");
    x= Serial.read();
  }
}

void loop() 
{
  int a = Serial.parseInt();
  Serial.println(a);
analogWrite(mot1,255);
analogWrite(mot2,0);
analogWrite(mot3,255);
analogWrite(mot4,0);



  if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
  if((Left==0 && Right==1)==1)
  LEFT();
  else if((Right==0 && Left==1)==1)
  RIGHT();

}

void LEFT (void)
{
   analogWrite(mot1,0);
   analogWrite(mot2,0);
   analogWrite(mot3,30);
   analogWrite(mot4,0);
   int a = Serial.parseInt();
     if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
   
   if(Left==0)
   {
    int a = Serial.parseInt();
     if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
    if(Right==0)
    {
      int lprev=Left;
      int rprev=Right;
      STOP();
      if(((lprev==Left)&&(rprev==Right))==1)
      {
         int a = Serial.parseInt();
     if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
      }
    }
    analogWrite(mot1,255);
    analogWrite(mot3,0); 
    analogWrite(mot2,0);
    analogWrite(mot4,0); 
   }
   analogWrite(mot3,255);
   analogWrite(mot1,0);
    analogWrite(mot2,0); 
   analogWrite(mot4,0);
}

void RIGHT (void)
{
   analogWrite(mot1,30);
   analogWrite(mot3,0);
    analogWrite(mot2,0);
    analogWrite(mot4,0);
int a = Serial.parseInt();
     if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
   if(Right==0)
   {
    int a = Serial.parseInt();
     if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
    if(Left==0)
    {
      int lprev=Left;
      int rprev=Right;
     STOP();
      if(((lprev==Left)&&(rprev==Right))==1)
      {
         int a = Serial.parseInt();
     if(a>270)
{
  Right=1;
  Left=0;

}
else if(a<120)
{
  Right=0;
  Left=1;

}
else
{
  Right=1;
  Left=1;
}
      }
    }
    analogWrite(mot3,255);
    analogWrite(mot1,0);
     analogWrite(mot2,0);
    analogWrite(mot4,0);
    }
   analogWrite(mot1,255);
   analogWrite(mot3,0);
    analogWrite(mot2,0);
    analogWrite(mot4,0);
}
void STOP (void)
{
analogWrite(mot1,0);
analogWrite(mot3,0);
 analogWrite(mot2,0);
    analogWrite(mot4,0);
}