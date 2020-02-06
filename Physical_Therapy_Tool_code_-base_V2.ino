
/*
 * PHYSICAL THERAPY TOOL RESEARCH PROJECT
 * --------------------------------------
 * Code uses two pressure sensors to see how much
 * force is being used on a patient with PT scraping
 * tools.
 * ------------------------------------------
 * Written by: Casey Walker
 * BYU CS HCI Research 2019
 *
*/
#include <FastLED.h>
#define NUM_LEDS 4
#define DATA_PIN 5

#define NUM_LEDS_1 4
#define DATA_PIN_1 4

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

// defines the array of leds being used.
CRGB leds[NUM_LEDS];
CRGB leds_1[NUM_LEDS_1];

const int analog_pin_0 = A0;
const int analog_pin_1 = A1;
const int led_pin_1 = A3;
int value1 = 0;
int value2 = 0;
int noise_reduction = 8;
int avg_value = 0;
int led_number = 0; 
int iterate = 0;

int upper_threshold = 400;
int lower_threshold = 280;


void setup() {
  Serial.begin(9600);
  Serial.println("-------------------");
  Serial.println("BYU HCI PT RESEARCH");
  LEDS.addLeds<WS2811,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.addLeds<WS2811,DATA_PIN_1,RGB>(leds_1,NUM_LEDS_1);
  LEDS.setBrightness(255);
  pinMode(analog_pin_0, INPUT);
  pinMode(analog_pin_1, INPUT);
  pinMode(led_pin_1, OUTPUT);
  delay(1000);
  for(led_number = 0; led_number<NUM_LEDS;led_number=led_number+1){
        leds[led_number] = CRGB::White;
        FastLED.show();
        leds_1[led_number] = CRGB::White;
        FastLED.show();
        delay(50);
    }
    for(int brightness = 255; brightness >=0; brightness=brightness-1)
    {
      LEDS.setBrightness(brightness);
      FastLED.show();
      delay(5);
    }
    for(led_number = 4; led_number >= 0;led_number=led_number-1)
    {
        leds[led_number] = CRGB::Black;
        FastLED.show();
        leds_1[led_number] = CRGB::Black;
        FastLED.show();
        delay(50);
    }
    LEDS.setBrightness(255);
}

void loop() {
  // contantly check both of the values from the Force Sensor
  static uint8_t hue = 0;
  //}
  //leds[0] = CRGB::Blue;
  //FastLED.show();
  value1 = analogRead(analog_pin_0);
  value2 = analogRead(analog_pin_1);

  // --------STUBS------
  // Serial.print("SENSOR 1  ");
  // Serial.println(value1);
  //Serial.print("SENSOR 2  ");
  //Serial.println(value2);

  
  // average out the vlues accross the two sensors.
  avg_value = (value1+value2)/2;
  //Serial.println(avg_value);
  // doesnt print out values that are pretty small(noise)
 
  if (value1 >= upper_threshold)
  {
    Serial.println(avg_value);
    for(int i=0;i<=NUM_LEDS;i++)
    {
      leds[i] = CRGB::Green;
      leds_1[i] = CRGB::Green;
      FastLED.show();
    }  
  }
  else if(avg_value > lower_threshold && avg_value < upper_threshold)
  {
    Serial.println(avg_value);
    for(int i =0;i<=NUM_LEDS;i++)
    {
      leds[i] = CRGB::Red;
      leds_1[i] = CRGB::Red;
      FastLED.show();
    }  
  }
  else if (avg_value > noise_reduction && avg_value < lower_threshold)
  {
    Serial.println(avg_value);
    for(int i=0;i<=NUM_LEDS;i++)
    {
      leds[i] = CRGB::Yellow;
      leds_1[i] = CRGB::Yellow;
      FastLED.show();
    }
  }
  else
  {
    for(int i=0;i<=NUM_LEDS;i++)
    {
      leds[i] = CRGB::Black;
      leds_1[i] = CRGB::Black;
      FastLED.show();
    }
  }
  delay(50);

}
