#include <ProjectButton.h>

ProjectButton projectButton(8);

void setup() {
  // put your setup code here, to run once:
  projectButton.setup();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (projectButton.PosEdge()) {
  Serial.println("Postive edge");
  }
  else if (projectButton.NegEdge()){
    Serial.println("Negative Edge");
  }
}
