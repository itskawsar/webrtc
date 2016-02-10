/*
 *  Copyright 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_API_LOCALAUDIOSOURCE_H_
#define WEBRTC_API_LOCALAUDIOSOURCE_H_

#include "webrtc/api/mediastreaminterface.h"
#include "webrtc/api/notifier.h"
#include "webrtc/api/peerconnectioninterface.h"
#include "webrtc/base/scoped_ptr.h"
#include "webrtc/media/base/mediachannel.h"

// LocalAudioSource implements AudioSourceInterface.
// This contains settings for switching audio processing on and off.

namespace webrtc {

class MediaConstraintsInterface;

class LocalAudioSource : public Notifier<AudioSourceInterface> {
 public:
  // Creates an instance of LocalAudioSource.
  static rtc::scoped_refptr<LocalAudioSource> Create(
      const PeerConnectionFactoryInterface::Options& options,
      const MediaConstraintsInterface* constraints);

  SourceState state() const override { return source_state_; }
  bool remote() const override { return false; }

  virtual const cricket::AudioOptions& options() const { return options_; }

  void AddSink(AudioTrackSinkInterface* sink) override {}
  void RemoveSink(AudioTrackSinkInterface* sink) override {}

 protected:
  LocalAudioSource() : source_state_(kInitializing) {}
  ~LocalAudioSource() override {}

 private:
  void Initialize(const PeerConnectionFactoryInterface::Options& options,
                  const MediaConstraintsInterface* constraints);

  cricket::AudioOptions options_;
  SourceState source_state_;
};

}  // namespace webrtc

#endif  // WEBRTC_API_LOCALAUDIOSOURCE_H_
