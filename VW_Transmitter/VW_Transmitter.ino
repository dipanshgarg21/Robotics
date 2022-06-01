/*
    Author: Dipansh Garg
    Roll no.: 2110994822 (Chitkara University)
    Course: BE Software Engineering (Global)
    Action: Transmits from transitter to reciever for master slave combo
*/

// Transmitter

#include <VirtualWire.h>

#define L1 5
#define L2 6
#define R1 9
#define R2 11

char input;
char *msg;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(9600);
  vw_set_tx_pin(10);
  vw_setup(2000);

  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}

void loop() {
  if (Serial.available())
  {
    input = Serial.read();
  }

  if (input == 'F')
  {
    msg[0] = 'f';
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
  }

  else if (input == 'S')
  {
    msg[0] = 's';
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
  }

  else if (input == 'B')
  {
    msg[0] = 'b';
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
  }

  else if (input == 'L')
  {
    msg[0] = 'l';
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
  }

  else if (input == 'R')
  {
    msg[0] = 'r';
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
  }
}
