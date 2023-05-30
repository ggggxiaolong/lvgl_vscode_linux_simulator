#include "lvgl.h"

void lv_example_get_start_1(void)
{
    lv_obj_t *src = lv_scr_act();
    lv_obj_set_style_bg_color(src, lv_color_hex(0x003a57), LV_PART_MAIN);
    lv_obj_t *label = lv_label_create(src);
    lv_label_set_text(label, "Hello, This is MrTan");
    lv_obj_set_style_text_color(src, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED)
    {
        static uint8_t cnt = 0;
        cnt ++;
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

/**
 * 创建一个带label的按钮，并响应点击事件
*/
void lv_example_get_start_2(void)
{
    lv_obj_t *src = lv_scr_act();
    lv_obj_t *btn = lv_btn_create(src);
    lv_obj_set_pos(btn, 10, 10);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);
}