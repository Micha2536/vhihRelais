void toggle() {

  // Switch 1

  if (switch_1_state == 1 && digitalRead(switch_1) == HIGH ) {
    switch_1_state = 0;
    na40_5->setTargetValue(2);
    na40_5->setCurrentValue(2);
    vhih.updateAttribute(na40_5);

  }
  if (digitalRead(switch_1) == LOW && switch_1_state == 0) {
    switch_1_state = 1;
    na40_5->setTargetValue(1);
    na40_5->setCurrentValue(1);
    vhih.updateAttribute(na40_5);
    if ( digitalRead(relay) == LOW && na41_5_value == 0) {
      digitalWrite(relay, HIGH);
      na1->setCurrentValue(1);
      na1->setTargetValue(1);
      vhih.updateAttribute(na1);
      na3->setTargetValue(60);
      vhih.updateAttribute(na3);
      relay1Milli = currentMillis;
      delay(500);
    }
    else if ( digitalRead(relay) == HIGH && na41_5_value == 0) {
      digitalWrite(relay, LOW);
      na1->setCurrentValue(0);
      na1->setTargetValue(0);
      vhih.updateAttribute(na1);
      na3->setCurrentValue(0);
      vhih.updateAttribute(na3);
      relay1Milli = currentMillis;
      delay(500);
    }
  }


  // Switch 2

  if (switch_2_state == 1 && digitalRead(switch_2) == HIGH ) {
    switch_2_state = 0;
    na40_6->setTargetValue(2);
    na40_6->setCurrentValue(2);
    vhih.updateAttribute(na40_6);
  }
  if (digitalRead(switch_2) == LOW && switch_2_state == 0) {

    na40_6->setTargetValue(1);
    na40_6->setCurrentValue(1);
    vhih.updateAttribute(na40_6);
    if ( digitalRead(relay2) == LOW && na41_6_value == 0) {
      digitalWrite(relay2, HIGH);
      na1_2->setCurrentValue(1);
      na1_2->setTargetValue(1);
      vhih.updateAttribute(na1_2);
      na3_2->setTargetValue(60);
      vhih.updateAttribute(na3_2);
      relay2Milli = currentMillis;
      delay(500);
    }

    else if ( digitalRead(relay2) == HIGH && na41_6_value == 0) {
      digitalWrite(relay2, LOW);
      na1_2->setCurrentValue(0);
      na1_2->setTargetValue(0);
      vhih.updateAttribute(na1_2);
      na3_2->setCurrentValue(0);
      vhih.updateAttribute(na3_2);
      relay2Milli = currentMillis;
      delay(500);
    }
    switch_2_state = 1;
  }

  // Switch 3

  if (switch_3_state == 1 && digitalRead(switch_3) == HIGH ) {
    switch_3_state = 0;
    na40_7->setTargetValue(2);
    na40_7->setCurrentValue(2);
    vhih.updateAttribute(na40_7);
  }

  if (digitalRead(switch_3) == LOW && switch_3_state == 0) {
    switch_3_state = 1;
    na40_7->setTargetValue(1);
    na40_7->setCurrentValue(1);
    vhih.updateAttribute(na40_7);
    if ( digitalRead(relay3) == LOW && na41_7_value == 0) {

      digitalWrite(relay3, HIGH);
      na1_3->setCurrentValue(1);
      na1_3->setTargetValue(1);
      vhih.updateAttribute(na1_3);
      na3_3->setTargetValue(60);
      vhih.updateAttribute(na3_3);
      relay3Milli = currentMillis;
      delay(500);
    }


    else if ( digitalRead(relay3) == HIGH && na41_7_value == 0) {
      digitalWrite(relay3, LOW);
      na1_3->setCurrentValue(0);
      na1_3->setTargetValue(0);
      vhih.updateAttribute(na1_3);
      na3_3->setCurrentValue(0);
      vhih.updateAttribute(na3_3);
      relay3Milli = currentMillis;
      delay(500);
    }
  }
  // Switch 4

  if (switch_4_state == 1 && digitalRead(switch_4) == HIGH ) {
    switch_4_state = 0;
    na40_8->setTargetValue(2);
    na40_8->setCurrentValue(2);
    vhih.updateAttribute(na40_8);
  }
  if (digitalRead(switch_4) == LOW && switch_4_state == 0) {
    switch_4_state = 1;
    na40_8->setTargetValue(1);
    na40_8->setCurrentValue(1);
    vhih.updateAttribute(na40_8);
    if ( digitalRead(relay4) == LOW && na41_8_value == 0) {
      digitalWrite(relay4, HIGH);
      na1_4->setCurrentValue(1);
      na1_4->setTargetValue(1);
      vhih.updateAttribute(na1_4);
      na3_4->setTargetValue(60);
      vhih.updateAttribute(na3_4);
      relay4Milli = currentMillis;
      delay(500);
    }

    else if ( digitalRead(relay4) == HIGH && na41_8_value == 0) {
      digitalWrite(relay4, LOW);
      na1_4->setCurrentValue(0);
      na1_4->setTargetValue(0);
      vhih.updateAttribute(na1_4);
      na3_4->setCurrentValue(0);
      vhih.updateAttribute(na3_4);
      relay4Milli = currentMillis;
      delay(500);
    }
  }


}
