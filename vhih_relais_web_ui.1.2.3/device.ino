int na5_pro = 20;
int na40_5_attri = 40;
 
 void device() {
  // Relais 1 Setup

  node* n1 = new node(20, 11, "Relay 1");
  na1 = n1->AddAttributes(new nodeAttributes(1));
  na2 = n1->AddAttributes(new nodeAttributes(227));
  na3 = n1->AddAttributes(new nodeAttributes(2));
  na4 = n1->AddAttributes(new nodeAttributes(44));
  na5 = n1->AddAttributes(new nodeAttributes(33));
  na4->setUnit(WiFi.macAddress());
  na4->setEditable(0);
  na3->setEditable(0);
  na3->setMinimumValue(0);
  na3->setMaximumValue(60);
  na3->setUnit("Min");
  na1->setEditable(1);
  na1->setMinimumValue(0);
  na1->setMaximumValue(1);
  na1->setCurrentValue(0);
  na1->setTargetValue(0);
  na2->setEditable(1);
  na2->setMinimumValue(0);
  na2->setMaximumValue(3600);
  na2->setUnit("Sek");
  na2->setCurrentValue(60);
  na2->setTargetValue(60);
  na1->setCallback([](nodeAttributes * a)
   {
    a->setCurrentValue(a->getTargetValue());
    if (a->getTargetValue() == 1.00) {
      digitalWrite(relay, HIGH);
      na3->setTargetValue(60);
      vhih.updateAttribute(na3);

      relay1Milli = currentMillis;
    }
    else {
      digitalWrite(relay, LOW);
      na3->setCurrentValue(0);
      vhih.updateAttribute(na3);
    }
    vhih.updateAttribute(a);
  });
  na2->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na2_value = a->getTargetValue();
    vhih.updateAttribute(na2);
  });
  vhih.addNode(n1);

  // Relais 2 Setup

  node* n2 = new node(30, 11, "Relay 2");
  na1_2 = n2->AddAttributes(new nodeAttributes(1));
  na2_2 = n2->AddAttributes(new nodeAttributes(227));
  na3_2 = n2->AddAttributes(new nodeAttributes(2));
  na3_2->setEditable(0);
  na3_2->setMinimumValue(0);
  na3_2->setMaximumValue(60);
  na3_2->setUnit("Min");
  na1_2->setEditable(1);
  na1_2->setMinimumValue(0);
  na1_2->setMaximumValue(1);
  na1_2->setCurrentValue(0);
  na1_2->setTargetValue(0);
  na2_2->setEditable(1);
  na2_2->setMinimumValue(0);
  na2_2->setMaximumValue(3600);
  na2_2->setUnit("Sek");
  na2_2->setCurrentValue(60);
  na2_2->setTargetValue(60);
  na1_2->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    if (a->getTargetValue() == 1.00) {
      digitalWrite(relay2, HIGH);
      na3_2->setTargetValue(60);
      vhih.updateAttribute(na3_2);
      relay2Milli = currentMillis;
    }
    else {
      digitalWrite(relay2, LOW);
      na3_2->setCurrentValue(0);
      vhih.updateAttribute(na3_2);
    }
    vhih.updateAttribute(a);
  });
  na2_2->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na2_2_value = a->getTargetValue();
    vhih.updateAttribute(na2_2);
  });
  vhih.addNode(n2);


  node* n3 = new node(40, 11, "Relay 3");
  na1_3 = n3->AddAttributes(new nodeAttributes(1));
  na2_3 = n3->AddAttributes(new nodeAttributes(227));
  na3_3 = n3->AddAttributes(new nodeAttributes(2));
  na3_3->setEditable(0);
  na3_3->setMinimumValue(0);
  na3_3->setMaximumValue(60);
  na3_3->setUnit("Min");
  na1_3->setEditable(1);
  na1_3->setMinimumValue(0);
  na1_3->setMaximumValue(1);
  na1_3->setCurrentValue(0);
  na1_3->setTargetValue(0);
  na2_3->setEditable(1);
  na2_3->setMinimumValue(0);
  na2_3->setMaximumValue(3600);
  na2_3->setUnit("Sek");
  na2_3->setCurrentValue(60);
  na2_3->setTargetValue(60);
  na1_3->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    if (a->getTargetValue() == 1.00) {
      digitalWrite(relay3, HIGH);
      na3_3->setTargetValue(60);
      vhih.updateAttribute(na3_3);
      relay3Milli = currentMillis;
    }
    else {
      digitalWrite(relay3, LOW);
      na3_3->setCurrentValue(0);
      vhih.updateAttribute(na3_3);
    }
    vhih.updateAttribute(a);
  });
  na2_3->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na2_3_value = a->getTargetValue();
    vhih.updateAttribute(na2_3);
  });
  vhih.addNode(n3);
  node* n4 = new node(50, 11, "Relay 4");
  na1_4 = n4->AddAttributes(new nodeAttributes(1));
  na2_4 = n4->AddAttributes(new nodeAttributes(227));
  na3_4 = n4->AddAttributes(new nodeAttributes(2));
  na3_4->setEditable(0);
  na3_4->setMinimumValue(0);
  na3_4->setMaximumValue(60);
  na3_4->setUnit("Min");
  na1_4->setEditable(1);
  na1_4->setMinimumValue(0);
  na1_4->setMaximumValue(1);
  na1_4->setCurrentValue(0);
  na1_4->setTargetValue(0);
  na2_4->setEditable(1);
  na2_4->setMinimumValue(0);
  na2_4->setMaximumValue(3600000);
  na2_4->setUnit("Millisek");
  na2_4->setCurrentValue(60000);
  na2_4->setTargetValue(60000);
  na1_4->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    if (a->getTargetValue() == 1.00) {
      digitalWrite(relay4, HIGH);
      na3_4->setTargetValue(60);
      vhih.updateAttribute(na3_4);
      relay4Milli = currentMillis;
    }
    else {
      digitalWrite(relay4, LOW);
      na3_4->setCurrentValue(0);
      vhih.updateAttribute(na3_4);
    }
    vhih.updateAttribute(a);
  });
  na2_4->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na2_4_value = a->getTargetValue();
    vhih.updateAttribute(na2_4);
  });
  vhih.addNode(n4);



  // Taster 1
  node* n5 = new node(60, na5_pro, "Taster 1");
  na40_5 = n5->AddAttributes(new nodeAttributes(na40_5_attri));
  na41_5 = n5->AddAttributes(new nodeAttributes(91));
  na41_5->setEditable(1);
  na41_5->setMinimumValue(0);
  na41_5->setMaximumValue(1);
  na41_5->setCurrentValue(0);
  na41_5->setTargetValue(0);

  na40_5->setEditable(0);
  na40_5->setMinimumValue(0);
  na40_5->setMaximumValue(2);
  na40_5->setCurrentValue(2);
  na40_5->setTargetValue(2);
  na41_5->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na41_5_value = a->getTargetValue();
    vhih.updateAttribute(na41_5);
  });
  vhih.addNode(n5);

  // Taster 2
  node* n6 = new node(70, 20, "Taster 2");
  na40_6 = n6->AddAttributes(new nodeAttributes(40));
  na41_6 = n6->AddAttributes(new nodeAttributes(91));
  na41_6->setEditable(1);
  na41_6->setMinimumValue(0);
  na41_6->setMaximumValue(1);
  na41_6->setCurrentValue(0);
  na41_6->setTargetValue(0);

  na40_6->setEditable(0);
  na40_6->setMinimumValue(0);
  na40_6->setMaximumValue(2);
  na40_6->setCurrentValue(2);
  na40_6->setTargetValue(2);
  na41_6->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na41_6_value = a->getTargetValue();
    vhih.updateAttribute(na41_6);
  });
  vhih.addNode(n6);


  // Taster 3
  node* n7 = new node(80, 20, "Taster 3");
  na40_7 = n7->AddAttributes(new nodeAttributes(40));
  na41_7 = n7->AddAttributes(new nodeAttributes(91));
  na41_7->setEditable(1);
  na41_7->setMinimumValue(0);
  na41_7->setMaximumValue(1);
  na41_7->setCurrentValue(0);
  na41_7->setTargetValue(0);
  na40_7->setEditable(0);
  na40_7->setMinimumValue(0);
  na40_7->setMaximumValue(2);
  na40_7->setCurrentValue(2);
  na40_7->setTargetValue(2);
  na41_7->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na41_7_value = a->getTargetValue();
    vhih.updateAttribute(na41_7);
  });
  vhih.addNode(n7);


  // Taster 4
  node* n8 = new node(90, 20, "Taster 4");
  na40_8 = n8->AddAttributes(new nodeAttributes(40));
  na41_8 = n8->AddAttributes(new nodeAttributes(91));
  na41_8->setEditable(1);
  na41_8->setMinimumValue(0);
  na41_8->setMaximumValue(1);
  na41_8->setCurrentValue(0);
  na41_8->setTargetValue(0);

  na40_8->setEditable(0);
  na40_8->setMinimumValue(0);
  na40_8->setMaximumValue(2);
  na40_8->setCurrentValue(2);
  na40_8->setTargetValue(2);
  na41_8->setCallback([](nodeAttributes * a)
  {
    a->setCurrentValue(a->getTargetValue());
    na41_8_value = a->getTargetValue();
    vhih.updateAttribute(na41_8);
  });

  vhih.addNode(n8);
}
