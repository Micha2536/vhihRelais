void switching_off() {

  // Relais 1

  if (na2_value > 0.0000) {
    if ( digitalRead(relay) == HIGH ) {
      if ( currentMillis - lastMillis >= 10000) {
        lastMillis = currentMillis;
        na3->setCurrentValue((na2_value/60) - ( (currentMillis - relay1Milli) / 60000));
        na3->setTargetValue((na2_value/60) - ( (currentMillis - relay1Milli) / 60000));
        vhih.updateAttribute(na3);
      }
      if ( currentMillis - relay1Milli >= na2_value * 1000) {
        digitalWrite(relay, LOW);
        na3->setCurrentValue(0);
        vhih.updateAttribute(na3);
        na1->setCurrentValue(0);
        na1->setTargetValue(0);
        vhih.updateAttribute(na1);
      }

    }
  };

  // Relais 2

  if (na2_2_value > 0.0000) {
    if ( digitalRead(relay2) == HIGH ) {
      if ( currentMillis - last2Millis >= 10000) {
        last2Millis = currentMillis;
        na3_2->setCurrentValue((na2_2_value/60) - ( (currentMillis - relay2Milli) / 60000));
        na3_2->setTargetValue((na2_2_value/60) - ( (currentMillis - relay2Milli) / 60000));
        vhih.updateAttribute(na3_2);
      }
      if ( currentMillis - relay2Milli >= na2_2_value * 1000) {
        digitalWrite(relay2, LOW);
        na3_2->setCurrentValue(0);
        vhih.updateAttribute(na3_2);
        na1_2->setCurrentValue(0);
        na1_2->setTargetValue(0);
        vhih.updateAttribute(na1_2);
      }

    }
  };

  // Relais 3

  if (na2_3_value > 0.0000) {
    if ( digitalRead(relay3) == HIGH ) {
      if ( currentMillis - last3Millis >= 10000) {
        last3Millis = currentMillis;
        na3_3->setCurrentValue((na2_3_value/60) - ( (currentMillis - relay3Milli) / 60000));
        na3_3->setTargetValue((na2_3_value/60) - ( (currentMillis - relay3Milli) / 60000));
        vhih.updateAttribute(na3_3);
      }
      if ( currentMillis - relay3Milli >= na2_3_value * 1000) {
        digitalWrite(relay3, LOW);
        na3_3->setCurrentValue(0);
        vhih.updateAttribute(na3_3);
        na1_3->setCurrentValue(0);
        na1_3->setTargetValue(0);
        vhih.updateAttribute(na1_3);
      }

    }
  };
  // Relais 4

  if (na2_4_value > 0.0000) {
    if ( digitalRead(relay4) == HIGH ) {
      if ( currentMillis - last4Millis >= 10000) {
        last4Millis = currentMillis;
        na3_4->setCurrentValue((na2_4_value/60000) - ( (currentMillis - relay4Milli) / 60000));
        na3_4->setTargetValue((na2_4_value/60000) - ( (currentMillis - relay4Milli) / 60000));
        vhih.updateAttribute(na3_4);
      }
      if ( currentMillis - relay4Milli >= na2_4_value ) {
        digitalWrite(relay4, LOW);
        na3_4->setCurrentValue(0);
        vhih.updateAttribute(na3_4);
        na1_4->setCurrentValue(0);
        na1_4->setTargetValue(0);
        vhih.updateAttribute(na1_4);
      }

    }
  };
}
