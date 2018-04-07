void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println(getVcc3());
  delay(1000);
}

unsigned int getVcc3() {
  ADC10CTL0 = SREF_1 + REFON + REF2_5V + ADC10ON + ADC10SHT_3;  // use internal ref, turn on 2.5V ref, set samp time = 64 cycles
  ADC10CTL1 = INCH_11;                        
  delay(1);                                     // Allow internal reference to stabilize
  ADC10CTL0 |= ENC + ADC10SC;                     // Enable conversions
  while (!(ADC10CTL0 & ADC10IFG));                // Conversion done?
  unsigned long temp = (ADC10MEM * 5000l);        // Convert raw ADC value to millivolts
  return ((unsigned int) (temp / 1024l));
}
