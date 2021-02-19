#include "../../../lvgl.h"
#if LV_USE_IMG && LV_BUILD_EXAMPLES

LV_IMG_DECLARE(img_skew_strip);

/**
 * Image styling and offset
 */
void lv_example_img_4(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_COLOR_YELLOW);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_img_recolor_opa(&style, LV_OPA_COVER);
    lv_style_set_img_recolor(&style, LV_COLOR_BLACK);

    lv_obj_t * img = lv_img_create(lv_scr_act(), NULL);
    lv_obj_add_style(img, LV_PART_MAIN, LV_STATE_DEFAULT, &style);
    lv_img_set_src(img, &img_skew_strip);
    lv_obj_set_size(img, 150, 100);
    lv_obj_align(img, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, img);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_img_set_offset_y);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_time(&a, 3000);
    lv_anim_set_playback_time(&a, 500);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

}

#endif