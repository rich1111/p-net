//
// Created by irich678 on 12/12/22.
//
#include "pn_dev.h"
#include <stdlib.h>

static PNDevSdk* sdk_pointer;

PNDevSdk* sdk_create() {
   sdk_pointer = malloc(sizeof(PNDevSdk));
   sdk_pointer->cb_get_input_data = NULL;
   sdk_pointer->cb_set_output_data = NULL;
   return sdk_pointer;
}

PNDevSdk* sdk_get_pointer()
{
   return sdk_pointer;
}

void sdk_set_callback(PNDevSdk* psdk, did_get_input_data_func cb_get_input, did_set_output_data_func cb_set_output)
{
   psdk->cb_get_input_data = cb_get_input;
   psdk->cb_set_output_data = cb_set_output;
}

int sdk_get_input_data(PNDevSdk* psdk, uint8_t *data, uint16_t size)
{
   if (psdk->cb_get_input_data != NULL) {
      return psdk->cb_get_input_data(psdk, data, size);
   } else
      return -1;
}

int sdk_set_output_data(PNDevSdk* psdk, uint8_t *data, uint16_t size)
{
   if (psdk->cb_set_output_data != NULL) {
      return psdk->cb_set_output_data(psdk, data, size);
   } else
      return -1;
}
