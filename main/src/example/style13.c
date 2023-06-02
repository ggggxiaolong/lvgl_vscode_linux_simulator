#include "style.h"

/**
 * 修改slider的样式
*/
// FIXME 渐变背景有问题
void example_style_13(void)
{
    static lv_style_t style_indic;
    lv_style_init(&style_indic);
    lv_style_set_bg_color(&style_indic, lv_palette_lighten(LV_PALETTE_RED, 3));
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    // lv_style_set_radius(&style_indic, LV_RADIUS_CIRCLE);
    lv_style_set_pad_ver(&style_indic, -2);
    lv_style_set_shadow_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
    // lv_style_set_bg_grad_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
    // lv_style_set_bg_grad_dir(&style_indic, LV_GRAD_DIR_HOR);

    static lv_style_t style_indic_pr;
    lv_style_init(&style_indic_pr);
    lv_style_set_shadow_color(&style_indic_pr, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_shadow_width(&style_indic_pr, 10);
    lv_style_set_shadow_spread(&style_indic_pr, 3);

    lv_obj_t *obj = lv_slider_create(lv_scr_act());
    lv_obj_add_style(obj, &style_indic, LV_PART_INDICATOR);
    lv_obj_add_style(obj, &style_indic_pr, LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_slider_set_value(obj, 80, LV_ANIM_OFF);
    lv_obj_center(obj);
}