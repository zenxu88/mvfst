/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#pragma once

#include <chrono>
#include <string>

using namespace std::chrono_literals;

namespace quic {

struct BbrStats {
  ~BbrStats() = default;
  uint8_t state;
};

struct CopaStats {
  ~CopaStats() = default;
  double deltaParam;
  bool useRttStanding;
};

union CongestionControllerStats {
  struct BbrStats bbrStats;
  struct CopaStats copaStats;
};

struct QuicConnectionStats {
 public:
  ~QuicConnectionStats() = default;
  uint8_t workerID;
  uint32_t numConnIDs;
  std::string localAddress;
  std::string peerAddress;
  std::chrono::duration<float> duration;
  uint64_t cwnd_bytes;
  std::string congestionController;
  CongestionControllerStats congestionControllerStats;
  uint32_t ptoCount{0};
  std::chrono::duration<float> srtt{0ms};
  std::chrono::duration<float> rttvar{0ms};
  uint64_t peerAckDelayExponent{0};
  uint64_t udpSendPacketLen{0};
  uint64_t numStreams{0};
  std::string clientChosenDestConnectionId;
  std::string clientConnectionId;
  std::string serverConnectionId;
  uint64_t totalBytesSent{0};
  uint64_t totalBytesReceived{0};
  uint64_t totalBytesRetransmitted{0};
  uint32_t version;
};

} // namespace quic
