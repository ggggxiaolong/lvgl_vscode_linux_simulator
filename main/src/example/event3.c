#include "event.h"

static void btn_cb(lv_event_t *e)
{
    lv_obj_t *t = lv_event_get_target(e);
    lv_obj_t *ct = lv_event_get_current_target(e);
    if(t == ct) return;

    lv_obj_set_style_bg_color(t, lv_palette_main(LV_PALETTE_RED), LV_STATE_DEFAULT);
}

void example_event_3(void)
{
    lv_obj_t *root = lv_obj_create(lv_scr_act());
    lv_obj_set_size(root, 290, 240);
    lv_obj_center(root);
    lv_obj_set_flex_flow(root, LV_FLEX_FLOW_ROW_WRAP);
    for (uint32_t i = 0; i < 30; i++)
    {
        lv_btn_t *btn = lv_btn_create(root);
        lv_obj_set_size(btn, 70, 50);
        lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);

        lv_label_t *label = lv_label_create(btn);
        lv_label_set_text_fmt(label, "%"LV_PRIu32, i);
        lv_obj_center(label);
    }

    lv_obj_add_event_cb(root, btn_cb, LV_EVENT_CLICKED, NULL);
    
}