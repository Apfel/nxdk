#ifndef __NXDK_LOG_UDP_H__
#define __NXDK_LOG_UDP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "log.h"

#include <lwip/ip4_addr.h>

/**
 * Registers the UDP logging function.
 * This'll print messages to a UDP socket on port 4405.
 *
 * @param ip The IP address to bind to.
 * @param netmask The subnet mask for the IP address.
 * @param gateway The IP address of the gateway to connect to.
 *
 * @note Set @c ip , @c netmask and @c gateway to @c NULL if you want to use DHCP.
 * @note All values either need to be @c NULL or contain a valid IP address / subnet mask.
 * @note In case @c NXDK_UDP_USE_INTERNAL_NETIF_IMPL is defined (e.g @c NXDK_UDP_INTERNAL_INIT is enabled in your Makefile), log_udp will use its own lwIP/nforceif initialization code.
 *
 * @return Returns an @link nxLogResult @endlink code.
 */
uint8_t nxLogUDPRegister(ip4_addr_t* ip, ip4_addr_t* netmask, ip4_addr_t* gateway);

/**
 * Unregisters the UDP logging function.
 */
void nxLogUDPUnregister();

#ifdef __cplusplus
}
#endif

#endif
