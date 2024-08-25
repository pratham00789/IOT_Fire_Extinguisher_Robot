

#define rmp 2
#define rmn 3
#define lmp 4
#define lmn 5
#define fmid 10
#define fleft 11
#define fright 13
#define pr 9
#define pl 8

void setup() {
  // put your setup code here, to run once:
  pinMode(rmp, OUTPUT);
  pinMode(rmn, OUTPUT);
  pinMode(lmp, OUTPUT);
  pinMode(lmn, OUTPUT);
  pinMode(fmid, INPUT);
  pinMode(fright, INPUT);
  pinMode(fleft, INPUT);
  pinMode(pr, OUTPUT);
  pinMode(pl, OUTPUT);
}
int vmid;
int vleft;
int vright;

void loop() {
  // put your main code here, to run repeatedly:
  vmid = digitalRead(fmid);
  vleft = digitalRead(fleft);
  vright = digitalRead(fright);
  
  if (vmid == 0) {
    forward();
    delay(1000);
    pump();
    delay(500);
    nopump();
    //stop1();
  }
  
  else if (vleft == 0 && vright == 1 && vmid == 1)
  {
    left();
    nopump();
  }
  
  else if (vright == 0 && vmid == 1 && vleft == 1) {
    right();
    nopump();
  }
  else {
    stop1();
    nopump();
  }
}
void forward() {
  digitalWrite(rmp, HIGH);
  digitalWrite(rmn, LOW);
  digitalWrite(lmp, HIGH);
  digitalWrite(lmn, LOW);
}
void left() {
  digitalWrite(rmp, HIGH);
  digitalWrite(rmn, LOW);
  digitalWrite(lmp, LOW);
  digitalWrite(lmn, LOW);
}
void stop1() {
  digitalWrite(rmp, LOW);
  digitalWrite(rmn, LOW);
  digitalWrite(lmp, LOW);
  digitalWrite(lmn, LOW);
}
void right() {
  digitalWrite(rmp, LOW);
  digitalWrite(rmn, LOW);
  digitalWrite(lmp, HIGH);
  digitalWrite(lmn, LOW);
}
void reverse() {
  digitalWrite(rmp, LOW);
  digitalWrite(rmn, HIGH);
  digitalWrite(lmp, LOW);
  digitalWrite(lmn, HIGH);
}
void pump() {
  digitalWrite(pr, LOW);
  digitalWrite(pl, HIGH);
}
void nopump() {
  digitalWrite(pr, LOW);
  digitalWrite(pl, LOW);
}
