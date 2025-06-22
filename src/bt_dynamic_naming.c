#include <zmk/event_manager.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/ble.h>
#include <stdio.h>

static void update_ble_name(uint8_t profile_index) {
    char new_name[16];
    snprintf(new_name, sizeof(new_name), "Paintbrush-%d", profile_index);
    zmk_ble_set_device_name(new_name);
}

static int bt_profile_changed_listener(const struct zmk_event_t *eh) {
    const struct zmk_ble_active_profile_changed *ev = as_zmk_ble_active_profile_changed(eh);
    if (ev == NULL) {
        return ZMK_EV_EVENT_BUBBLE;
    }
    update_ble_name(ev->index);
    return ZMK_EV_EVENT_BUBBLE;
}

static int set_name_at_boot(void) {
    update_ble_name(zmk_ble_active_profile_index());
    return 0;
}

SYS_INIT(set_name_at_boot, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
ZMK_LISTENER(name_updater, bt_profile_changed_listener);
ZMK_SUBSCRIPTION(name_updater, zmk_ble_active_profile_changed);
