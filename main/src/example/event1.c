#include "event.h"

static void btn_click_cd(lv_event_t *e)
{
    static uint32_t count = 1;
    lv_btn_t *btn = lv_event_get_target(e);
    lv_label_t *label = lv_obj_get_child(btn, 0);
    lv_label_set_text_fmt(label, "%"LV_PRIu32, count++);
}

void example_event_1(void)
{
    lv_btn_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn, btn_click_cd, LV_EVENT_CLICKED, NULL);
    lv_obj_set_size(btn, 100, 40);
    lv_label_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(btn);
    lv_obj_center(label);
}