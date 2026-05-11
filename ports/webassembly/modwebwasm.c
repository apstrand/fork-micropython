#include "py/runtime.h"
#include "py/obj.h"
#include "library.h"

#if MICROPY_PY_MICROPYTHON_WASM

// Defined in library.js / library.h
extern void mp_js_display(const char *data, const char *mime_type);

static mp_obj_t mod_webwasm_display(size_t n_args, const mp_obj_t *args) {
    const char *data = mp_obj_str_get_str(args[0]);
    const char *mime_type = "text/plain";
    if (n_args > 1) {
        mime_type = mp_obj_str_get_str(args[1]);
    }
    
    mp_js_display(data, mime_type);
    
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mod_webwasm_display_obj, 1, 2, mod_webwasm_display);

static const mp_rom_map_elem_t mp_module_webwasm_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_webwasm) },
    { MP_ROM_QSTR(MP_QSTR_display), MP_ROM_PTR(&mod_webwasm_display_obj) },
};
static MP_DEFINE_CONST_DICT(mp_module_webwasm_globals, mp_module_webwasm_globals_table);

const mp_obj_module_t mp_module_webwasm = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&mp_module_webwasm_globals,
};

MP_REGISTER_MODULE(MP_QSTR_webwasm, mp_module_webwasm);

#endif // MICROPY_PY_MICROPYTHON_WASM
