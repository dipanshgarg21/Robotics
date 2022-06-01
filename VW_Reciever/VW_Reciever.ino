/*
    Author: Dipansh Garg
    Roll no.: 2110994822 (Chitkara University)
    Course: BE Software Engineering (Global)
    Action: Recives from reciever to follow commands for master slave combo
*/

// Reciever

#include <VirtualWire.h>

#define L1 10
#define L2 11
#define R1 12
#define R2 13

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(9600);
  vw_set_rx_pin(9);
  vw_setup(2000);
  pinMode(9, INPUT);
  vw_rx_start();
}

void loop() {
  uint8_t msg[VW_MAX_MESSAGE_LEN];
  uint8_t msglen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(msg, &msglen))
  {
    if (msg[0] == 'f')
    {
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, LOW);
    }

    else if (msg[0] == 's')
    {
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }

    else if (msg[0] == 'b')
    {
      digitalWrite(L1, LOW);
      digitalWrite(L2, HIGH);
      digitalWrite(R1, LOW);
      digitalWrite(R2, HIGH);
    }

    else if (msg[0] == 'l')
    {
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }

    else if (msg[0] == 'r')
    {
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, LOW);
    }
    delay(200);
  }
}
