/*!
 * \file unpack_spir_gss6450_samples.h
 *
 * \brief Unpacks SPIR int samples
 * \author Antonio Ramos, antonio.ramos(at)cttc.es
 * \author Javier Arribas jarribas (at) cttc.es
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2018  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is not part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_UNPACK_SPIR_GSS6450_SAMPLES_H
#define GNSS_SDR_UNPACK_SPIR_GSS6450_SAMPLES_H

#include <gnuradio/sync_interpolator.h>

class unpack_spir_gss6450_samples;

typedef boost::shared_ptr<unpack_spir_gss6450_samples> unpack_spir_gss6450_samples_sptr;

unpack_spir_gss6450_samples_sptr make_unpack_spir_gss6450_samples(unsigned int adc_nbit);


class unpack_spir_gss6450_samples : public gr::sync_interpolator
{
public:
    int work(int noutput_items,
        gr_vector_const_void_star &input_items, gr_vector_void_star &output_items);
    friend unpack_spir_gss6450_samples_sptr make_unpack_spir_gss6450_samples_sptr(unsigned int adc_nbit);
    void decode_4bits_word(uint32_t input_int32, gr_complex *out, int adc_bits);
    unpack_spir_gss6450_samples(unsigned int adc_nbit);
    ~unpack_spir_gss6450_samples();

private:
    unsigned int adc_bits;
    unsigned int samples_per_int;
};

#endif
