/*
 * Copyright (c) 2022 SAP SE. All rights reserved.
 * Copyright (c) 2022, Oracle and/or its affiliates. All rights reserved.
 * Copyright (c) 2022, Huawei Technologies Co., Ltd. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_GC_SHARED_GCTRIMNATIVEHEAP_HPP
#define SHARE_GC_SHARED_GCTRIMNATIVEHEAP_HPP

#include "memory/allocation.hpp"

class NativeTrimmer;

class GCTrimNative : public AllStatic {
  friend class NativeTrimmer;

  static bool _async_mode;
  static double _next_trim_not_before;

  static void do_trim();

public:

  static void initialize(bool async_mode);
  static void cleanup();

  // Returns true if:
  // - trimming is enabled and possible
  // - trimming may have an actual effect (guess)
  // - delay timer has expired (unless ignore_delay is true)
  static bool should_trim(bool ignore_delay);

  // Execute trim-native in this thread
  static void execute_trim();

  // Pause/unpause periodic trim
  static void pause_periodic_trim();
  static void unpause_periodic_trim();

  // Schedule an explicit trim now; if periodic trims had been
  // paused, they are unpaused.
  static void schedule_trim();

};

#endif // SHARE_GC_SHARED_GCTRIMNATIVEHEAP_HPP
