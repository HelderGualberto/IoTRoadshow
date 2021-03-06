/* Copyright (c) 2014, Nordic Semiconductor ASA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef H_ACI_SETUP
#define H_ACI_SETUP

#define SETUP_SUCCESS                        0
#define SETUP_FAIL_COMMAND_QUEUE_NOT_EMPTY   1
#define SETUP_FAIL_EVENT_QUEUE_NOT_EMPTY     2
#define SETUP_FAIL_TIMEOUT                   3
#define SETUP_FAIL_NOT_SETUP_EVENT           4
#define SETUP_FAIL_NOT_COMMAND_RESPONSE      5

bool aci_setup_fill(aci_state_t *aci_stat, uint8_t *num_cmd_offset);
/** @brief Setup the nRF8001 device
 *  @details
 *  Performs ACI Setup by transmitting the setup messages generated by nRFgo Studio to the
 *  nRF8001, and should be called when the nRF8001 starts or resets.
 *  Once all messages are sent, the nRF8001 will send a Device Started Event.
 *  The function requires that the Command queue is empty when it is invoked, and will fail
 *  otherwise.
 *  @returns An integer indicating the reason the function terminated
 */
uint8_t do_aci_setup(aci_state_t *aci_stat);

#endif
