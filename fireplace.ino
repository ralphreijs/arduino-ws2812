#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(56, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void modeFireplace(){

	uint8_t iRandom = 0;
	for(int iRow = 0; iRow<8; iRow++){

		for(int iCol = 0; iCol<9; iCol++){
                for(int iBlank = 0; iBlank < strip.numPixels(); iBlank++){strip.setPixelColor(iRow+(iCol*8), 0,0,0);}            
			iRandom = random(1,100);
			if (iRandom > 0){strip.setPixelColor(iCol, random(200,255), 0, 0);}
			if (iRandom > 50){strip.setPixelColor(8+iCol, 255, random(0,50), 0);}
			if (iRandom > 65){strip.setPixelColor(16+iCol, 255, random(50,100), 0);}
			if (iRandom > 80){strip.setPixelColor(24+iCol, 255, random(50,150), 0);}
			if (iRandom > 90){strip.setPixelColor(32+iCol, 255, random(100,150), 0);}
			if (iRandom > 95){strip.setPixelColor(40+iCol, 255, random(150,200), 0);}
			if (iRandom > 98){strip.setPixelColor(48+iCol, 255, random(200,255), 255);}
//                  delay(10);
		}
	}
        strip.show();
}

void loop() {
    modeFireplace();
}

 
