#include "lvgl.h"
/**
 * 不透明度和旋转
*/
// FIXME 旋转有问题
void example_style_15(void)
{
    lv_obj_t *btn;
    lv_obj_t *label;
    btn = lv_btn_create(lv_scr_act());
    label = lv_label_create(btn);
    lv_label_set_text(label, "Normal");
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, -70);

    btn = lv_btn_create(lv_scr_act());
    lv_obj_set_style_bg_opa(btn, LV_OPA_50, LV_STATE_DEFAULT);
    label = lv_label_create(btn);
    lv_label_set_text(label, "Opa:50%%");
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);

    btn = lv_btn_create(lv_scr_act());
    label = lv_label_create(btn);
    lv_obj_set_size(btn, 100, 40);
    lv_obj_set_style_bg_opa(btn, LV_OPA_50, LV_STATE_DEFAULT);
    lv_obj_set_style_transform_angle(btn, 15, LV_STATE_DEFAULT);
    lv_obj_set_style_transform_zoom(btn, 256 + 64, LV_STATE_DEFAULT);
    lv_obj_set_style_transform_pivot_x(btn, 50, LV_STATE_DEFAULT);
    lv_obj_set_style_transform_pivot_y(btn, 20, LV_STATE_DEFAULT);
    lv_label_set_text(label, "Transf,");
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 70);
}