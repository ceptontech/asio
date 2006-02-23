//
// udp.hpp
// ~~~~~~~
//
// Copyright (c) 2003-2006 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_IPV6_UDP_HPP
#define ASIO_IPV6_UDP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio/detail/push_options.hpp"

#include "asio/detail/push_options.hpp"
#include <memory>
#include "asio/detail/pop_options.hpp"

#include "asio/basic_datagram_socket.hpp"
#include "asio/datagram_socket_service.hpp"
#include "asio/error.hpp"
#include "asio/ipv6/address.hpp"
#include "asio/ipv6/basic_endpoint.hpp"
#include "asio/detail/socket_types.hpp"

namespace asio {
namespace ipv6 {

/// Encapsulates the flags needed for UDP.
/**
 * The asio::ipv6::udp class contains flags necessary for UDP sockets.
 *
 * @par Thread Safety:
 * @e Distinct @e objects: Safe.@n
 * @e Shared @e objects: Safe.
 *
 * @par Concepts:
 * Protocol.
 */
class udp
{
public:
  /// The type of a UDP endpoint.
  typedef basic_endpoint<udp> endpoint;

  /// Obtain an identifier for the type of the protocol.
  int type() const
  {
    return SOCK_DGRAM;
  }

  /// Obtain an identifier for the protocol.
  int protocol() const
  {
    return IPPROTO_UDP;
  }

  /// Obtain an identifier for the protocol family.
  int family() const
  {
    return PF_INET6;
  }

  /// Template typedefs for socket types.
  template <typename Allocator>
  struct types
  {
    /// The service type for IPv4 UDP sockets.
    typedef datagram_socket_service<udp, Allocator> socket_service;

    /// The IPv4 UDP socket type.
    typedef basic_datagram_socket<socket_service> socket;
  };

  /// The IPv4 UDP socket type.
  typedef types<std::allocator<void> >::socket socket;
};

} // namespace ipv6
} // namespace asio

#include "asio/detail/pop_options.hpp"

#endif // ASIO_IPV6_UDP_HPP