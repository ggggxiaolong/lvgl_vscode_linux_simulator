#include "event.h"

static void btn_cb(lv_event_t *e)
{
    lv_label_t *label = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_RELEASED:
        lv_label_set_text(label, "The las button event:\n LV_EVENT_RELEASED");
        break;
    case LV_EVENT_CLICKED:
        lv_label_set_text(label, "The las button event:\n LV_EVENT_CLICKED");
        break;
    case LV_EVENT_LONG_PRESSED:
        lv_label_set_text(label, "The las button event:\n LV_EVENT_LONG_PRESSED");
        break;
    case LV_EVENT_LONG_PRESSED_REPEAT:
        lv_label_set_text(label, "The last button event:\nLV_EVENT_LONG_PRESSED_REPEAT");
        break;
    default:
        break;
    }
}

void example_event_2(void)
{
    lv_label_t *msg = lv_label_create(lv_scr_act());
    lv_label_set_text(msg, "The las button event:\n None");
    lv_btn_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_center(btn);
    lv_obj_add_event_cb(btn, btn_cb, LV_EVENT_ALL, msg);
    lv_label_t *la = lv_label_create(btn);
    lv_label_set_text(la, "Click me!");
}