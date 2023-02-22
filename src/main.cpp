#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "FT62XXTouchScreen.h"
#include "demos\lv_demos.h"

#define PIN_SDA 18
#define PIN_SCL 19
/*Change to your screen resolution*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
//static lv_color_t buf[ screenWidth * 10 ];
static lv_color_t buf[ screenWidth * screenHeight /10 ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
FT62XXTouchScreen touchScreen = FT62XXTouchScreen(screenHeight, PIN_SDA, PIN_SCL);

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
  static int last_x = 0;
  static int last_y = 0;
  TouchPoint touchPos = touchScreen.read();
  if (touchPos.touched) {
    data->state = LV_INDEV_STATE_PR;
    //Serial.printf("x: %d, y: %d", touchPos.xPos, touchPos.yPos);
    last_x = 480 - touchPos.xPos;
    last_y = 320 - touchPos.yPos;
    //Serial.printf("x: %d, y: %d", last_x, last_y);
  }else
    data->state = LV_INDEV_STATE_REL;
  data->point.x = last_x;
  data->point.y = last_y;    
}

long date = 0;
lv_ui guider_ui;
void setup() {
  Serial.begin( 9600 );
  // put your setup code here, to run once:
  lv_init();
  tft.begin();          /* TFT init */
  tft.setRotation( 3 ); /* Landscape orientation, flipped */
  tft.fillScreen(TFT_OLIVE);

  touchScreen.begin();

  //uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
  //tft.setTouch( calData );

  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );
  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register( &indev_drv );

  date = millis();
  // turn on tft backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, 128);

  lv_demo_widgets();
}

void loop() {
  // put your main code here, to run repeatedly:
  lv_timer_handler(); /* let the GUI do its work */
  delay( 1 );
  if(millis()-date > 5)
  {  
    lv_tick_inc(int(millis() - date));
    date = millis();
  }
}