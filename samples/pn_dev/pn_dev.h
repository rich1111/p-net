//
// Created by irich678 on 12/7/22.
//

#ifndef PROFINET_PN_DEV_H
#define PROFINET_PN_DEV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct PNDevSdk PNDevSdk;

typedef int (*did_get_input_data_func) (
   PNDevSdk* client,
   uint8_t  *data,
   uint16_t size
);

typedef int (*did_set_output_data_func) (
   PNDevSdk* client,
   uint8_t  *data,
   uint16_t size
);

struct PNDevSdk {
   did_get_input_data_func cb_get_input_data;
   did_set_output_data_func cb_set_output_data;
};

extern int PNDevStartup();
PNDevSdk* sdk_create();
PNDevSdk* sdk_get_pointer();
void sdk_set_callback(PNDevSdk* psdk, did_get_input_data_func cb_get_input, did_set_output_data_func cb_set_output);
int sdk_get_input_data(PNDevSdk* psdk, uint8_t *data, uint16_t size);
int sdk_set_output_data(PNDevSdk* psdk, uint8_t *data, uint16_t size);


#ifdef __cplusplus
}
#endif

#endif // PROFINET_PN_DEV_H
